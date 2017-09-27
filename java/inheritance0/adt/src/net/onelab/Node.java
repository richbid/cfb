package net.onelab;

public class Node<T> {
	private static int globalUid = 0;
	private static int nextUid() {
		return ++globalUid;
	}
	private int mUid = 0;
	public int uid() {
		return mUid;
	}
	public boolean hit(Node<T> item) {
		if (item == null) return false;
		return item.uid() == this.uid();
	}
	public T Value;
	public Node<T> Parent;
	public Troop<Node<T>> Children = new Troop<Node<T>>();
	public Node<T> next() {
		if (Parent == null) return null;
		int len = Parent.Children.length();
		for (int n = 0; n < len; n++) {
			if (hit(Parent.Children.get(n)))
				return (n == len-1) ? null : Parent.Children.get(n+1);
		}
		return null;
	}
	public Node<T> previous() {
		if (Parent == null) return null;
		int len = Parent.Children.length();
		for (int n = 0; n < len; n++) {
			if (hit(Parent.Children.get(n)))
				return (n == 0) ? null : Parent.Children.get(n-1);
		}
		return null;
	}	
	public int indexOfChild(Node<T> item) {
		int len = Children.length();
		for (int n = 0; n < len; n++) {
			Node<T> child = Children.get(n);
			if (child != null && child.hit(item))
				return n;
		}
		return -1;
	}
	public boolean removeChild(int index) {
		return Children.remove(index);
	}
	public boolean removeChild(Node<T> item) {
		int index = indexOfChild(item);
		return (index > -1) ? removeChild(index) : false;
	}
	public Node<T> appendChild(Node<T> item) {
		Children.append(item);
		if (item != null)
			item.Parent = this;
		return item;
	}
	public Node<T> insertChild(int index, Node<T> newItem) {
		return Children.insert(index, newItem) ? newItem : null;
	}
	public Node<T> insertChild(Node<T> item, Node<T> newItem) {
		int index = indexOfChild(item);
		if (index == -1)
			return null;
		return Children.insert(index, newItem) ? newItem : null;
	}
	public Node(T value) {
		mUid = nextUid();
		Value = value;
		Parent = null;
	}
	
	public static void nodeInt32Test() {
		Node<Integer> root = new Node<Integer>(20170527);
		Node<Integer> n0 = root.appendChild(new Node<Integer>(101));
		Node<Integer> n1 = root.appendChild(new Node<Integer>(102));
		Node<Integer> n2 = root.appendChild(new Node<Integer>(103));
		
		boolean testIndex = root.indexOfChild(n0) == 0;
		boolean testIndex2 = root.indexOfChild(n1) == 1;
		boolean testIndex3 = root.indexOfChild(n2) == 2;
		
		boolean testPrevious = n1.previous().hit(n0);
		boolean testPrevious2 = n1.previous().hit(n2);
		boolean testNext = n1.next().hit(n2);
		boolean testNext2 = n1.next().hit(n1);
		
		root.removeChild(n0);
		boolean testLen = root.Children.length() == 2;
		root.removeChild(n1);
		boolean testLen2 = root.Children.length() == 1;
		root.removeChild(n2);
		boolean testLen3 = root.Children.length() == 0;
		
		return;
		
	}
}
