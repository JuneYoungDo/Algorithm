//
// Created by June Young Do on 2022/07/09.
//

#include<iostream>
#include<vector>
#include<cstring>

using namespace std;
#define endl '\n'
#define INF 99999999

int N;
vector<vector<int>> mp;
bool visited[11];
int ans = INF;

int getMin(int tmp) {
    if (tmp < ans) {
        return tmp;
    } else {
        return ans;
    }
}

void dfs(int start, int now, int size, int tmp) {
    visited[now] = true;
    size++;
    if (size == N) {
        if (mp[now][start] == 0) {
            return;
        } else {
            ans = getMin(tmp + mp[now][start]);
        }
    }
    for (int i = 0; i < N; i++) {
        if (!visited[i] && mp[now][i] != 0) {
            dfs(start, i, size, tmp + mp[now][i]);
        }
    }
    visited[now] = false;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    mp.resize(N + 1);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int x;
            cin >> x;
            mp[i].push_back(x);
        }
    }

    for (int i = 0; i < N; i++) {
        memset(visited, false, sizeof(visited));
        dfs(i, i, 0, 0);
    }

    cout << ans << endl;

    return 0;
}