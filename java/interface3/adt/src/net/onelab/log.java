package net.onelab;

import java.text.SimpleDateFormat;  
import java.util.Calendar;
import java.util.ArrayList;
import java.io.BufferedWriter;
import java.io.IOException;

public class log {
	public static void printf(String format, Object...args) {
		System.out.printf(format, args);
	}
	
	public class Message {
		public String Time;
		public String Sender;
		public String Content;
		public Message(String aSender, String aContent) {
			Sender = aSender;
			Content = aContent;
			Calendar now = Calendar.getInstance();
			SimpleDateFormat f = new SimpleDateFormat("yyyy/MM/dd HH:mm:ss.SSS");
			Time = f.format(now);
		}
	}
	
	private static ArrayList<Message> ErrorList = new ArrayList<Message>();
	
	private static ArrayList<Message> InfoList = new ArrayList<Message>();
	
	private static void mark(String aSender, Object aContent, ArrayList<Message> list) {
		if (aSender == null || aContent == null || list == null) return;
		String content = aContent.toString();
		if (content.isEmpty()) return;
		list.add(new log().new Message(aSender, content));
	}
	
	public static void err(String aSender, Object aContent) {
		mark(aSender, aContent, ErrorList);
	}
	
	public static void info(String aSender, Object aContent) {
		mark(aSender, aContent, InfoList);
	}	
	
	private static boolean output(BufferedWriter writer, ArrayList<Message> list){
		if (list == null) return false;
		if (writer == null) {
			for(Message m : list)
				System.out.println(m.Time + "\t" + m.Sender + "\t" + m.Content);
		}
		else {
			try {
				for (Message m : list)
					writer.write(m.Time + "\t" + m.Sender + "\t" + m.Content);
				writer.flush();
			} catch (IOException e) {
				return false;
			}
		}
		return true;
	}
	
	public static boolean outputInfo(BufferedWriter writer) {
		return output(writer, InfoList);
	}
	
	public static boolean outputError(BufferedWriter writer) {
		return output(writer, ErrorList);
	}	
}
