#include<iostream>
using namespace std;

int main()
{
	int score;
	cin >> score;

	if (score / 10 == 10 || score / 10 == 9)
	{
		cout << "A" << endl;
	}
	else if (score / 10 == 8)
	{
		cout << "B" << endl;
	}
	else if (score / 10 == 7)
	{
		cout << "C" << endl;
	}
	else if (score / 10 == 6)
	{
		cout << "D" << endl;
	}
	else
	{
		cout << "F" << endl;
	}

	return 0;
}