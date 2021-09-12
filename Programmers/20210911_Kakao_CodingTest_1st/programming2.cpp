#include <string>
#include <vector>
#include<cmath>
#include<iostream>

using namespace std;

int solution(int n, int k) {
    int answer = 0;

    vector<int> num;
    while (1) {
        if (n == 0)
            break;
        num.push_back(n % k);
        n /= k;
    }

    bool flag = true;
    long long tmp = 0;
    for (int i = num.size() - 1; i >= 0; i--) {
        if (num[i] == 0) {
            flag = true;
            if (tmp == 1 || tmp ==0)
                flag = false;
            for (int j = 2; j <= sqrt(tmp); j++) {
                if (tmp % j == 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                answer++;
            }
            tmp = 0;
        } else {
            tmp = tmp * 10 + num[i];
        }
    }
    flag = true;
    if (tmp ==1 || tmp ==0)
        flag = false;
    for (int j = 2; j <= sqrt(tmp); j++) {
        if (tmp % j == 0) {
            flag = false;
            break;
        }
    }
    if (flag) {
        answer++;
    }

    return answer;
}