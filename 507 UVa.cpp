// 507 UVa
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

const ll N = 20005;
const ll INF = 1e9;
const int MOD = 1e9 + 7;
const double EPS = 1e-7;
const double PI = acos(-1.0);

ll arr[N];
ll t, n, c;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin >> t;
    while(t--)
    {
        c++;
        cin >> n;
        ll tmp = 0, l = 0, r = 0;
        ll sum = 0, maxx = 0;
        for(int i = 0; i < n - 1; i ++)
        {
            cin >> arr[i];
            sum = sum + arr[i];
            if(sum < arr[i])
            {
                tmp = i;
                sum = arr[i];
            }
            if(maxx < sum)
            {
                maxx = sum;
                l = tmp;
                r = i;
            }
            else if(maxx == sum && i - tmp > r - l)
            {
                l = tmp;
                r = i;
            }
        }
        if(maxx)
            cout << "The nicest part of route " << c << " is between stops " << l + 1 << " and " << r + 2 << endl;
        else
            cout << "Route " << c << " has no nice parts" << endl;
    }
}
