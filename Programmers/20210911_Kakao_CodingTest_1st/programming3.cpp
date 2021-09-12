//
// Created by June Young Do on 2021/09/11.
//

#include<iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> recordList[9999];
int ansList[9999];

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }
    return answer;
}

int timeCalculate(string a, string b) {
    vector<string> tmp = split(a, ':');
    int startH = stoi(tmp[0]);
    int startM = stoi(tmp[1]);

    tmp.clear();

    tmp = split(b, ':');

    int endH = stoi(tmp[0]);
    int endM = stoi(tmp[1]);

    int lastStartTime = (startH * 60) + startM;
    int lastEndTime = (endH * 60) + endM;

    return lastEndTime - lastStartTime;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;

    int initTime = fees[0];
    int initCost = fees[1];
    int perTime = fees[2];
    int perCost = fees[3];

    for (int i = 0; i < records.size(); i++) {
        vector<string> tmp = split(records[i], ' ');
        string t = tmp[0];

        string s = tmp[1];
        int carNum = stoi(s);

        if (recordList[carNum].empty())
            recordList[carNum].push_back(t);
        else {
            ansList[carNum] += timeCalculate(recordList[carNum][0], t);
            recordList[carNum].clear();
        }
    }
    for (int i = 0; i < 9999; i++) {
        if (recordList[i].empty())
            continue;
        else
            ansList[i] += timeCalculate(recordList[i].front(), "23:59");
    }

    for (int i = 0; i < 9999; i++) {
        if (ansList[i] == 0)
            continue;
        else if (ansList[i] <= initTime)
            answer.push_back(initCost);
        else {
            int tmp = 0;
            if ((ansList[i] - initTime) % perTime != 0)
                tmp = (ansList[i] - initTime) / perTime + 1;
            else
                tmp = (ansList[i] - initTime) / perTime;
            int ans = initCost + tmp * perCost;
            answer.push_back(ans);
        }
    }

    return answer;
}

int main() {
    vector<int> fees;
    fees.push_back(1);
    fees.push_back(461);
    fees.push_back(1);
    fees.push_back(10);
    vector<string> records;
    records.push_back("00:00 1234 IN");

    vector<int> v = solution(fees, records);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }
    return 0;
}