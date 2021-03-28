#include<iostream>
#include<vector>
#include<algorithm>
#define endl '\n'
using namespace std;

int N, M;
vector<int> v;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	vector<int>::iterator iter;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int tmp;
		cin >> tmp;
		iter = lower_bound(v.begin(), v.end(), tmp);
		int idx = iter - v.begin();
		if (iter == v.end())
			cout << 0 << ' ';
		else
		{
			if (v[idx] == tmp)
				cout << 1 << ' ';
			else
				cout << 0 << ' ';
		}
	}
	cout << endl;

	return 0;
}