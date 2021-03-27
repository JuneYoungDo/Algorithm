#include<iostream>
#include<stack>
#include<vector>
using namespace std;

#define endl '\n'

int n;
stack<int> s;
vector<char> v;
int arr[100001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		s.push(i);
		v.push_back('+');

		while (!s.empty() && s.top() == arr[cnt])
		{
			s.pop();
			v.push_back('-');
			cnt++;
		}
	}
	if (!s.empty())
		cout << "NO" << endl;
	else
	{
		for (int i = 0; i < v.size(); i++)
			cout << v[i] << endl;
	}

	return 0;
}