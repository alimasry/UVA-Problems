// UVa 729
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

ll t, n, h;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin >> t;
    bool nl = false;
    while (t--) {
        if (nl)
            cout << endl;
        cin >> n >> h;
        string s(n, '0');
        for (int i = 0; i < h; ++i)
            s[i] = '1';
        sort(s.begin(), s.end());
        do {
            cout << s << endl;
        } while (next_permutation(s.begin(), s.end()));
        nl = true;
    }
}


