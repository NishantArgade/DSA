
import java.io.*;
import java.util.*;

class CustomHashMap {

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

	public static class Hashmap<K, V> {

		
		private class Node {
			K key;
			V value;

			Node(K key, V value) {
				this.key = key;
				this.value = value;
			}
		}
		
		private LinkedList<Node> buckets[];
		private int size;// n
		
		Hashmap() {
			initializeBucket(6);
			size = 0;
		}
		
		private void initializeBucket(int N) {
			buckets = new LinkedList[N];
			for (int i = 0; i < N; i++) {
				buckets[i] = new LinkedList<>();
			}
		}

		private int HashFun(K key) {
			int hc = key.hashCode();
			return Math.abs(hc) % buckets.length;

		}

		private int getIndexWithinLinkedList(K key, int bi) {
			int idx = 0;
			for (Node nod : buckets[bi]) {
				if (nod.key.equals(key)) {

					return idx;
				} else
					idx++;
			}
			return -1;
		}

		private void hashReset() {

			LinkedList<Node>[] ohm = buckets;

			initializeBucket(2 * ohm.length);
			for (int i = 0; i < ohm.length; i++) {
				for (Node nod : ohm[i])
					put(nod.key, nod.value);
			}
		}

		public void put(K key, V value) {
			int bi = HashFun(key);

			int di = getIndexWithinLinkedList(key, bi);

			if (di != -1) {

				buckets[bi].get(di).value = value;
			} else {
				buckets[bi].add(new Node(key, value));
				size++;

			}

			float lamda = (float) (size / buckets.length);//n/N Loading factor
			if (lamda > 5.0) {
				hashReset();
			}
		}

		public V get(K key) throws Exception {

			int bi = HashFun(key);
			int di = getIndexWithinLinkedList(key, bi);

			if (di != -1) {

				return buckets[bi].get(di).value;
			} else {
				return null;
			}

		}

		public V remove(K key) throws Exception {

			int bi = HashFun(key);
			int di = getIndexWithinLinkedList(key, bi);

			if (di != -1) {
				size--;
				return buckets[bi].remove(di).value;
			} else {
				return null;
			}

		}

		public boolean containsKey(K key) {
			int bi = HashFun(key);

			int di = getIndexWithinLinkedList(key, bi);

			if (di != -1) {

				return true;
			} else {
				return false;
			}

		}

		public ArrayList<K> keySet() {

			ArrayList<K> kset = new ArrayList<>();

			for (int i = 0; i < buckets.length; i++) {
				for (Node nod : buckets[i]) {
					kset.add(nod.key);
				}
			}
			return kset;
		}

		public int size() {
			return size;
		}

	}

	public static void main(String[] args) throws Exception {
		Scanner read = io();

		Hashmap<Integer, Integer> hm = new Hashmap<>();
		hm.put(2, 50);
		hm.put(5, 80);
		hm.put(1, 60);
		hm.put(1, 60);
		hm.put(1, 60);
		hm.put(6, 90);
		hm.put(1, 60);
		hm.put(1, 60);
		hm.put(1, 60);
		hm.put(1, 60);
		hm.put(1, 60);
		hm.put(7, 90);
		hm.remove(5);
		System.out.println(hm.get(1));
		System.out.println(hm.get(2));
		System.out.println(hm.get(7));
		System.out.println(hm.size());
		System.out.println(hm.containsKey(8));
		System.out.println(hm.keySet());
	}
}