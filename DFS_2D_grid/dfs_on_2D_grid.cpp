#include <bits/stdc++.h>
using namespace std;

char grid[20][20];
bool visited_cell[20][20];
vector<pair<int, int>> cell_index = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int row, col;

bool valid(int i, int j)
{
    if (i < 0 || i >= row || j < 0 || j >= col)
    {
        return false;
    }
    else 
    {
        return true;
    }
}

void dfs(int src_i, int src_j) // complexity: O(row * col)/O(n*m) ---> O(V) 
{
    cout << src_i << " " << src_j << endl;
    visited_cell[src_i][src_j] = true;

    for (int i = 0; i < 4; i++)
    {
        int child_i = src_i + cell_index[i].first;
        int child_j = src_j + cell_index[i].second;

        // cout << child_i << " " << child_j << endl;

        if (valid(child_i, child_j) == true && visited_cell[child_i][child_j] == false)
        {
            dfs(child_i, child_j);
        }
    }
}

int main()
{

    // to avoid run time error
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // int row, col;
    cin >> row >> col;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> grid[i][j];
        }
    }

    // for (int i = 0; i < row; i++)
    // {
    //     for (int j = 0; j < col; j++)
    //     {
    //         cout << arr[i][j];
    //     }
    //     cout << endl;
    // }

    int source_1, source_2;
    cin >> source_1 >> source_2;

    memset(visited_cell, false, sizeof(visited_cell));

    dfs(source_1, source_2);

    return 0;
}