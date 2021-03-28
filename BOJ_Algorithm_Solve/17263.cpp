#include<iostream>
#include<algorithm>
using namespace std;
#define endl '\n';

int arr[500001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);

	cout << arr[n - 1] << endl;

	return 0;
}