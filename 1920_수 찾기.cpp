//
// Created by June Young Do on 2023/06/26.
//

#include<iostream>
#include<algorithm>

using namespace std;
#define endl '\n'

int arr[100002];
int n, m;

int binarySearch(int num) {
    int left = 1;
    int right = n;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (num == arr[mid]) {
            return 1;
        } else if (num < arr[mid]) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    sort(arr + 1, arr + n + 1);
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        cout << binarySearch(x) << endl;
    }
    return 0;
}