#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct st {
	int cost;
	int x;
	int y;
};

int n, m, k;
int uf[1001];
vector<st> v;

bool cmp(st p, st q) {
	if (p.cost < q.cost) return true;
	else return false;
}

int find(int x) {
	if (uf[x] < 0) return x;
	uf[x] = find(uf[x]);
	return uf[x];
}

bool merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return false;
	if (y < x) swap(x, y);
	uf[x] += uf[y];
	uf[y] = x;
	return true;
}

int cruscal(int turn) {
	int total = 0;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		uf[i] = -1;
	}
	for (int i = turn; i < v.size(); i++) {
		if (cnt == n - 1) break;
		int x = v[i].x;
		int y = v[i].y;
		if (merge(x, y)) {
			cnt++;
			total += v[i].cost;
		}
	}
	if (cnt == n - 1) return total;
	else return -1;
}

int main() {
	cin >> n >> m >> k;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ i + 1, a, b });
	}

	sort(v.begin(), v.end(), cmp);

	bool fin = false;

	for (int i = 0; i < k; i++) {
		if (fin) {
			cout << "0 ";
			continue;
		}
		int tot = cruscal(i);
		if (tot == -1) {
			cout << "0 ";
			fin = true;
		}
		else {
			cout << tot << " ";
		}
	}
	cout << "\n";

	return 0;
}