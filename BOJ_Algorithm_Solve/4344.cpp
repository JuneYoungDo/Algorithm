#include<iostream>
using namespace std;

int main()
{
	int set;
	cin >> set;
	int p = 0;

	double brr[1000];

	while (p < set)
	{
		int num;
		int arr[1000];
		cin >> num;
		double avg = 0;
		double n = 0;
		for (int i = 0; i < num; i++)
		{
			cin >> arr[i];
			avg += arr[i];
		}
		double avg2 = avg / num;
		for (int j = 0; j < num; j++)
		{
			if (arr[j] > avg2)
			{
				n++;
			}
		}
		double percent = (n / num) * 100;
		//		cout << percent << "%" << endl;
		brr[p] = percent;
		p++;
	}

	for (int i = 0; i < set; i++)
	{
		cout << fixed;
		cout.precision(3);
		cout << brr[i] << "%" << endl;
	}

	return 0;
}