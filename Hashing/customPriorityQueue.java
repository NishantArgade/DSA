import java.io.*;
import java.util.*;

class customPriorityQueue {

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

	public static class students implements Comparable<students> {
		int roll;
		int hight;
		int weight;

		students(int roll, int hight, int weight) {
			this.roll = roll;
			this.hight = hight;
			this.weight = weight;
		}

		public int compareTo(students o) {
			return this.roll - o.roll;
		}

		public String toString() {
			return roll + "," + hight + "," + weight;
		}
	}

	public static class sortAccorHight implements Comparator<students> {

		public int compare(students o1, students o2) {
			return o1.hight - o2.hight;
		}
	}

	public static class sortAccorweight implements Comparator<students> {

		public int compare(students o1, students o2) {
			return o1.weight - o2.weight;
		}
	}

	public static class Custom_Priority_Queue<T> {

		ArrayList<T> data;
		Comparator com;

		Custom_Priority_Queue(int arr[]) {
			for (int x : arr) {
				add(x);
			}
			for (int i = data.size() / 2 - 1; i >= 0; i--) {
				downHipify(i);
			}
		}

		Custom_Priority_Queue() {
			data = new ArrayList<>();
			this.com = null;
		}

		Custom_Priority_Queue(Comparator com) {
			data = new ArrayList<>();
			this.com = com;
		}

		// T.C - O(logn)
		void add(T val) {
			data.add(val);
			upHipify(data.size()-1);
		}

		// T.C - O(logn)
		T remove() {
			if (data.size() == 0) {
				System.out.println("Underflow");
				return null;
			} else {

				swap(0, data.size() - 1);
				T val = data.get(data.size() - 1);
				data.remove(data.get(data.size() - 1));
				downHipify(0);
				return val;
			}
		}

		// T.C - O(1)
		T peek() {
			if (data.size() == 0) {
				System.out.println("Underflow");
				return null;
			} else
				return data.get(0);
		}

		int size() {
			return data.size();
		}

		private boolean isSmaller(int ci, int pi) {

			if (com == null) {
				Comparable a = (Comparable) data.get(ci);
				Comparable b = (Comparable) data.get(pi);
				if (a.compareTo(b) < 0)
					return true;
				else
					return false;
			} else {
				T a = data.get(ci);
				T b = data.get(pi);
				if (com.compare(a, b) < 0)
					return true;
				else
					return false;

			}
		}

		void upHipify(int ci) {
			if (ci == 0)
				return;

			int pi = (ci - 1) / 2;

			if (isSmaller(ci, pi)) {
				swap(pi, ci);
				upHipify(pi);
			}
		}

		void downHipify(int pi) {

			int lci = 2 * pi + 1;
			int rci = 2 * pi + 2;

			int min = pi;

			if (lci < data.size() && isSmaller(lci, min)) {
				min = lci;
			}
			if (rci < data.size() && isSmaller(rci, min)) {
				min = rci;
			}
			if (min != pi) {
				swap(pi, min);
				downHipify(min);
			}

		}

		void swap(int pi, int ci) {
			T pidata = data.get(pi);
			T cidata = data.get(ci);
			data.set(pi, cidata);
			data.set(ci, pidata);
		}

	}

	public static void display(Custom_Priority_Queue<students> pq) {
		while (pq.size() > 0) {
			System.out.println(pq.peek());
			pq.remove();
		}
	}

	public static void main(String[] args) {
		Scanner read = io();

		Custom_Priority_Queue<Integer> pq = new Custom_Priority_Queue();

		display(pq);
	}
}