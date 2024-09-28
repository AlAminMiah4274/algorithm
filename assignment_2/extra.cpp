#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
bool vis[N][N];
int dx[4] = {-1, 0, 1, 0}; // row er move
int dy[4] = {0, 1, 0, -1}; // col er move
int shortest_path_parent[N][N];

int n, m;

char graph[N][N];

bool valid(int ci, int cj)
{

    if (ci >= 0 && ci < n && cj >= 0 && cj < m)
    {
        return true;
    }
    else
        return false;
}

void bfs(int si, int sj)
{
    vis[si][sj] = true;

    queue<pair<int, int>> q;
    q.push({si, sj});

    while (!q.empty())
    {
        pair<int, int> node = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ci = node.first + dx[i];
            int cj = node.second + dy[i];

            if (valid(ci, cj) && !vis[ci][cj])
            {
                vis[ci][cj] = true;
                q.push({ci, cj});
                shortest_path_parent[ci][cj] = (node.first, node.second);
            }
        }
    }
}

int main()
{

    cin >> n >> m;

    memset(vis, false, sizeof(vis));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> graph[i][j];
        }
    }
    
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && graph[i][j] == 'A')
            {
                bfs(i, j);
            }
        }
    }
    
    pair<int ,int> stp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && graph[i][j] == 'B')
            {
                // bfs(i, j);
                stp = make_pair(i, j);
            }
        }
    }

    // int sti = par[{2, 2}].first, stj = par[{2, 2}].second;
    int sti = shortest_path_parent[stp.first][stp.second], stj = shortest_path_parent[stp.first][stp.second];

    while (graph[sti][stj] != 'A')
    {

        graph[sti][stj] = 'X';

        // sti = par[{sti, stj}].first;  // sti is changing
        // stj = par[{sti, stj}].second; // we are using sti here again.
        // // which were causing the problem

        // int Nsti = par[{sti, stj}].first;
        int Nsti = shortest_path_parent[sti][stj];
        // stj = par[{sti, stj}].second;
        stj = shortest_path_parent[sti][stj];

        // this time it wont cause any problem

        sti = Nsti;
        // now we will update the value of sti
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << graph[i][j];
        }
        cout << endl;
    }

    cout << endl;
}