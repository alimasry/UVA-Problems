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

const int N = 30005;
const int c[] = {1, 5, 10, 25, 50};

ll n, dp[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    while (cin >> n) {
        memset(dp, 0, sizeof(dp));

        dp[0] = 1;
        for (int coin = 0; coin < 5; ++coin)
            for (int sum = c[coin]; sum <= n; ++sum)
                dp[sum] += dp[sum - c[coin]];

        ll m = dp[n];
        if (m == 1) 
            cout << "There is only 1 way to produce " << n << " cents change." << endl;
        else
            cout << "There are " << m << " ways to produce " << n << " cents change." << endl;
    }
}
