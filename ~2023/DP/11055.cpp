//
// Created by June Young Do on 2021/10/10.
//

#include<iostream>

using namespace std;
#define endl '\n'

int n;
int ans;
int arr[1001];
int dp[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        dp[i] = arr[i];
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i] && dp[i] < dp[j] + arr[i])
                dp[i] = dp[j] + arr[i];
        }
        if (ans < dp[i])ans = dp[i];
    }
    cout << ans << endl;

    return 0;
}