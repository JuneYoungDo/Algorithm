//
// Created by June Young Do on 2022/07/12.
//

#include <iostream>
#include <algorithm>

using namespace std;
#define endl '\n'
#define INF 987654321

int N;
int mp[17][17];
int dp[17][65537];      // [현재위치][비트로 되어 있는 방문한 점들]

int tsp(int now, int route) {
    if (route == (1 << N) - 1 && mp[now][0]) {
        return mp[now][0];
    }

    if (dp[now][route]) return dp[now][route];
    dp[now][route] = INF;

    for (int next = 1; next < N; next++) {
        if (route & (1 << next)) { continue; }  // 이미 방문한 정점을 간 경우
        if (!mp[now][next]) { continue; }       // 가는 길이 없는 경우
        dp[now][route] = min(dp[now][route], tsp(next, route | (1 << next)) + mp[now][next]);
    }
    return dp[now][route];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> mp[i][j];
        }
    }

    cout << tsp(0, 1) << endl;

    return 0;
}