#include<iostream>
#include<vector>
using namespace std;
#define endl '\n'

int countA = 0;
vector<int> v[1001];
bool check[1001];
void dfs(int start) {
	check[start] = true;
	for (int i = 0; i < v[start].size(); i++) {
		if (check[v[start][i]] == false)
			dfs(v[start][i]);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= N; i++) {
		if (check[i] == true)
			continue;
		else {
			dfs(i);
			countA++;
		}
	}

	cout << countA << endl;

	return 0;
}