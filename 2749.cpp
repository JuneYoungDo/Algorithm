//
// Created by June Young Do on 2021/11/10.
//

#include<iostream>

using namespace std;
#define endl '\n'
#define ll long long

ll n;
ll arr[1500001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    arr[0] = 0;
    arr[1] = 1;
    for (ll i = 2; i < 1500000; i++) {
        arr[i] = (arr[i - 2] + arr[i - 1]) % 1000000;
    }
    cout << arr[n % 1500000] << endl;

    return 0;
}