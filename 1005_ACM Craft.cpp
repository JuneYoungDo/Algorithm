//
// Created by June Young Do on 2022/07/13.
//
#include<iostream>
#include<queue>
#include<vector>
#include<cstring>

using namespace std;
#define endl '\n'

int tc;
int N, K, W;
int building[1002];
int in_degree[1002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> tc;

    while (tc--) {
        vector<int> v[1002];
        memset(in_degree, 0, sizeof(in_degree));
        cin >> N >> K;
        for (int i = 1; i <= N; i++) {
            cin >> building[i];
        }
        for (int i = 0; i < K; i++) {
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
            in_degree[b]++;
        }

        cin >> W;
        priority_queue<pair<int, int>> pq;
        for (int i = 1; i <= N; i++) {
            if (in_degree[i] == 0) {
                pq.push({-building[i], i});
            }
        }

        while (!pq.empty()) {
            int now = pq.top().second;
            int weight = -pq.top().first;
            pq.pop();

            if (now == W) {
                cout << weight << endl;
            }

            for (int i : v[now]) {
                in_degree[i]--;
                if (in_degree[i] == 0) {
                    pq.push({-(weight + building[i]), i});
                }
            }
        }
    }
    return 0;
}
