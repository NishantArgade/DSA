import java.io.*;
import java.util.*;

class Main {

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

	// this data member created in heap.
	static int size;
	static int max;
	static int min;
	static int height;

	// depth created in stack it created and deleted dependss on stack motione
	public static void TravelAndChange(Node node, int depth) {

		size++;
		min = Math.min(min, node.data);
		max = Math.max(max, node.data);
		height = Math.max(height, depth);

		for (Node ch : node.chlidrens) {
			TravelAndChange(ch, depth + 1);
		}
	}

	static int predessor;
	static int successor;
	static int state = 0;

	public static void PredessorAndSuccessor(Node node, int target) {
		if (state == 0) {

			if (node.data == target)
				state = 1;
			else
				predessor = node.data;

		} else if (state == 1) {
			successor = node.data;
			state = 2;
		}

		for (Node ch : node.chlidrens) {
			PredessorAndSuccessor(ch, target);
		}

	}

	static int floor = Integer.MIN_VALUE;
	static int ceil = Integer.MAX_VALUE;

	public static void floorAndCeil(Node node, int target) {

		if (node.data < target) {
			if (node.data > floor) {
				floor = node.data;
			}
		}
		if (node.data > target) {
			if (node.data < ceil) {
				ceil = node.data;
			}
		}

		for (Node ch : node.chlidrens) {
			floorAndCeil(ch, target);
		}
	}

	public static int KthLargest(Node node, int k) {
		int factor = Integer.MAX_VALUE;
		for (int i = 0; i < k; i++) {
			floorAndCeil(node, factor);
			factor = floor;
			floor = Integer.MIN_VALUE;
		}
		return factor;
	}

	static Node msn;
	static int ms = Integer.MIN_VALUE;

	public static int maxSumTree(Node node) {
		int sum = 0;
		for (Node ch : node.chlidrens) {
			int ch_sum = maxSumTree(ch);
			sum += ch_sum;

		}
		sum = sum + node.data;

		if (sum > ms) {
			ms = sum;
			msn = node;
		}

		return sum;

	}

	static int dia = 0;

	public static int DiaOfTree(Node node) {
		int fd = -1;
		int sd = -1;
		for (Node ch : node.chlidrens) {
			int val = DiaOfTree(ch);
			if (val > fd) {
				sd = fd;
				fd = val;
			} else if (val > sd) {
				sd = val;
			}

		}
		int cand = fd + sd + 2;
		if (cand > dia) {
			dia = cand;
		}
		return fd += 1;

	}

	public static class Pair {
		Node node;
		int state;

		Pair(Node node, int state) {
			this.node = node;
			this.state = state;
		}
	}

	public static void preOrderIterative(Node node) {
		Pair p1 = new Pair(node, -1);
		Stack<Pair> stc = new Stack<>();
		stc.push(p1);
		String pre="";
		String post="";
		while (stc.size() > 0) {
			Pair p = stc.peek();
			if (p.state == -1) {
				pre += p.node.data+" ";
				p.state++;
			} else if (p.state == p.node.chlidrens.size()) {

				post += p.node.data+" ";
				stc.pop();
			} else {
				stc.push(new Pair(p.node.chlidrens.get(p.state), -1));
				p.state++;

			}
		}

		System.out.println(pre);
		System.out.println(post);
	}

	public static void main(String[] args) {
		Scanner read = io();
		int n = read.nextInt();
		int arr[] = new int[n];

		for (int i = 0; i < n; i++) {
			arr[i] = read.nextInt();
		}
		Node r = GenericTreeConstruction(arr);
		// PredessorAndSuccessor(r, 30);
		// System.out.println(predessor);
		// System.out.println(successor);
		// floorAndCeil(r, 10);
		// KthLargest(r, 3);
		// System.out.println(floor);
		// System.out.println(KthLargest(r, 3));
		// maxSumTree(r);
		// System.out.println(msn.data);
		// System.out.println(ms);
		// DiaOfTree(r);
		// System.out.println(dia);
		preOrderIterative(r);
	}
}