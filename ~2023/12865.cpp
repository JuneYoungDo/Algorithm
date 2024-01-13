//
// Created by June Young Do on 2021/11/11.
//

#include<iostream>
#include<algorithm>

#define endl '\n'
using namespace std;

int n, k;
int weight[101];
int value[101];
int dp[101][100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> weight[i] >> value[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (j < weight[i])dp[i][j] = dp[i - 1][j];
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
            }
        }
    }

    cout << dp[n][k] << endl;

    return 0;
}
