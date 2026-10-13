package bst;

import java.util.Queue;
import java.util.Stack;
import java.util.LinkedList;

public class BST {
    static class Node {
        private int data;
        private Node left, right;
        public Node(int value) {
            this.data = value;
            left = right = null;
        }
    }
    
    Node root;
    public BST () {
        root = null;
    }
    public boolean isEmpty() { 
        return root==null;
    }
    // 1. add node
    public void addNode(int val) {
        Node newNode = new Node(val);
        if(root == null) 
            root = newNode;
        else {
            Node trav = root;
            while(trav!=newNode) {
                if(val > trav.data) {
                    if(trav.right==null) 
                        trav.right = newNode;
                    else 
                        trav = trav.right;
                } else {
                    if(trav.left==null)
                        trav.left = newNode;
                    else 
                        trav = trav.left;
                }
            }
        }
    }

    // 2. preorder
    public void preOrder(Node trav) {
        // root left right
        if(trav==null) return;
        System.out.print(" " + trav.data);
        preOrder(trav.left);
        preOrder(trav.right);
    } 
    public void preOrder() {
        System.out.print("Preorder :: ");
        preOrder(root);
        System.out.println();
    }
    // 3. inorder
    public void inOrder(Node trav) {
        // left root right
        if(trav==null) return;
        inOrder(trav.left);
        System.out.print(" " + trav.data);
        inOrder(trav.right);
    }
    public void inOrder() {
        System.out.print("InOrder :: ");
        inOrder(root);
        System.out.println();
    }
    // 4. postorder
    public void postOrder(Node trav) {
        // left right root
        if(trav==null) return;
        postOrder(trav.left);
        postOrder(trav.right);
        System.out.print(trav.data);
    }
    public void postOrder() {
        System.out.print("PostOrder :: ");
        postOrder(root);
        System.out.println();
    }
    // 5. delete node
    public void deleteNode(int key) {
        if(root==null) return;
        // search the key
        Node trav = root;
        Node parent = null;
        while(trav!=null) {
            if(trav.data == key)
                break;
            parent = trav;
            if(key > trav.data) 
                trav = trav.right;
            else 
                trav = trav.left;
        }
        if(trav==null) return;
        else if(trav.right==null) { 
            if(trav==root) 
                root = trav.left;
            else if(trav == parent.right)
                parent.right = trav.left;
            else 
                parent.left = trav.left;
        } else if(trav.left==null) {
            if(trav==root)
                root = trav.right;
            else if(trav == parent.left) 
                parent.left = trav.right;
            else 
                parent.right = trav.right;
        } else { // both the children are present
            Node pred = root.left;
            parent = trav;
            while(pred.right!=null) {
                parent = pred;
                pred = pred.right;
            }
            trav.data = pred.data;
            if(pred == parent.right)
                parent.right = pred.left;
            else 
                parent.left = pred.left;
        }
    } 
    // 6. height
    public int height(Node root) {
        if(root==null) return -1;
        return Math.max(height(root.left), height(root.right)) + 1;
    }
    public int height() {
        return height(root);
    }
    // 7. dfs
    public void dfs() {
        Stack<Node> stk = new Stack<>();
        stk.push(root);
        System.out.print("DFS: ");
        while(!stk.empty()) {
            Node popped = stk.pop();
            System.out.print(" " + popped.data);
            if(popped.right!=null) stk.push(popped.right);
            if(popped.left!=null) stk.push(popped.left);
        }
        System.out.println();
    }
    // 8. bfs
    public void bfs() {
        Queue<Node> q = new LinkedList<>();
        q.offer(root);
        System.out.print("BFS: ");
        while(!q.isEmpty()) {
            Node polled = q.poll();
            System.out.print(" " + polled.data);
            if(polled.left!=null) q.offer(polled.left);
            if(polled.right!=null) q.offer(polled.right);
        }
        System.out.println();
    }
    // 9. delete all
    public void deleteAll() {
        root = null;
    }
    // 10. search node
    public Node searchNode(int key) {
        Node trav = root;
        while(trav!=null) {
            if(trav.data==key) return trav;
            else if(key > trav.data) trav = trav.right;
            else trav = trav.left;
        }
        return trav;
    }
}