#include<iostream>
using namespace std;

int main()
{
	int arr1[4], arr2[4], arr3[4];

	int total1 = 0;
	for (int i = 0; i < 4; i++)
	{
		cin >> arr1[i];
	}
	total1 = arr1[0] + arr1[1] + arr1[2] + arr1[3];

	int total2 = 0;
	for (int i = 0; i < 4; i++)
	{
		cin >> arr2[i];
	}
	total2 = arr2[0] + arr2[1] + arr2[2] + arr2[3];

	int total3 = 0;
	for (int i = 0; i < 4; i++)
	{
		cin >> arr3[i];
	}
	total3 = arr3[0] + arr3[1] + arr3[2] + arr3[3];


	switch (total1 % 5)
	{
	case 1:cout << "C" << endl;
		break;
	case 2:cout << "B" << endl;
		break;
	case 3:cout << "A" << endl;
		break;
	case 4:cout << "E" << endl;
		break;
	case 0:cout << "D" << endl;
		break;
	}

	switch (total2 % 5)
	{
	case 1:cout << "C" << endl;
		break;
	case 2:cout << "B" << endl;
		break;
	case 3:cout << "A" << endl;
		break;
	case 4:cout << "E" << endl;
		break;
	case 0:cout << "D" << endl;
		break;
	}

	switch (total3 % 5)
	{
	case 1:cout << "C" << endl;
		break;
	case 2:cout << "B" << endl;
		break;
	case 3:cout << "A" << endl;
		break;
	case 4:cout << "E" << endl;
		break;
	case 0:cout << "D" << endl;
		break;
	}

	return 0;
}