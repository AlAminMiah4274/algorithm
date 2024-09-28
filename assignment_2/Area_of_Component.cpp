#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;

int row, col;
char component[N][N];
bool visited_cell[N][N];
vector<pair<int, int>> cell_index = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};


bool valid(int i, int j)
{
    if (i < 0 || i >= row || j < 0 || j >= col || component[i][j] == '#')
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

    int count_area = 0;
    for (int i = 0; i < 4; i++)
    {
        int child_i = src_i + cell_index[i].first;
        int child_j = src_j + cell_index[i].second;

        if (valid(child_i, child_j) == true && visited_cell[child_i][child_j] == false)
        {
            int area = dfs(child_i, child_j);
            count_area += area;
        }
    }
    
    return count_area + 1;
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

    memset(visited_cell, false, sizeof(visited_cell));

    // dfs(1, 1);
    
    vector<int> component_area_count;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (component[i][j] == '.' && visited_cell[i][j] == false)
            {
                int area = dfs(i, j);
                component_area_count.push_back(area);
            }
        }
    }
    
    sort(component_area_count.begin(), component_area_count.end());
    if (component_area_count.empty())
    {
        cout << 0 << endl;
    }
    else 
    {
        cout << component_area_count[0] << endl;
    }
    
    

    return 0; 
}