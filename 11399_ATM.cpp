//
// Created by June Young Do on 2023/08/17.
//
#include<iostream>
#include<algorithm>
using namespace std;
#define endl '\n'

int n;
int arr[1001];
int accumulate[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    accumulate[0] = arr[0];
    for (int i = 1; i < n; i++) {
        accumulate[i] = accumulate[i - 1] + arr[i];
    }

    int answer = 0;
    for (int i = 0; i < n; i++) {
        answer = answer + accumulate[i];
    }

    cout << answer << endl;

    return 0;
}
