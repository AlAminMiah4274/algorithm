#include <bits/stdc++.h>
using namespace std;

int row, col;
int chessboard[105][105];
bool visited_cell[105][105];
int level[105][105];
vector<pair<int, int>> cell_index = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

bool valid(int i, int j)
{
    if ((i < 0 || i >= row) || (j < 0 || j >= col))
    {
        return false;
    }
    else
    {
        return true;
    }
}

void bfs(int src_i, int src_j) 
{
    queue<pair<int, int>> bfs_grid_queue;
    bfs_grid_queue.push({src_i, src_j});

    visited_cell[src_i][src_j] = true;
    level[src_i][src_j] = 0;

    while (!bfs_grid_queue.empty())
    {
        pair<int, int> parent_cell = bfs_grid_queue.front();
        int parent_cell_i = parent_cell.first;
        int parent_cell_j = parent_cell.second;
        bfs_grid_queue.pop();

        // cout << parent_cell_i << " " << parent_cell_j << endl;

        for (int i = 0; i < 8; i++)
        {
            int child_i = parent_cell_i + cell_index[i].first;
            int child_j = parent_cell_j + cell_index[i].second;

            if (valid(child_i, child_j) == true && visited_cell[child_i][child_j] == false)
            {
                bfs_grid_queue.push({child_i, child_j});
                visited_cell[child_i][child_j] = true;
                level[child_i][child_j] = level[parent_cell_i][parent_cell_j] + 1;
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    
    while (t--)
    {
        cin >> row >> col;

        int k_i, k_j;
        cin >> k_i >> k_j;
    
        int q_i, q_j;
        cin >> q_i >> q_j;
        

        memset(visited_cell, false, sizeof(visited_cell));
        memset(level, -1, sizeof(level));

        bfs(k_i, k_j);

        cout << level[q_i][q_j] << endl;
    }

    return 0;
}