import java.util.*;

class Graph_SP {
    private double[] distTo; // distTo[v] = distance of shortest path from source to v
    private Edge[] edgeTo; // edgeTo[v] = last edge on shortest path to v
    private PriorityQueue<Node> pq; // Priority queue for Dijkstra's algorithm

    public Graph_SP(Graph G, int s) {
        int V = G.V();
        distTo = new double[V];
        edgeTo = new Edge[V];
        pq = new PriorityQueue<>();

        Arrays.fill(distTo, Double.POSITIVE_INFINITY);
        distTo[s] = 0.0;
        pq.add(new Node(s, 0.0));

        while (!pq.isEmpty()) {
            int v = pq.poll().vertex;
            for (Edge e : G.adj(v)) {
                relax(e);
            }
        }
    }

    private void relax(Edge e) {
        int v = e.from(), w = e.to();
        if (distTo[w] > distTo[v] + e.weight()) {
            distTo[w] = distTo[v] + e.weight();
            edgeTo[w] = e;
            pq.add(new Node(w, distTo[w]));
        }
    }

    public double distTo(int v) {
        return distTo[v];
    }

    public boolean hasPathTo(int v) {
        return distTo[v] < Double.POSITIVE_INFINITY;
    }

    public Iterable<Edge> pathTo(int v) {
        if (!hasPathTo(v))
            return null;
        LinkedList<Edge> path = new LinkedList<>();
        for (Edge e = edgeTo[v]; e != null; e = edgeTo[e.from()]) {
            path.addFirst(e);
        }
        return path;
    }

    private static class Node implements Comparable<Node> {
        int vertex;
        double dist;

        Node(int v, double d) {
            this.vertex = v;
            this.dist = d;
        }

        @Override
        public int compareTo(Node other) {
            return Double.compare(this.dist, other.dist);
        }
    }
}

// Supporting Graph and Edge classes
class Graph {
    private final int V;
    private final List<Edge>[] adj;

    public Graph(int V) {
        this.V = V;
        adj = (List<Edge>[]) new ArrayList[V]; // Proper casting

        for (int i = 0; i < V; i++) {
            adj[i] = new ArrayList<Edge>(); // Ensure type safety
        }
    }

    public void addEdge(int v, int w, double weight) {
        Edge e = new Edge(v, w, weight);
        adj[v].add(e);
        adj[w].add(e); // Assuming an undirected graph
    }

    public int V() {
        return V;
    }

    public Iterable<Edge> adj(int v) {
        return adj[v];
    }
}

class Edge {
    private final int v, w;
    private final double weight;

    public Edge(int v, int w, double weight) {
        this.v = v;
        this.w = w;
        this.weight = weight;
    }

    public int from() {
        return v;
    }

    public int to() {
        return w;
    }

    public double weight() {
        return weight;
    }
}

public class test {
    public static void main(String[] args) {
        Graph g = new Graph(5);
        g.addEdge(0, 1, 2.5);
        g.addEdge(1, 2, 1.2);
        g.addEdge(2, 3, 0.9);
        g.addEdge(3, 4, 2.1);

        Graph_SP sp = new Graph_SP(g, 0);
        System.out.println("Distance to 4: " + sp.distTo(4));
    }
}
