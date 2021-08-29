import java.io.*;
import java.util.*;


// import org.graalvm.compiler.graph.NodeClass;

// import jdk.internal.jshell.tool.resources.l10n;

class javaMain {

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
		ArrayList<Node> chlidrens = new ArrayList<>();

		public Node() {
		}

		public Node(int data) {
			this.data = data;
		}
	}

	public static class Pair {
		Node node;
		int level;

		public Pair() {
		}

		public Pair(Node node, int level) {
			this.node = node;
			this.level = level;
		}
	}

	public static Node GenericTreeConstruction(int arr[]) {

		Stack<Node> stc = new Stack<>();
		Node root = null;
		for (int i = 0; i < arr.length; i++) {

			if (arr[i] == -1)
				stc.pop();
			else {
				Node Nnode = new Node();
				Nnode.data = arr[i];

				if (stc.empty()) {
					root = Nnode;
				} else {
					Node temp = stc.peek();
					temp.chlidrens.add(Nnode);
				}
				stc.push(Nnode);
			}
		}
		return root;
	}

	public static void preOrder(Node ptr) {

		System.out.print(ptr.data + " ");
		for (Node child : ptr.chlidrens) {
			preOrder(child);

		}
	}

	public static void DisplayTree(Node node) {
		String s = node.data + "-->";
		for (Node child : node.chlidrens) {
			s += child.data + ",";
		}
		s += ".";
		System.out.println(s);

		for (Node child : node.chlidrens) {
			DisplayTree(child);
		}

	}

	public static int MaximumValNode(Node node) {
		int cur = node.data;
		for (Node child : node.chlidrens) {
			int ch_data = MaximumValNode(child);
			cur = Integer.max(cur, ch_data);
		}
		return cur;
	}

	public static int sizeOfTree(Node node) {
		int cur = 0;// identity
		for (Node child : node.chlidrens) {
			int chSize = sizeOfTree(child);
			cur = cur + chSize;
		}
		cur += 1;
		return cur;
	}

	public static int hightOfTree(Node node) {
		int ht = -1;// identity
		for (Node child : node.chlidrens) {
			int chSize = hightOfTree(child);
			ht = Integer.max(ht, chSize);
		}
		ht += 1;
		return ht;
	}

	public static void Traversal(Node node) {

		System.out.println("Node pre " + node.data);

		for (Node child : node.chlidrens) {

			System.out.println("Edge pre " + node.data + "--> " + child.data);
			Traversal(child);
		}

	}

	public static void LevelOrder(Node node) {
		Queue<Node> q = new ArrayDeque<>();
		q.add(node);
		while (q.size() > 0) {
			Node temp = q.remove();
			System.out.println(temp.data + " ");

			for (Node child : temp.chlidrens) {
				q.add(child);
			}

		}
	}

	public static void LevelOrderZigZag(Node node) {
		Stack<Node> mStack = new Stack<>();
		Stack<Node> cStack = new Stack<>();
		mStack.push(node);
		int level = 1;
		while (mStack.size() > 0) {
			Node temp = mStack.pop();
			System.out.print(temp.data + " ");
			if (level % 2 != 0) {
				for (int i = 0; i < temp.chlidrens.size(); i++) {
					cStack.push(temp.chlidrens.get(i));
				}

			} else {
				for (int i = temp.chlidrens.size() - 1; i >= 0; i--) {
					cStack.push(temp.chlidrens.get(i));
				}

			}
			if (mStack.size() == 0) {
				mStack = cStack;
				cStack = new Stack<>();
				level++;
				System.out.println();

			}
		}
	}

	public static void LevelOrderLevelwise1(Node node) {
		Queue<Node> mQueue = new ArrayDeque<>();
		Queue<Node> cQueue = new ArrayDeque<>();
		mQueue.add(node);

		while (!mQueue.isEmpty()) {

			Node n = mQueue.remove();
			System.out.print(n.data + " ");

			for (Node ch : n.chlidrens) {
				cQueue.add(ch);
			}

			if (mQueue.size() == 0) {
				mQueue = cQueue;
				cQueue = new ArrayDeque<>();
				System.out.println();
			}
		}
	}

	public static void LevelOrderLevelwise2(Node node) {

		Queue<Node> mQueue = new ArrayDeque<>();

		mQueue.add(node);
		Node flag = new Node(-1);
		mQueue.add(flag);

		while (!mQueue.isEmpty()) {

			Node n = mQueue.remove();

			if (n.data != -1) {
				System.out.print(n.data + " ");

				for (Node ch : n.chlidrens) {
					mQueue.add(ch);
				}
			} else {
				if (mQueue.size() > 0) {
					mQueue.add(flag);
					System.out.println();
				}
			}
		}
	}

	public static void LevelOrderLevelwise3(Node node) {
		Queue<Node> q = new ArrayDeque<>();
		q.add(node);
		while (q.size() > 0) {

			int q_size = q.size();
			for (int i = 0; i < q_size; i++) {
				Node temp = q.remove();
				System.out.print(temp.data + " ");
				for (Node ch : temp.chlidrens)
					q.add(ch);
			}
			System.out.println();

		}

	}

	public static void LevelOrderLevelwise4(Node node) {
		Pair p1 = new Pair();
		p1.node = node;
		p1.level = 1;
		Queue<Pair> q = new ArrayDeque<>();
		q.add(p1);
		int level = 1;
		while (q.size() > 0) {
			Pair pir = q.remove();
			Node nod = pir.node;
			int lev = pir.level;

			if (lev != level) {
				level = lev;
				System.out.println();
			}
			System.out.print(nod.data + " ");

			for (Node ch : nod.chlidrens) {
				q.add(new Pair(ch, lev + 1));
			}

		}

	}

	public static void MirrorOfTree(Node node) {

		for (Node ch : node.chlidrens) {
			MirrorOfTree(ch);
		}
		Collections.reverse(node.chlidrens);
	}

	public static void removeLeafNode(Node node) {
		for (int i = node.chlidrens.size() - 1; i >= 0; i--) {
			Node child = node.chlidrens.get(i);

			if (child.chlidrens.size() == 0)
				node.chlidrens.remove(child);
		}

		for (Node ch : node.chlidrens) {
			removeLeafNode(ch);
		}

	}

	public static Node getTail(Node node) {
		while (node.chlidrens.size() == 1)
			node = (node.chlidrens.get(0));
		return node;
	}

	public static void LinearizedTree1(Node node) {
		for (Node ch : node.chlidrens) {
			LinearizedTree1(ch);
		}
		while (node.chlidrens.size() > 1) {
			Node ln = node.chlidrens.remove(node.chlidrens.size() - 1);
			Node sln = node.chlidrens.get(node.chlidrens.size() - 1);
			Node tail = getTail(sln);
			tail.chlidrens.add(ln);
		}
	}

	public static Node LinerizedTree2(Node node) {

		if (node.chlidrens.size() == 0)
			return node;

		Node lt = LinerizedTree2(node.chlidrens.get(node.chlidrens.size() - 1));

		while (node.chlidrens.size() > 1) {

			Node ln = node.chlidrens.remove(node.chlidrens.size() - 1);
			Node sln = node.chlidrens.get(node.chlidrens.size() - 1);

			Node tail = LinerizedTree2(sln);

			tail.chlidrens.add(ln);

		}
		return lt;
	}

	public static boolean FindTargetNode(Node node, int target) {

		if (node.data == target) {
			return true;
		}
		for (Node ch : node.chlidrens) {
			boolean find = FindTargetNode(ch, target);
			if (find == true)
				return true;
		}
		return false;

	}

	public static ArrayList<Node> NodeToRootPath(Node node, int target) {
		if (node.data == target) {
			ArrayList<Node> path = new ArrayList<>();
			path.add(node);
			return path;
		}
		for (Node ch : node.chlidrens) {
			ArrayList<Node> path = NodeToRootPath(ch, target);
			if (path.size() > 0) {
				path.add(node);
				return path;
			}
		}
		return new ArrayList<Node>();
	}

	public static int lowestCommonAncestor(Node node, int target1, int target2) {
		ArrayList<Node> AL1 = NodeToRootPath(node, target1);
		ArrayList<Node> AL2 = NodeToRootPath(node, target2);
		int i = AL1.size() - 1;
		int j = AL2.size() - 1;
		while (i >= 0 && j >= 0 && AL1.get(i) == AL2.get(j)) {
			i--;
			j--;
		}
		i++;
		j++;
		return AL1.get(i).data;
	}

	public static int distanceBetweentwoNodes(Node node, int target1, int target2) {
		ArrayList<Node> AL1 = NodeToRootPath(node, target1);
		ArrayList<Node> AL2 = NodeToRootPath(node, target2);
		int i = AL1.size() - 1;
		int j = AL2.size() - 1;
		while (i >= 0 && j >= 0 && AL1.get(i) == AL2.get(j)) {
			i--;
			j--;
		}
		i++;
		j++;
		return i + j;
	}

	public static boolean areSimillarTree(Node node1, Node node2) {
		if (node1.chlidrens.size() != node2.chlidrens.size())
			return false;

		for (int i = 0; i < node1.chlidrens.size(); i++) {
			boolean flag = areSimillarTree(node1.chlidrens.get(i), node2.chlidrens.get(i));
			if (flag == false)
				return false;
		}
		return true;
	}

	public static boolean areMirrorImaageOfTree(Node node1, Node node2) {
		if (node1.chlidrens.size() != node2.chlidrens.size())
			return false;

		for (int i = 0; i < node1.chlidrens.size(); i++) {
			Node ch1 = node1.chlidrens.get(i);
			Node ch2 = node2.chlidrens.get(node2.chlidrens.size() - 1 - i);

			boolean flag = areMirrorImaageOfTree(ch1, ch2);
			if (flag == false) {
				return false;
			}
		}
		return true;
	}

	// Mirror of Semetric Tree is tree of itself
	public static boolean isSemetricTree(Node node) {
		if (areMirrorImaageOfTree(node, node))
			return true;
		else
			return false;
	}

	
	public static void main(String[] args) {
		Scanner read = io();

		int n = read.nextInt();
		int arr[] = new int[n];

		for (int i = 0; i < n; i++) {
			arr[i] = read.nextInt();
		}
		// int n2 = read.nextInt();
		// int arr2[] = new int[n2];

		// for (int i = 0; i < n2; i++) {
		// arr2[i] = read.nextInt();
		// }
		Node r = GenericTreeConstruction(arr);
		// Node r2 = GenericTreeConstruction(arr2);
		// preOrder(h);
		// DisplayTree(h);
		// System.out.println(Traversal(h));
		// Traversal(h);
		// LevelOrderZigZag(h);
		// LevelOrderLevelwise4(h);
		// MirrorOfTree(h);
		// removeLeafNode(h);
		// LinearizedTree(h);
		// LinerizedTree2(h);
		// DisplayTree(h);
		// System.out.println(FindTargetNode(h, 80));
		// for (Node node : NodeToRootPath(h, 450)) {
		// System.out.println(node.data);
		// }
		// System.out.println(lowestCommonAncestor(h, 10, 80));
		// System.out.println(distanceBetweentwoNodes(h, 10, 80));

		// System.out.println(areSimillarTree(h1, h2));
		// System.out.println(areMirrorImaageOfTree(r1, r2));
		System.out.println(isSemetricTree(r));
	}
}