#include<iostream>
#include<stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	int result;
	cin >> n >> result;

	stack<int> s;

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		s.push(x);
	}
	int answer = 0;
	while (!s.empty())
	{
		answer += result / s.top();
		result = result % s.top();
		s.pop();
	}
	cout << answer << '\n';

	return 0;
}