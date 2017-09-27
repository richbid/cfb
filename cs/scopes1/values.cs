using System;
using System.Collections.Generic;
using System.Text;
using HashCodeType = System.UInt32;

namespace onelab
{
    public class Text
    {
        public static String to_hex(String input)
        {
            byte[] bytes = System.Text.Encoding.UTF8.GetBytes(input);
            String output = "";
            foreach (byte b in bytes)
            {
                String ch = String.Format("{0:x2}", b);
                output += ch;
            }
            return output;
        }
        public static String from_hex(String input)
        {
            int len = input.Length;
            List<byte> bytes = new List<byte>(input.Length / 2);
            bool failed = false;
            String output = "";
            if ((len % 2) == 0)
            {
                for (int n = 0; n < len; n += 2)
                {
                    String s = input.Substring(n, 2);
                    byte b;
                    if (!Byte.TryParse(s, System.Globalization.NumberStyles.AllowHexSpecifier, null, out b))
                    {
                        failed = true;
                        break;
                    }
                    bytes.Add(b);
                }
                if (!failed)
                    output = System.Text.Encoding.UTF8.GetString(bytes.ToArray());
            }
            return output;
        }
        public static String to_md5(String input)
        {
            System.Security.Cryptography.MD5 hash = new System.Security.Cryptography.MD5CryptoServiceProvider();
            byte[] bytes = hash.ComputeHash(System.Text.Encoding.UTF8.GetBytes(input));
            String output = "";
            foreach (byte b in bytes)
            {
                String ch = String.Format("{0:x2}", b);
                output += ch;
            }
            return output;
        }
        public static String to_base64(String input)
        {
            String output = Convert.ToBase64String(System.Text.Encoding.UTF8.GetBytes(input));
            return output;
        }
        public static String from_base64(String input)
        {
            String output = System.Text.Encoding.UTF8.GetString(Convert.FromBase64String(input));
            return output;
        }
    }

    public interface ISortable
    {
        void sort(bool decending);
    }

    public interface IStringable
    {
        int fromString(String input);
        String toString();
    }

    public class Troop<T> : ICloneable
    {
        public override int GetHashCode()
        {
            return base.GetHashCode();
        }

        public override bool Equals(object obj) { return this == (Troop<T>)obj; }

        public object Clone()
        {
            Troop<T> oValue = new Troop<T>();
            oValue.cloneFrom(this);
            return oValue;
        }

        protected bool equalsTo(Troop<T> aValue)
        {
            if (aValue == null) return false;
            int len = aValue.length();
            if (len == this.length())
            {
                for (int n = 0; n < len; n++)
                {
                    if (!aValue.data[n].Equals(data[n]))
                        return false;
                }
                return true;
            }
            return false;
        }

        protected void cloneFrom(Troop<T> aValue)
        {
            data.Clear();
            data.AddRange(aValue.data);
        }

        public static bool operator ==(Troop<T> a0, Troop<T> a1) { object o1 = (object)a0; object o2 = (object)a1; if (o1 == null && o2 == null) return true; return (o1 == null || o2 == null) ? false : a0.equalsTo(a1); }

        public static bool operator !=(Troop<T> a0, Troop<T> a1) { object o1 = (object)a0; object o2 = (object)a1; if (o1 == null && o2 == null) return false; return (o1 == null || o2 == null) ? true : !a0.equalsTo(a1); }

        private bool mHasError = false;
        public bool hasError() { return mHasError; }
        public List<T> data = new List<T>();

