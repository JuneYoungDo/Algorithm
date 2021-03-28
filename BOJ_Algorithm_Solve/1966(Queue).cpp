#include<iostream>
#include<algorithm>
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
	int testcase;
	cin >> testcase;

	for (int i = 0; i < testcase; i++)
	{
		int n, m;
		cin >> n >> m;

		List qu;
		int cnt = 0;
		int* arr = new int[n];

		for (int j = 0; j < n; j++)
		{
			int imp;
			cin >> imp;
			qu.push(imp);
			arr[j] = imp;
		}
		int M = arr[m];
		sort(arr, arr + n);
		reverse(arr, arr + n);

		while (!qu.empty())
		{
			if (m == 0 && qu.front1() == arr[cnt] && M == qu.front1())
			{
				cnt++;
				cout << cnt << '\n';
				break;
			}
			else if (qu.front1() == arr[cnt])
			{
				qu.pop();
				cnt++;
				m = m - 1;
				if (m == -1)
					m = qu.size() - 1;
			}
			else
			{
				qu.push(qu.front1());
				qu.pop();
				m = m - 1;
				if (m == -1)
					m = qu.size() - 1;
			}
		}
	}

	return 0;
}