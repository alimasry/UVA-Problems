#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define endl "\n"

const ll INF = 1e15;
const int MOD = 1e9 + 7;
const double EPS = 1e-7;
const double PI = acos(-1.0);

const int M = 15;
const int N = 105;

pll doctor[M], tree[N][M];
ll t, n, m, k, d, p[2 * N], b[N];

ll root(ll a) {
    if (p[a] == a) return a;
    return p[a] = root(p[a]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin >> t;

    while (t--) {
        cin >> n >> m >> k >> d;

        for (int i = 0; i < n + m; ++i) 
            p[i] = i;

        for (int i = 0; i < m; ++i)
            cin >> doctor[i].first >> doctor[i].second;

        for (int i = 0; i < n; ++i) {
            cin >> b[i];
            for (int j = 0; j < b[i]; ++j) {
                cin >> tree[i][j].first >> tree[i][j].second;
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < b[i]; ++j) {
                for (int ii = i + 1; ii < n; ++ii) {
                    for (int jj = 0; jj < b[ii]; ++jj) {
                        if ((tree[i][j].first - tree[ii][jj].first) * (tree[i][j].first - tree[ii][jj].first) +
                                (tree[i][j].second- tree[ii][jj].second) * (tree[i][j].second - tree[ii][jj].second) <= k * k) {
                            p[root(i + m)] = root(ii + m);
                        }
                    }
                }

                for (int ii = 0; ii < m; ++ii) {
                    if ((tree[i][j].first - doctor[ii].first) * (tree[i][j].first - doctor[ii].first) + 
                            (tree[i][j].second - doctor[ii].second) * (tree[i][j].second - doctor[ii].second) <= d * d) {
                        p[root(i + m)] = root(ii);
                    }
                }
            }
        }

        bool ok = false;

        for (int i = 0; i < m; ++i) {
            if (root(i) == root(m)) {
                ok = true;
                break;
            }
        }

        cout << (ok ? "Tree can be saved :)" : "Tree can't be saved :(") << endl;
    }
}
