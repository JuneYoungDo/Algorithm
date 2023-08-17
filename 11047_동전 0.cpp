//
// Created by June Young Do on 2023/08/17.
//

#include<iostream>
#include<stack>

using namespace std;
#define endl '\n'

int n, k;
int answer;
stack<int> coin;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        coin.push(a);
    }

    while (!coin.empty()) {
        int top = coin.top();
        coin.pop();
        answer += k / top;
        k = k % top;
        if (k == 0) break;
    }

    cout << answer << endl;

    return 0;
}