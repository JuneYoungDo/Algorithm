#include<iostream>
#include<vector>
#include<cmath>
#define max 10001
using namespace std;

struct triple
{
	int prime1;
	int prime2;
	int gap;
};

bool check[max] = { false, };
vector<int> prime;
vector<triple> state;

void primeNumber(int x)		// primeNumber를 prime vector에 모아둠
{
	check[1] = true;
	for (int i = 1; i <= sqrt(x); i++)
	{
		if (check[i] == false)
		{
			for (int j = i + 1; j <= x; j++)
			{
				if (j % i == 0)
				{
					check[j] = true;
				}
			}
		}
	}
	for (int i = 1; i < x; i++)
	{
		if (check[i] == false)
			prime.push_back(i);
	}
}
void makeNum(vector<int> arr, int num)		// 더했을때 원래 수를 만들 수 있는 두 수를 찾아 묶은 후 state 벡터에 저장
{
	for (int i = 0; i < arr.size(); i++)
	{
		if (check[num - arr[i]] == false)
		{
			triple p;
			p.prime1 = arr[i];
			p.prime2 = num - arr[i];
			p.gap = abs(2 * arr[i] - num);
			state.push_back(p);
		}
	}
}
triple compareGap(vector<triple> arr)		// 두 수의 차이값을 비교하여 가장 작은 값 return
{
	int cnt = arr[0].gap;
	triple ptr = arr[0];
	if (arr.size() == 1)
		return ptr;
	else
	{
		for (int i = 1; i < arr.size(); i++)
		{
			if (cnt > arr[i].gap)
			{
				cnt = arr[i].gap;
				ptr = arr[i];
			}
		}
		return ptr;
	}
}


void reset()		// 초기화
{
	for (int i = 0; i < max; i++)
	{
		check[i] = false;
	}
	while (!prime.empty())
		prime.pop_back();
	while (!state.empty())
		state.pop_back();
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	while (n--)
	{
		int x;
		cin >> x;

		primeNumber(x);
		makeNum(prime, x);

		cout << compareGap(state).prime1 << " " << compareGap(state).prime2 << '\n';

		reset();
	}

	return 0;
}