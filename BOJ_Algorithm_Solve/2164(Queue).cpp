#include<iostream>
using namespace std;

struct Node
{
	int value;
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
	Node* head;
	Node* tail;
	Node* front;
	Node* rear;
	int sizeline;
	List()
	{
		head = NULL;
		tail = NULL;
		front = tail;
		rear = head;
		sizeline = 0;
	}
	void push(int x)
	{
		Node* new_node = new Node();
		new_node->value = x;
		if (sizeline == 0)
		{
			head = new_node;
			tail = new_node;
		}
		else
		{
			new_node->next = head;
			head->prev = new_node;
			head = new_node;
		}
		front = tail;
		rear = head;
		sizeline++;
	}

	int pop()
	{
		if (sizeline == 0)
			return -1;
		else
		{
			int ret = tail->value;
			if (sizeline == 1)
			{
				head = NULL;
				tail = NULL;
			}
			else if (sizeline == 2)
			{
				tail = head;
				tail->next = NULL;
			}
			else
			{
				tail = tail->prev;
				tail->next = NULL;
			}
			front = tail;
			rear = head;
			sizeline--;

			return ret;
		}
	}
	int size()
	{
		return sizeline;
	}
	int empty()
	{
		if (sizeline == 0)
			return 1;
		else
			return 0;
	}
	int front1()
	{
		if (sizeline == 0)
			return -1;
		else
			return tail->value;
	}
	int back()
	{
		if (sizeline == 0)
			return -1;
		else
			return head->value;
	}
};

int main()
{
	List q;

	int num;
	cin >> num;

	for (int i = 1; i < num + 1; i++)
	{
		q.push(i);
	}
	while (1)
	{
		if (q.size() == 1)
		{
			break;
		}
		q.pop();
		q.push(q.front1());
		q.pop();
	}
	cout << q.front1() << '\n';

	return 0;
}