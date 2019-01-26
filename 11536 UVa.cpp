// 11536 UVa
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

const ll N = 1000005;
const ll INF = 1e15;
const int MOD = 1e9 + 7;
const double EPS = 1e-7;
const double PI = acos(-1.0);

ll t, n, m, k, a[N], vis[1005], cnt, c;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin >> t;
    while(t--)
    {
        c++;
        cnt = 0;
        cin >> n >> m >> k;
        fill(vis, vis + 1001, 0);
        a[0] = 1;
        a[1] = 2;
        a[2] = 3;
        for(int i = 3; i < n; i++)
            a[i] = (a[i - 1] + a[i - 2] + a[i - 3]) % m + 1;
        ll ans = INF, st = 0;
        for(int i = 0; i < n; i++) {
            if(a[i] <= k) {
                if(!vis[a[i]]) 
                    cnt++;
                vis[a[i]]++;
                if(cnt == k) {
                    int j;
                    for(j = st; j < i; j++) {
                        if(a[j] <= k && vis[a[j]] == 1)
                            break;
                        vis[a[j]]--;
                    }
                    st = j;
                    ans = min(ans, i - j + 1LL);
                }
            }
        }
        if(ans != INF)
            cout << "Case " << c << ": " << ans << endl;
        else
            cout << "Case " << c << ": sequence nai" << endl;
    }
}