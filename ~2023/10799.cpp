//
// Created by June Young Do on 2021/11/09.
//

#include<iostream>
#include<string>
#include<stack>
using namespace std;
#define endl '\n'

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int ans = 0;
    string s;
    cin >> s;
    stack<char> sta;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') sta.push(s[i]);
        else {
            sta.pop();
            if (s[i - 1] == '(')ans += sta.size();
            else ans++;
        }
    }
    cout << ans << endl;

    return 0;
}