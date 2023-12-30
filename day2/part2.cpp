#include <fstream>
#include <iostream>

using namespace std;

int main() {
    ifstream my_file("input.txt");
    string line;

    int result = 0;

    while (my_file) {
        getline(my_file, line);

        int cur = 0;
        int red = 0;
        int green = 0;
        int blue = 0;

        for (char c : line) {
            if (isdigit(c)) {
                cur = cur * 10 + (c - '0');
                continue;
            }

            switch (c) {
                case ':': {
                    cur = 0;
                    break;
                }
                case 'r': {
                    red = max(red, cur);
                    cur = 0;
                    break;
                }
                case 'g': {
                    green = max(green, cur);
                    cur = 0;
                    break;
                }
                case 'b': {
                    blue = max(blue, cur);
                    cur = 0;
                    break;
                }
            }
        }

        result += red * green * blue;
    }
    cout << result << endl;
}