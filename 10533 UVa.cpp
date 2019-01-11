// 10533 UVa

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<bool> isPrime(1000003, true);

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

string s;
int t, a, b, c, arr[1000005], temp;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    sieve(1000000);

    for(int i = 2; i <= 1000000; i+=1)
    {
        arr[i] = arr[i - 1];
        if(isPrime[i])
        {
            temp = 0;
            c = i;
            while(c>0)
            {
                temp += c%10;
                c/=10;
            }

            if(isPrime[temp])
                arr[i]++;
        }
    }

    scanf("%d", &t);

    while(t--)
    {
        scanf("%d%d", &a, &b);
        int sum = 0;
        if(a > 0)
            printf("%d\n", arr[b] - arr[a - 1]);
        else printf("%d\n", arr[b]);
    }

    return 0;
}
