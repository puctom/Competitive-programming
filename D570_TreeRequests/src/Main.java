import java.io.*;
import java.util.*;
import java.util.Scanner;

public class Main {
    static class FastReader {
        final private int BUFFER_SIZE = 1 << 16;
        private DataInputStream din;
        private byte[] buffer;
        private int bufferPointer, bytesRead;

        public FastReader() {
            din = new DataInputStream(System.in);
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }

        public FastReader(String file_name) throws IOException {
            din = new DataInputStream(
                    new FileInputStream(file_name));
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }

        public String nextLine() throws IOException {
            byte[] buf = new byte[500005]; // line length
            int cnt = 0, c;
            while ((c = read()) != -1) {
                if (c == '\n') {
                    if (cnt != 0) {
                        break;
                    } else {
                        continue;
                    }
                }
                buf[cnt++] = (byte) c;
            }
            return new String(buf, 0, cnt);
        }

        public int nextInt() throws IOException {
            int ret = 0;
            byte c = read();
            while (c <= ' ') {
                c = read();
            }
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');

            if (neg)
                return -ret;
            return ret;
        }

        public long nextLong() throws IOException {
            long ret = 0;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');
            if (neg)
                return -ret;
            return ret;
        }

        public double nextDouble() throws IOException {
            double ret = 0, div = 1;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();

            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');

            if (c == '.') {
                while ((c = read()) >= '0' && c <= '9') {
                    ret += (c - '0') / (div *= 10);
                }
            }

            if (neg)
                return -ret;
            return ret;
        }

        private void fillBuffer() throws IOException {
            bytesRead = din.read(buffer, bufferPointer = 0,
                    BUFFER_SIZE);
            if (bytesRead == -1)
                buffer[0] = -1;
        }

        private byte read() throws IOException {
            if (bufferPointer == bytesRead)
                fillBuffer();
            return buffer[bufferPointer++];
        }

        public void close() throws IOException {
            if (din == null)
                return;
            din.close();
        }
    }

    public static Node[] nodesCatalogue;
    public static int[] letters = new int[30];

    public static void main(String[] args) throws IOException {
        OutputStream output =
                new BufferedOutputStream(System.out);
        initializeLetters();

        FastReader scanner = new FastReader();
        int nodes = scanner.nextInt();
        //System.out.println(nodes);
        int queries = scanner.nextInt();
        nodesCatalogue = new Node[nodes + 3];
        for (int i = 0; i <= nodes; i++)
            nodesCatalogue[i] = new Node(i);
        Graph G = new Graph(nodes);

        if (nodes > 1) {
            for (int i = 2; i <= nodes; i++) {
                int a = scanner.nextInt();

                G.g.get(a).add(Main.nodesCatalogue[i]);
                Main.nodesCatalogue[i].parent = Main.nodesCatalogue[a];
                Main.nodesCatalogue[a].children++;
                //G.addEdge(a, i);
            }
            String s = scanner.nextLine();
            s = s.trim();
            // System.out.println("|" + s + "|");
            //  System.out.println(s);
            for (int i = 0; i < s.length(); i++) {
                //  System.out.println((i+1));
                nodesCatalogue[i + 1].setLetter(s.charAt(i));
            }
        }
        else {
            //String s = scanner.nextLine();
            String s = scanner.nextLine();
            s = scanner.nextLine();
            s = s.trim();
            // System.out.println("|" + s + "|");
            //  System.out.println(s);
            for (int i = 0; i < s.length(); i++) {
                //  System.out.println((i+1));
                nodesCatalogue[i + 1].setLetter(s.charAt(i));
            }
        }
        // scanner.nextLine();



        //  System.out.println(G.toString());
        //G.doDFS();
        G.dfsUtil(Main.nodesCatalogue[1], 1 );
        G.calculatePostorder();
       // System.out.println(G.toString());
        for (int i = 0; i < queries; i++) {
            int v = scanner.nextInt();
            int height = scanner.nextInt();
            //   System.out.println("Query " + i + " v: "+ v + ", height: "  + height);
            int l = 0, r = G.h.get(height).size();
            while (l < r) {
                int mid = (l + r) / 2;
                //    System.out.println("We have l = "+ l+", r = " + r+", mid: "+mid);
                if (G.h.get(height).get(mid).preOrder < nodesCatalogue[v].preOrder)
                    l = mid + 1;
                else
                    r = mid;

            }
            int left = (l + r - 2) / 2;
            //  System.out.println("left " + left);

            l = 0;
            r = G.h.get(height).size();
            while (l < r) {
                int mid = (l + r) / 2;
                //    System.out.println("We have l = "+ l+", r = " + r+", mid: "+mid);
                if (G.h.get(height).get(mid).preOrder < nodesCatalogue[v].postOrder)
                    l = mid + 1;
                else
                    r = mid;
            }
            int right = (l + r - 2) / 2;
            //  System.out.println("right " + right);
            int oddEncoding = G.h.get(height).get(left).getBitmask() ^
                    G.h.get(height).get(right).getBitmask();
            if (oddEncoding - (oddEncoding & (-oddEncoding)) == 0) {
                output.write(("Yes\n").getBytes());
                //System.out.println("Yes");
            } else {
                output.write(("No\n").getBytes());
            }

        }
        output.flush();


    }

