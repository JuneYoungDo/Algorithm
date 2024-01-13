//
// Created by June Young Do on 2022/03/25.
//
#include<iostream>

using namespace std;
#define endl '\n'

int N;
int arr[51][2];
int ranking[51];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        arr[i][0] = x;
        arr[i][1] = y;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i][0] < arr[j][0] && arr[i][1] < arr[j][1])
                ranking[i]++;
        }
    }
    for (int i = 0; i < N; i++)
        cout << ranking[i] + 1 << ' ';
    cout << endl;

    return 0;
}
