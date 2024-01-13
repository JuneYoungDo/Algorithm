//
// Created by June Young Do on 2022/07/14.
//

#include<iostream>
#include<algorithm>

using namespace std;
#define endl '\n'

int n;
int dp[1001][3];
int R[1001];
int G[1001];
int B[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> R[i] >> G[i] >> B[i];
    }

    dp[0][0] = R[0];
    dp[0][1] = G[0];
    dp[0][2] = B[0];
    for (int i = 1; i < n; i++) {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + R[i];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + G[i];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + B[i];
    }

    cout << min({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]}) << endl;

    return 0;
}
