#include<iostream>
#include<queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	queue<int> q;

	while (1)
	{
		int a, b;
		cin >> a >> b;

		if (a == b && a == 0)
		{
			break;
		}
		q.push(a + b);
	}
	while (!q.empty())
	{
		cout << q.front() << endl;
		q.pop();
	}


	return 0;
}