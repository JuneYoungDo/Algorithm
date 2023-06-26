//
// Created by June Young Do on 2022/03/26.
//

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr, vector<int> brr) {
    int answer = 0;

    vector<int> v1, v2;
    v1.push_back(arr[0]);
    v2.push_back(brr[0]);
    for (int i = 1; i < arr.size(); i++) {
        v1.push_back(v1[i - 1] + arr[i]);
        v2.push_back(v2[i - 1] + brr[i]);
    }
    for (int i = 0; i < v1.size(); i++) {
        int prev = v1[i];
        int target = v2[i];
        if (prev != target)
            answer++;
    }


    return answer;
}