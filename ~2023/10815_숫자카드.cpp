//
// Created by June Young Do on 2023/08/16.
//
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
#define endl '\n'

int N, M;
vector<int> have;

bool bs(vector<int> &v, int target) {
    int left = 0;
    int right = v.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (v[mid] == target) {
            return true;
        } else if (target > v[mid]) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        have.emplace_back(a);
    }
    sort(have.begin(), have.end());

    cin >> M;
    for (int i = 0; i < M; i++) {
        int a;
        cin >> a;
        cout<<binary_search(have.begin(),  have.end(),a)<<' ';
        cout << (int) bs(have, a) << ' ';
    }

    return 0;
}
