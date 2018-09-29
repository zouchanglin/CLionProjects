import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Stack;

public class Demo {

	public static void main(String[] args) {
		int push[] = { 1, 2, 3, 4, 5 };
		//int pop[] = { 2, 3, 4, 5, 1 };
		int pop[] = {4, 5, 3, 1, 2 };
		System.out.println(IsPopOrder(push,pop)); 
	}

	//这个是中文的注释
	public static boolean IsPopOrder(int[] pushA, int[] popA) {
		int index = 0;
		if (pushA.length != popA.length)
			return false;
		Stack<Integer> s = new Stack<>();
		for (int i = 0; i < pushA.length; i++) {
			s.push(pushA[i]);
			if (s.peek() == popA[index]) {
				s.pop();
				index++;
			}
		}
		for (; index < popA.length; index++) {
			int ret = s.peek();
			s.pop();
			if (ret != popA[index])
				return false;
		}
		return true;
	}
	
	public class TreeNode {
	    int val = 0;
	    TreeNode left = null;
	    TreeNode right = null;

	    public TreeNode(int val) {
	        this.val = val;

	    }

	}
	public ArrayList<Integer> PrintFromTopToBottom(TreeNode root) {
        //层序遍历
        if(root == null)
            return null;
        ArrayList<Integer> arr = new ArrayList<>();
        LinkedList<TreeNode> queue = new LinkedList<>();
        queue.push(root);
        while(!queue.isEmpty()) {
        	TreeNode tmp = queue.peek();
        	arr.add(tmp.val);
        	queue.pop();
        	
        	if(tmp.left != null)
        		queue.push(tmp.left);
        	if(tmp.right!=null)
        		queue.push(tmp.right);
        	
        }
        
        return arr;
    }

}
