package com.xpu.demo;

public class StringReplace {
	public static void main(String[] args) {
		StringBuffer str = new StringBuffer("Hello World ");
		System.out.println(replaceSpace(str));
	}
	
	
	public static String replaceSpace(StringBuffer str) {
		StringBuffer ret = new StringBuffer();
		char[] charArray = str.toString().toCharArray();
		for (char c : charArray) {
			if(c != ' ') {
				ret.append(c);
			}else {
				ret.append("%20");
			}
		}
		return ret.toString();
    }
}
