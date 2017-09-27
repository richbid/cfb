package net.onelab;

import java.math.BigInteger;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.ArrayList;

public class Text {
	public static String join(String spliter, java.util.List<String> list) {
		String result = "";
		int count = list.size();
		int index = 0;
		for (String item : list){
			index++;
			if (index == count)
				result = result + item;
			else
				result = result + item + spliter;
		}		
		return result;
	}	

	public static String to_hex(String input) {
		StringBuilder output = new StringBuilder();
		byte[] bytes = input.getBytes();
		int len = bytes.length;
		for (int i = 0; i < len; i++) {
			String hex = Integer.toHexString(bytes[i] & 0xFF);
			if (hex.length() == 1) {
				hex = '0' + hex;
			}
			output.append(hex);
		}
		return output.toString();
	}
	
	public static String from_hex(String input) {
		int len = input.length();
		ArrayList<Byte> bytes = new ArrayList<Byte>();
		boolean failed = false;
		if ((len % 2) == 0) {
			for (int n = 0; n < len; n += 2) {
				String hex = input.substring(n,  n + 2);
				try {
					byte b = (byte)Integer.parseInt(hex, 16);
					bytes.add(b);
				}
				catch (NumberFormatException ex) {
					failed = true;
				}
				if (failed)
					break;
			}
		}
		byte[] output = null;
		if (!failed) {
			len = bytes.size();
			output = new byte[len];
			for (int n = 0; n < len; n++)
				output[n] = bytes.get(n);
		}
		return failed ? "" : new String(output);
	}
	
	public static String to_md5(String input) {
		try {
			MessageDigest md5 = MessageDigest.getInstance("MD5");
			return new BigInteger(1, md5.digest()).toString(16);
		} catch (NoSuchAlgorithmException e) {
			e.printStackTrace();
		}
		return "";
	}
	
	private static class Base64 {
	    private static final byte[] encodingTable = {
	            (byte) 'A', (byte) 'B', (byte) 'C', (byte) 'D', (byte) 'E',
	            (byte) 'F', (byte) 'G', (byte) 'H', (byte) 'I', (byte) 'J',
	            (byte) 'K', (byte) 'L', (byte) 'M', (byte) 'N', (byte) 'O',
	            (byte) 'P', (byte) 'Q', (byte) 'R', (byte) 'S', (byte) 'T',
	            (byte) 'U', (byte) 'V', (byte) 'W', (byte) 'X', (byte) 'Y',
	            (byte) 'Z', (byte) 'a', (byte) 'b', (byte) 'c', (byte) 'd',
	            (byte) 'e', (byte) 'f', (byte) 'g', (byte) 'h', (byte) 'i',
	            (byte) 'j', (byte) 'k', (byte) 'l', (byte) 'm', (byte) 'n',
	            (byte) 'o', (byte) 'p', (byte) 'q', (byte) 'r', (byte) 's',
	            (byte) 't', (byte) 'u', (byte) 'v', (byte) 'w', (byte) 'x',
	            (byte) 'y', (byte) 'z', (byte) '0', (byte) '1', (byte) '2',
	            (byte) '3', (byte) '4', (byte) '5', (byte) '6', (byte) '7',
	            (byte) '8', (byte) '9', (byte) '+', (byte) '/'
	        };
	    private static final byte[] decodingTable;

	    static {
	        decodingTable = new byte[128];

	        for (int i = 0; i < 128; i++) {
	            decodingTable[i] = (byte) -1;
	        }

	        for (int i = 'A'; i <= 'Z'; i++) {
	            decodingTable[i] = (byte) (i - 'A');
	        }

	        for (int i = 'a'; i <= 'z'; i++) {
	            decodingTable[i] = (byte) (i - 'a' + 26);
	        }

	        for (int i = '0'; i <= '9'; i++) {
	            decodingTable[i] = (byte) (i - '0' + 52);
	        }

	        decodingTable['+'] = 62;
	        decodingTable['/'] = 63;
	    }

