//
// Created by June Young Do on 2023/08/21.
//

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
#define endl '\n'
#define ll long long

ll n, m;
vector<ll> v;
ll arr[1000001];

void bs() {
    ll left = 0;
    ll right = arr[n - 1];
    while (left <= right) {
        ll mid = (left + right + 1) / 2;
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] - mid >= 0) {
                sum += (arr[i] - mid);
            }
        }
        if (sum >= m) {
            v.emplace_back(mid);
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    bs();
    sort(v.begin(), v.end());

    cout << v[0] << endl;

    return 0;
}