import java.io.*;
import java.util.*;

class BTree {
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
			this.lchild = null;
			this.rchild = null;
		}
	}

	public static class Pair {
		Node node;
		int state;

		Pair(Node node, int state) {
			this.node = node;
			this.state = state;
		}
	}

	public static Node constructBT(int arr[]) {

		Stack<Pair> stc = new Stack<>();
		Node root = new Node(arr[0]);
		stc.push(new Pair(root, 1));
		int i = 1;

		while (stc.size() > 0) {

			Pair top = stc.peek();

			if (top.state == 1) {
				if (arr[i] != -1) {
					Node nod = new Node(arr[i]);
					top.node.lchild = nod;
					stc.push(new Pair(nod, 1));
					top.state++;
				} else {
					top.node.lchild = null;
					top.state++;

				}
				i++;

			} else if (top.state == 2) {

				if (arr[i] != -1) {
					Node nod = new Node(arr[i]);
					top.node.rchild = nod;
					stc.push(new Pair(nod, 1));
					top.state++;
				} else {
					top.node.rchild = null;
					top.state++;

				}
				i++;

			} else {
				stc.pop();
			}
		}
		return root;
	}

	public static void Display(Node node) {
		if (node == null)
			return;

		String ans = "";
		ans += node.lchild == null ? ". " : node.lchild.data + "";
		ans += " <-(" + node.data + ")-> ";
		ans += node.rchild == null ? ". " : node.rchild.data + "";

		System.out.println(ans);

		Display(node.lchild);
		Display(node.rchild);
	}

	public static int sizeOfTree(Node node) {

		if (node == null)
			return 0;

		int lch = sizeOfTree(node.lchild);
		int rch = sizeOfTree(node.rchild);

		return 1 + lch + rch;
	}

	public static int sumOfTree(Node node) {

		if (node == null)
			return 0;

		int lch = sumOfTree(node.lchild);
		int rch = sumOfTree(node.rchild);

		return node.data + lch + rch;
	}

	public static int MaxOfTree(Node node) {

		if (node == null)
			return Integer.MIN_VALUE;

		int lch = MaxOfTree(node.lchild);
		int rch = MaxOfTree(node.rchild);

		return Math.max(node.data, Math.max(lch, rch));
	}

	public static int MinOfTree(Node node) {

		if (node == null)
			return Integer.MAX_VALUE;

		int lch = MinOfTree(node.lchild);
		int rch = MinOfTree(node.rchild);

		return Math.min(node.data, Math.min(lch, rch));
	}

	public static void RecurrsiveTraversal(Node node) {

		if (node == null)
			return;
		System.out.println("PreOrder " + node.data);
		RecurrsiveTraversal(node.lchild);
		System.out.println("InOrder " + node.data);
		RecurrsiveTraversal(node.rchild);
		System.out.println("PostOrder " + node.data);
	}

	public static void IterativeTraversal(Node node) {

		Stack<Pair> stc = new Stack<>();
		stc.push(new Pair(node, 1));

		String PreOrder = "", PostOrder = "", InOrder = "";

		while (stc.size() > 0) {

			Pair top = stc.peek();

			if (top.state == 1) {
				if (top.node == null)
					stc.pop();
				else {
					PreOrder += top.node.data + " ";
					stc.push(new Pair(top.node.lchild, 1));
					top.state++;
				}
			} else if (top.state == 2) {

				InOrder += top.node.data + " ";
				stc.push(new Pair(top.node.rchild, 1));
				top.state++;
			} else {

				PostOrder += top.node.data + " ";
				stc.pop();

			}

		}
		System.out.println(PreOrder);
		System.out.println(InOrder);
		System.out.println(PostOrder);

	}

	public static void LevelOrder(Node node) {
		Queue<Node> q = new ArrayDeque<>();
		q.add(node);

		while (q.size() > 0) {
			Node top = q.remove();
			System.out.println(top.data + " ");

			if (top.lchild != null)
				q.add(top.lchild);
			if (top.rchild != null)
				q.add(top.rchild);

		}
	}

	public static void LevelOrderLevelwise(Node node) {

		Queue<Node> q = new ArrayDeque<>();
		q.add(node);
		while (q.size() > 0) {
			int curr_size = q.size();
			for (int i = 0; i < curr_size; i++) {
				Node top = q.remove();
				System.out.print(top.data + " ");

				if (top.lchild != null)
					q.add(top.lchild);
				if (top.rchild != null)
					q.add(top.rchild);
			}
			System.out.println();
		}
	}

	public static ArrayList<Node> nodeToRootPath(Node node, int target) {

		if (node == null)
			return new ArrayList<>();

		if (node.data == target) {
			ArrayList<Node> temp = new ArrayList<Node>();
			temp.add(node);
			return temp;
		}

		ArrayList<Node> a1 = nodeToRootPath(node.lchild, target);
		if (a1.size() > 0) {
			a1.add(node);
			return a1;
		}
		ArrayList<Node> a2 = nodeToRootPath(node.rchild, target);
		if (a2.size() > 0) {
			a2.add(node);
			return a2;
		}
		return new ArrayList<>();
	}

	public static void printKlevelDown(Node node, int k, int flag) {
		if (node == null || k < 0) {
			return;
		}
		if (k == 0 && node.data != flag) {
			System.out.print(node.data + " ");
			return;
		}
		printKlevelDown(node.lchild, k - 1, flag);
		printKlevelDown(node.rchild, k - 1, flag);
	}

	public static void printKFarNode(Node node, int target, int k) {
		ArrayList<Node> al = nodeToRootPath(node, target);
		int flag = 0;
		for (int i = 0; i < al.size(); i++) {
			flag = i == 0 ? 0 : al.get(i - 1).data;
			printKlevelDown(al.get(i), k - i, flag);
		}
	}

	public static void printLeafTorootInRange(Node node, String path, int sum, int l, int h) {
		if (node == null)
			return;

		if (node.lchild == null && node.rchild == null) {
			sum += node.data;
			if (sum >= l && sum <= h)
				System.out.println(path + node.data);
		}
		printLeafTorootInRange(node.lchild, path + node.data + " ", sum + node.data, l, h);
		printLeafTorootInRange(node.rchild, path + node.data + " ", sum + node.data, l, h);
	}

	public static Node normalTreeToLeftClone(Node node) {
		if (node == null)
			return null;

		if (node.lchild == null && node.rchild == null) {
			Node newNode = new Node(node.data);
			node.lchild = newNode;
			return node;
		}

		Node temp = normalTreeToLeftClone(node.lchild);
		Node newNode = new Node(node.data);
		newNode.lchild = temp;
		node.lchild = newNode;

		node.rchild = normalTreeToLeftClone(node.rchild);

		return node;
	}

	public static Node leftCloneTreeToNormal(Node node) {

		if (node == null) {
			return node;
		}

		if (node.lchild != null)// for calling left child lchild must not null
			node.lchild = leftCloneTreeToNormal(node.lchild.lchild);

		node.rchild = leftCloneTreeToNormal(node.rchild);

		return node;

	}

	public static void PrintSinglechildNode(Node node) {

		if (node == null)
			return;

		if ((node.lchild != null && node.rchild == null) || (node.lchild == null && node.rchild != null))
			System.out.println(node.data);

		PrintSinglechildNode(node.lchild);
		PrintSinglechildNode(node.rchild);

	}

	public static Node removeLeaves(Node node) {

		if (node == null)
			return null;

		if (node.lchild == null && node.rchild == null)
			return null;

		node.lchild = removeLeaves(node.lchild);
		node.rchild = removeLeaves(node.rchild);

		return node;
	}

	static int Dia = Integer.MIN_VALUE;

	public static int DiameterOfBT(Node node) {

		if (node == null)
			return -1;

		int lsh = DiameterOfBT(node.lchild);
		int rsh = DiameterOfBT(node.rchild);

		int nodeDia = lsh + rsh + 2;
		if (nodeDia > Dia)
			Dia = nodeDia;

		return Math.max(lsh, rsh) + 1;
	}

	public static class dhPair {
		int currDia;
		int currhight;

		dhPair(int dia, int hight) {
			currDia = dia;
			currhight = hight;
		}
	}

	public static dhPair DiameterOfBT2(Node node) {

		if (node == null) {
			dhPair currPair = new dhPair(0, -1);
			return currPair;

		}

		dhPair lsp = DiameterOfBT2(node.lchild);
		dhPair rsp = DiameterOfBT2(node.rchild);

		int nodeDia = lsp.currhight + rsp.currhight + 2;
		int maxdia = Math.max(nodeDia, Math.max(lsp.currDia, rsp.currDia));

		dhPair currPair = new dhPair(maxdia, Math.max(lsp.currhight, rsp.currhight) + 1);

		return currPair;
	}

	static int tilt = 0;

	public static class tsPair {
		int curr_tilt;
		int curr_sum;

		tsPair(int tilt, int sum) {
			curr_tilt = tilt;
			curr_sum = sum;
		}

	}

	public static int tiltOfBT(Node node) {

		if (node == null)
			return 0;

		int lss = tiltOfBT(node.lchild);
		int rss = tiltOfBT(node.rchild);
		tilt += Math.abs(lss - rss);

		return lss + rss + node.data;

	}

	public static tsPair tiltOfBT1(Node node) {

		if (node == null) {
			tsPair p = new tsPair(0, 0);
			return p;
		}

		tsPair lsp = tiltOfBT1(node.lchild);
		tsPair rsp = tiltOfBT1(node.rchild);

		tsPair p = new tsPair(lsp.curr_tilt + rsp.curr_tilt + Math.abs(lsp.curr_sum - rsp.curr_sum),
				lsp.curr_sum + rsp.curr_sum + node.data);

		return p;

	}

	public static class isBSTPair {
		int min;
		int max;
		boolean isBST;

		isBSTPair() {
		}

		isBSTPair(int min, int max, boolean b) {
			this.min = min;
			this.max = max;
			isBST = b;
		}

	}

	public static isBSTPair isBinarySearchTree(Node node) {

		if (node == null) {
			isBSTPair p = new isBSTPair(Integer.MAX_VALUE, Integer.MIN_VALUE, true);
			return p;
		}
		isBSTPair isLBST = isBinarySearchTree(node.lchild);
		isBSTPair isRBST = isBinarySearchTree(node.rchild);

		isBSTPair p = new isBSTPair();
		p.min = Integer.min(node.data, Integer.min(isLBST.min, isRBST.min));
		p.max = Integer.max(node.data, Integer.max(isLBST.max, isRBST.max));
		p.isBST = isLBST.isBST && isRBST.isBST && (isLBST.max < node.data && node.data < isRBST.min);

		return p;

	}

	public static class BBPair {
		boolean isBalance;
		int height;

		BBPair() {
		}

		BBPair(boolean b, int h) {
			isBalance = b;
			height = h;
		}
	}

	public static BBPair isBalanceBT(Node node) {

		if (node == null) {
			BBPair p = new BBPair(true, -1);
			return p;
		}
		BBPair lpair = isBalanceBT(node.lchild);
		BBPair rpair = isBalanceBT(node.rchild);

		BBPair p = new BBPair();
		p.isBalance = (lpair.isBalance && rpair.isBalance && Math.abs(lpair.height - rpair.height) <= 1);

		p.height = Math.max(lpair.height, rpair.height) + 1;

		return p;
	}

	public static class MsPair {
		boolean isBST;
		int min;
		int max;
		int node;
		int size;

		MsPair() {
		}

		MsPair(int min, int max, boolean isBST, int node, int size) {
			this.min = min;
			this.max = max;
			this.isBST = isBST;
			this.node = node;
			this.size = size;
		}
	}

	public static MsPair maxSizeBST(Node node) {
		if (node == null) {
			MsPair p = new MsPair(Integer.MAX_VALUE, Integer.MIN_VALUE, true, 0, 0);
			return p;
		}
		MsPair lpair = maxSizeBST(node.lchild);
		MsPair rpair = maxSizeBST(node.rchild);

		MsPair p = new MsPair();

		p.min = Integer.min(node.data, Integer.min(lpair.min, rpair.min));
		p.max = Integer.max(node.data, Integer.max(lpair.max, rpair.max));

		p.isBST = lpair.isBST && rpair.isBST && (node.data > lpair.max && node.data < rpair.min);
		if (p.isBST) {

			p.node = node.data;
			p.size = lpair.size + rpair.size + 1;

		} else if (lpair.size > rpair.size) {

			p.node = lpair.node;
			p.size = lpair.size;

		} else {

			p.node = rpair.node;
			p.size = rpair.size;

		}
		System.out.println(p.isBST+" "+p.min +" "+ p.max +" "+ p.node +" "+ p.size);
		return p;

	}

	public static void main(String[] args) {
		Scanner sc = io();
		int n;
		n = sc.nextInt();

		int arr[] = new int[n];
		for (int i = 0; i < n; i++) {
			arr[i] = sc.nextInt();
		}
		Node root = constructBT(arr);
		// System.out.println(root.data);
		// Display(root);
		// System.out.println(sizeOfTree(root));
		// System.out.println(sumOfTree(root));
		// System.out.println(MaxOfTree(root));
		// System.out.println(MinOfTree(root));
		// RecurrsiveTraversal(root);
		// IterativeTraversal(root);
		// LevelOrder(root);
		// LevelOrderLevelwise(root);
		// for (Node node : nodeToRootPath(root, 50)) {
		// System.out.print(node.data + " ");
		// }
		// printKlevelDown(root, 3);
		// printKFarNode(root, 60, 1);
		// printLeafTorootInRange(root,"",0, 60,110);

		// normalTreeToLeftClone(root);
		// leftCloneTreeToNormal(root);

		// PrintSinglechildNode(root);

		// removeLeaves(root);
		// Display(root);
		// dhPair p = DiameterOfBT2(root);
		// System.out.println(p.currDia);
		// System.out.println(p.currhight);
		// int sum = tiltOfBT(root);
		// System.out.println(tilt);
		// System.out.println(sum);

		// tsPair p = tiltOfBT1(root);
		// System.out.println(p.curr_tilt + " " + p.curr_sum);

		// isBSTPair p = isBinarySearchTree(root);
		// System.out.println(p.min);
		// System.out.println(p.max);
		// System.out.println(p.isBST);
		// BBPair p = isBalanceBT(root);
		// System.out.println(p.isBalance);
		// System.out.println(p.height);
		// Display(root);
		// MsPair p = maxSizeBST(root);
		// System.out.println(p.node + " @ " + p.size);

	}
}
