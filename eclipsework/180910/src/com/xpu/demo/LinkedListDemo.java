package com.xpu.demo;

import java.util.ArrayList;
import java.util.Stack;
//输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。

class ListNode {
        int val;
        ListNode next = null;

        ListNode(int val) {
            this.val = val;
        }
    }
public class LinkedListDemo{
	public void getNode(ArrayList<Integer> array,ListNode listNode) {
		if(listNode == null) {
			return;
		}else {
			getNode(array, listNode.next);
			array.add(listNode.val);
		}
		
	}
	
	public ArrayList<Integer> printListFromTailToHead(ListNode listNode) {
		ArrayList<Integer> ret = new ArrayList<>();
		if(listNode == null)
			return ret;
		getNode(ret, listNode);
		return ret;
	}
	public static void main(String[] args) {
		
	}
}
