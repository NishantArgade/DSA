import java.io.*;
import java.util.*;

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

	public static void display(PriorityQueue<students> pq) {
		while (pq.size() > 0) {
			System.out.println(pq.peek());
			pq.remove();
		}
	}

	public static void main(String[] args) {
		Scanner read = io();
	
		PriorityQueue<students> pq = new PriorityQueue<>(new sortAccorHight());

		pq.add(new students(03, 145, 70));
		pq.add(new students(12, 165, 20));
		pq.add(new students(01, 175, 40));
		pq.add(new students(18, 150, 90));
		pq.add(new students(6, 120, 80));

		display(pq);

	}
}