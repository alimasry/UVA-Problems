#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define endl "\n"

const ll INF = 1e15;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double PI = acos(-1.0);

const int N = 1005;

ll t, n, m;

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

struct edge {
    ll x, y, cost;
    bool operator< (const edge& other) const {
        return cost > other.cost; 
    }
};

ll dist[N][N], grid[N][N];

bool valid(int x, int y) {
    return x < n && x >= 0 && y < m && y >= 0;
}

void dijkstra(int srcx, int srcy) {
    memset(dist, 0x7F, sizeof(dist));
    dist[srcx][srcy] = grid[srcx][srcy];
    priority_queue<edge> minn;
    minn.push({srcx, srcy, grid[srcx][srcy]});
    while (!minn.empty()) {
        edge r = minn.top();
        minn.pop();
        ll x = r.x, y = r.y, cost = r.cost;

        if (dist[x][y] < cost) continue;

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (valid(nx, ny) && dist[nx][ny] > dist[x][y] + grid[nx][ny]) {
                dist[nx][ny] = dist[x][y] + grid[nx][ny];
                minn.push({nx, ny, dist[nx][ny]});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin >> t;

    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> grid[i][j];
            }
        }
        dijkstra(0, 0);
        cout << dist[n - 1][m - 1] << endl;
    }
}
