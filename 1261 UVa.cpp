#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define endl '\n'

const ll INF = 1e15;
const int MOD = 1e9 + 7;
const double EPS = 1e-7;
const double PI = acos(-1.0);

const int N = 30;

int t;

int solve(string s) {
    int n = (int) s.size();
    int ret = n;
    string w = "";
    for (int i = 0; i < n - 1; ++i) {
        string tmp = string(1, s[i]);
        if (s[i] == s[i + 1]) {
            while (i < n - 1 && s[i] == s[i + 1]) ++i, tmp += s[i];
            string rest = "";
            for (int j = i + 1; j < n; ++j) rest += s[j];
            ret = min(ret, solve(w + rest));
        }
        w += tmp;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin >> t;
    while (t--) {
        string s; cin >> s;
        cout << (solve(s) == 0 ? 1 : 0) << endl;
    }
}

