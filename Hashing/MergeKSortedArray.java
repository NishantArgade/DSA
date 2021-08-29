import java.io.*;
import java.util.*;

class MergeKSortedArray {

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

	public static class Pair implements Comparable<Pair> {
		int ai;
		int di;
		int data;

		Pair(int ai, int di, int data) {
			this.ai = ai;
			this.di = di;
			this.data = data;
		}

		public int compareTo(Pair o) {
			return this.data - o.data;
		}
	}

	public static ArrayList<Integer> MergeKSortedArray(ArrayList<ArrayList<Integer>> al) {
		ArrayList<Integer> mergeList = new ArrayList<>();
		PriorityQueue<Pair> pq = new PriorityQueue<>();
		int i = 0;
		for (ArrayList<Integer> alist : al) {
			pq.add(new Pair(i++, 0, alist.get(0)));
		}

		while (pq.size() > 0) {
			Pair p = pq.remove();
			mergeList.add(p.data);
			p.di++;
			if(p.di<al.get(p.ai).size())
			pq.add(new Pair(p.ai,p.di,al.get(p.ai).get(p.di)));
		}
		return mergeList;
	}

	public static void main(String[] args) {
		Scanner read = io();
		// ArrayList<ArrayList<Integer>> al = new ArrayList<>();
	
		// ArrayList<Integer> a1 = new ArrayList<>();
		// a1.add(1);
		// a1.add(3);
		// a1.add(4);
		// a1.add(8);
	
		// ArrayList<Integer> a2 = new ArrayList<>();
		// a2.add(2);
		// a2.add(9);
		// a2.add(10);
	
		// ArrayList<Integer> a3 = new ArrayList<>();
		// a3.add(5);
		// a3.add(11);
		// a3.add(12);
		
		// ArrayList<Integer> a4 = new ArrayList<>();
		// a4.add(6);
		// a4.add(7);

		// al.add(a1);
		// al.add(a2);
		// al.add(a3);
		// al.add(a4);
	
		// ArrayList<Integer> ans= MergeKSortedArray(al);
		// System.out.println(ans);
	}
}