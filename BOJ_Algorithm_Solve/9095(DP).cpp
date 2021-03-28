#include<iostream>
#define endl '\n'
using namespace std;

int T, n;
int arr[12];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;
	for (int i = 4; i < 12; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
	}
	cin >> T;
	while (T--)
	{
		cin >> n;
		cout << arr[n] << endl;
	}

	return 0;
}