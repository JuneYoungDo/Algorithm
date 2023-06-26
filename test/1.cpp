//
// Created by June Young Do on 2021/12/02.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int sum[2004];

//1번

int countSubstrings(string input_str) {
    int n = input_str.size();
    int ret = 0;

    for (int i = 0; i < n; i++) {
        char c = input_str[i];
        int val;
        if (c <= 'b') val = 1;
        else if (c <= 'e') val = 2;
        else if (c <= 'h') val = 3;
        else if (c <= 'k') val = 4;
        else if (c <= 'n') val = 5;
        else if (c <= 'q') val = 6;
        else if (c <= 't') val = 7;
        else if (c <= 'w') val = 8;
        else val = 9;
        sum[i + 1] = sum[i] + val;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j + i <= n; j++) {
            int x = sum[i + j] - sum[j];
            if (!(x % i)) ret++;
        }
    }
    return ret + n;
}

int main() {
    cout << countSubstrings("asdf");
}