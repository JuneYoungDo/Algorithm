#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> dwarf;
vector<int> ans;

int main()
{
	int sum = 0;

	for (int i = 0; i < 9; i++)
	{
		int n;
		cin >> n;
		dwarf.push_back(n);
		sum = sum + n;
	}

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (sum - dwarf[i] - dwarf[j] == 100 && i != j)
			{
				for (int k = 0; k < 9; k++)
				{
					if (k != i && k != j)
					{
						ans.push_back(dwarf[k]);
					}
				}
				goto inorder;
			}
		}
	}
inorder:
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << '\n';
	}

	return 0;
}