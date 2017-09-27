package net.onelab;

import java.util.ArrayList;
import java.util.Comparator;

public class Bytes extends Troop<Byte> implements net.onelab.Stringable, net.onelab.Sortable {
//	public static void main(String args[]) {
//		test();
//	}
	
	public Object clone() {
		Bytes obj = new Bytes();
		obj.data.addAll(data);
		return obj;	
	}
	
	public Bytes(Troop<Byte> input) {
		data = input.data;
	}
	
	public Bytes(String input) {
		fromString(input);
	}
	
	public Bytes() {
		
	}
	
	public static short value(Byte b) {
		return (short) ((256 + b) % 256);
	}
	
//	@SuppressWarnings("unchecked")
//	public static void test() {
//		java.io.PrintStream o = System.out;
//        Byte last;
//        Bytes bytes2 = new Bytes("(11,13,15)");
//        o.printf("bytes2(11,13,15) %1$s\n", bytes2.toString());
//        Bytes bytes3 = new Bytes("(12,14,16)");
//        o.printf("bytes3(12,14,16) %1$s\n", bytes3.toString());
//        Bytes bytes = new Bytes();
//        bytes.fromString("(1,3,5,7,9)");
//        o.printf("bytes.fromString((1,3,5,7,9) %1$s\n", bytes.toString());
//        bytes.insert(1, (byte)4);
//        o.printf("bytes.insert(1, 4) %1$s\n", bytes.toString());
//        bytes.append((byte)2);
//        o.printf("bytes.append(2) %1$s\n", bytes.toString());
//        bytes.insertRange(0, bytes2.data);
//        o.printf("bytes.insertRange(0, bytes2.data) %1$s\n", bytes.toString());
//        bytes.appendRange(bytes3.data);
//        o.printf("bytes.appendRange(bytes3.data) %1$s\n", bytes.toString());
//        bytes.enqueue((byte)100);
//        o.printf("bytes.enqueue(100) %1$s\n", bytes.toString());
//        last = bytes.dequeue();
//        o.printf("last = bytes.dequeue() %1$s\n", last.toString());
//        bytes.push((byte)101);
//        o.printf("bytes.push(101) %1$s\n", bytes.toString());
//        last = bytes.pop();
//        o.printf("last = bytes.pop() %1$s\n", last.toString() + " " + bytes.toString());
//        bytes.removeRange(1, 3);
//        o.printf("bytes.removeRange(1, 3) %1$s\n", bytes.toString());
//        bytes.set(1, (byte)255);
//        o.printf("bytes.set(1, 255) %1$s\n", bytes.toString());
//        for (int n = 0; n < bytes.length(); n++)
//            o.printf("bytes [ %1$d : %2$s]\n", n, value(bytes.get(n)));
//        bytes = new Bytes(bytes.getRange(2, 4));
//        o.printf("getRange(2, 4) %1$s\n", bytes.toString());
//        bytes.sort(true);
//        o.printf("bytes.sort(true) %1$s\n", bytes.toString());
//        for (int n = 0; n < bytes.length(); n++)
//            o.printf("bytes [ %1$d : %2$s]\n", n, value(bytes.get(n)));
//        bytes.clear();
//        o.printf("bytes.clear(), bytes.count = %1$d\n", bytes.length());
//
//        Byte b;
//        bytes.fromString("(1,3,5,7,9)");
//        o.printf("bytes.fromString(1,3,5,7,9) %1$s\n", bytes.toString());
//        bytes.rollForward(3);
//        o.printf("bytes.rollForward(3) %1$s\n", bytes.toString());
//        b = bytes.take(2);
//        o.printf("bytes.take(2) %1$s\n", b.toString() + " " + bytes.toString());
//        bytes.fromString("(2,4,6,8,10)");
//        o.printf("bytes.fromString(2,4,6,8,10) %1$s\n", bytes.toString());
//        bytes.rollBackward(3);
//        o.printf("bytes.rollBackward(3) %1$s\n", bytes.toString());
//        bytes.swap(1, 3);
//        o.printf("bytes.swap(1, 3) %1$s\n", bytes.toString());
//        bytes.sort(false);
//        o.printf("bytes.sort(false) %1$s\n", bytes.toString());
//        bytes.sort(true);
//        o.printf("bytes.sort(true) %1$s\n", bytes.toString());
//        
//        Bytes b1 = new Bytes("(1,2,3)");
//        Bytes b2 = b1;//different from clone(), = for java is to add reference count
//        o.printf("b1 " + b1.toString() + " b2 " + b2.toString() + "\n");
//        o.printf("(b2 == b1) " + ((b2 == b1) ? "true" : "false") + "\n");
//        o.printf("(b2 != b1) " + ((b2 != b1) ? "true" : "false") + "\n");
//        b2 = new Bytes((Troop<Byte>)b1.clone()); //copy members from b1 to b2, keep members if b1 clear
//        b1.clear();
//        o.printf("b1.clear(), b1 " + b1.toString() + " b2 " + b2.toString() + "\n");
//        o.printf("(b2 == b1) " + ((b2 == b1) ? "true" : "false") + "\n");
//        o.printf("(b2 != b1) " + ((b2 != b1) ? "true" : "false") + "\n");        
//	}
	
	private class AscSorter implements Comparator<Byte>
	{

		@Override
		public int compare(Byte o1, Byte o2) {
			if (o1 == o2)
				return 0;
			
			return o1 > o2 ? 1 : -1;
		}
		
	}
	private class DescSorter implements Comparator<Byte>
	{

		@Override
		public int compare(Byte o1, Byte o2) {
			if (o1 == o2)
				return 0;
			
			return o1 > o2 ? -1 : 1;
		}
		
	}
	private AscSorter ascSorter = new AscSorter();
	
	private DescSorter descSorter = new DescSorter();
	
    public void sort(boolean decending) {
        if (decending)
            data.sort(descSorter);
        else
            data.sort(ascSorter);    	
    }	

	public int fromString(String input) {
		if (input == null) return 0;
		if (!input.startsWith("(") || !input.endsWith(")"))
			return 0;
		int len = input.length();
		int n = 1;
		ArrayList<Byte> newData = new ArrayList<Byte>();
		StringBuilder sb = new StringBuilder();
		String s;
		while (n < len) {
			s = input.substring(n, n+1);
			if (!s.equals(",") && !s.equals(")"))
				sb.append(s);
			else {
				try {				
					newData.add(Byte.parseByte(sb.toString()));
				}
				catch(NumberFormatException ex) {
					newData = null;
					return 0;
				}
				sb.delete(0, sb.length());
			}				
			n++;
		}
		data.clear();
		data = newData;		
		return 1;
	}
	
	public String toString() {
		Short i;
		ArrayList<String> list = new ArrayList<String>();
		for (Byte b : data) {
			i = (short) (((short)b + 256) % 256);
			list.add(i.toString());
		}
		return "(" + net.onelab.Text.join(",", list) + ")";
	}
}
