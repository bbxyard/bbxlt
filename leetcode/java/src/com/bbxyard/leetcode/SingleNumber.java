package com.bbxyard.leetcode;

public class SingleNumber {
	public class Solution {
	    public int singleNumber(int[] A) {
	    	int result = 0;
	    	for (int a : A) {
	    		result = result ^ a;
	    	}
	    	return result;
	    }
	}
	
	int demo(int[] A) {
		Solution sln = new Solution();
		int result = sln.singleNumber(A);
		return result;
	}
	
	public static void main(String[] args) {
		SingleNumber sn = new SingleNumber();		
		int[] A = new int[] { 100, 200, 300, 200, 100, 400, 300 };
		int result = sn.demo(A);
		System.out.printf("hello single number is: %d\n", result);
	}
}
