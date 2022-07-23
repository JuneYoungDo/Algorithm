//
// Created by June Young Do on 2022/07/23.
//

#include<iostream>
#include<vector>
#include<queue>

using namespace std;
#define endl '\n'

int N, M;
vector<int> v[32002];
int in_degree[32002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        in_degree[b]++;
    }

    priority_queue<int> pq;
    for (int i = 1; i <= N; i++) {
        if (in_degree[i] == 0) {
            pq.push(-i);
        }
    }
    while (!pq.empty()) {
        int now = -pq.top();
        cout << now << ' ';
        pq.pop();
        for (int i = 0; i < v[now].size(); i++) {
            in_degree[v[now][i]]--;
            if (in_degree[v[now][i]] == 0) {
                pq.push(-v[now][i]);
            }
        }
    }
    cout << endl;

    return 0;
}