	    public static byte[] encode(byte[] data) {
	        byte[] bytes;

	        int modulus = data.length % 3;

	        if (modulus == 0) {
	            bytes = new byte[(4 * data.length) / 3];
	        } else {
	            bytes = new byte[4 * ((data.length / 3) + 1)];
	        }

	        int dataLength = (data.length - modulus);
	        int a1;
	        int a2;
	        int a3;

	        for (int i = 0, j = 0; i < dataLength; i += 3, j += 4) {
	            a1 = data[i] & 0xff;
	            a2 = data[i + 1] & 0xff;
	            a3 = data[i + 2] & 0xff;

	            bytes[j] = encodingTable[(a1 >>> 2) & 0x3f];
	            bytes[j + 1] = encodingTable[((a1 << 4) | (a2 >>> 4)) & 0x3f];
	            bytes[j + 2] = encodingTable[((a2 << 2) | (a3 >>> 6)) & 0x3f];
	            bytes[j + 3] = encodingTable[a3 & 0x3f];
	        }

	        int b1;
	        int b2;
	        int b3;
	        int d1;
	        int d2;

	        switch (modulus) {
	        case 0: /* nothing left to do */
	            break;

	        case 1:
	            d1 = data[data.length - 1] & 0xff;
	            b1 = (d1 >>> 2) & 0x3f;
	            b2 = (d1 << 4) & 0x3f;

	            bytes[bytes.length - 4] = encodingTable[b1];
	            bytes[bytes.length - 3] = encodingTable[b2];
	            bytes[bytes.length - 2] = (byte) '=';
	            bytes[bytes.length - 1] = (byte) '=';

	            break;

	        case 2:
	            d1 = data[data.length - 2] & 0xff;
	            d2 = data[data.length - 1] & 0xff;

	            b1 = (d1 >>> 2) & 0x3f;
	            b2 = ((d1 << 4) | (d2 >>> 4)) & 0x3f;
	            b3 = (d2 << 2) & 0x3f;

	            bytes[bytes.length - 4] = encodingTable[b1];
	            bytes[bytes.length - 3] = encodingTable[b2];
	            bytes[bytes.length - 2] = encodingTable[b3];
	            bytes[bytes.length - 1] = (byte) '=';

	            break;
	        }

	        return bytes;
	    }

	    public static byte[] decode(byte[] data) {
	        byte[] bytes;
	        byte b1;
	        byte b2;
	        byte b3;
	        byte b4;

	        data = discardNonBase64Bytes(data);

	        if (data[data.length - 2] == '=') {
	            bytes = new byte[(((data.length / 4) - 1) * 3) + 1];
	        } else if (data[data.length - 1] == '=') {
	            bytes = new byte[(((data.length / 4) - 1) * 3) + 2];
	        } else {
	            bytes = new byte[((data.length / 4) * 3)];
	        }

	        for (int i = 0, j = 0; i < (data.length - 4); i += 4, j += 3) {
	            b1 = decodingTable[data[i]];
	            b2 = decodingTable[data[i + 1]];
	            b3 = decodingTable[data[i + 2]];
	            b4 = decodingTable[data[i + 3]];

	            bytes[j] = (byte) ((b1 << 2) | (b2 >> 4));
	            bytes[j + 1] = (byte) ((b2 << 4) | (b3 >> 2));
	            bytes[j + 2] = (byte) ((b3 << 6) | b4);
	        }

	        if (data[data.length - 2] == '=') {
	            b1 = decodingTable[data[data.length - 4]];
	            b2 = decodingTable[data[data.length - 3]];

	            bytes[bytes.length - 1] = (byte) ((b1 << 2) | (b2 >> 4));
	        } else if (data[data.length - 1] == '=') {
	            b1 = decodingTable[data[data.length - 4]];
	            b2 = decodingTable[data[data.length - 3]];
	            b3 = decodingTable[data[data.length - 2]];

	            bytes[bytes.length - 2] = (byte) ((b1 << 2) | (b2 >> 4));
	            bytes[bytes.length - 1] = (byte) ((b2 << 4) | (b3 >> 2));
	        } else {
	            b1 = decodingTable[data[data.length - 4]];
	            b2 = decodingTable[data[data.length - 3]];
	            b3 = decodingTable[data[data.length - 2]];
	            b4 = decodingTable[data[data.length - 1]];

	            bytes[bytes.length - 3] = (byte) ((b1 << 2) | (b2 >> 4));
	            bytes[bytes.length - 2] = (byte) ((b2 << 4) | (b3 >> 2));
	            bytes[bytes.length - 1] = (byte) ((b3 << 6) | b4);
	        }

	        return bytes;
	    }

