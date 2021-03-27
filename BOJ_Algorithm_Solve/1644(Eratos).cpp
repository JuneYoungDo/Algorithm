#include <iostream>

#include <vector>

#include <algorithm>

using namespace std;



const int MAX = 4000000;



long long minFactor[MAX];

vector<int> prime;



//에라토스테네스의 체

void eratosthenes(void)

{

	minFactor[0] = minFactor[1] = -1;

	for (long long i = 2; i < MAX; i++)

		minFactor[i] = i;



	for (long long i = 2; i < MAX; i++)

		if (minFactor[i] == i)

			for (long long j = i * i; j < MAX; j += i)

				if (minFactor[j] == j)

					minFactor[j] = i;



	for (int i = 2; i < MAX; i++)

		if (minFactor[i] == i)

			prime.push_back(i);

}



int main(void)

{

	ios_base::sync_with_stdio(0);

	cin.tie(0);

	int N;

	cin >> N;



	eratosthenes();

	int low = 0, high = 0;

	int sum = prime[0];

	int result = 0;

	//투 포인터 알고리즘 적용

	while (low <= high && high < prime.size() && prime[low] <= N)

	{

		if (sum < N)

			sum += prime[++high];

		else if (sum == N)

		{

			result++;

			sum += prime[++high];

		}

		else if (sum > N)

		{

			sum -= prime[low++];

			if (low > high&& low < prime.size())

			{

				high = low;

				sum = prime[low];

			}

		}

	}

	cout << result << "\n";

	return 0;

}
