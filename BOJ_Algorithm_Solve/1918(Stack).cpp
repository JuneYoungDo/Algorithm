#include<iostream>
#include<string>
using namespace std;

struct Node
{
	char value;
	Node* next;
	Node()
	{
		value = 0;
		next = NULL;
	}
};
struct List
{
	Node* head;		// = Top
	Node* tail;
	Node* top;
	int size;
	List()
	{
		head = NULL;
		tail = NULL;
		size = 0;
		top = NULL;
	}
};
void pushnode(List* mylist, char a)
{
	Node* new_node = new Node();
	new_node->value = a;

	if (mylist->head == NULL)
	{
		mylist->head = new_node;
		mylist->tail = mylist->head;
		mylist->tail->next = 0;
	}
	else
	{
		new_node->next = mylist->head;
		mylist->head = new_node;
	}
	mylist->size = mylist->size + 1;
	mylist->top = mylist->head;
}
char popnode(List* mylist)
{
	char ret = mylist->head->value;
	Node* tmp_node = mylist->head;

	if (mylist->head == mylist->tail)
	{
		mylist->head = NULL;
		mylist->tail = NULL;
	}
	else
	{
		mylist->head = tmp_node->next;
		delete tmp_node;
	}
	mylist->top = mylist->head;
	mylist->size = mylist->size - 1;
	return ret;
}
int priority(char b)
{
	if (b == '*' || b == '/')
		return 2;
	else if (b == '+' || b == '-')
		return 1;
	else
		return 0;
}

int main()
{
	List mylist;

	string s;
	cin >> s;

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] >= 65 && s[i] <= 90)
		{
			cout << s[i];
		}
		else
		{
			if (s[i] == ')')
			{
				while (1)
				{
					if (mylist.top->value == '(')
					{
						popnode(&mylist);
						break;
					}
					else
					{
						cout << popnode(&mylist);
					}
				}
			}
			else
			{
				int one = priority(s[i]);
				while (1)
				{
					if (mylist.head == NULL)
					{
						pushnode(&mylist, s[i]);
						break;
					}
					else if (s[i] == '(')
					{
						pushnode(&mylist, s[i]);
						break;
					}
					else if (priority(mylist.head->value) < one)
					{
						pushnode(&mylist, s[i]);
						break;
					}
					else
						cout << popnode(&mylist);
				}
			}
		}
	}
	while (1)
	{
		if (mylist.size == 0)
			break;
		else
			cout << popnode(&mylist);
	}
	cout << '\n';
	return 0;
}