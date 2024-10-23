#include <bits/stdc++.h>
using namespace std;


int main()
{
	string a, b;
	cin >> a >> b;

	int n = a.size(), m = b.size();

	int lcs[n + 1][m + 1];
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			if (i == 0 || j == 0) lcs[i][j] = 0;
		}
	}


	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (a[i - 1] == b[j - 1])
			{
				lcs[i][j] = lcs[i - 1][j - 1] + 1;

				// lcs[i][j] = ans + 1;
			}
			else
			{
				int ans1 = lcs[i - 1][j];
				int ans2 = lcs[i][j - 1];

				lcs[i][j] = max(ans1, ans2);
			}
		}
	}


	// for (int i = 0; i <= n; i++)
	// {
	// 	for (int j = 0; j <= m; j++)
	// 	{
	// 		cout << lcs[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }


	int i = n, j = m;
	string ans;

	while (i != 0 && j != 0)
	{
		if (a[i - 1] == b[j - 1])
		{
			ans += a[i - 1];
			i--;
			j--;
		}
		else
		{
			if (lcs[i][j - 1] > lcs[i - 1][j])
			{
				j--;
			}
			else
			{
				i--;
			}
		}
	}

	reverse(ans.begin(), ans.end());

	cout << ans;



	return 0;
}