#include<iostream>
#include<vector>
#include<string>
#include<map>
#define endl '\n'
using namespace std;

struct Friend
{
	string arr[2];
	Friend(string a, string b)
	{
		this->arr[0] = a;
		this->arr[1] = b;
	}
};

int	T, F;
map<string, int> m;
vector<int> parent;
vector<Friend> connection;
vector<int> ArrSize;

int FindParent(int x);
void Union(int a, int b);
int CheckParent(int a, int b);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	while (T--)
	{
		int num = 1;
		cin >> F;
		parent.resize(2 * F + 1);
		ArrSize.resize(2 * F + 1);
		for (int i = 1; i < 2 * F + 1; i++)
		{
			parent[i] = i;
		}
		for (int i = 1; i < 2 * F + 1; i++)
		{
			ArrSize[i] = 1;
		}
		int sum = 0;
		for (int k = 0; k < F; k++)
		{
			string a;
			cin >> a;
			if (m.count(a) == 0)
			{
				m.insert(make_pair(a, num));
				num++;
			}
			string b;
			cin >> b;
			if (m.count(b) == 0)
			{
				m.insert(make_pair(b, num));
				num++;
			}

			if (!CheckParent(m.find(a)->second, m.find(b)->second))
			{
				Union(m.find(a)->second, m.find(b)->second);
			}
			if (ArrSize[parent[m.find(a)->second]] >= ArrSize[parent[m.find(b)->second]])
				cout << ArrSize[parent[m.find(a)->second]] << endl;
			else
				cout << ArrSize[parent[m.find(b)->second]] << endl;
		}
		parent.clear();
		connection.clear();
	}
	return 0;
}

int FindParent(int x)
{
	if (x == parent[x])return x;
	else return parent[x] = FindParent(parent[x]);
}
void Union(int a, int b)
{
	int pa = FindParent(a);
	int pb = FindParent(b);
	if (pa < pb)
	{
		ArrSize[pa] += ArrSize[pb];
		ArrSize[pb] = 0;
		parent[pb] = pa;
	}
	else
	{
		ArrSize[pb] += ArrSize[pa];
		ArrSize[pa] = 0;
		parent[pa] = pb;
	}
}
int CheckParent(int a, int b)
{
	a = FindParent(a);
	b = FindParent(b);
	if (a == b)return 1;
	return 0;
}