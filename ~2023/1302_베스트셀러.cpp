//
// Created by June Young Do on 2022/07/11.
//

#include<iostream>
#include<map>

using namespace std;
#define endl '\n'

int N;
string ans;
int maxN;
map<string, int> bookStore;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        if (bookStore.count(s)) {
            bookStore[s]++;
        } else {
            bookStore.insert({s, 1});
        }
    }

    for (auto itr = bookStore.begin(); itr != bookStore.end(); itr++) {
        if (itr->second > maxN) {
            maxN = itr->second;
            ans = itr->first;
        }
    }

    cout << ans << endl;

    return 0;
}