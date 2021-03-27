#include<iostream>
#include<string>
using namespace std;

struct Node
{
	char value;
	Node* next;
	Node* prev;
	Node()
	{
		value = 0;
		next = NULL;
		prev = NULL;
	}
};
struct List
{
	int size;
	Node* top;
	Node* head;
	Node* tail;
	List()
	{
		size = 0;
		top = NULL;
		head = NULL;
		tail = NULL;
	}
	void push(char x)
	{
		Node* new_node = new Node();
		new_node->value = x;
		if (head == NULL)
		{
			head = new_node;
			tail = head;
		}
		else
		{
			new_node->next = head;
			head->prev = new_node;
			head = new_node;
		}
		top = head;
		size++;
	}
	char pop()
	{
		char tmp = top->value;
		if (size == 1)
		{
			head = NULL;
			tail = NULL;
			top = NULL;
		}
		else if (size == 2)
		{
			head->next = NULL;
			tail->prev = NULL;
			head = tail;
			top = head;
		}
		else
		{
			head = head->next;
			head->prev = NULL;
			top = head;
		}
		size--;

		return tmp;
	}
};


int main()
{
	List frontstack;
	List backstack;

	string str;
	cin >> str;

	for (int i = 0; i < str.length(); i++)
	{
		frontstack.push(str[i]);
	}
	int num;
	cin >> num;

	for (int i = 0; i < num; i++)
	{
		char a;
		cin >> a;
		if (a == 'P')
		{
			char x;
			cin >> x;
			frontstack.push(x);
		}
		else if (a == 'L')
		{
			if (frontstack.size == 0)
			{
			}
			else
				backstack.push(frontstack.pop());
		}
		else if (a == 'D')
		{
			if (backstack.size == 0)
			{
			}
			else
				frontstack.push(backstack.pop());
		}
		else if (a == 'B')
		{
			if (frontstack.size == 0)
			{
			}
			else
				frontstack.pop();
		}
	}

	List reverse;
	while (1)
	{
		if (frontstack.size == 0)
			break;
		else
		{
			reverse.push(frontstack.pop());
		}
	}
	while (1)
	{
		if (reverse.size == 0)
			break;
		else
		{
			cout << reverse.top->value;
			reverse.pop();
		}
	}
	while (1)
	{
		if (backstack.size == 0)
			break;
		else
		{
			cout << backstack.top->value;
			backstack.pop();
		}
	}
	cout << '\n';
	return 0;
}