#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long N, answer;
vector<int> v;

void bs(long long target, long long* arr, long long size)
{
	long long left = 0;
	long long right = size;

	while (left <= right)
	{
		long long mid = (left + right + 1) / 2;
		long long sum = 0;

		//		if (mid == 0)
		//			return;

		for (int i = 0; i < N; i++)
		{
			if (1 <= arr[i] / mid)
			{
				sum = sum + (arr[i] / mid);
			}
		}

		if (sum >= target)
		{
			v.push_back(mid);
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> answer;
	long long* arr = new long long[N];

	for (int i = 0; i < N; i++)
	{
		long long a;
		cin >> a;
		arr[i] = a;
	}

	sort(arr, arr + N);
	bs(answer, arr, arr[N - 1]);
	sort(v.begin(), v.end());

	cout << v[v.size() - 1] << '\n';

	return 0;
}