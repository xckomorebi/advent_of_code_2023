#include <iostream>
#include <fstream>
#include <unordered_set>

using namespace std;

int process_line(string &line) {
    unordered_set<int> s;

    int start = line.find(':') + 1;
    int end = line.find('|');

    int prod = 1;

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
    for (int i = end + 2; i <= line.size(); i++) {
        if (line[i] == ' ' || i == line.size()) {
            if (s.find(cur) != s.end()) {
                prod *= 2;
            }
            cur = 0;
        } else {
            cur = cur * 10 + (line[i] - '0');
        }
    }

    return prod / 2;
}

int main() {
    ifstream file("input.txt");

    string line;
    int result = 0;
    while (getline(file, line)) {
        result += process_line(line);
    }
    cout << result << endl;
}