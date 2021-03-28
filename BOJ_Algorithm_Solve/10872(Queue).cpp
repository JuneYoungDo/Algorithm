#include<iostream>
#include<queue>
using namespace std;

int main()
{
	int n;
	int mul = 1;
	cin >> n;
	queue<int> q;

	for (int i = 1; i < n + 1; i++)
	{
		q.push(i);
	}
	while (!q.empty())
	{
		mul = mul * q.front();
		q.pop();
	}

	cout << mul << endl;

	return 0;
}