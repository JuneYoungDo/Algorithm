#include<iostream>
#include<string>
using namespace std;

struct sta
{
	int arr[10000];
	int index;
	sta()
	{
		arr[10000] = { 0, };
		index = 0;
	}

	void push(int x)
	{
		arr[index] = x;
		index++;
	}
	int pop()
	{
		if (index == 0)
			return -1;
		int ans = 0;
		ans = arr[index - 1];
		index--;
		return ans;
	}
	int size()
	{
		return index;
	}
	int empty()
	{
		if (index == 0)
			return 1;
		else
			return 0;
	}
	int top()
	{
		int ans = arr[index - 1];
		if (index == 0)
			return -1;
		else
			return ans;
	}
};

int main()
{
	string s;

	sta a;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		if (s == "push")
		{
			int x;
			cin >> x;
			a.push(x);
		}
		else if (s == "pop")
		{
			cout << a.pop() << '\n';
		}
		else if (s == "size")
		{
			cout << a.size() << '\n';
		}
		else if (s == "empty")
		{
			cout << a.empty() << '\n';
		}
		else if (s == "top")
		{
			cout << a.top() << '\n';
		}
	}
	return 0;
}