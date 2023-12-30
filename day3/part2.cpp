#include <fstream>
#include <iostream>

using namespace std;

int dirs[8][2] = {
        {0,  1},
        {0,  -1},
        {1,  0},
        {-1, 0},
        {1,  1},
        {1,  -1},
        {-1, 1},
        {-1, -1},
};

bool is_star(char c) {
    return c == '*';
}

int get_cur_value(vector<string> &lines, int i, int j, bool **visited) {
    int W = lines[0].size();

    int start = j;
    int end = j + 1;

    if (visited[i][j]) {
        return -1;
    }

    visited[i][j] = true;

    while (start > 0 && isdigit(lines[i][start - 1])) {
        visited[i][start-1] = true;
        start--;
    }

    while (end < W && isdigit(lines[i][end])) {
        visited[i][end] = true;
        end++;
    }

    return stoi(lines[i].substr(start, end - start));
}


int main() {
    ifstream file("input.txt");
    vector<string> lines;

    string line;

    while (getline(file, line)) {
        lines.push_back(line);
    }

    int H = lines.size();
    int W = lines[0].size();

    vector<pair<int, int> > star_locs;

    bool **visited = new bool *[H];
    for (int i = 0; i < H; i++) {
        visited[i] = new bool[W];
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (is_star(lines[i][j])) {
                star_locs.emplace_back(i, j);
            }
        }
    }

    unordered_map<string, vector<int> > star_values;

    for (auto [x, y] : star_locs) {
        string cur_pos_str = to_string(x) + "," + to_string(y);
        for (auto [dx, dy] : dirs) {
            int nx = x + dx;
            int ny = y + dy;

            if (nx < 0 || nx >= H || ny < 0 || ny >= W) {
                continue;
            }
            if (isdigit(lines[nx][ny])) {
                int cur = get_cur_value(lines, nx, ny, visited);                
                if (cur != -1) {
                    star_values[cur_pos_str].push_back(cur);
                }
            }
        }
    }

    int result = 0;

    for (auto [key, value] : star_values) {
        if (value.size() != 2) {
            continue;
        }
        result += value[0] * value[1];
    }

    cout << result << endl;
}
