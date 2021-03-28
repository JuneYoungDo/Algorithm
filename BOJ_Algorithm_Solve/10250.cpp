#include<iostream>
using namespace std;

int main()
{
	int num;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		int H, W, N;
		cin >> H >> W >> N;

		if (N % H != 0)
		{
			if (N / H + 1 < 10)
			{
				cout << N % H << '0' << N / H + 1 << endl;
			}
			else
			{
				cout << N % H << N / H + 1 << endl;
			}
		}
		else if (N % H == 0)
		{
			if (N / H < 10)
			{
				cout << H << '0' << N / H << endl;
			}
			else
			{
				cout << H << N / H << endl;
			}
		}
	}

	return 0;
}