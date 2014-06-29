package com.bbxyard.leetcode;

public class ReverseWordsInAString {
	public class Solution {
	    public String reverseWords(String s) {
	    	s = s.trim();
	        return s;
	    }
//	    private void reverseSent(String s) {
//	    	s = s.replace(" ", "todo");
//	    }
	}
	
	String demo(String s) {
		Solution sln = new Solution();
		return sln.reverseWords(s);
	}
	
	public static void main(String[] args) {
		ReverseWordsInAString obj = new ReverseWordsInAString();
		String s = "do you know www.bbxyard.com?";
		if (args.length >= 1)
			s = args[0];
		s = obj.demo(s);
		System.out.printf("after reverse string is: *%s*\n", s);
	}
}
