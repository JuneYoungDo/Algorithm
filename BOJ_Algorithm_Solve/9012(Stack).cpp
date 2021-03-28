#include<iostream>
#include<string>
using namespace std;

struct ps
{
	char arr[1000];
	int index;
	ps()
	{
		arr[1000] = { 0, };
		index = 0;
	}
};

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;

		ps p;

		for (int j = 0; j < s.length(); j++)
		{
			if (s[j] == '(')
			{
				p.arr[p.index] = '(';
				p.index++;
			}
			else
			{
				if (p.index == 0)
				{
					p.index = 1;
					break;
				}
				else {
					p.arr[p.index - 1] = 0;
					p.index--;
				}
			}
		}
		if (p.index != 0)
		{
			cout << "NO" << '\n';
		}
		else
		{
			cout << "YES" << '\n';
		}
	}
	return 0;
}