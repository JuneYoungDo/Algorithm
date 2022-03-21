//
// Created by June Young Do on 2022/03/09.
//
#include<iostream>
#include<list>
using namespace std;
#define endl '\n'

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCase;
    string input;

    cin >> testCase;
    while (testCase--) {
        cin >> input;
        list<char> password;
        list<char>::iterator cursor = password.end();

        for (int i = 0; i < input.length(); i++) {
            if (input[i] == '<') {
                if (cursor == password.begin())continue;
                cursor--;
            } else if (input[i] == '>') {
                if (cursor == password.end())continue;
                cursor++;
            } else if (input[i] == '-') {
                if (cursor == password.begin())continue;
                cursor = password.erase(--cursor);
            } else
                password.insert(cursor, input[i]);
        }

        for (auto it : password)
            cout << it;
        cout << endl;
    }

    return 0;
}