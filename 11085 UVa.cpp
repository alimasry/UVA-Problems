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

ll q[10];
bool vis[10][10];

bool valid(int row, int col) {
    for (int i = 0; i < 8; ++i) {
        if (vis[row][i] || vis[i][col])
            return false;
        if (row + i < 8) {
            if (col + i < 8 && vis[row + i][col + i])
                return false;
            if (col - i >= 0 && vis[row + i][col - i])
                return false;
        }
        if (row - i >= 0) {
            if (col + i < 8 && vis[row - i][col + i])
                return false;
            if (col - i >= 0 && vis[row - i][col - i])
                return false;
        }
    }
    return true;
}

ll solve(int col) {
    if (col == 8) {
        return 0;
    }
    ll ret = INF;
    for (int row = 0; row < 8; ++row) {
        if (valid(row, col)) {
            vis[row][col] = true;
            ret = min(ret, solve(col + 1) + (row != q[col]));
            vis[row][col] = false;
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int c = 1;
    while (cin >> q[0]) {
        q[0]--;
        for (int i = 1; i < 8; ++i) {
            cin >> q[i];
            q[i]--;
        }
        cout << "Case " << c++ << ": " << solve(0) << endl;
    }
}
