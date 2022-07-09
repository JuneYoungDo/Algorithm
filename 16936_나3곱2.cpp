//
// Created by June Young Do on 2022/07/09.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
#define endl '\n'
#define ll long long

int N;
ll arr[101];
bool visited[101];
vector<ll> ans;

void dfs(int idx) {
    ans.push_back(arr[idx]);
    visited[idx] = true;
    for (int i = idx + 1; i < N; i++) {
        if (arr[i] == arr[idx] * 2 && !visited[i]) {
            dfs(i);
        }
    }
    for (int i = 0; i < idx; i++) {
        if (arr[idx] % 3 == 0 && arr[i] == arr[idx] / 3 && !visited[i]) {
            dfs(i);
        }
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + N);

    for (int i = 0; i < N; i++) {
        ans.clear();
        memset(visited, false, sizeof(visited));
        dfs(i);
        if(ans.size() == N) {
            break;
        }
    }
    for (int i = 0; i < N; i++) {
        cout << ans[i] << ' ';
    }
    cout << endl;

    return 0;
}