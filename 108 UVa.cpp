// 108 UVa
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

const ll N = 105;
const ll INF = 1e9;
const int MOD = 1e9 + 7;
const double EPS = 1e-7;
const double PI = acos(-1.0);

ll n, maxx;
ll grid[N][N];

ll getSum(int i, int j, int x, int y) {
    return grid[x][y] + grid[i - 1][j - 1] - grid[x][j - 1] - grid[i - 1][y];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    while(scanf("%lld", &n) != EOF)
    {
        maxx = LLONG_MIN;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++) {
                scanf("%lld", &grid[i][j]);
                grid[i][j] += grid[i - 1][j];
            }

        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++) 
                grid[i][j] += grid[i][j - 1];
        
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                for(int x = i; x <= n; x++)
                    for(int y = j; y <= n; y++)
                        maxx = max(maxx, getSum(i, j, x, y));

        printf("%lld\n", maxx);
    }
}
