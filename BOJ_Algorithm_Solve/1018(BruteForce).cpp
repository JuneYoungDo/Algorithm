#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int M, N;
	cin >> M >> N;

	int sub = 64;
	int cnt = 0;
	int cnt1 = 0;

	vector<vector<char>> v(M);

	for (int i = 0; i < M; i++)
	{
		string s;
		cin >> s;

		for (int j = 0; j < N; j++)
		{
			v[i].push_back(s[j]);
		}
	}

	for (int i = 0; i < M - 7; i++)
	{
		for (int j = 0; j < N - 7; j++)
		{

			if (i % 2 == 0 && j % 2 == 0)
			{
				for (int q = i; q < i + 8; q++)
				{
					for (int p = j; p < j + 8; p++)
					{
						if (q % 2 == 0 && p % 2 == 0 && v[q][p] == 'B')
						{
							cnt++;
						}
						else if (q % 2 == 0 && p % 2 == 1 && v[q][p] == 'W')
						{
							cnt++;
						}
						else if (q % 2 == 1 && p % 2 == 0 && v[q][p] == 'W')
						{
							cnt++;
						}
						else if (q % 2 == 1 && p % 2 == 1 && v[q][p] == 'B')
						{
							cnt++;
						}
					}
				}
			}
			else if (i % 2 == 0 && j % 2 == 1)
			{
				for (int q = i; q < i + 8; q++)
				{
					for (int p = j; p < j + 8; p++)
					{
						if (q % 2 == 0 && p % 2 == 0 && v[q][p] == 'W')
						{
							cnt++;
						}
						else if (q % 2 == 0 && p % 2 == 1 && v[q][p] == 'B')
						{
							cnt++;
						}
						else if (q % 2 == 1 && p % 2 == 0 && v[q][p] == 'B')
						{
							cnt++;
						}
						else if (q % 2 == 1 && p % 2 == 1 && v[q][p] == 'W')
						{
							cnt++;
						}
					}
				}
			}
			else if (i % 2 == 1 && j % 2 == 0)
			{
				for (int q = i; q < i + 8; q++)
				{
					for (int p = j; p < j + 8; p++)
					{
						if (q % 2 == 0 && p % 2 == 0 && v[q][p] == 'W')
						{
							cnt++;
						}
						else if (q % 2 == 0 && p % 2 == 1 && v[q][p] == 'B')
						{
							cnt++;
						}
						else if (q % 2 == 1 && p % 2 == 0 && v[q][p] == 'B')
						{
							cnt++;
						}
						else if (q % 2 == 1 && p % 2 == 1 && v[q][p] == 'W')
						{
							cnt++;
						}
					}
				}
			}
			else if (i % 2 == 1 && j % 2 == 1)
			{
				for (int q = i; q < i + 8; q++)
				{
					for (int p = j; p < j + 8; p++)
					{
						if (q % 2 == 0 && p % 2 == 0 && v[q][p] == 'B')
						{
							cnt++;
						}
						else if (q % 2 == 0 && p % 2 == 1 && v[q][p] == 'W')
						{
							cnt++;
						}
						else if (q % 2 == 1 && p % 2 == 0 && v[q][p] == 'W')
						{
							cnt++;
						}
						else if (q % 2 == 1 && p % 2 == 1 && v[q][p] == 'B')
						{
							cnt++;
						}
					}
				}
			}


			if (i % 2 == 0 && j % 2 == 0)
			{
				for (int q = i; q < i + 8; q++)
				{
					for (int p = j; p < j + 8; p++)
					{
						if (q % 2 == 0 && p % 2 == 0 && v[q][p] == 'W')
						{
							cnt1++;
						}
						else if (q % 2 == 0 && p % 2 == 1 && v[q][p] == 'B')
						{
							cnt1++;
						}
						else if (q % 2 == 1 && p % 2 == 0 && v[q][p] == 'B')
						{
							cnt1++;
						}
						else if (q % 2 == 1 && p % 2 == 1 && v[q][p] == 'W')
						{
							cnt1++;
						}
					}
				}
			}
			else if (i % 2 == 0 && j % 2 == 1)
			{
				for (int q = i; q < i + 8; q++)
				{
					for (int p = j; p < j + 8; p++)
					{
						if (q % 2 == 0 && p % 2 == 0 && v[q][p] == 'B')
						{
							cnt1++;
						}
						else if (q % 2 == 0 && p % 2 == 1 && v[q][p] == 'W')
						{
							cnt1++;
						}
						else if (q % 2 == 1 && p % 2 == 0 && v[q][p] == 'W')
						{
							cnt1++;
						}
						else if (q % 2 == 1 && p % 2 == 1 && v[q][p] == 'B')
						{
							cnt1++;
						}
					}
				}
			}
			else if (i % 2 == 1 && j % 2 == 0)
			{
				for (int q = i; q < i + 8; q++)
				{
					for (int p = j; p < j + 8; p++)
					{
						if (q % 2 == 0 && p % 2 == 0 && v[q][p] == 'B')
						{
							cnt1++;
						}
						else if (q % 2 == 0 && p % 2 == 1 && v[q][p] == 'W')
						{
							cnt1++;
						}
						else if (q % 2 == 1 && p % 2 == 0 && v[q][p] == 'W')
						{
							cnt1++;
						}
						else if (q % 2 == 1 && p % 2 == 1 && v[q][p] == 'B')
						{
							cnt1++;
						}
					}
				}
			}
			else if (i % 2 == 1 && j % 2 == 1)
			{
				for (int q = i; q < i + 8; q++)
				{
					for (int p = j; p < j + 8; p++)
					{
						if (q % 2 == 0 && p % 2 == 0 && v[q][p] == 'W')
						{
							cnt1++;
						}
						else if (q % 2 == 0 && p % 2 == 1 && v[q][p] == 'B')
						{
							cnt1++;
						}
						else if (q % 2 == 1 && p % 2 == 0 && v[q][p] == 'B')
						{
							cnt1++;
						}
						else if (q % 2 == 1 && p % 2 == 1 && v[q][p] == 'W')
						{
							cnt1++;
						}
					}
				}
			}

			if (cnt <= cnt1 && cnt <= sub)
			{
				sub = cnt;
				cnt = 0;
				cnt1 = 0;
			}
			else if (cnt1 <= cnt && cnt1 <= sub)
			{
				sub = cnt1;
				cnt = 0;
				cnt1 = 0;
			}
			else
			{
				cnt = 0;
				cnt1 = 0;
			}
		}
	}

	cout << sub << endl;

	return 0;
}