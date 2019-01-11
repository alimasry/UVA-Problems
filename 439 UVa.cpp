#include <bits/stdc++.h>
using namespace std;

int di[] = {-1, -1, 1, 1, -2, -2, 2, 2};
int dj[] = {2, -2, 2, -2, 1, -1, -1, 1};

string u, v;

bool valid(int x, int y) { return x < 8 && x >= 0 && y <= 8 && y > 0; }

int main()
{
    while(cin >> u >> v)
    {
        int n = 0;
        queue<pair<int, int>> Q;
        pair<int, int> parent, dest;
        map<pair<int, int>, int> lvl;
        map<pair<int, int>, bool> vis;
        parent = {u[0] - 'a', u[1] - '0'};
        dest = {v[0] - 'a', v[1] - '0'};
        Q.push(parent);
        vis[parent] = true;
        while(!Q.empty())
        {
            auto q = Q.front();
            if(q == dest)
            {
                break;
            }
            Q.pop();
            for(int i = 0; i < 8; i++)
            {
                if(valid(q.first + di[i], q.second + dj[i]) && !vis[{q.first + di[i], q.second + dj[i]}])
                {
                    vis[{q.first + di[i], q.second + dj[i]}] = true;
                    Q.push({q.first + di[i], q.second + dj[i]});
                    lvl[{q.first + di[i], q.second + dj[i]}] = lvl[q] + 1;
                }
            }
        }
        cout << "To get from " << u << " to " << v <<  " takes " << lvl[dest] << " knight moves." << endl;
    }
}

