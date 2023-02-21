class Node{
	int data;
	Node left;
	Node right;
	Node(int data){
		this.data = data;
		left = null;
		right = null;
	}
}
class Solution4 {
    Node first, last, prev;
    void helper(Node root){
        if(root != null){
            helper(root.left);
            if((prev != null) && (prev.data > root.data)){
                if(first == null){
                    first = prev;
                    last = root;
                }else{
                    last = root;
                }
            }
            prev = root;
            helper(root.right);
        }
    }
    public Node correctBST(Node root) {
        first = last = prev = null;
        helper(root);
        if((first != null) && (last != null)){
            int tmp = first.data;
            first.data = last.data;
            last.data = tmp;
        }
        return root;
    }
    public static void main(String args[]){
    }
}

