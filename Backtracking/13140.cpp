//
// Created by June Young Do on 2021/11/03.
//

#include<iostream>
#include<algorithm>

using namespace std;
#define endl '\n'

int n;
int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int hello[5] = {0, 1, 2, 2, 3};   // 0 1 2 2 3  => h = 0번째, e = 1번째 ...
int world[5] = {4, 3, 5, 2, 6};   // 4 3 5 2 6

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    do {
        if (arr[hello[0]] == 0 || arr[world[0]] == 0) continue;

        int a = arr[hello[0]] * 10000 + arr[hello[1]] * 1000 + arr[hello[2]] * 100 + arr[hello[3]] * 10 + arr[hello[4]];
        int b = arr[world[0]] * 10000 + arr[world[1]] * 1000 + arr[world[2]] * 100 + arr[world[3]] * 10 + arr[world[4]];

        if (a + b == n) {
            cout << "  " + to_string(a) << endl;
            cout << "+ " + to_string(b) << endl;
            cout << "-------" << endl;
            if (n >= 100000)
                cout << " " + to_string(n) << endl;
            else
                cout << "  " + to_string(n) << endl;
            return 0;
        }

    } while (next_permutation(arr, arr + 10));

    cout << "No Answer" << endl;

    return 0;
}