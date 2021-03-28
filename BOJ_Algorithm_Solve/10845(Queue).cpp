#include<iostream>
#include<string>
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
	List st;

	int num;
	cin >> num;

	for (int i = 0; i < num; i++)
	{
		string s;
		cin >> s;

		if (s == "push")
		{
			int x;
			cin >> x;
			st.push(x);
		}
		else if (s == "pop")
		{
			cout << st.pop() << '\n';
		}
		else if (s == "size")
		{
			cout << st.size() << '\n';
		}
		else if (s == "empty")
		{
			cout << st.empty() << '\n';
		}
		else if (s == "front")
		{
			cout << st.front1() << '\n';
		}
		else if (s == "back")
		{
			cout << st.back() << '\n';
		}
	}

	return 0;
}
