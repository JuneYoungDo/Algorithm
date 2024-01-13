
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

vector<vector<string>> employee(103);
bool exist[20];

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }
    return answer;
}

vector<int>
solution(int num_teams, vector<string> remote_tasks, vector<string> office_tasks, vector<string> employees) {
    vector<int> answer;
    vector<int> tmp;
    vector<int> minus;
    int num = employees.size();
    for (int i = 0; i < employees.size(); i++) {
        vector<string> v = split(employees[i], ' ');
        for (int j = 0; j < v.size(); j++) {
            employee[i + 1].push_back(v[j]);
        }
    }
    cout << employee[2][0] << ' ' << employee[2][1] << ' ' << employee[2][2] << endl;;
    for (int i = 1; i <= num; i++) {
        bool flag = false;
        for (int j = 1; j < employee[i].size(); j++) {
            auto it = find(office_tasks.begin(), office_tasks.end(), employee[i][j]);
            if (it != office_tasks.end()) {
                exist[stoi(employee[i][0])] = true;
                flag = false;
                break;
            } else {
                flag = true;
            }
        }
        if (flag)
            tmp.push_back(i);
    }
    for (int i = 1; i <= num_teams; i++) {
        if (exist[i])continue;
        else {
            for (int j = 1; j <= employee.size(); j++) {
                if (stoi(employee[j][0]) == i) {
                    minus.push_back(j);
                    break;
                }
            }
        }
    }

    for (int i = 0; i < minus.size(); i++)
        cout << minus[i] << endl;
    for (int i = 0; i < tmp.size(); i++) {
        auto it = find(minus.begin(), minus.end(), tmp[i]);
        if (it == minus.end())
            answer.push_back(tmp[i]);
    }
    return answer;
}