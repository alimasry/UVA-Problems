// 167 UVa
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

bool vis[8][8];
ll k, a[8][8];

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

ll solve(int row) {
    if (row == 8) 
        return 0;
    ll ret = -INF;
    for (int col = 0; col < 8; ++col) {
        if (valid(row, col)) {
            vis[row][col] = true;
            ret = max(ret, solve(row + 1) + a[row][col]) ;
            vis[row][col] = false;
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin >> k;
    while (k--) {
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                cin >> a[i][j];
            }
        }
        cout << setw(5) << right << solve(0) << endl;
    }
}
