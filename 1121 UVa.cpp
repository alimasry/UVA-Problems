// 1121 UVa
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

const ll N = 100005;
const ll INF = 1e15;
const int MOD = 1e9 + 7;
const double EPS = 1e-7;
const double PI = acos(-1.0);

ll n, s, a[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    while(cin >> n >> s)
    {
        for(int i = 0; i < n; i++)
            cin >> a[i];
        ll sum = 0, maxx = INF, st = 0;
        for(int i = 0; i < n; i++)
        {
            sum += a[i];
            if(sum >= s) {
                int j;
                for(j = st; j < i; j++) {
                    if(sum - a[j] < s) break;
                    sum -= a[j];
                }
                st = j;
                maxx = min(maxx, i - j + 1ll);
            }
        }
        if(maxx == INF)
            cout << 0 << endl;
        else
            cout << maxx << endl;
    }
}