	    public static byte[] decode(String data) {
	        byte[] bytes;
	        byte b1;
	        byte b2;
	        byte b3;
	        byte b4;

	        data = discardNonBase64Chars(data);

	        if (data.charAt(data.length() - 2) == '=') {
	            bytes = new byte[(((data.length() / 4) - 1) * 3) + 1];
	        } else if (data.charAt(data.length() - 1) == '=') {
	            bytes = new byte[(((data.length() / 4) - 1) * 3) + 2];
	        } else {
	            bytes = new byte[((data.length() / 4) * 3)];
	        }

	        for (int i = 0, j = 0; i < (data.length() - 4); i += 4, j += 3) {
	            b1 = decodingTable[data.charAt(i)];
	            b2 = decodingTable[data.charAt(i + 1)];
	            b3 = decodingTable[data.charAt(i + 2)];
	            b4 = decodingTable[data.charAt(i + 3)];

	            bytes[j] = (byte) ((b1 << 2) | (b2 >> 4));
	            bytes[j + 1] = (byte) ((b2 << 4) | (b3 >> 2));
	            bytes[j + 2] = (byte) ((b3 << 6) | b4);
	        }

	        if (data.charAt(data.length() - 2) == '=') {
	            b1 = decodingTable[data.charAt(data.length() - 4)];
	            b2 = decodingTable[data.charAt(data.length() - 3)];

	            bytes[bytes.length - 1] = (byte) ((b1 << 2) | (b2 >> 4));
	        } else if (data.charAt(data.length() - 1) == '=') {
	            b1 = decodingTable[data.charAt(data.length() - 4)];
	            b2 = decodingTable[data.charAt(data.length() - 3)];
	            b3 = decodingTable[data.charAt(data.length() - 2)];

	            bytes[bytes.length - 2] = (byte) ((b1 << 2) | (b2 >> 4));
	            bytes[bytes.length - 1] = (byte) ((b2 << 4) | (b3 >> 2));
	        } else {
	            b1 = decodingTable[data.charAt(data.length() - 4)];
	            b2 = decodingTable[data.charAt(data.length() - 3)];
	            b3 = decodingTable[data.charAt(data.length() - 2)];
	            b4 = decodingTable[data.charAt(data.length() - 1)];

	            bytes[bytes.length - 3] = (byte) ((b1 << 2) | (b2 >> 4));
	            bytes[bytes.length - 2] = (byte) ((b2 << 4) | (b3 >> 2));
	            bytes[bytes.length - 1] = (byte) ((b3 << 6) | b4);
	        }

	        return bytes;
	    }

	    private static byte[] discardNonBase64Bytes(byte[] data) {
	        byte[] temp = new byte[data.length];
	        int bytesCopied = 0;

	        for (int i = 0; i < data.length; i++) {
	            if (isValidBase64Byte(data[i])) {
	                temp[bytesCopied++] = data[i];
	            }
	        }

	        byte[] newData = new byte[bytesCopied];

	        System.arraycopy(temp, 0, newData, 0, bytesCopied);

	        return newData;
	    }

	    private static String discardNonBase64Chars(String data) {
	        StringBuffer sb = new StringBuffer();

	        int length = data.length();

	        for (int i = 0; i < length; i++) {
	            if (isValidBase64Byte((byte) (data.charAt(i)))) {
	                sb.append(data.charAt(i));
	            }
	        }

	        return sb.toString();
	    }

	    private static boolean isValidBase64Byte(byte b) {
	        if (b == '=') {
	            return true;
	        } else if ((b < 0) || (b >= 128)) {
	            return false;
	        } else if (decodingTable[b] == -1) {
	            return false;
	        }

	        return true;
	    }
	}

	public static String to_base64(String input) {
		return input == null ? "" : new String(Base64.encode(input.getBytes()));
	}

	public static String from_base64(String input) {
		return input == null ? "" : new String(Base64.decode(input));
	}
	
	public static void test() {
		String input = "\n123xyz";
		String hex = Text.to_hex(input);
		System.out.println("to_hex(\\n123xyz) = " + hex);
		input = Text.from_hex(hex);
		System.out.println("from_hex(" + hex + ") = " + input);
		System.out.println("to_md5(" + hex + ") = " + Text.to_md5(hex));
		String base64 = Text.to_base64(hex);
		System.out.println("to_base64(" + hex + ") = " + base64);
		System.out.println("from_base64(" + base64 + ") = " + Text.from_base64(base64));		
	}
}