        public T get(int index)
        {
            mHasError = false;
            if (index >= 0 && index < data.Count)
                return data[index];
            mHasError = true;
            return default(T);
        }
        public bool set(int index, T value)
        {
            if (index >= 0 && index < data.Count)
            {
                data[index] = value;
                return true;
            }
            return false;
        }
        public void append(T value)
        {
            data.Add(value);
        }
        public bool insert(int index, T value)
        {
            if (index >= 0 && index < data.Count)
            {
                data.Insert(index, value);
                return true;
            }
            return false;
        }
        public void appendRange(ref List<T> range)
        {
            data.AddRange(range);
        }
        public bool insertRange(int index, ref List<T> range)
        {
            if (index >= 0 && index < data.Count)
            {
                data.InsertRange(index, range);
                return true;
            }
            return false;
        }
        public void clear()
        {
            data.Clear();
        }
        public bool remove(int index)
        {
            if (index >= 0 && index < data.Count)
            {
                data.RemoveAt(index);
                return true;
            }
            return false;
        }
        public bool removeRange(int index, int count)
        {
            if (count > 0 && index >= 0 && ((index + count) <= data.Count))
            {
                data.RemoveRange(index, count);
                return true;
            }
            return false;
        }
        public int length()
        {
            return data.Count;
        }
        public void enqueue(T value)
        {
            data.Insert(0, value);
        }
        public T dequeue()
        {
            mHasError = false;
            int length = data.Count;
            if (length > 0)
            {
                T b = data[length - 1];
                data.RemoveAt(length - 1);
                return b;
            }
            mHasError = true;
            return default(T);
        }
        public void push(T value)
        {
            data.Add(value);
        }
        public T pop()
        {
            return dequeue();
        }
        public Troop<T> getRange(int index, int count)
        {
            Troop<T> output = new Troop<T>();
            mHasError = true;
            if (count > 0 && index >= 0 && ((index + count) <= data.Count))
            {
                output.data = data.GetRange(index, count);
                mHasError = false;
            }
            return output;
        }
        public void reverse()
        {
            data.Reverse();
        }

        public bool swap(int index0, int index1)
        {
            int length = data.Count;
            if (index0 >= 0 && index0 < length && index1 >= 0 && index1 < length)
            {
                T v = data[index0];
                data[index0] = data[index1];
                data[index1] = v;
                return true;
            }
            return false;

        }
        public T take(int index)
        {
            mHasError = false;
            if (index >= 0 && index < data.Count)
            {
                T v = data[index];
                data.RemoveAt(index);
                return v;
            }
            mHasError = true;
            return default(T);
        }
        public void rollForward(int offset)
        {
            if (offset >= data.Count) return;
            List<T> left = data.GetRange(offset - 1, data.Count - offset + 1);
            List<T> right = data.GetRange(0, offset - 1);
            data.Clear();
            data.AddRange(left);
            data.AddRange(right);
        }
        public void rollBackward(int offset)
        {
            if (offset >= data.Count) return;
            List<T> left = data.GetRange(offset, data.Count - offset);
            List<T> right = data.GetRange(0, offset);
            data.Clear();
            data.AddRange(left);
            data.AddRange(right);
        }
    }

    public class Bytes : Troop<Byte>, IStringable, ISortable
    {
        public object Clone()
        {
            Bytes oValue = new Bytes();
            oValue.cloneFrom(this);
            return oValue;
        }

        private class DescSorter : IComparer<Byte>
        {
            public int Compare(Byte x, Byte y)
            {
                if (x == y)
                    return 0;
                return x > y ? -1 : 1;
            }
        }

        private class AscSorter : IComparer<Byte>
        {
            public int Compare(Byte x, Byte y)
            {
                if (x == y)
                    return 0;
                return x > y ? 1 : -1;
            }
        }

        private DescSorter descSorter = new DescSorter();

        private AscSorter ascSorter = new AscSorter();

        public void sort(bool decending)
        {
            if (decending)
                data.Sort(descSorter);
            else
                data.Sort(ascSorter);
        }

