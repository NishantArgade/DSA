import java.util.*;//util-iterator // lang- iterable
import java.io.*;

class iterableAndIterator {
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
		int state;

		Pair(Node node, int state) {
			this.node = node;
			this.state = state;
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

	public static class GenericTree implements Iterable<Integer> {
		Node root;

		GenericTree(Node root) {
			this.root = root;
		}

		public Iterator<Integer> iterator() {
			Iterator<Integer> obj = new GTreeTraversal(root);
			return obj;
		}
	}

	public static class GTreeTraversal implements Iterator<Integer> {
		Integer nval;
		Stack<Pair> stc;

		GTreeTraversal(Node node) {
			stc = new Stack<>();
			stc.push(new Pair(node, -1));
			next();
		}

		public boolean hasNext() {
			if (nval == null)
				return false;
			else
				return true;
		}

		public Integer next() {
			Integer fr = nval;
			nval = null;

			while (stc.size() > 0) {
				Pair p = stc.peek();
				if (p.state == -1) {
					nval = p.node.data;
					p.state++;
					break;
					
				} else if (p.state == p.node.chlidrens.size()) {
					
					stc.pop();
				} else {
					stc.push(new Pair(p.node.chlidrens.get(p.state), -1));
					p.state++;

				}
			}
			return fr;
		}

	}

	public static void main(String[] arguments) {
		// ArrayList<Integer> al = new ArrayList<>();
		// al.add(12);
		// al.add(23);
		// al.add(34);
		// al.add(55);
		// al.add(39);

		// for(int x:al){
		// System.out.println(x);
		// }

		Scanner read = io();

		int n = read.nextInt();
		int arr[] = new int[n];

		for (int i = 0; i < n; i++) {
			arr[i] = read.nextInt();
		}

		Node r = GenericTreeConstruction(arr);
		GenericTree gt = new GenericTree(r);
		
		for (int x : gt) {//Syntatical depends on iterable
			System.out.println(x);
		}

		// Iterator<Integer> g = gt.iterator();
		// while (g.hasNext()) {
		// System.out.println(g.next());
		// }
	}

}
