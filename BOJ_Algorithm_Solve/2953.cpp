#include<iostream>
using namespace std;

int main()
{

	int arr1[4];

	cin >> arr1[0] >> arr1[1] >> arr1[2] >> arr1[3];

	int total1 = 0;

	for (int i = 0; i < 4; i++)
	{
		total1 = total1 + arr1[i];
	}

	int arr2[4];

	cin >> arr2[0] >> arr2[1] >> arr2[2] >> arr2[3];

	int total2 = 0;

	for (int i = 0; i < 4; i++)
	{
		total2 = total2 + arr2[i];
	}

	int arr3[4];

	cin >> arr3[0] >> arr3[1] >> arr3[2] >> arr3[3];

	int total3 = 0;

	for (int i = 0; i < 4; i++)
	{
		total3 = total3 + arr3[i];
	}

	int arr4[4];

	cin >> arr4[0] >> arr4[1] >> arr4[2] >> arr4[3];

	int total4 = 0;

	for (int i = 0; i < 4; i++)
	{
		total4 = total4 + arr4[i];
	}

	int arr5[4];

	cin >> arr5[0] >> arr5[1] >> arr5[2] >> arr5[3];

	int total5 = 0;

	for (int i = 0; i < 4; i++)
	{
		total5 = total5 + arr5[i];
	}

	int arrT[] = { total1,total2,total3,total4,total5 };
	int max = arrT[0];

	for (int i = 0; i < 5; i++)
	{
		if (arrT[i] > max)
		{
			max = arrT[i];
		}
	}
	if (max == arrT[0])
	{
		cout << "1 ";
	}
	else if (max == arrT[1])
	{
		cout << "2 ";
	}
	else if (max == arrT[2])
	{
		cout << "3 ";
	}
	else if (max == arrT[3])
	{
		cout << "4 ";
	}
	else
	{
		cout << "5 ";
	}
	cout << max << endl;




	return 0;
}