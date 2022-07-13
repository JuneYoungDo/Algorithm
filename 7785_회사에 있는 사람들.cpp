//
// Created by June Young Do on 2022/07/11.
//

#include<iostream>
#include<string>
#include<map>

using namespace std;
#define endl '\n'

int n;
map<string, bool> company;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        string name;
        string inOut;
        cin >> name >> inOut;

        if (company.count(name)) {
            if (inOut == "enter") {
                company[name] = true;
            } else if (inOut == "leave") {
                company[name] = false;
            }
        } else {
            if (inOut == "enter") {
                company.insert({name, true});
            }
        }
    }
    for (map<string, bool>::reverse_iterator itr = company.rbegin(); itr != company.rend(); ++itr) {
        if (itr->second == true) {
            cout << itr->first << endl;
        } else {
            continue;
        }
    }

    return 0;
}