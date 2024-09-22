/*
You are given two m x n binary matrices grid1 and grid2 containing only 0's (representing water) and 1's (representing land).
An island is a group of 1's connected 4-directionally (horizontal or vertical).
Any cells outside of the grid are considered water cells.

An island in grid2 is considered a sub-island if there is an island in grid1
that contains all the cells that make up this island in grid2.

Return the number of islands in grid2 that are considered sub-islands.



Example 1:
Input: grid1 = [[1,1,1,0,0],[0,1,1,1,1],[0,0,0,0,0],[1,0,0,0,0],[1,1,0,1,1]],
grid2 = [[1,1,1,0,0],[0,0,1,1,1],[0,1,0,0,0],[1,0,1,1,0],[0,1,0,1,0]]
Output: 3
Explanation: In the picture above, the grid on the left is grid1 and the grid on the right is grid2.
The 1s colored red in grid2 are those considered to be part of a sub-island. There are three sub-islands.

Example 2:
Input: grid1 = [[1,0,1,0,1],[1,1,1,1,1],[0,0,0,0,0],[1,1,1,1,1],[1,0,1,0,1]],
grid2 = [[0,0,0,0,0],[1,1,1,1,1],[0,1,0,1,0],[0,1,0,1,0],[1,0,0,0,1]]
Output: 2
Explanation: In the picture above, the grid on the left is grid1 and the grid on the right is grid2.
The 1s colored red in grid2 are those considered to be part of a sub-island. There are two sub-islands.


Constraints:

m == grid1.length == grid2.length
n == grid1[i].length == grid2[i].length
1 <= m, n <= 500
grid1[i][j] and grid2[i][j] are either 0 or 1.
*/

/*
class Solution {
public:

    bool visited_node[500][500];
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

    void dfs(int src_i, int src_j, vector<vector<int>>& grid1, vector<vector<int>>& grid2)
    {
        visited_node[src_i][src_j] = true;


        if (grid1[src_i][src_j] == 0) flag = false;

        for (int i = 0; i < 4; i++)
        {
            int child_i = src_i + cell_index[i].first;
            int child_j = src_j + cell_index[i].second;

            if (valid(child_i, child_j) && !visited_node[child_i][child_j] && grid2[child_i][child_j] == 1)
            {
                dfs(child_i, child_j, grid1, grid2);
            }
        }
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {

        memset(visited_node, false, sizeof(visited_node));
        m = grid2.size();
        n = grid2[0].size();
        int ans = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!visited_node[i][j] && grid2[i][j] == 1)
                {
                    flag = true;
                    dfs(i, j, grid1, grid2);
                    if (flag) ans++;
                }
            }
        }

        return ans;

    }
};
*/