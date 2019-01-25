// 543 UVa
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

const ll N = 1000005;
const ll INF = 1e9;
const int MOD = 1e9 + 7;
const double EPS = 1e-7;
const double PI = acos(-1.0);

ll n;
bool notPrime[N];
void sieve() {
    notPrime[0] = notPrime[1] = true;
    for(int i = 2; i < N / i; i++)
        if(!notPrime[i])
            for(int j = i * i; j < N; j += i)
                notPrime[j] = true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    sieve();
    while(cin >> n && n) {
        for(int i = 0; i < n; i++)
            if(!notPrime[i] && !notPrime[n - i]) {
                cout << n << " = " << i << " + " << n - i << endl;
                break;
            }
    }
}


