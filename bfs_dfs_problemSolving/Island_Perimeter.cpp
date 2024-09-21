/*
You are given row x col grid representing a map where
grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.

Grid cells are connected horizontally/vertically (not diagonally).
The grid is completely surrounded by water, and there is exactly
one island (i.e., one or more connected land cells).

The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island.
One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100.
Determine the perimeter of the island.



Example 1:
Input: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
Output: 16
Explanation: The perimeter is the 16 yellow stripes in the image above.

Example 2:
Input: grid = [[1]]
Output: 4

Example 3:
Input: grid = [[1,0]]
Output: 4


Constraints:

row == grid.length
col == grid[i].length
1 <= row, col <= 100
grid[i][j] is 0 or 1.
There is exactly one island in grid.
*/

/*
class Solution {
public:

    bool visited_node[105][105];
    int ans;
    vector<pair<int, int>> cell_index = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    int n, m;

    bool valid(int i, int j)
    {
        if (i < 0 || i >= n || j < 0 || j >= m)
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

        for (int i = 0; i < 4; i++)
        {
            int child_i = src_i + cell_index[i].first;
            int child_j = src_j + cell_index[i].second;

            if (valid(child_i, child_j))
            {
                if (grid[child_i][child_j] == 0)
                {
                    ans++;
                }
            }
            else
            {
                ans++;
            }

            if (valid(child_i, child_j) && !visited_node[child_i][child_j] && grid[child_i][child_j] == 1)
            {
                dfs(child_i, child_j, grid);
            }
        }
    }

    int islandPerimeter(vector<vector<int>>& grid) {

        memset(visited_node, false, sizeof(visited_node));
        n = grid.size();
        m = grid[0].size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!visited_node[i][j] && grid[i][j] == 1)
                {
                    dfs(i, j, grid);
                }
            }
        }

        return ans;
    }
};
*/