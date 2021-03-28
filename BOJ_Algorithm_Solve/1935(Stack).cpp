#include<iostream>
#include<string>
using namespace std;

struct stac
{
	int index;
	double arr[100];
	stac()
	{
		index = 0;
		arr[100] = { 0, };
	}
	void push(double x)
	{
		arr[index] = x;
		index++;
	}
	double pop()
	{
		double ans = arr[index - 1];
		arr[index - 1] = 0;
		index--;

		return ans;
	}
};
int main()
{
	int num;
	cin >> num;

	double a;
	double b;
	double result;

	string str;
	cin >> str;

	int arr2[26] = { 0, };

	for (int i = 0; i < num; i++)
	{
		cin >> arr2[i];
	}

	stac s;

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '*' || str[i] == '/' || str[i] == '+' || str[i] == '-')
		{
			double b = s.arr[s.index - 1];
			s.pop();
			double a = s.arr[s.index - 1];
			s.pop();
			if (str[i] == '*')
			{
				s.push(a * b);
			}
			else if (str[i] == '/')
			{
				s.push(a / b);
			}
			else if (str[i] == '+')
			{
				s.push(a + b);
			}
			else if (str[i] == '-')
			{
				s.push(a - b);
			}
		}
		else
		{
			s.push(arr2[(int)str[i] - 65]);
		}
	}
	result = s.arr[s.index - 1];

	cout.precision(2);
	cout << fixed << result << '\n';

	return 0;
}