// UVa 677
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define endl '\n'

const ll INF = 1e10;
const int MOD = 1e9 + 7;
const double EPS = 1e-7;
const double PI = acos(-1.0);

ll v, n;

struct Matrix {
    ll a[15][15];
    Matrix() {
        for (int i = 0; i < v; ++i) {
            for (int j = 0; j < v; ++j) {
                a[i][j] = 0;
            }
        }
    }
    ll* operator[](int index) { return a[index]; }
    Matrix operator*(Matrix b) {
        Matrix c;
        for (int i = 0; i < v; ++i) {
            for (int k = 0; k < v; ++k) {
                for (int j = 0; j < v; ++j) {
                    c.a[i][j] |= a[i][k] & b.a[k][j];
                }
            }
        }
        return c;
    }
};

Matrix a;
bool vis[15];
vector<int> nxt[15][15];
set<vector<int>> ans;

void solve(int idx, int num, vector<int> cur) {
    if (num == n) {
        ans.insert(cur);
        return;
    }
    if (idx == v) {
        return;
    }
    vis[idx] = true;
    for (int i : nxt[idx][num]) {
        if (!vis[i]) {
            vector<int> tmp = cur;
            tmp.push_back(i);
            solve(i, num + 1, tmp);
        }
    }
    vis[idx] = false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    ll c = 0;
    while (cin >> v >> n) {
        if (c == -9999)
            cout << endl;
        for (int i = 0; i < v; ++i) {
            for (int j = 0; j < v; ++j) {
                cin >> a[i][j];
            }
        }
        Matrix b = a;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < v; ++j) {
                for (int k = 0; k < v; ++k) {
                    if (a[j][k]) {
                        nxt[j][i].push_back(k);
                        nxt[k][i].push_back(j);
                    }
                }
            }
            b = b * a;
        }
        solve(0, 0, {0});
        if (ans.empty()) {
            cout << "no walk of length " << n << endl;
        }
        else {
            for (auto& i : ans) {
                cout << "(";
                for (int j = 0; j < (int) i.size(); ++j) {
                    if (j) cout << ',';
                    cout << i[j] + 1;
                }
                cout << ")" << endl;
            }
        }

        for (int i = 0; i < v; ++i) {
            for (int j = 0; j < n; ++j) {
                nxt[i][j].clear();
            }
        }
        ans.clear();
        cin >> c;
    }
}
