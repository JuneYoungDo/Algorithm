#include<iostream>
#include<string>
#define endl '\n';
using namespace std;

class node
{
public:
	char value;
	node* next;
	node()
	{
		value = 0;
		next = NULL;
	}
};

class stackList
{
public:
	node* head;
	node* ptr;
	int size = 0;

	void push(char x)
	{
		node* new_node = new node;
		new_node->value = x;

		if (size == 0)
			head = new_node;
		else
		{
			new_node->next = head;
			head = new_node;
		}
		size++;
	}
	char pop()
	{
		char tmp;
		if (size == 0)
			return -1;
		else
		{
			tmp = head->value;
			head = head->next;
		}
		size--;

		return tmp;
	}
	char top()
	{
		if (size == 0)
			return -1;
		else
			return head->value;
	}
	int empty()
	{
		if (size == 0)
			return 1;
		else
			return 0;
	}
	int isSize()
	{
		return size;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	stackList l;

	string s;
	cin >> s;

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
		{
			cout << s[i];
		}
		else
		{
			if (s[i] == '(')
			{
				l.push(s[i]);
			}
			else if (s[i] == ')')
			{
				while (!l.empty() && l.top() != '(')
					cout << l.pop();
				l.pop();
			}
			else if (s[i] == '*' || s[i] == '/')
			{
				while (!l.empty() && (l.top() == '*' || l.top() == '/'))
					cout << l.pop();
				l.push(s[i]);
			}
			else if (s[i] == '+' || s[i] == '-')
			{
				while (!l.empty() && (l.top() == '+' || l.top() == '-' || l.top() == '*' || l.top() == '/'))
					cout << l.pop();
				l.push(s[i]);
			}
		}
	}
	while (!l.empty())
		cout << l.pop();

	cout << endl;

	return 0;
}