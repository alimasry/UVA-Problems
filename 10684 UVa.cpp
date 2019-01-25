// 10684 UVa
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

const ll N = 10005;
const ll INF = 1e15;
const int MOD = 1e9 + 7;
const double EPS = 1e-7;
const double PI = acos(-1.0);

ll n, arr[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    while(cin >> n && n) {
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        ll sum = 0, maxx = -INF;
        for(int i = 0; i < n; i++) {
            sum = max(sum + arr[i], arr[i]);
            maxx = max(maxx, sum);
        }
        if(maxx > 0)
            cout << "The maximum winning streak is " << maxx  << '.' << endl;
        else 
            cout << "Losing streak." << endl;
    }
}


