// UVa 352
#include <bits/stdc++.h>
using namespace std;
char image[30][30];
int vis[30][30];
int dimension, cnt, cases;

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool valid(int x, int y) { return x >= 0 && x < dimension && y >= 0 && y < dimension && image[x][y] == '1' && vis[x][y] != cases;}

void DFS(int x, int y)
{
    vis[x][y] = cases;
    for(int i = 0; i < 8; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(valid(nx,ny))
            DFS(nx, ny);
    }
}
int main()
{
    while(cin >> dimension)
    {
        cases ++;
        cnt = 0;
        for(int i = 0; i < dimension; i++)
            for(int j = 0; j < dimension; j++)
                scanf(" %c", &image[i][j]);
        for(int i = 0; i < dimension; i++)
        {
            for(int j = 0; j < dimension; j++)
            {
                if(image[i][j] == '1' && vis[i][j] != cases)
                {
                    cnt++;
                    DFS(i, j);
                }
            }
        }
        printf("Image number %d contains %d war eagles.\n", cases, cnt);
    }
}

