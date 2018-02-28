#include <bits/stdc++.h>
using namespace std;

unordered_map<string, unordered_set<string>> hm;
unordered_set<string> visited;
queue<vector<string>> paths;

vector<string> bfs(string const & str1, string const & str2) {
    paths.push({str1});
    while (!paths.empty()) {
        vector<string> path = paths.front();
        unordered_set<string> aux_path(path.begin(), path.end());
        paths.pop();
        string s = path[path.size() - 1];
        if (s == str2) {
            return path;
        } else if (visited.find(s) != visited.end()) {
            continue;
        }
        visited.insert(s);
        for (auto & p : hm[s]) {
            if (aux_path.find(p) == aux_path.end()) {
                vector<string> new_path(path.begin(), path.end());
                new_path.push_back(p);
                paths.push(new_path);
            }
        }
    }
    return {};
}

int main() {
    string str1,str2;
    cin >> str1 >> str2;
    hm["ani"] = {};
    hm["sha"] = {};
    hm["ni"] = {};
    hm["ha"] = {};
    hm["na"] = {};
 
    for (auto & x : hm) {
        for (int i = 0; i < x.first.length(); i++) {
            string a = x.first.substr(0, i) + x.first.substr(i+1, x.first.length());
            if (hm.find(a) != hm.end() && a != x.first) {
                hm[x.first].insert(a);
            }
            for (int j = 'a'; j <= 'z'; j++) {
                string b = x.first.substr(0, i) + char(j) + x.first.substr(i+1, x.first.length());
                if (hm.find(b) != hm.end() && b != x.first) {
                    hm[x.first].insert(b);
                }
            }
        } 
        for (int i = 0; i <= x.first.length(); i++) {
            for (int j = 'a'; j <= 'z'; j++) {
                string c = x.first.substr(0, i) + char(j) + x.first.substr(i, x.first.length());
                if (hm.find(c) != hm.end() && c != x.first) {
                    hm[x.first].insert(c);
                }
            }
        }
    }
    // Printing graph
    for (auto & x : hm) {
        cout << x.first << " -> ";
        for (auto & y : x.second) {
            cout << y << " ";
        }
        cout << endl;
    }
    cout << endl;
    // Printing path
    vector<string> path = bfs(str1, str2);
    if (path.empty()) {
        cout << "No path!";
    } else {
        for (auto & p : path) {
            cout << p << " ";
        }
    }
    return 0;
}
