//
// Created by June Young Do on 2022/07/18.
//
#include <iostream>

using namespace std;
#define endl '\n'

int N;
int dp[11][1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < 10; i++) {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 9; k >= j; k--) {
                dp[j][i] = (dp[j][i] + dp[k][i - 1]) % 10007;
            }
        }
    }

    cout << dp[0][N] << endl;

    return 0;
}
