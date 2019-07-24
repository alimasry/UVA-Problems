#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
 
#define endl "\n"
 
const ll INF = 1e15;
const int MOD = 1e9 + 7;
const double EPS = 1e-10;
const double PI = acos(-1.0);

const int N = 35;
const int MAX = N * 100;

string s;
char o[N];
set<ll> ans;
int n, a[N], vis[N][MAX * 2][N], vid;

void solve(int i, int sum, int p) {
    if (i == n) {
        ans.insert(sum);
        return;
    }
    
    if (vis[i][sum + MAX][p] == vid) return;
    vis[i][sum + MAX][p] = vid;

    if (p)
        solve(i, sum, p - 1);

    if (o[i] == '+') {
        if (p & 1)
            solve(i + 1, sum - a[i], p);
        else 
            solve(i + 1, sum + a[i], p);
    } else {
        if (p & 1)
            solve(i + 1, sum + a[i], p + 1);
        else
            solve(i + 1, sum - a[i], p + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    while (getline(cin, s)) {
        if (s.empty()) continue;
        ++vid;
        n = 0;
        int cur = 0;
        for (char c : s) {
            if (c == ' ') {
                if (cur) 
                    a[n++] = cur;
                cur = 0;
            } else if (isdigit(c)) {
                if (cur == 0 && c == '0')
                    a[n++] = 0;
                cur = cur * 10 + (c - '0');
            } else
                o[n] = c;
        }
        a[n++] = cur;

        o[0] = '+';
        solve(0, 0, 0);
        cout << ans.size() << endl;
        ans.clear();
    }
}
