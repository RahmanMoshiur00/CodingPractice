#include <bits/stdc++.h>
using namespace std;

int LCSubStr(string X, string Y, int m, int n)
{
	int LCSuff[m + 1][n + 1];
	int result = 0; // To store length of the

	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (i == 0 || j == 0)
				LCSuff[i][j] = 0;

			else if (X[i - 1] == Y[j - 1]) {
				LCSuff[i][j] = LCSuff[i - 1][j - 1] + 1;
				result = max(result, LCSuff[i][j]);
			}
			else
				LCSuff[i][j] = 0;
		}
	}
	return result;
}

int main()
{
    int t, n, m;
    cin >> t;
    string X, Y;
    while(t--){
        cin >> X >> Y;
        n = X.size();
        m = Y.size();
        cout << n+m- (2* LCSubStr(X, Y, X.size(), Y.size())) << endl;
    }



	return 0;
}

