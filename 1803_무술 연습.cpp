//
// Created by June Young Do on 2022/07/25.
//
#include<iostream>
#include<vector>
#include<cstring>
#include<queue>

using namespace std;
#define endl '\n'

int n, m;
int arr[100002];
vector<int> v[100002];
int in_degree[100002];
queue<int> q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(arr, -1, sizeof(arr));

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        v[i].emplace_back(a + n);
        in_degree[a + n]++;
    }

    for (int i = n + 1; i <= n + m; i++) {
        int a;
        cin >> a;
        v[i].emplace_back(a);
        in_degree[a]++;
    }

    for (int i = 1; i <= n + m; i++) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int now = q.front();
        q.pop();
        if (arr[now] != -1) { continue; }
        arr[now] = 1;
        arr[v[now][0]] = 0;
        in_degree[v[v[now][0]][0]]--;
        if (in_degree[v[v[now][0]][0]] == 0) {
            q.push(v[v[now][0]][0]);
        }

        if (q.empty()) {
            for (int i = 1; i <= n + m; i++) {
                if (arr[i] == -1) {
                    q.push(i);
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << arr[i];
    }
    cout << endl;
    for (int i = n + 1; i <= n + m; i++) {
        cout << arr[i];
    }
    cout << endl;
    return 0;
}
