#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;

int row, col;
char building_map[N][N];
bool visited_cell[N][N];

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

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << building_map[i][j];
        }
        cout << endl;
    }

    return 0; 
}