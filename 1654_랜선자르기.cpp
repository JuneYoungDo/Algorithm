//
// Created by June Young Do on 2023/10/12.
//

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
#define endl '\n'
#define ll long long

ll k, n;
vector<ll> v;
ll answer;

void binarySearch(int target, int end) {
    ll left = 0;
    ll right = end;
    while (left <= right) {
        ll mid = (left + right + 1) / 2;
        ll sum = 0;

        for (int i = 0; i < k; i++) {
            if (v[i] / mid >= 1) {
                sum += (v[i] / mid);
            }
        }
        if (sum >= target) {
            if (answer <= mid) {
                answer = mid;
            }
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> k >> n;
    for (ll i = 0; i < k; i++) {
        ll a;
        cin >> a;
        v.emplace_back(a);
    }

    sort(v.begin(), v.end());
    binarySearch(n, v[v.size() - 1]);
    cout << answer << endl;

    return 0;
}