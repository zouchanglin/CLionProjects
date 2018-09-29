package com.xpu.demo;
import java.util.Stack;

public class Solution {
    Stack<Integer> stack1 = new Stack<Integer>();
    Stack<Integer> stack2 = new Stack<Integer>();
    
    public void m_push(int node) {
        stack1.push(node);
    }
    
    public int m_pop() {
        //栈二非空
        if(stack2.isEmpty()){
            while(!stack1.isEmpty()){
                stack2.push(stack1.peek());
                stack1.pop();
            }
        }
        Integer peek = stack2.peek();
        stack2.pop();
        return peek;
    }
}