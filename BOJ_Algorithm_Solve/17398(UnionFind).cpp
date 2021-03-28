#include<iostream>
#include<vector>
#define ll long long
#define endl '\n'
using namespace std;

struct Edge
{
	ll vertex[2];
	Edge(ll a, ll b)
	{
		this->vertex[0] = a;
		this->vertex[1] = b;
	}
};

ll N, M, Q;

vector<ll> parent;
vector<ll> Unionsize;
vector<Edge> arr;
vector<ll> seq;

ll FindParent(ll x);
void Union(ll a, ll b);
ll CheckParent(ll a, ll b);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> Q;
	parent.resize(N + 1);
	Unionsize.resize(N + 1);

	for (ll i = 0; i <= N; i++)
		parent[i] = i;
	for (ll i = 0; i <= N; i++)
		Unionsize[i] = 1;

	for (ll i = 0; i < M; i++)
	{
		ll a, b;
		cin >> a >> b;
		arr.push_back(Edge(a, b));
	}

	seq.resize(Q);
	bool checkA[100001] = {};
	for (ll i = 0; i < Q; i++)
	{
		ll x;
		cin >> x;
		seq[i] = x;
		checkA[x - 1] = true;
	}

	for (ll i = 0; i < arr.size(); i++)
	{
		if (checkA[i] == true)
			continue;
		if (!CheckParent(arr[i].vertex[0], arr[i].vertex[1]))
		{
			Union(arr[i].vertex[0], arr[i].vertex[1]);
		}
	}

	ll sum = 0;
	for (ll i = 0; i < Q; i++)
	{
		ll a = seq.back() - 1;
		seq.pop_back();
		if (!CheckParent(arr[a].vertex[0], arr[a].vertex[1]))
		{
			sum += Unionsize[FindParent(arr[a].vertex[0])] * Unionsize[FindParent(arr[a].vertex[1])];
			Union(arr[a].vertex[0], arr[a].vertex[1]);
		}
	}
	cout << sum << endl;

	return 0;
}

ll FindParent(ll x)
{
	if (x == parent[x])return x;
	else return parent[x] = FindParent(parent[x]);
}
void Union(ll a, ll b)
{
	ll pa = FindParent(a);
	ll pb = FindParent(b);
	if (pa < pb)
	{
		parent[pb] = pa;
		Unionsize[pa] += Unionsize[pb];
	}
	else
	{
		parent[pa] = pb;
		Unionsize[pb] += Unionsize[pa];
	}
}
ll CheckParent(ll a, ll b)
{
	a = FindParent(a);
	b = FindParent(b);
	if (a == b)return 1;
	return 0;
}