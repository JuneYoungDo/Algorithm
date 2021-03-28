#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define endl '\n';

int N, C;
vector<int> v;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int left, right;
	int mid;
	int ans = 0;

	cin >> N >> C;
	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}
	// 정렬
	sort(v.begin(), v.end());

	// 최소거리 1, 최대거리 right
	left = 1;
	right = v[N - 1] - v[0];

	// 이분탐색
	while (left <= right)
	{
		mid = (left + right) / 2;
		int cnt = 1;	// 사용 공유기 갯수
		int start = v[0];	// 시작점

		for (int i = 1; i < N; i++)
		{
			if (v[i] - start >= mid)	// 시작점에서 거리가 mid 거리 보다 큰가
			{
				cnt++;		// 크다면 공유기 설치
				start = v[i];		// 공유기 설치 시점에서 부터 다시 거리 측정
			}
		}

		//	주어진 공유기 수보다 많이 사용했다면
		if (cnt >= C)
		{
			ans = mid;
			left = mid + 1;
			//	거리를 늘린다
		}
		else
			right = mid - 1;	// 거기를 좁힌다
	}

	cout << ans << endl;


	return 0;
}