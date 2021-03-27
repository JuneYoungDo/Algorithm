#include<iostream>
#include <iomanip>
using namespace std;

int main(void)
{
	double num1, num2;


	cin >> num1 >> num2;

	cout.setf(ios::showpoint);
	cout << fixed;
	cout.precision(10);
	cout << num1 / num2;

	return 0;
}