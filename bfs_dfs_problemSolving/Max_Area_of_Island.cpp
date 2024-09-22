/*
You are given an m x n binary matrix grid. An island is a group of 1's (representing land)
connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

The area of an island is the number of cells with a value 1 in the island.

Return the maximum area of an island in grid. If there is no island, return 0.



Example 1:
Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],
[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
Output: 6
Explanation: The answer is not 11, because the island must be connected 4-directionally.


Example 2:
Input: grid = [[0,0,0,0,0,0,0,0]]
Output: 0


Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 50
grid[i][j] is either 0 or 1.
*/

/*
class Solution {
public:

    int m, n;
    bool visited_node[55][55];
    vector<pair<int, int>> cell_index = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};


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

    int dfs(int src_i, int src_j, vector<vector<int>>& grid)
    {
        visited_node[src_i][src_j] = true;
        int island_area = 0;

        for (int i = 0; i < 4; i++)
        {
            int child_i = src_i + cell_index[i].first;
            int child_j = src_j + cell_index[i].second;

            if (valid(child_i, child_j) && !visited_node[child_i][child_j] && grid[child_i][child_j] == 1)
            {
                int area = dfs(child_i, child_j, grid);
                island_area += area;
            }
        }

        return island_area + 1;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {

        memset(visited_node, false, sizeof(visited_node));

        m = grid.size();
        n = grid[0].size();
        vector<int> island_area;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!visited_node[i][j] && grid[i][j] == 1)
                {
                    int area_num = dfs(i, j, grid);
                    island_area.push_back(area_num);
                }
            }
        }

        sort(island_area.begin(), island_area.end(), greater<int>());

        if (island_area.empty())
        {
            return 0;
        }
        else
        {
            return island_area[0];
        }
    }
};
*/