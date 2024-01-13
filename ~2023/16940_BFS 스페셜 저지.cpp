//
// Created by June Young Do on 2022/07/28.
//
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
#define endl '\n'

int n;
bool visit[100002];
int sequence[100002];
vector<int> v[100002];
vector<int> guess;
vector<int> real;

bool cmp(int a, int b) {
    return sequence[a] < sequence[b];
}

void bfs(int x) {
    queue<int> q;
    q.push(x);
    visit[x] = true;
    real.emplace_back(x);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int i = 0; i < v[now].size(); i++) {
            if (!visit[v[now][i]]) {
                q.push(v[now][i]);
                visit[v[now][i]] = true;
                real.emplace_back(v[now][i]);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        v[a].emplace_back(b);
        v[b].emplace_back(a);
    }

    real.emplace_back(0);
    guess.emplace_back(0);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        guess.emplace_back(a);
        sequence[a] = i;
    }

    for (int i = 1; i <= n; i++) {
        sort(v[i].begin(), v[i].end(), cmp);
    }

    if (guess[1] != 1) {
        cout << 0 << endl;
        return 0;
    }
    bfs(guess[1]);

    bool flag = true;
    for (int i = 1; i <= n; i++) {
        if (guess[i] != real[i]) {
            flag = false;
            break;
        }
    }

    cout << flag << endl;

    return 0;
}
