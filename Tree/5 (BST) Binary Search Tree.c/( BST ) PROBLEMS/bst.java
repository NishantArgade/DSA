import java.io.*;
import java.util.*;

class bst {
	public static Scanner io() {
		Scanner rd = new Scanner(System.in);
		if (System.getProperty(" ONLINE_JUDGE ") == null) {
			try {
				System.setOut(new PrintStream(new FileOutputStream("2output.txt")));
				rd = new Scanner(new File("1input.txt"));
			} catch (Exception e) {
			}
		}
		return rd;
	}

	public static class Node {
		int data;
		Node lchild;
		Node rchild;

		Node(int data) {
			this.data = data;
			lchild = null;
			rchild = null;
		}
	}

	public static Node constructBST(int arr[], int l, int h) {
		if (l > h)
			return null;

		int mid = (l + h) / 2;
		Node newNode = new Node(arr[mid]);
		newNode.lchild = constructBST(arr, l, mid - 1);
		newNode.rchild = constructBST(arr, mid + 1, h);
		return newNode;
	}

	public static void display(Node node) {
		if (node == null)
			return;

		System.out.print((node.lchild == null) ? "." : node.lchild.data);
		System.out.print("<- " + node.data + " ->");
		System.out.println((node.rchild == null) ? "." : node.rchild.data);

		display(node.lchild);
		display(node.rchild);

	}

	public static int size(Node node) {
		if (node == null)
			return 0;
		int ls = size(node.lchild);
		int rs = size(node.rchild);
		return ls + rs + 1;

	}

	public static int sum(Node node) {
		if (node == null)
			return 0;
		int ls = sum(node.lchild);
		int rs = sum(node.rchild);
		return ls + rs + node.data;

	}

	public static int min(Node node) {

		if (node.lchild == null)
			return node.data;

		else
			return min(node.lchild);

	}

	public static int max(Node node) {

		if (node.rchild == null)
			return node.data;
		else
			return max(node.rchild);

	}

	public static boolean find(Node node, int data) {
		if (node == null)
			return false;

		if (data < node.data)
			return find(node.lchild, data);
		else if (data > node.data)
			return find(node.rchild, data);
		else
			return true;

	}

	public static Node add(Node node, int data) {
		if (node == null)
			return new Node(data);

		if (data < node.data)
			node.lchild = add(node.lchild, data);
		else if (data > node.data)
			node.rchild = add(node.rchild, data);
		else {

		}
		return node;
	}

	public static Node remove(Node node, int data) {
		if (node == null) {
			return null;
		}
		if (data < node.data) {
			node.lchild = remove(node.lchild, data);

		} else if (data > node.data) {
			node.rchild = remove(node.rchild, data);

		} else {

			if (node.lchild == null && node.rchild == null)
				return null;
			else if (node.rchild == null)
				return node.lchild;
			else if (node.lchild == null)
				return node.rchild;
			else {
				int mval = max(node.lchild);
				node.data = mval;
				remove(node.lchild, mval);
			}

		}
		return node;

	}

	public static int sum = 0;

	public static void replaceWithLargestSum(Node node) {

		if (node == null) {
			return;
		}
		replaceWithLargestSum(node.rchild);
		int od = node.data;
		node.data = sum;

		sum += od;
		replaceWithLargestSum(node.lchild);

	}

	public static int findLCA(Node node, int d1, int d2) {

		if (d1 > node.data && d2 > node.data) {
			return findLCA(node.rchild, d1, d2);
		} else if (d1 < node.data && d2 < node.data) {
			return findLCA(node.lchild, d1, d2);
		} else
			return node.data;

	}

	public static void printNodeInRange(Node node, int min, int max) {
		if (node == null)
			return;

		if (node.data >= min && node.data <= max) {
			printNodeInRange(node.lchild, min, max);
			System.out.print(node.data + " ");
			printNodeInRange(node.rchild, min, max);
		} else if (node.data < min && node.data < max) {
			printNodeInRange(node.rchild, min, max);
		} else if (node.data > min && node.data > max) {
			printNodeInRange(node.lchild, min, max);
		}

	}

	public static void TargetSumPair(Node root, Node node, int Target) {
		if (node == null)
			return;

		TargetSumPair(root, node.lchild, Target);

		int comp = Target - node.data;
		if (node.data < comp) {
			if (find(root, comp) == true) {
				System.out.println("( " + node.data + "," + comp + " )");
			}
		}
		TargetSumPair(root, node.rchild, Target);
	}

	public static void TargetSumPair2(ArrayList<Integer> al, Node node) {
		if (node == null)
			return;

		TargetSumPair2(al, node.lchild);
		al.add(node.data);
		TargetSumPair2(al, node.rchild);
	}

	public static void arrTargetSumPair(Node node, int Target) {

		ArrayList<Integer> al = new ArrayList<>();
		TargetSumPair2(al, node);
		int l = 0;
		int h = al.size() - 1;
		while (l < h) {
			if (al.get(l) + al.get(h) < Target)
				l++;
			else if (al.get(l) + al.get(h) > Target)
				h--;
			else {
				System.out.println(al.get(l) + " " + al.get(h));
				l++;
				h--;
			}
		}

	}

	public static class nsPair {
		Node node;
		int state;

		nsPair(Node node, int state) {
			this.node = node;
			this.state = state;
		}

	}

	// 1 - pre state++ call left / 2 - in state++ call right / 3 - post pop
	public static int getNextFromNormalStk(Node node, Stack<nsPair> norStk) {
		while (norStk.size() > 0) {
			nsPair top = norStk.peek();
			if (top.state == 1) {

				if (top.node.lchild != null)
					norStk.push(new nsPair(top.node.lchild, 1));
				top.state++;

			} else if (top.state == 2) {

				if (top.node.rchild != null)
					norStk.push(new nsPair(top.node.rchild, 1));
				top.state++;
				return top.node.data;

			} else
				norStk.pop();
		}
		return -1;
	}

	public static int getNextFromReverseStk(Node node, Stack<nsPair> revStk) {

		while (revStk.size() > 0) {
			nsPair top = revStk.peek();
			if (top.state == 1) {

				if (top.node.rchild != null)
					revStk.push(new nsPair(top.node.rchild, 1));
				top.state++;

			} else if (top.state == 2) {

				if (top.node.lchild != null)
					revStk.push(new nsPair(top.node.lchild, 1));
				top.state++;
				return top.node.data;

			} else
				revStk.pop();

		}
		return -1;
	}

	public static void TargetSumPairBest(Node node, int Target) {
		Stack<nsPair> norStk = new Stack<>();
		Stack<nsPair> revStk = new Stack<>();

		norStk.push(new nsPair(node, 1));
		revStk.push(new nsPair(node, 1));

		int fval = getNextFromNormalStk(node, norStk);
		int sval = getNextFromReverseStk(node, revStk);

		while (fval < sval) {
			if (fval + sval == Target) {

				System.out.println(fval + " " + sval);

				fval = getNextFromNormalStk(node, norStk);
				sval = getNextFromReverseStk(node, revStk);

			} else if (fval + sval < Target) {
				fval = getNextFromNormalStk(node, norStk);
			} else {
				sval = getNextFromReverseStk(node, revStk);
			}

		}
	}

	public static void main(String[] args) {
		Scanner sc = io();

		int n;
		n = sc.nextInt();
		int[] arr = new int[n];
		for (int i = 0; i < n; i++) {
			arr[i] = sc.nextInt();
		}
		Node root = constructBST(arr, 0, n - 1);

		// arrTargetSumPair(root, 100);
		TargetSumPairBest(root, 5);
	}
}
