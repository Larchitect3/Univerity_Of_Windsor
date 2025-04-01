//Node in the huffman tree. Note that compareTo is defined as the comparison
	// for the frequency of the node
	public class Node implements Comparable<Node> {
		public final char ch;
		public final int freq;
		public final Node left, right;

		Node(char ch, int freq, Node left, Node right) {
			this.ch = ch;
			this.freq = freq;
			this.left = left;
			this.right = right;
		}

		public boolean isLeaf() {
			return (left == null) && (right == null);
		}

		public int compareTo(Node that) {
			return this.freq - that.freq;
		}
	}

