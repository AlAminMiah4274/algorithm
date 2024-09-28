#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;

int row, col;
char maze[N][N];
bool visited_node[N][N];
int shortest_path_parent[N][N];
vector<pair<int, int>> cell_index = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};



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


void bfs(int src_i, int src_j)
{
    queue<pair<int, int>> ad_list_queue;
    ad_list_queue.push({src_i, src_j});

    visited_node[src_i][src_j] = true;

    while (!ad_list_queue.empty())
    {
        pair<int, int> parent_node = ad_list_queue.front();
        ad_list_queue.pop();

        for (int i = 0; i < 4; i++)
        {

            int child_i = src_i + cell_index[i].first;
            int child_j = src_j + cell_index[i].second;

            if(valid(child_i, child_j) && !visited_node[child_i][child_j])
            {
                ad_list_queue.push({child_i, child_j});
                visited_node[child_i][child_j] = true;
                shortest_path_parent[child_i][child_j] = parent_node.first;
            }
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
            cin >> maze[i][j];
        }
    }

    memset(visited_node, false, sizeof(visited_node));
    memset(shortest_path_parent, -1, sizeof(shortest_path_parent));

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (!visited_node[i][j] && maze[i][j] == 'D')
            {
                bfs(i, j);
            }
        }
    }

    // int x = location;
    // vector<int> shortest_path;

    // while (x != -1)
    // {
    //     // cout << x << " ";
    //     shortest_path.push_back(x);
    //     x = shortest_path_parent[x];
    // }

    // reverse(shortest_path.begin(), shortest_path.end());

    // for (int path : shortest_path)
    // {
    //     cout << path << " ";
    // }

    return 0;
}