#include<iostream>
#define endl '\n'
#define max 1000001
using namespace std;

int arr[max];
int N;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	arr[1] = 0;
	for (int i = 2; i < max; i++)
	{
		arr[i] = arr[i - 1] + 1;
		if (i % 2 == 0 && arr[i] > arr[i / 2] + 1)
			arr[i] = arr[i / 2] + 1;
		if (i % 3 == 0 && arr[i] > arr[i / 3] + 1)
			arr[i] = arr[i / 3] + 1;
	}

	cout << arr[N] << endl;

	return 0;
}