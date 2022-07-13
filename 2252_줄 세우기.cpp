//
// Created by June Young Do on 2022/07/12.
//

#include<iostream>
#include<vector>
#include<queue>

using namespace std;
#define endl '\n'

int N, M;
vector<vector<int>> v;
queue<int> q;
int in_degree[32001];
bool visited[32001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    v.resize(N + 1);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        in_degree[b]++;
    }

    for (int i = 1; i <= N; i++) {
        if (!in_degree[i]) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        cout << q.front() << ' ';
        for (int i = 0; i < v[q.front()].size(); i++) {
            in_degree[v[q.front()][i]]--;
            if(in_degree[v[q.front()][i]] == 0) {
                q.push(v[q.front()][i]);
            }
        }
        q.pop();
    }
    cout << endl;

    return 0;
}