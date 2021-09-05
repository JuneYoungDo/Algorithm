//
// Created by June Young Do on 2021/09/05.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector <int>> v(100001);
int n, k;
queue <int> q;
bool visited[100001];
int cnt[100001];


void bfs(int n) {
    while (!q.empty() || q.front() == n) {
        int tmp = q.front();
        q.pop();

        for (int i = 0; i < v[tmp].size(); i++) {
            if (!visited[v[tmp][i]] && v[tmp][i]>=0 ) {
                q.push(v[tmp][i]);
                cnt[v[tmp][i]] = cnt[tmp] + 1;
                visited[v[tmp][i]] = true;
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> k;
    for (int i = 0; i < 20; i++) {
        if (i == 0) {
            v[i] = { 1,0 };
        }
        else
            v[i] = { i - 1,i + 1,i * 2 };
    }


    q.push(n);
    bfs(k);
    cout << cnt[k];

}