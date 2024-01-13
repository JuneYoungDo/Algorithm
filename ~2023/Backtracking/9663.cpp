//
// Created by June Young Do on 2021/10/23.
//

#include<iostream>

using namespace std;
#define endl '\n'

int n;
int cnt;
int arr[15];

bool isValid(int tmp) {
    for (int i = 0; i < tmp; i++) {
        if (arr[tmp] == arr[i] || tmp - i == abs(arr[tmp] - arr[i]))
            return false;
    }
    return true;
}

void nQueen(int tmp) {
    if (tmp == n) {
        cnt++;
        return;
    }
    for (int i = 0; i < n; i++) {
        arr[tmp] = i;
        if (isValid(tmp)) {
            nQueen(tmp + 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    nQueen(0);
    cout << cnt << endl;


    return 0;
}