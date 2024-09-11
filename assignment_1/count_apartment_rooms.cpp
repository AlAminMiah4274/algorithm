#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;

int row, col;
char building_map[N][N];
bool visited_cell[N][N];
vector<pair<int, int>> cell_index = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};


bool valid(int i, int j)
{
    if (i < 0 || i >= row || j < 0 || j >= col || building_map[i][j] == '#')
    {
        return false;
    }
    else 
    {
        return true;
    }
}


int dfs(int src_i, int src_j)
{
    // cout << src_i << " " << src_j << endl;
    visited_cell[src_i][src_j] = true;

    int count_rooms = 0;
    for (int i = 0; i < 4; i++)
    {
        int child_i = src_i + cell_index[i].first;
        int child_j = src_j + cell_index[i].second;

        if (valid(child_i, child_j) == true && visited_cell[child_i][child_j] == false)
        {
            int room = dfs(child_i, child_j);
            count_rooms += room;
        }
    }
    
    return count_rooms + 1;
}


int main()
{
    cin >> row >> col;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> building_map[i][j];
        }
    }

    memset(visited_cell, false, sizeof(visited_cell));

    // dfs(1, 1);
    
    vector<int> apt_rooms_count;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (building_map[i][j] == '.' && visited_cell[i][j] == false)
            {
                int room = dfs(i, j);
                apt_rooms_count.push_back(room);
            }
        }
    }
    
    sort(apt_rooms_count.begin(), apt_rooms_count.end());
    if (apt_rooms_count.empty())
    {
        cout << 0 << endl;
    }
    else 
    {
        for (int room : apt_rooms_count)
        {
            cout << room << " ";
        }
        cout << endl;
    }
    
    

    return 0; 
}