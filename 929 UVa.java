import java.util.*;

class edge {
    public int x, y, cost;

    public edge(int x, int y, int cost) {
        this.x = x;
        this.y = y;
        this.cost = cost;
    }
};

class edgeComparator implements Comparator<edge> {
    @Override
    public int compare(edge o1, edge o2) {
        if (o1.cost < o2.cost) return -1;
        if (o1.cost > o2.cost) return 1;
        return 0;
    }
};

public class Main {

    private static Scanner scn = new Scanner(System.in);

    private static final int N = 1005;
    private static final int INF = (int) 2e9;

    private static int n, m;
    private static int[][] grid = new int[N][N];
    private static int[][] dist = new int[N][N];

    private static final int[] dx = {-1, 0, 0, 1};
    private static final int[] dy = {0, -1, 1, 0};

    private static void dijkstra(int srcx, int srcy) {
        PriorityQueue<edge> min = new PriorityQueue<>(n * m, new edgeComparator());
        min.add(new edge(srcx, srcy, grid[srcx][srcy]));
        init();
        dist[srcx][srcy] = grid[srcx][srcy];
        while (!min.isEmpty()) {
            edge u = min.remove();
            int x = u.x, y = u.y, cost = u.cost;

            if (dist[x][y] < cost) continue;

            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (valid(nx, ny) && dist[x][y] + grid[nx][ny] < dist[nx][ny]) {
                    dist[nx][ny] = dist[x][y] + grid[nx][ny];
                    min.add(new edge(nx, ny, dist[nx][ny]));
                }
            }
        }
    }

    private static void init() {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                dist[i][j] = INF;
            }
        }
    }

    private static boolean valid(int nx, int ny) {
        return nx >= 0 && nx < n && ny >= 0 && ny < m;
    }

    static public void main(String[] args) throws InterruptedException {
        int t = scn.nextInt();

        for (int test = 0; test < t; ++test) {
            n = scn.nextInt();
            m = scn.nextInt();

            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    grid[i][j] = scn.nextInt();
                }
            }

            dijkstra(0, 0);
            System.out.println(dist[n - 1][m - 1]);
        }

    }
}

