#include<iostream>
#include<vector>
#include<algorithm>
#define endl '\n'
using namespace std;

int n;
int arr[13];
int Lotto[6];

void printLotto(int index, int size)
{
	if (size == 6)
	{
		for (int i = 0; i < 6; i++)
		{
			cout << Lotto[i] << ' ';
		}
		cout << endl;
		return;
	}
	for (int i = index; i < n; i++)
	{
		Lotto[size] = arr[i];
		printLotto(i + 1, size + 1);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1)
	{
		cin >> n;
		if (n == 0)
			break;

		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		printLotto(0, 0);
		cout << endl;
	}

	return 0;
}