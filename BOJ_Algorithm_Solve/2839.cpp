#include<iostream>
using namespace std;

int main()
{
	int num;
	int num2 = 0;
	int ans = 0;

	while (1)
	{
		cin >> num;
		if (num >= 3 && num <= 5000)
		{
			break;
		}
	}
	for (int i = num / 5; i >= 0; i--)
	{
		if (num % 5 == 0)
		{
			ans = num / 5;
			goto answer;
		}
		else if (num % 5 == 3)
		{
			ans = (num / 5) + 1;
			goto answer;
		}
		else if ((num - 5 * i) > 0 && (num - 5 * i) % 3 == 0)
		{
			num2 = i;
			goto truble;
		}
		else if (num % 3 == 0)
		{
			ans = num / 3;
		}
		else
		{
			ans = -1;
		}
	}

	cout << ans << endl;
	return 0;

truble:
	ans = num2 + (num - (5 * num2)) / 3;
	cout << ans << endl;
	return 0;

answer:
	cout << ans << endl;
	return 0;
}