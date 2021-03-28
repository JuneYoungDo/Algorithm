#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
#include<queue>
using namespace std;
#define ll long long

bool cancel[1000001];
ll n, m, k, cnt;
int p[1000001];
priority_queue<pair<ll, pair<int, int> >, vector<pair<ll, pair<int, int> > >, greater<pair<ll, pair<int, int> > > > pq;

int Find(int x) {
	if (x == p[x])
		return x;
	return p[x] = Find(p[x]);
}

void Union(int a, int b) {
	int aa = Find(a);
	int bb = Find(b);
	if (aa != bb)
		p[aa] = bb;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m >> k;


	for (int i = 1; i <= n; i++)
		p[i] = i;
	for (int i = 1; i <= n; i++) {
		ll cst;
		cin >> cst;
		pq.push({ cst, {0, i} });
	}

	/*for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cancel[a] = true;
	}*/

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		if (a > b)
			swap(a, b);
		if (b == n && a == 1)
			cancel[b] = true;
		else
			cancel[a] = true;
	}

	if (m < 2) {
		cout << "YES";
		return 0;
	}

	for (int i = 1; i < n; i++) {
		if (!cancel[i])
			pq.push({ (ll)0, {i, i + 1} });
	}
	if (!cancel[n])
		pq.push({ (ll)0, {n, 1} });

	while (!pq.empty()) {
		ll cur_cst = pq.top().first;
		int cur = pq.top().second.first;
		int nxt = pq.top().second.second;
		pq.pop();

		int cur_p = Find(cur);
		int nxt_p = Find(nxt);
		if (cur_p != nxt_p) {
			Union(cur_p, nxt_p);
			cnt += cur_cst;
		}
	}
	//cout << cnt;
	if (cnt > k)
		cout << "NO";
	else
		cout << "YES";
	return 0;
}