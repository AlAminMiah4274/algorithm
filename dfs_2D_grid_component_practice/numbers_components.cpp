#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

vector<int> ad_list[N];
bool visited_node[N];

void dfs(int src)
{
    visited_node[src] = true;

    for (int child : ad_list[src])
    {
        if (!visited_node[child])
        {
            dfs(child);
        }
    }
}

/*
“Innallahaa Yusmiuu Mayiashaa” 

If you want something from Allah SWT, you must recite 
“innallaha yusmiu mayasha hu” 342 times daily after every salah for 20 days. 
*/

int main()
{
    int n, e;
    cin >> n >> e;

    while (e--)
    {
        int a, b;
        cin >> a >> b;

        ad_list[a].push_back(b);
        ad_list[b].push_back(a);
    }

    int component = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited_node[i])
        {
            dfs(i);
            component++;
        }
    }

    cout << component << endl;

    return 0;
}