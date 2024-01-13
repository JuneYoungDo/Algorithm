//
// Created by June Young Do on 2021/09/11.
//

#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>

using namespace std;

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }
    return answer;
}

map<string, pair<int, vector<string>>> m;
map<string, int> ans;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    for (int i = 0; i < id_list.size(); i++) {
        ans.insert({id_list[i], 0});
    }
    vector<string> b;
    for (int i = 0; i < report.size(); i++) {
        vector<string> v = split(report[i], ' ');
        if (m.find(v[1]) == m.end()) {
            m.insert({v[1], {0, b}});
            m[v[1]].first++;
            m[v[1]].second.push_back(v[0]);
        } else {
            auto it = find(m[v[1]].second.begin(), m[v[1]].second.end(), v[0]);
            if (it == m[v[1]].second.end()) {
                m[v[1]].first++;
                m[v[1]].second.push_back(v[0]);
            }
        }
    }

    for (int i = 0; i < id_list.size(); i++) {
        string id = id_list[i];
        if (m[id].first >= k) {
            for (int j = 0; j < m[id].second.size(); j++) {
                ans[m[id].second[j]]++;
            }
        }
    }
    for (int i = 0; i < id_list.size(); i++) {
        answer.push_back(ans[id_list[i]]);
    }

    return answer;
}