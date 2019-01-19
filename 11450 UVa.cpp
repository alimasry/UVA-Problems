// 11450 UVa
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

const ll N = 25;
const ll INF = 1e9;
const int MOD = 1e9 + 7;
const double EPS = 1e-7;
const double PI = acos(-1.0);

ll n, m, c, k[N];
ll prices[N][N], dp[N][205];

ll solve(ll i, ll j)
{
    if(j > m)
        return -INF;
    if(i == c)
        return j;

    ll& ret = dp[i][j];

    if(~ret)
        return ret;
         
    ret = -INF;
    for(int x = 0; x < k[i]; x++)
        ret = max(ret, solve(i + 1, j + prices[i][x]));
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    scanf("%lld", &n);
    while(n--) {
        memset(dp, -1, sizeof(dp));
        scanf("%lld %lld", &m, &c);
        for(int i = 0; i < c; i++) {
            scanf("%lld", &k[i]);
            for(int j = 0; j < k[i]; j++)
                scanf("%lld", &prices[i][j]);
        }
        if(solve(0, 0) != -INF)
            printf("%lld\n", solve(0, 0));
        else 
            printf("no solution\n");
    }
}