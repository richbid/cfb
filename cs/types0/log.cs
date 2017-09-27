using System;
using System.Collections.Generic;
using Messages = System.Collections.Generic.List<onelab.log.Message>;

namespace onelab
{
    public class log
    {
        public static void printf(String format, params Object[] args)
        {
            System.Console.Write(format, args);
        }

        public class Message
        {
            public String Time = DateTime.Now.ToString("yyyy/MM/dd HH:mm:ss.fff");
            public String Sender;
            public String Content;
            public Message(String aSender, String aContent)
            {
                Sender = aSender;
                Content = aContent;
            }
        }

        private static Messages ErrorList = new Messages();

        private static Messages InfoList = new Messages();

        private static void mark(String aSender, object aContent, ref Messages list)
        {
            if (string.IsNullOrWhiteSpace(aSender) || aContent == null) return;
            String content = aContent.ToString();
            if (string.IsNullOrWhiteSpace(content)) return;
            Message msg = new Message(aSender, content);
            list.Add(msg);
        }

        public static void err(String aSender, object aContent)
        {
            mark(aSender, aContent, ref ErrorList);
        }

        public static void info(String aSender, object aContent)
        {
            mark(aSender, aContent, ref InfoList);
        }

        private static bool output(System.IO.TextWriter writer, ref List<Message> list)
        {
            try
            {
                if (writer == null)
                    foreach (Message m in list)
                        System.Console.WriteLine("{0}\t{1}\t{2}", m.Time, m.Sender, m.Content);
                else
                {
                    foreach (Message m in list)
                        writer.WriteLine("{0}\t{1}\t{2}", m.Time, m.Sender, m.Content);
                    writer.Flush();
                }
            }
            catch (Exception)
            {
                return false;
            }
            return true;
        }

        public static bool outputInfo(System.IO.TextWriter writer)
        {
            return output(writer, ref InfoList);
        }

        public static bool outputError(System.IO.TextWriter writer)
        {
            return output(writer, ref ErrorList);
        }
    }
}
