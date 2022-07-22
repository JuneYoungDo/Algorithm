//
// Created by June Young Do on 2022/07/22.
//

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
#define endl '\n'
#define INF 987654321

int N, M, party, ans;
vector<pair<int, int>> graph[1001];
int visited[1001];

void dijkstra(int start) {
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    while (!pq.empty()) {
        int curV = pq.top().second;
        int curW = pq.top().first;
        pq.pop();

        if (visited[curV] != INF) { continue; }
        visited[curV] = curW;

        for (int i = 0; i < graph[curV].size(); i++) {
            int nextV = graph[curV][i].second;
            int nextW = graph[curV][i].first + curW;

            if (visited[nextV] != INF) { continue; }
            pq.push({nextW, nextV});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> party;

    for (int i = 0; i < M; i++) {
        int sv, ev, w;
        cin >> sv >> ev >> w;
        graph[sv].push_back({-w, ev});
    }

    for (int i = 1; i <= N; i++) {
        int tmp;
        if (i == party) { continue; }

        for (int j = 1; j <= N; j++) {
            visited[j] = INF;
        }
        dijkstra(i);
        tmp = -visited[party];

        for (int j = 1; j <= N; j++) {
            visited[j] = INF;
        }
        dijkstra(party);
        tmp += (-visited[i]);

        ans = max(ans, tmp);
    }

    cout << ans << endl;

    return 0;
}
