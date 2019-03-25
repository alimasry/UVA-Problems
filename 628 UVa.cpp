// UVa 628
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

ll n, m;
string a[105];

void solve(int idx, const string& pat, string cur = "") {
    if (idx == (int) pat.size()) {
        cout << cur << endl;
        return;
    }
    if (pat[idx] == '0') {
        for (int i = 0; i < 10; ++i) {
            solve(idx + 1, pat, cur + char(i + '0'));
        }
    }
    else {
        for (int i = 0; i < n; ++i) {
            solve(idx + 1, pat, cur + a[i]);
        }
    }
} 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    while (cin >> n) {
        cout << "--" << endl;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        cin >> m;
        for (int i = 0; i < m; ++i) {
            string b; cin >> b;
            solve(0, b);
        }
    }
}
