// 10789 UVa

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<bool> isPrime(2005, true);

void sieve(int n)
{
    isPrime[0] = isPrime[1] = 0;

    for (ll i = 2; i*i <= n; ++i) {
        if (isPrime[i]) {
            for (int j = i * 2; j <= n; j += i)
                isPrime[j] = 0;
        }
    }

}

int n, cnt;
string s;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    sieve(2002);

    cin >> n;

    while(n --)
    {
        cin >> s;

        map<char, int> mp;

        for(char c:s)
            mp[c]++;

        auto it = mp.begin();
        queue<char> q;

        cout << "Case " << ++cnt << ": ";

        for(; it != mp.end(); ++it)
        {
            if(isPrime[it->second])
                q.push(it->first);
        }
        if(q.empty()) cout << "empty";
        else
            while(!q.empty())
            {
                cout << q.front();
                q.pop();
            }
        cout << endl;
    }

    return 0;
}
