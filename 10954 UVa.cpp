// 10954 UVa

#include <bits/stdc++.h>

using namespace std;

int n, k;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    while(true)
    {
        cin >> n;

        if(n == 0) return 0;

        priority_queue<int> pq;

        for(int i = 0; i < n; i++)
        {
            cin >> k;
            pq.push((k*(-1)));
        }

        int sum = 0;
        int temp;
        while(pq.size() > 1)
        {
            temp = pq.top();
            pq.pop();
            temp += pq.top();
            pq.pop();
            pq.push(temp);
            sum+=temp;
        }
        cout << sum*(-1) << endl;
    }
}
