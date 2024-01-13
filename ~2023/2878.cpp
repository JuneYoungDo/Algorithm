//
// Created by June Young Do on 2021/11/08.
//

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
#define endl '\n'
#define ll long long

ll m, n;
ll ans;
vector<ll> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> m >> n;

    ll noCandy = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
        noCandy += x;
    }
    noCandy = noCandy - m;
    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++) {
        ll minT = min(v[i], noCandy / (n - i));
        ans += minT * minT;
        noCandy -= minT;
    }
    cout << ans << endl;

    return 0;
}