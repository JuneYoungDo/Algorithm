#include<iostream>
#include<string>
using namespace std;

int main()
{
	int num1 = 0;
	int num2 = 0;
	int max = 0;
	int count = 0;
	string str;
	cin >> str;
	int num = str.length();
	//	int* arr = new int(str.length());
	int arr[26] = { 0, };

	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < num; j++)
		{
			if ((int)str[j] == 65 + i || (int)str[j] == 97 + i)
			{
				num1++;
			}
		}
		arr[i] = num1;
		num1 = 0;
	}
	for (int i = 0; i < 26; i++)
	{
		if (max < arr[i])
		{
			max = arr[i];
			num2 = i + 65;
		}
	}
	for (int i = 0; i < 26; i++)
	{
		if (arr[i] == max)
		{
			count++;
		}
	}

	if (count >= 2)
	{
		cout << "?" << endl;
	}
	else
	{
		cout << (char)num2 << endl;
	}
	return 0;
}