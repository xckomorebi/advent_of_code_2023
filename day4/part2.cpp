#include <iostream>
#include <fstream>
#include <unordered_set>

using namespace std;

int process_line(string &line) {
    unordered_set<int> s;

    int start = line.find(':') + 1;
    int end = line.find('|');


    int cur = 0;

    for (int i = start; i < end; i++) {
        if (line[i] == ' ') {
            s.insert(cur);
            cur = 0;
        } else {
            cur = cur * 10 + (line[i] - '0');
        }
    }

    s.erase(0);

    cur = 0;
    int sum = 0;
    for (int i = end + 2; i <= line.size(); i++) {
        if (line[i] == ' ' || i == line.size()) {
            if (s.find(cur) != s.end()) {
                sum++;
            }
            cur = 0;
        } else {
            cur = cur * 10 + (line[i] - '0');
        }
    }

    return sum;
}

int main(int argc, char **argv) {
    ifstream file(argv[1]);

    string line;
    vector<int> v;

    while (getline(file, line)) {
        v.push_back(process_line(line));
    } 

    int balance[v.size()];
    memset(balance, 0, sizeof balance);

    balance[0] = 1;

    int cur = 0;
    int result = 0;
    for (int i = 0; i < v.size(); i++) {
        cur += balance[i];
        result += cur;

        if (i + 1 < v.size()) {
            balance[i+1] += cur;
        }

        if (i + 1 + v[i] < v.size()) {
            balance[i+1+v[i]] -= cur;
        }
    }

    cout << result << endl;
}
