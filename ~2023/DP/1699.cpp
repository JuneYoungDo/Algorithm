//
// Created by June Young Do on 2021/08/20.
//

#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;
#define endl '\n'

int n;
int dp[100002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i <= n; i++) {
        dp[i] = i;
    }

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    for (int i = 4; i <= n; i++) {
        for (int j = 1; j <= sqrt(i); j++) {
            dp[i] = min(dp[i - j * j] + 1, dp[i]);
        }
    }

    cout << dp[n] << endl;

    return 0;
}