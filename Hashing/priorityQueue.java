import java.io.*;
import java.util.*;

class priorityQueue {

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

	public static class MedianPQ {
		PriorityQueue<Integer> left;
		PriorityQueue<Integer> right;

		MedianPQ() {
			left = new PriorityQueue<>(Collections.reverseOrder());// maxPriorityQueue
			right = new PriorityQueue<>();// minPriorityQueue
		}

		void add(int val) {
			if (right.size() > 0 && val > right.peek())
				right.add(val);
			else
				left.add(val);

			if (left.size() - right.size() >= 2) {
				right.add(left.remove());
			}
			if (right.size() - left.size() >= 2) {
				left.add(right.remove());
			}
		}

		int remove() {
			int rv = -1;
			if (size() == 0) {
				System.out.println("Underflow");
				return -1;
			} else if (left.size() >= right.size()) {
				rv = left.remove();
			} else {
				rv = right.remove();
			}
			if (left.size() - right.size() >= 2) {
				right.add(left.remove());
			}
			if (right.size() - left.size() >= 2) {
				left.add(right.remove());
			}
			return rv;
		}

		int peek() {
			if (size() == 0) {
				System.out.println("Underflow");
				return -1;
			} else if (left.size() >= right.size()) {
				return left.peek();
			} else
				return right.peek();
		}

		int size() {
			return left.size() + right.size();
		}
	}

	public static void main(String[] args) {
		Scanner read = io();
		// by default get highest priority to the min value
		// int n;
		// n = read.nextInt();
		// int arr[] = new int[n];
		// for (int i = 0; i < n; i++) {
		// arr[i] = read.nextInt();
		// }
		MedianPQ mpq = new MedianPQ();
		mpq.add(10);
		mpq.add(20);
		mpq.add(40);
		mpq.add(50);
		mpq.add(70);
		mpq.add(50);
		// mpq.remove();
		
		
		System.out.println(mpq.peek());
		System.out.println(mpq.size());

	}
}
