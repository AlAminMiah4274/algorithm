/*
Given a 2D grid consists of 0s (land) and 1s (water).
An island is a maximal 4-directionally connected group of 0s and a closed island
is an island totally (all left, top, right, bottom) surrounded by 1s.

Return the number of closed islands.


Example 1:
Input: grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
Output: 2
Explanation:
Islands in gray are closed because they are completely surrounded by water (group of 1s).

Example 2:
Input: grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
Output: 1

Example 3:
Input: grid = [[1,1,1,1,1,1,1],
               [1,0,0,0,0,0,1],
               [1,0,1,1,1,0,1],
               [1,0,1,0,1,0,1],
               [1,0,1,1,1,0,1],
               [1,0,0,0,0,0,1],
               [1,1,1,1,1,1,1]]
Output: 2


Constraints:

1 <= grid.length, grid[0].length <= 100
0 <= grid[i][j] <=1
*/

/*
class Solution {
public:

    bool visited_node[105][105];
    vector<pair<int, int>> cell_index = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    int m, n;
    bool flag;


    bool valid(int i, int j)
    {
        if (i < 0 || i >= m || j < 0 || j >= n)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    void dfs(int src_i, int src_j, vector<vector<int>>& grid)
    {
        visited_node[src_i][src_j] = true;

        if (src_i == 0 || src_i == m - 1 || src_j == 0 || src_j == n - 1 ) flag = false;

        for (int i = 0; i < 4; i++)
        {
            int child_i = src_i + cell_index[i].first;
            int child_j = src_j + cell_index[i].second;

            if (valid(child_i, child_j) && !visited_node[child_i][child_j] && grid[child_i][child_j] == 0)
            {
                dfs(child_i, child_j, grid);
            }
        }
    }

    int closedIsland(vector<vector<int>>& grid) {

        memset(visited_node, false, sizeof(visited_node));
        m = grid.size();
        n = grid[0].size();
        int closed_island = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!visited_node[i][j] && grid[i][j] == 0)
                {
                    flag = true;
                    dfs(i, j, grid);
                    if (flag) closed_island++;
                }
            }
        }

        return closed_island;
    }
};
*/