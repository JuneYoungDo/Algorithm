#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

long long num;
long long answer;
vector<long long> v;

void bs(long long target, long long* arr, long long size)
{
	long long left = 0;
	long long right = size;

	while (left <= right)
	{
		long long mid = (left + right + 1) / 2;

		long long sum = 0;

		for (int i = 0; i < num; i++)
		{
			if (0 <= arr[i] - mid)
			{
				sum = sum + (arr[i] - mid);
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

	cin >> num >> answer;


	long long* arr = new long long[num];

	for (int i = 0; i < num; i++)
	{
		long long x;
		cin >> x;
		arr[i] = x;
	}
	sort(arr, arr + num);

	bs(answer, arr, arr[num - 1]);

	sort(v.begin(), v.end(), greater<long long>());

	long long result = v[0];
	cout << result << '\n';

	return 0;
}