        //public static void test()
        //{
        //    Byte last;
        //    Bytes bytes2 = new onelab.Bytes("(11,13,15)");
        //    System.Console.WriteLine("bytes2(11,13,15) " + bytes2.toString());
        //    Bytes bytes3 = new onelab.Bytes("(12,14,16)");
        //    System.Console.WriteLine("bytes3(12,14,16) " + bytes3.toString());
        //    Bytes bytes = new Bytes();
        //    bytes.fromString("(1,3,5,7,9)");
        //    System.Console.WriteLine("bytes.fromString((1,3,5,7,9) " + bytes.toString());
        //    bytes.insert(1, 4);
        //    System.Console.WriteLine("bytes.insert(1, 4) " + bytes.toString());
        //    bytes.append(2);
        //    System.Console.WriteLine("bytes.append(2) " + bytes.toString());
        //    bytes.insertRange(0, ref bytes2.data);
        //    System.Console.WriteLine("bytes.insertRange(0, ref bytes2.data) " + bytes.toString());
        //    bytes.appendRange(ref bytes3.data);
        //    System.Console.WriteLine("bytes.appendRange(ref bytes3.data) " + bytes.toString());
        //    bytes.enqueue(100);
        //    System.Console.WriteLine("bytes.enqueue(100) " + bytes.toString());
        //    last = bytes.dequeue();
        //    System.Console.WriteLine("last = bytes.dequeue() " + last.ToString());
        //    bytes.push(101);
        //    System.Console.WriteLine("bytes.push(101) " + bytes.toString());
        //    last = bytes.pop();
        //    System.Console.WriteLine("last = bytes.pop() " + last.ToString() + " " + bytes.toString());
        //    bytes.removeRange(1, 3);
        //    System.Console.WriteLine("bytes.removeRange(1, 3) " + bytes.toString());
        //    bytes.set(1, 255);
        //    System.Console.WriteLine("bytes.set(1, 255) " + bytes.toString());
        //    for (int n = 0; n < bytes.length(); n++)
        //    {
        //        string line = string.Format("bytes[ {0} ] : {1}", n, bytes.get(n));
        //        System.Console.WriteLine(line);
        //    }
        //    bytes = Bytes.convert(bytes.getRange(2, 4));
        //    System.Console.WriteLine("getRange(2, 4) " + bytes.toString());
        //    bytes.sort(true);
        //    System.Console.WriteLine("bytes.sort(true) " + bytes.toString());
        //    for (int n = 0; n < bytes.length(); n++)
        //    {
        //        string line = string.Format("bytes [ {0} ] : {1}", n, bytes.get(n));
        //        System.Console.WriteLine(line);
        //    }
        //    bytes.clear();
        //    System.Console.WriteLine("bytes.clear(), bytes.count = " + bytes.length().ToString());

        //    Byte b;
        //    bytes.fromString("(1,3,5,7,9)");
        //    System.Console.WriteLine("bytes.fromString(1,3,5,7,9) " + bytes.toString());
        //    bytes.rollForward(3);
        //    System.Console.WriteLine("bytes.rollForward(3) " + bytes.toString());
        //    b = bytes.take(2);
        //    System.Console.WriteLine("bytes.take(2) " + b.ToString() + " " + bytes.toString());
        //    bytes.fromString("(2,4,6,8,10)");
        //    System.Console.WriteLine("bytes.fromString(2,4,6,8,10) " + bytes.toString());
        //    bytes.rollBackward(3);
        //    System.Console.WriteLine("bytes.rollBackward(3) " + bytes.toString());
        //    bytes.swap(1, 3);
        //    System.Console.WriteLine("bytes.swap(1, 3) " + bytes.toString());
        //    bytes.sort(false);
        //    System.Console.WriteLine("bytes.sort(false) " + bytes.toString());
        //    bytes.sort(true);
        //    System.Console.WriteLine("bytes.sort(true) " + bytes.toString());

        //    Bytes b1 = new Bytes("(1,2,3)");
        //    Bytes b2 = b1;//different from Clone(), = for c# is to add reference count
        //    System.Console.WriteLine("b1 " + b1.toString() + " b2 " + b2.toString());
        //    System.Console.WriteLine("(b2 == b1) " + ((b2 == b1) ? "true" : "false"));
        //    System.Console.WriteLine("(b2 != b1) " + ((b2 != b1) ? "true" : "false"));
        //    b2 = (Bytes)(b1.Clone()); //copy members from b1 to b2, keep members if b1 clear
        //    b1.clear();
        //    System.Console.WriteLine("b1.clear(), b1 " + b1.toString() + " b2 " + b2.toString());
        //    System.Console.WriteLine("(b2 == b1) " + ((b2 == b1) ? "true" : "false"));
        //    System.Console.WriteLine("(b2 != b1) " + ((b2 != b1) ? "true" : "false"));
        //    System.Console.ReadLine();
        //}