    private static void initializeLetters() {
        for (int i = 0; i <= 26; i++)
            letters[i] = 1 << i;
    }
}
class PairNodeHeight {
    public Node node;
    public int height;

    public PairNodeHeight(Node node, int height) {
        this.node = node;
        this.height = height;
    }

}
class Graph {
    private Stack<PairNodeHeight> dfsStack = new Stack<>();
    private int height = 0;
    public int totalPostOrder = 0;
    private int n;
    public ArrayList<ArrayList<Node>> g = new ArrayList<>();
    public ArrayList<ArrayList<PairNodeBitmask>> h = new ArrayList<>();
    private int count = 0;
    public Stack<Node> noChildren = new Stack<>();
    public ArrayList<Node> noChildrenList = new ArrayList<>();

    public Graph(int n) {
        this.n = n;
        for (int i = 0; i <= n; i++)
            g.add(new ArrayList<>());
        for (int i = 0; i <= n; i++) {
            h.add(new ArrayList<>());
            h.get(i).add(new PairNodeBitmask(0, 0));
        }
    }

   /* public void addEdge(int a, int b) {
        g.get(a).add(Main.nodesCatalogue[b]);
        g.get(b).add(Main.nodesCatalogue[a]);
    }*/

   /* public void doDFS() {
        boolean[] visited = new boolean[n + 3];

        dfsUtil(Main.nodesCatalogue[1]);
    }

   public void dfsUtil(Node v) {

        v.preOrder = (++count);
        height++;
       // System.out.println("We are in node " + v.getNumber() + " height: " + height);
        this.h.get(height).add(new PairNodeBitmask
                (v.preOrder, h.get(height).get(h.get(height).size() - 1).bitmask
                        ^ Main.letters[v.letter - 'a']));
        for (Node node : g.get(v.number)) {
            dfsUtil(node);

        }
        v.postOrder = (++count);
        height--;
    } */

    public void dfsUtil(Node u, int heightStart) {
        dfsStack.push(new PairNodeHeight(u, heightStart));
        int enteredCount = 0;
        int exitedCount = 0;

        while(dfsStack.isEmpty() == false) {
            Node v = dfsStack.peek().node;
            int height = dfsStack.peek().height;
            dfsStack.pop();
            if(v.children ==0 )
                noChildrenList.add(v);
            enteredCount++;
            // System.out.println("We are in node " + v.getNumber());

            v.setPreOrder(enteredCount);
            v.height = height;

            for (Node node : g.get(v.getNumber())) {
                dfsStack.push(new PairNodeHeight(node, height+1));
                //   dfsUtil(node, height + 1);

            }
            //exitedCount++;
            //v.setPostOrder(enteredCount+1+(n-exitedCount)*2);

        }
    }

