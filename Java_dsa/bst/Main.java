package bst;


public class Main {
    public static void main(String[] args) {
        BST bst = new BST();

        bst.addNode(8);
		bst.addNode(3);
		bst.addNode(10);
		bst.addNode(2);
		bst.addNode(15);
		bst.addNode(6);
		bst.addNode(14);
		bst.addNode(4);
		bst.addNode(7);

        bst.inOrder();
        bst.deleteNode(10);
        bst.inOrder();

        bst.dfs();
        bst.bfs();

        BST.Node searchedNode = bst.searchNode(14);
        if(searchedNode!=null)
            System.out.println("Node found!!!");
        else
            System.out.println("Node not found!!!");
    }
}
