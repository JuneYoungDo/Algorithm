//
// Created by June Young Do on 2022/07/19.
//
#include<iostream>
#include<algorithm>

using namespace std;
#define endl '\n'

int n;
int ans = -987654321;
int now[100001];
int dp[2][100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> now[i];
    }

    dp[0][0] = now[0];
    dp[1][0] = 0;
    for (int i = 1; i < n; i++) {
        dp[0][i] = max(dp[0][i - 1] + now[i], now[i]);
        dp[1][i] = max(dp[1][i - 1] + now[i], dp[0][i - 1]);
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 1 && j == 0) { continue; }
            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans << endl;

    return 0;
}
