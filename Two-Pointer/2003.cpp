//
// Created by June Young Do on 2021/09/18.
//

#include<iostream>
#include<algorithm>

using namespace std;

int N, M;
int ans;
int input[10002];
int arr[10002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin>>input[i];
    }
    arr[1] = input[1];
    for (int i = 2; i <= N; i++) {
        arr[i] = arr[i - 1] + input[i];
    }

    int start = 0;
    int end = 0;
    while (start <= N && end <= N) {
        int diff = arr[end] - arr[start];
        if (diff == M) {
            ans++;
            start++;
        } else if (diff > M) {
            start++;
        } else {
            end++;
        }
    }

    cout << ans << endl;

    return 0;
}