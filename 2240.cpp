//
// Created by June Young Do on 2022/05/10.
//
#include<iostream>
#include<algorithm>

using namespace std;

int T, W;
int a[1001];
int dp[1001][31][3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T >> W;
    for (int i = 1; i <= T; i++)
        cin >> a[i];

    if (a[1] == 1) dp[1][0][1] = 1;
    if (a[1] == 2) dp[1][1][2] = 1;

    for (int i = 2; i <= T; i++) {
        for (int j = 0; j <= W; j++) {
            if (a[i] == 1) {
                if (j == 0) {
                    dp[i][0][1] = dp[i - 1][0][1] + 1;
                    continue;
                }
                dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][2]) + 1;
                dp[i][j][2] = dp[i - 1][j][2];
            }
            if (a[i] == 2) {
                if (j == 0) {
                    dp[i][0][1] = dp[i - 1][0][1];
                    continue;
                }
                dp[i][j][1] = dp[i - 1][j][1];
                dp[i][j][2] = max(dp[i - 1][j - 1][1], dp[i - 1][j][2]) + 1;
            }
        }
    }

    int answer = -1;
    for (int i = 0; i <= W; i++) {
        answer = max(answer, max(dp[T][i][1], dp[T][i][2]));
    }

    cout << answer << endl;

    return 0;
}