    public void calculatePostorder() {
        /*for(int i=1;i<=n;i++) {
            System.out.println("Vertex" + i + " has that many children: "+Main.nodesCatalogue[i].children);
                 if(Main.nodesCatalogue[i].children == 0)
                 noChildren.push(Main.nodesCatalogue[i]);
        }*/
      //  System.out.println(noChildrenList.toString());
        Collections.reverse(noChildrenList);
        for(Node node: noChildrenList)
            noChildren.push(node);
        while(!noChildren.isEmpty()) {
            Node v = noChildren.peek();
            noChildren.pop();

         //   System.out.println("We start considering vertex: " + v.number + ", now preorder: " + v.preOrder);
            v.preOrder += (totalPostOrder-(v.subtreeSize-1));
            this.h.get(v.height).add(new PairNodeBitmask
                    (v.preOrder, h.get(v.height).get(h.get(v.height).size() - 1).getBitmask()
                            ^ Main.letters[v.getLetter() - 'a']));
            v.postOrder = v.preOrder+2*(v.subtreeSize-1)+1;
            totalPostOrder ++;
            if(v.number == 1)
                break;
            v.parent.subtreeSize += v.subtreeSize;
            v.parent.children--;
            if(v.parent.children == 0)
                noChildren.push(v.parent);
//            System.out.println("Vertex "+ v.number + " finished. " +
//                    "New preorder: " + v.preOrder+
//                    ". New postorder: " + v.postOrder+ ". It's subtree size: " + v.subtreeSize +
//                    " which was also added to node: " + v.parent.number);
        }
        Main.nodesCatalogue[1].preOrder = 1;
        Main.nodesCatalogue[1].postOrder = 2*n;

    }


    public String toString() {
        String res="";
        for(int i=1;i<=n;i++) {
            res+="\nNode: " + i + ", letter: "+ Main.nodesCatalogue[i].getLetter();
            res+=" preorder: " + Main.nodesCatalogue[i].getPreOrder();
            res+=", postorder: " + Main.nodesCatalogue[i].getPostOrder();
        }

        res+="\n";
        for(int i=0;i<h.size();i++) {
            res+="H["+i+"]: "+h.get(i)+"\n";
        }

        return res;
    }


    public ArrayList<ArrayList<Node>> getG() {
        return g;
    }

    public ArrayList<ArrayList<PairNodeBitmask>> getH() {
        return h;
    }


}

class PairNodeBitmask {
    public int preOrder;
    public int bitmask;

    public PairNodeBitmask(int preOrder, int bitmask) {
        this.preOrder = preOrder;
        this.bitmask = bitmask;
    }
    public String toString() {
        String res="";
        res="<" + preOrder + ", " + bitmask+">";
        return res;
    }

    public int getPreOrder() {
        return preOrder;
    }


    public int getBitmask() {
        return bitmask;
    }


}


class Node {
    public int height;
    public Node parent;
    public int subtreeSize = 1;
    public int children;
    public int number;
    public char letter;
    public int preOrder;
    public int postOrder;

    public String toString() {
        return String.valueOf(this.number);
    }

    public Node(int number) {
        this.number = number;
    }

    public int getNumber() {
        return number;
    }


    public char getLetter() {
        return letter;
    }

    public void setLetter(char letter) {
        this.letter = letter;
    }

    public int getPreOrder() {
        return preOrder;
    }

    public void setPreOrder(int preOrder) {
        this.preOrder = preOrder;
    }

    public int getPostOrder() {
        return postOrder;
    }

    public void setPostOrder(int postOrder) {
        this.postOrder = postOrder;
    }
}