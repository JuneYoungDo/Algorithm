#include <iostream>
#include <vector>
using namespace std;

#define endl '\n'

int cnt;

class Node {
public:
	int data;
//	Node* par;
	vector<Node*> child;
	Node() {
		data = 0;
//		par = NULL;
	}
};

class Tree {
public:
	Node* root;
	vector<Node*> list;
	
	Tree() {
		root = NULL;
	}

	Node* findNode(int e) {
		for (int i = 0; i < list.size(); i++) {
			if (list[i]->data == e) {
				return list[i];
			}
		}
		return NULL;
	}

	void insertRoot() {
		Node* new_node = new Node();
		new_node->data = 0;
		root = new_node;
		list.push_back(new_node);
	}

	void insertNode(int p, int c) {
		if (p == -1) {
			insertRoot();
		}
		else {
			Node* par_node = findNode(p);

			Node* new_node = new Node();
			new_node->data = c;
	//		new_node->par = par_node;
			par_node->child.push_back(new_node);
			list.push_back(new_node);
		}
	}

	void del(Node* v)
	{
		v->data = -1;
		for (int i = 0; i < v->child.size(); i++)
			del(v->child[i]);
		return;
	}

	void eraseNode(int e)
	{
		if (e == 0) {
			return;
		}
		else {
			Node* del_node = findNode(e);
			
			del(del_node);
		}
	}

	void leafCount() {
		
		for (int i = 0; i < list.size(); i++)
		{
			int sz = list[i]->child.size();
			for (int j = 0; j < list[i]->child.size(); j++)
			{
				if (list[i]->child[j]->data == -1)
					sz--;
			}

			if (sz == 0 && list[i]->data != -1)
				cnt++;
		}
	}

};

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	Tree tree;

	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		tree.insertNode(x, i);
	}
	
	int del;
	cin >> del;
	
	if (del == 0)
		cout << 0 << endl;
	else {
		tree.eraseNode(del);
		tree.leafCount();
		cout <<  cnt << endl;
	}

	return 0;
}