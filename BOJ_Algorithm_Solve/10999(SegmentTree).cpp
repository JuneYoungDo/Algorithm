#include<iostream>
#include<cmath>
#include<vector>
#define endl '\n'
#define ll long long
using namespace std;

struct Tree
{
	ll value;
	ll lazy;
	Tree()
	{
		value = 0;
		lazy = 0;
	}
};

int N, M, K;
vector<ll> arr;
Tree* tree;

// ÇÔ¼ö
ll SegmentTree(int index, int start, int end);
ll sum(int index, int start, int end, int left, int right);
void update(int index, int diff, int start, int end, int left, int right);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;
	arr.resize(N);
	for (int i = 0; i < N; i++)cin >> arr[i];
	int h = ceil(log2(N));
	tree = new Tree[(int)pow(2, h + 1)];
	SegmentTree(0, 0, N - 1);

	for (int i = 0; i < M + K; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1)
		{
			int d;
			cin >> d;
			update(0, d, 0, N - 1, b - 1, c - 1);
		}
		if (a == 2)
		{
			cout << sum(0, 0, N - 1, b - 1, c - 1) << endl;
		}
	}

	return 0;
}

ll SegmentTree(int index, int start, int end)
{
	if (start == end)tree[index].value = arr[start];
	else
	{
		int mid = (start + end) / 2;
		tree[index].value = SegmentTree(index * 2 + 1, start, mid) + SegmentTree(index * 2 + 2, mid + 1, end);
	}
	return tree[index].value;
}

ll sum(int index, int start, int end, int left, int right)
{
	if (tree[index].lazy != 0)
	{
		tree[index].value += ((ll)end - (ll)start + 1) * tree[index].lazy;
		if (start != end)
		{
			tree[2 * index + 1].lazy += tree[index].lazy;
			tree[2 * index + 2].lazy += tree[index].lazy;
		}
		tree[index].lazy = 0;
	}
	if (start > right || end < left)return 0;
	else if (start >= left && end <= right)return tree[index].value;
	else
	{
		int mid = (start + end) / 2;
		return sum(index * 2 + 1, start, mid, left, right) + sum(index * 2 + 2, mid + 1, end, left, right);
	}
}

void update(int index, int diff, int start, int end, int left, int right)
{
	if (tree[index].lazy != 0)
	{
		tree[index].value += ((ll)end - (ll)start + 1) * tree[index].lazy;
		if (start != end)
		{
			tree[2 * index + 1].lazy += tree[index].lazy;
			tree[2 * index + 2].lazy += tree[index].lazy;
		}
		tree[index].lazy = 0;
	}
	if (start > right || end < left)return;
	else if (start >= left && end <= right)
	{
		tree[index].value += (ll)diff * ((ll)end - (ll)start + 1);
		if (start != end)
		{
			tree[index * 2 + 1].lazy += (ll)diff;
			tree[index * 2 + 2].lazy += (ll)diff;
		}
		return;
	}
	int mid = (start + end) / 2;
	update(index * 2 + 1, diff, start, mid, left, right);
	update(index * 2 + 2, diff, mid + 1, end, left, right);
	tree[index].value = tree[index * 2 + 1].value + tree[index * 2 + 2].value;
}