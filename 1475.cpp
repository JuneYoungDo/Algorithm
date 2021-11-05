//
// Created by June Young Do on 2021/11/05.
//

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
#define endl '\n'

string input;
int arr[10];
int ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> input;
    for (int i = 0; i < input.size(); i++)
        arr[input[i] - '0']++;

    for (int i = 0; i < 10; i++) {
        if (i != 6 && i != 9)
            ans = max(ans, arr[i]);
    }
    ans = max(ans, (arr[6] + arr[9] + 1) / 2 );
    cout << ans << endl;

    return 0;
}