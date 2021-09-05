//
// Created by June Young Do on 2021/08/20.
//
#include<iostream>
#include<algorithm>
using namespace std;
#define endl '\n'

int n, k;
int dp[10003];
int arr[101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    for(int i=1;i<=k;i++)       // 0은 0으로 저장해 놔야 dp[5-5]와 같은 상황에서 연산 가능
        dp[i] = 100001;         // 최솟값을 찾기 때문에 최댓값으로 초기 설정

    for (int i = 0; i < n; i++) {
        cin >> arr[i];          // 사용가능한 동전이 들어오면

        for (int j = arr[i]; j <= k; j++) {
            dp[j] = min(dp[j], dp[j - arr[i]] + 1);     // 해당 코인을 이용하였을 때의 갯수와 이전 코인 사용 비교
        }
    }

    if (dp[k] == 100001)
        cout << -1 << endl;
    else
        cout << dp[k] << endl;

    return 0;
}

