#include <bits/stdc++.h>
using namespace std;


int main()
{
	string a, b;
	cin >> a >> b;


	int n = a.size(), m = b.size();

	int substring[n + 1][m + 1];
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			if (i == 0 ||  j == 0) substring[i][j] = 0;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
		{
			if (a[i - 1] == b[j - 1]) {
				substring[i][j] = substring[i - 1][j - 1] + 1;
			}
			else {
				substring[i][j] = 0;
			}
		}
	}


	// for (int i = 0; i <= n; i++)
	// {
	// 	for (int j = 0; j <= m; j++)
	// 	{
	// 		cout << substring[i][j] << " ";
	// 	}
	// }

	cout << substring[n][m];


	return 0;
}