/*
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
You may assume all four edges of the grid are all surrounded by water.



Example 1:
Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1

Example 2:
Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3


Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.
*/

/*
class Solution {
public:

    bool visited_node[300][300];
    vector<pair<int, int>> cell_index = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    int m, n;


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

    void dfs(int src_i, int src_j, vector<vector<char>>& grid)
    {
        visited_node[src_i][src_j] = true;

        for (int i = 0; i < 4; i++)
        {
            int child_i = src_i + cell_index[i].first;
            int child_j = src_j + cell_index[i].second;

            if (valid(child_i, child_j) && !visited_node[child_i][child_j] && grid[child_i][child_j] == '1')
            {
                dfs(child_i, child_j, grid);
            }
        }
    }


    int numIslands(vector<vector<char>>& grid) {

        memset(visited_node, false, sizeof(visited_node));

        m = grid.size();
        n = grid[0].size();
        int island_number = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!visited_node[i][j] && grid[i][j] == '1')
                {
                    island_number++;
                    dfs(i, j, grid);
                }
            }
        }

        return island_number;
    }
};
*/