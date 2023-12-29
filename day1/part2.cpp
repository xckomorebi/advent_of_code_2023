#include <fstream>
#include <iostream>

using namespace std;

string numbers[] = {"one", "two",   "three", "four", "five",
                    "six", "seven", "eight", "nine"};

int main() {
    ifstream my_file("input.txt");

    string line;
    int result = 0;

    while (my_file) {
        getline(my_file, line);

        int start = 0;
        int end = 0;

        int start_index = -1;
        int end_index = line.size();

        for (char c : line) {
            start_index++;
            if (isdigit(c)) {
                start = c - '0';
                break;
            }
        }

        for (auto itr = line.rbegin(); itr != line.rend(); itr++) {
            end_index--;
            if (isdigit(*itr)) {
                end = *itr - '0';
                break;
            }
        }

        for (int i = 0; i < 9; i++) {
            int idx = line.find(numbers[i]);
            if (idx != string::npos) {
                if (idx < start_index) {
                    start_index = idx;
                    start = i + 1;
                }
            }

            idx = line.rfind(numbers[i]);
            if (idx != string::npos) {
                if (idx > end_index) {
                    end_index = idx;
                    end = i + 1;
                }
            }
        }

        result += start * 10 + end;
    }

    cout << result << endl;
}