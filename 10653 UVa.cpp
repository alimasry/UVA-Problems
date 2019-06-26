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

const int dx[] = {-1, 0, 0, 1};
const int dy[] = {0, -1, 1, 0};

ll n, m;

struct edge {
    ll x, y, cost;
    bool operator< (const edge& other) const {
        return cost > other.cost; 
    }
};

ll dist[N][N], vis[N][N], bomb[N][N], vid;

bool valid(int x, int y) {
    return x < n && x >= 0 && y < m && y >= 0 && bomb[x][y] != vid;
}

void dijkstra(int srcx, int srcy) {
    memset(dist, 0x7F, sizeof(dist));
    dist[srcx][srcy] = 0;
    priority_queue<edge> minn;
    minn.push({srcx, srcy, 0});
    while (!minn.empty()) {
        auto u = minn.top();
        ll x = u.x, y = u.y;
        minn.pop();

        if (vis[x][y] == vid) continue;

        vis[x][y] = vid;

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (valid(nx, ny) && dist[nx][ny] > dist[x][y] + 1) {
                dist[nx][ny] = dist[x][y] + 1;
                minn.push({nx, ny, dist[nx][ny]});
            }
        }
    }
}

void clear() {
    ++vid;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    while (cin >> n >> m && (m || n)) {
        clear();
        int r; cin >> r;
        while (r--) {
            int row, c; cin >> row >> c;
            for (int i = 0; i < c; ++i) {
                int col; cin >> col;
                bomb[row][col] = vid;
            }
        }
        int srcx, srcy; cin >> srcx >> srcy;
        int desx, desy; cin >> desx >> desy;
        dijkstra(srcx, srcy);
        cout << dist[desx][desy] << endl;
    }
}
