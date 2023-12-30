#include <fstream>
#include <iostream>

using namespace std;

bool is_star(char c) {
    return !isdigit(c) && c != '.';
}

bool check_surrounding(vector<string> &lines, int i, int j) {
    int H = lines.size();
    int W = lines[0].size();

    int dirs[][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                     {0, 1},   {1, -1}, {1, 0},  {1, 1}};

    int has_symbol = false;

    for (auto [di, dj] : dirs) {
        int ni = i + di;
        int nj = j + dj;

        if (ni < 0 || ni >= H || nj < 0 || nj >= W) {
            continue;
        }

        if (is_star(lines[ni][nj])) {
            has_symbol = true;
            break;
        }
    }

    return has_symbol;
}

int main() {
    ifstream file("input.txt");
    vector<string> lines;

    string line;

    int result = 0;
    while (getline(file, line)) {
        lines.push_back(line);
    }

    int H = lines.size();
    int W = lines[0].size();

    for (int i = 0; i < H; i++) {
        int cur = 0;
        for (int j = 0; j < W; j++) {
            char c = lines[i][j];

            if (isdigit(c)) {
                cur *= 10;
                cur += (c - '0');
                if (check_surrounding(lines, i, j)) {
                    while (j + 1 < W && isdigit(lines[i][j+1])) {
                        j++;
                        cur *= 10;
                        cur += (lines[i][j] - '0');
                    }
                    result += cur;
                    cur = 0;
                }
            } else {
                cur = 0;
            }

        }
    }
    cout << result << endl;
}