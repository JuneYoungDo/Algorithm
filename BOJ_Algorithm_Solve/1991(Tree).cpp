#include<iostream>
#include<vector>
using namespace std;

vector<char> node[27];

void preorder(char a)
{
	if (a == '.')
	{
		return;
	}
	else
	{
		cout << node[a - 'A'][0];
		preorder(node[a - 'A'][1]);
		preorder(node[a - 'A'][2]);
	}
}

void inorder(char a)
{
	if (a == '.')
	{
		return;
	}
	else
	{
		inorder(node[a - 'A'][1]);
		cout << node[a - 'A'][0];
		inorder(node[a - 'A'][2]);
	}
}

void postorder(char a)
{
	if (a == '.')
	{
		return;
	}
	else
	{
		postorder(node[a - 'A'][1]);
		postorder(node[a - 'A'][2]);
		cout << node[a - 'A'][0];
	}
}

int main()
{
	int num;
	cin >> num;

	for (int i = 0; i < num; i++)
	{
		char d, l, r;
		cin >> d >> l >> r;

		node[d - 'A'].push_back(d);
		node[d - 'A'].push_back(l);
		node[d - 'A'].push_back(r);
	}

	preorder('A');
	cout << endl;
	inorder('A');
	cout << endl;
	postorder('A');
	cout << endl;

	return 0;
}