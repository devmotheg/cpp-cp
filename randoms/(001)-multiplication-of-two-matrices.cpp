#include <bits/stdc++.h>

using namespace std;

int main()
{
	int r1, c1 = 1, r2 = -1, c2, errs = 0;

	while (c1 != r2)
	{
		if (errs > 0)
			cout << "Number of columns in matrix a must be equal to number of rows in matrix b" << endl << endl;

		for (int i = 0; i < 2; ++i)
		{
			cout << "Enter the number of rows then columns in matrix " << (i == 0 ? 'a' : 'b') << endl;
			cin >> (i == 0 ? r1 : r2) >> (i == 0 ? c1 : c2);
			cout << endl;
		}

		++errs;
	}

	int m1[r1][c1];
	int m2[r2][c2];

	for (int i = 0; i < 2; ++i)
	{
		int r = i == 0 ? r1 : r2, c = i == 0 ? c1 : c2;

		for (int j = 0; j < r; ++j)
		{
			for (int k = 0; k < c; ++k)
			{
				cout << "Fill " << (i == 0 ? 'a' : 'b') << j + 1 << k + 1 << endl;
				cin >> (i == 0 ? m1[j][k] : m2[j][k]);
			}
		}

		cout << endl;
	}

	for (int i = 0; i < 2; ++i)
	{
		cout << "This is matrix " << (i == 0 ? 'a' : 'b') << endl;

		int r = i == 0 ? r1 : r2, c = i == 0 ? c1 : c2;

		for (int j = 0; j < r; ++j)
		{
			for (int k = 0; k < c; ++k)
			{
				cout << (i == 0 ? m1[j][k] : m2[j][k]) << ' ';
			}

			cout << endl;
		}

		cout << endl;
	}

	cout << "Multiplication result is:" << endl;

	int m3[r1][c2] = { };

	for (int i = 0; i < r1; ++i)
	{
		for (int j = 0; j < c2; ++j)
		{
			int res = 0;

			// `r2` also works instead of `c2` becuase of resulting matrix dimensions
			for (int k = 0; k < c1; ++k)
			{
				res += m1[i][k] * m2[k][j];
			}

			m3[i][j] = res;
		}
	}

	for (int i = 0; i < r1; ++i)
	{
		for (int j = 0; j < c2; ++j)
		{
			cout << m3[i][j] << ' ';
		}

		cout << endl;
	}

	return 0;
}
