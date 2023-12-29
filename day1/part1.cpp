#include <fstream>
#include <iostream>

using namespace std;

int main() {
    ifstream my_file("input.txt");

    string line;
    int result = 0;

    while (my_file) {
        getline(my_file, line);

        for (char c : line) {
            if (isdigit(c)) {
                result += (c - '0') * 10;
                break;
            }
        }

        for (auto itr = line.rbegin(); itr != line.rend(); itr++) {
            if (isdigit(*itr)) {
                result += *itr - '0';
                break;
            }
        }
    }

    cout << result << endl;
}