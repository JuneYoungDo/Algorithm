#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct st {
	int cost;
	int x;
	int y;
};

int uf[201];
int n, cnt, total;
vector<st> v;
vector<pair<int, int>> ans;

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
	int xx = find(x);
	int yy = find(y);
	if (xx == yy) return false;
	uf[xx] = yy;
	return true;
}

int main() {
	cout.tie(0);
	cin.tie(0);
	std::ios::sync_with_stdio(false);

	for (int i = 0; i < 201; i++) {
		uf[i] = -1;
	}

	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int a;
			cin >> a;
			if (i >= j) continue;
			if (a < 0) {
				total -= a;
				if (merge(i, j)) {
					cnt++;
				}
			}
			else {
				v.push_back({ a, i, j });
			}
		}
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); i++) {
		if (cnt == n - 1) break;
		int x = v[i].x;
		int y = v[i].y;
		if (merge(x, y)) {
			total += v[i].cost;
			cnt++;
			ans.push_back({ x, y });
		}
	}

	cout << total << " " << ans.size() << "\n";

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i].first << " " << ans[i].second << "\n";
	}

	return 0;
}