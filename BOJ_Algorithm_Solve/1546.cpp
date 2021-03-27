#include<iostream>
using namespace std;

int main()
{
	int num;
	cin >> num;

	double arr[1000];
	int max = 0;
	for (int i = 0; i < num; i++)
	{
		cin >> arr[i];
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	double avg = 0;
	double avg2 = 0;
	for (int j = 0; j < num; j++)
	{
		avg += (arr[j] / max) * 100;
	}
	avg2 = avg / num;

	cout << avg2 << endl;

	return 0;
}