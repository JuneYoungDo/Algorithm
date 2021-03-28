#include<iostream>
#include<algorithm>
#define rmax 1000000001
using namespace std;

int number[12];
int oper[4];
int n;
int resultMax = -rmax;
int resultMin = rmax;

void DFS(int plus, int minus, int multi, int div, int result, int cnt)
{
	if (cnt == n)
	{
		resultMax = max(resultMax, result);
		resultMin = min(resultMin, result);
	}
	if (plus > 0)
		DFS(plus - 1, minus, multi, div, result + number[cnt], cnt + 1);
	if (minus > 0)
		DFS(plus, minus - 1, multi, div, result - number[cnt], cnt + 1);
	if (multi > 0)
		DFS(plus, minus, multi - 1, div, result * number[cnt], cnt + 1);
	if (div > 0)
		DFS(plus, minus, multi, div - 1, result / number[cnt], cnt + 1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> number[i];
	for (int i = 0; i < 4; i++)
		cin >> oper[i];

	DFS(oper[0], oper[1], oper[2], oper[3], number[0], 1);
	cout << resultMax << '\n';
	cout << resultMin << '\n';

	return 0;
}