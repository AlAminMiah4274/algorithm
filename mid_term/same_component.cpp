#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;


char component[N][N];
bool visited_node[N][N];
int row, col;
vector<pair<int, int>> cell_index = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};


bool valid(int i, int j)
{
    if (i < 0 || i >= row || j < 0 || j >= col || component[i][j] == '-')
    {
        return false;
    }
    else 
    {
        return true;
    }
}


void dfs(int src_i, int src_j)
{
    visited_node[src_i][src_j] = true;

    for (int i = 0; i < 4; i++)
    {
        int child_i = src_i + cell_index[i].first;
        int child_j = src_j + cell_index[i].second;

        if (valid(child_i, child_j) && !visited_node[child_i][child_j])
        {
            dfs(child_i, child_j);
        }
    }
}


int main()
{
    cin >> row >> col;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> component[i][j];
        }
    }

    int s_i, s_j;
    cin >> s_i >> s_j;
    int d_i, d_j;
    cin >> d_i >> d_j;

    memset(visited_node, false, sizeof(visited_node));
    dfs(s_i, s_j);

    if (visited_node[d_i][d_j])
    {
        cout << "YES" << endl;
    }
    else 
    {
        cout << "NO" << endl;
    }

    return 0;
}