#include<iostream>
#include<stack>
using namespace std;

int main()
{
	int num;
	int num2;
	int total = 0;
	int size = 0;
	stack<int> mon;
	cin >> num;

	for (int i = 0; i < num; i++)
	{
		cin >> num2;
		if (num2 == 0)
		{
			mon.pop();
		}
		else
		{
			mon.push(num2);
		}
	}
	while (!mon.empty())
	{
		total = total + mon.top();
		mon.pop();
	}

	cout << total << endl;
	return 0;
}