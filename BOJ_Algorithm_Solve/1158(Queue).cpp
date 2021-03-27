#include<iostream>
#include<queue>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	queue<int> q;

	for (int i = 1; i < n + 1; i++)
	{
		q.push(i);
	}
	cout << "<";
	while (!q.empty())
	{
		if (q.size() == 1)
		{
			cout << q.front() << ">";
			q.pop();
		}
		else
		{
			for (int i = 0; i < k - 1; i++)
			{
				q.push(q.front());
				q.pop();
			}
			cout << q.front() << ", ";
			q.pop();
		}
	}
	cout << '\n';

	return 0;
}