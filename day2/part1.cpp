#include <fstream>
#include <iostream>

using namespace std;

const int red_limit = 12;
const int green_limit = 13;
const int blue_limit = 14;

int main() {
    ifstream my_file("input.txt");
    string line;

    int result = 0;

    while (my_file) {
        getline(my_file, line);

        int id = 0;
        int cur = 0;

        for (char c : line) {
            if (isdigit(c)) {
                cur = cur * 10 + (c - '0');
            }

            if (c == ':') {
                id = cur;
                cur = 0;
            }

            if (c == 'r') {
                if (cur > red_limit) {
                    id = 0;
                    break;
                }
                cur = 0;
            }

            if (c == 'g') {
                if (cur > green_limit) {
                    id = 0;
                    break;
                }
                cur = 0;
            }

            if (c == 'b') {
                if (cur > blue_limit) {
                    id = 0;
                    break;
                }
                cur = 0;
            }
        }

        result += id;
    }
    cout << result << endl;
}