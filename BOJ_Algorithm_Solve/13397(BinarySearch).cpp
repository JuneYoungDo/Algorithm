#include <iostream>
#include <vector>
using namespace std;
int n, m;
vector <int> v;
bool check(int mid)
{
	int max_num = -1, min_num = 10001, cnt = 1;
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
		{
			min_num = v[i];
			max_num = v[i];
		}
		if (v[i] < min_num) // 최솟값 갱신
			min_num = v[i];
		if (v[i] > max_num) // 최댓값 갱신
			max_num = v[i];
		if (max_num - min_num > mid) // 구간의 점수가 넘어가면
		{
			cnt += 1; // 새로운 구간 시작
			max_num = v[i];
			min_num = v[i];
		}
	}
	if (m >= cnt)
		return true;
	else
		return false;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	v.resize(n);
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		sum += v[i];
	}
	int ans = 1987654321, mid, left = 0, right = sum;
	while (left <= right) // // 구간의 점수값 이분탐색
	{
		mid = (left + right) / 2;
		if (check(mid))
		{
			right = mid - 1;
			if (mid < ans)
				ans = mid;
		}
		else
			left = mid + 1;
	}
	cout << ans;
	return 0;
}