        public int fromString(String input)
        {
            if (input == null)
                return 0;
            if (!input.StartsWith("(") || !input.EndsWith(")"))
                return 0;
            int len = input.Length;
            int n = 1;
            Byte b;
            String s;
            StringBuilder sb = new StringBuilder();
            List<Byte> newData = new List<Byte>();
            while (n < len)
            {
                s = input.Substring(n, 1);
                if (s != "," && s != ")")
                    sb.Append(s);
                else
                {
                    if (Byte.TryParse(sb.ToString(), out b))
                        newData.Add(b);
                    else
                    {
                        newData = null;
                        return 0;
                    }
                    sb.Clear();
                }
                n++;
            }
            data = newData;
            return 1;
        }
        public String toString()
        {
            String result = "";
            List<String> lines = new List<string>();
            foreach (Byte b in data)
                lines.Add(b.ToString());
            result = "(" + String.Join(",", lines.ToArray()) + ")";
            return result;
        }

        public Bytes()
        {
        }

        public Bytes(Troop<Byte> input)
        {
            data.AddRange(input.data);
        }

        public Bytes(String input)
        {
            fromString(input);
        }

        public static Bytes convert(Troop<Byte> input)
        {
            Bytes bytes = new Bytes(input);
            return bytes;
        }
    }

    public class Node<T>
    {
        private static HashCodeType globalUid = HashCodeType.MinValue;
        private static HashCodeType nextUid()
        {
            return ++globalUid;
        }
        private HashCodeType mUid = 0;
        public HashCodeType uid()
        {
            return mUid;
        }
        public bool hit(Node<T> item)
        {
            if (item == null) return false;
            return item.uid() == this.uid();
        }
        public T Value;
        public Node<T> Parent;
        public Troop<Node<T>> Children = new Troop<Node<T>>();
        public Node<T> next()
        {
            if (Parent == null) return null;
            int len = Parent.Children.length();
            for (int n = 0; n < len; n++)
            {
                if (hit(Parent.Children.get(n)))
                    return (n == len-1) ? null : Parent.Children.get(n+1);
            }
            return null;
        }
        public Node<T> previous()
        {
            if (Parent == null) return null;
            int len = Parent.Children.length();
            for (int n = 0; n < len; n++)
            {
                if (hit(Parent.Children.get(n)))
                    return (n == 0) ? null : Parent.Children.get(n-1);
            }
            return null;
        }
        public int indexOfChild(Node<T> item)
        {
            int len = Children.length();
            for (int n = 0; n < len; n++)
            {
                Node<T> child = Children.get(n);
                if (child != null && child.hit(item))
                    return n;
            }
            return -1;
        }
        public bool removeChild(int index)
        {
            return Children.remove(index);
        }
        public bool removeChild(Node<T> item)
        {
            int index = indexOfChild(item);
            return (index > -1) ? removeChild(index) : false;
        }
        public Node<T> appendChild(Node<T> item)
        {
            Children.append(item);
            if (item != null)
                item.Parent = this;
            return item;
        }
        public Node<T> insertChild(int index, Node<T> newItem)
        {
            return Children.insert(index, newItem) ? newItem : null;
        }
        public Node<T> insertChild(Node<T> item, Node<T> newItem)
        {
            int index = indexOfChild(item);
            if (index == -1)
                return null;
            return Children.insert(index, newItem) ? newItem : null;
        }        
        public Node(T value)
        {
            mUid = nextUid();
            Value = value;
            Parent = null;
        }
        public static Node<T> create(T value)
        {
            return new Node<T>(value);
        }

        public static void testInt32()
        {
            Node<int> root = Node<int>.create(20170527);
            Node<int> n0 = root.appendChild(Node<int>.create(101));
            Node<int> n1 = root.appendChild(Node<int>.create(102));
            Node<int> n2 = root.appendChild(Node<int>.create(103));

            bool testIndex = root.indexOfChild(n0) == 0;
            bool testIndex2 = root.indexOfChild(n1) == 1;
            bool testIndex3 = root.indexOfChild(n2) == 2;

            bool testPrevious = n1.previous().hit(n0);
            bool testPrevious2 = n1.previous().hit(n2);
            bool testNext = n1.next().hit(n2);
            bool testNext2 = n1.next().hit(n1);

            root.removeChild(n0);
            bool testLen = root.Children.length() == 2;
            root.removeChild(n1);
            bool testLen2 = root.Children.length() == 1;
            root.removeChild(n2);
            bool testLen3 = root.Children.length() == 0;

            return;
        }
    }
}
