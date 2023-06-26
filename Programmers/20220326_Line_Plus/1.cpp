#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include<iostream>
using namespace std;
#define endl '\n'

vector<string> log;

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }
    return answer;
}

bool isValid2(string l) {
    for (int i = 0; i < l.size(); i++) {
        if ((int) l[i] < 65 || ((int) l[i] > 90 && (int) l[i] < 97) || (int) l[i] > 122){
            return false;
        }
    }
    return true;
}

bool isValid(string l) {
    vector<string> v = split(l, ' ');
    if (l.size() > 100) {
        return false;
    }
    for (int i = 0; i < l.size(); i++) {
        if (isdigit(l[i]) != 0) {
            return false;
        }
    }
    if (v[0] != log[0] || v[1] != log[1] || v[3] != log[3] || v[4] != log[4] || v[6] != log[6] || v[7] != log[7] ||
    v[9] != log[9] || v[10] != log[10]) {
        return false;
    }
    if (isValid2(v[2]) == false || isValid2(v[5]) == false || isValid2(v[8]) == false || isValid2(v[11]) == false){
        return false;
    }
    return true;
}

int solution(vector<string> logs) {
    log.push_back("team_name"); // 0
    log.push_back(":");         // 1
    log.push_back("db");        //2
    log.push_back("application_name");  //3
    log.push_back(":");            //4
    log.push_back("dbtest");        //5
    log.push_back("error_level");   //6
    log.push_back(":");             //7
    log.push_back("info");          //8
    log.push_back("message");       //9
    log.push_back(":");             //10
    log.push_back("test");          //11
    int answer = 0;
    for (int i = 0; i < logs.size(); i++) {
        if (isValid(logs[i]) == false) {
            answer++;
        }
    }
    return answer;
}