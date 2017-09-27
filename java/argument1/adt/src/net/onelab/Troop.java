package net.onelab;

import java.util.ArrayList;

public class Troop<T> implements Cloneable {
	public Object clone() {
		Troop<T> obj = new Troop<T>();
		obj.data.addAll(data);
		return obj;	
	}

	private boolean mHasError = false;
	public boolean hasError() { return mHasError; }
	public ArrayList<T> data = new ArrayList<T>();
	public T get(int index) {
		mHasError = false;
		if (index >= 0 && index < data.size())
			return data.get(index);
		mHasError = true;
		return null;
		
	}
	public boolean set(int index, T value) {
		if (index >= 0 && index < data.size())
		{
			data.set(index, value);
			return true;
		}
		return false;
	}
    public void append(T value) {
        data.add(value);
    }
    public boolean insert(int index, T value) {
        if (index >= 0 && index < data.size())
        {
            data.add(index, value);
            return true;
        }
        return false;
    }
    public void appendRange(ArrayList<T> range) {
        data.addAll(range);
    }
    public boolean insertRange(int index, ArrayList<T> range) {
        if (index >= 0 && index < data.size())
        {
            data.addAll(index, range);
            return true;
        }
        return false;
    }
    public void clear() {
        data.clear();
    }
    public boolean remove(int index) {
        if (index >= 0 && index < data.size())
        {
            data.remove(index);
            return true;
        }
        return false;
    }
    public boolean removeRange(int index, int count) {
        if (count > 0 && index >= 0 && ((index + count) <= data.size()))
        {
            for (int n = 0; n < count; n++)
            	data.remove(index);
            
            return true;
        }
        return false;
    }
    public int length() {
        return data.size();
    }
    public void enqueue(T value) {
        data.add(0, value);
    }
    public T dequeue() {
        mHasError = false;
        int length = data.size();
        if (length > 0)
        {
            T b = data.get(length - 1);
            data.remove(length - 1);
            return b;
        }
        mHasError = true;
        return null;
    }
    public void push(T value) {
        data.add(value);
    }
    public T pop() {
        return dequeue();
    }
    public Troop<T> getRange(int index, int count) {
        mHasError = true;
        Troop<T> output = new Troop<T>();
        if (count > 0 && index >= 0 && ((index + count) <= data.size()))
        {
        	output.data.addAll(data.subList(index, index + count));
            mHasError = false;
        }
        return output;
    }
    public void reverse() {
    	int length = data.size();
    	ArrayList<T> newData = new ArrayList<T>(); 
    	for (int n = length - 1; n >= 0; n--)
    		newData.add(data.get(n));
    	
    	data.clear();
    	data = newData;
    }

    boolean swap(int index0, int index1) {
        int length = data.size();
        if (index0 >= 0 && index0 < length && index1 >= 0 && index1 < length)
        {
            T v = data.get(index0);
            data.set(index0, data.get(index1));
            data.set(index1, v);
            return true;
        }
        return false;    	
    }
    T take(int index)
    {
        mHasError = false;
        if (index >= 0 && index < data.size())
        {
            T v = data.get(index);
            data.remove(index);
            return v;
        }
        mHasError = true;
        return null;
    }
    void rollForward(int offset)
    {
        if (offset >= data.size()) return;
        ArrayList<T> left = new ArrayList<T>();
        left.addAll(data.subList(offset - 1, data.size()));
        ArrayList<T> right = new ArrayList<T>();
        right.addAll(data.subList(0, offset - 1));
        data.clear();
        data.addAll(left);
        data.addAll(right);
    }  
    void rollBackward(int offset)
    {
        if (offset >= data.size()) return;
        ArrayList<T> left = new ArrayList<T>();
        left.addAll(data.subList(offset, data.size()));
        ArrayList<T> right = new ArrayList<T>();
        right.addAll(data.subList(0, offset));
        data.clear();
        data.addAll(left);
        data.addAll(right);
    }      
}
