#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int char_to_int(char c) {
    return c - '0';
}

vvi generate_map() {
    vvi map;
    string s;

    while (cin >> s) {
        vi v;

        for (int i = 0; i < s.size(); i++) {
            v.push_back(char_to_int(s[i]));
        }

        map.push_back(v);
    }

    return map;
}

vvi calculate_visibility(vvi map) {
    vvi map_v;

    for (int i = 0; i < map.size(); i++) {
        vi v(map[i].size(), 0);
        map_v.push_back(v);
    }

    // north-south
    for (int i = 0; i < map[0].size(); i++) {
        int max_height = INT_MIN;

        for (int j = 0; j < map.size(); j++) {
            if (map[j][i] > max_height) {
                max_height = map[j][i];
                map_v[j][i] = 1;
            }
        }
    }

    // south-north
    for (int i = 0; i < map[map.size() - 1].size(); i++) {
        int max_height = INT_MIN;

        for (int j = map.size() - 1; j > 0; j--) {
            if (map[j][i] > max_height) {
                max_height = map[j][i];
                map_v[j][i] = 1;
            }
        }
    }

    // west-east
    for (int i = 0; i < map.size(); i++) {
        int max_height = INT_MIN;

        for (int j = 0; j < map[i].size(); j++) {
            if (map[i][j] > max_height) {
                max_height = map[i][j];
                map_v[i][j] = 1;
            }
        }
    }

    // east-west
    for (int i = 0; i < map.size(); i++) {
        int max_height = INT_MIN;

        for (int j = map[i].size() - 1; j > 0; j--) {
            if (map[i][j] > max_height) {
                max_height = map[i][j];
                map_v[i][j] = 1;
            }
        }
    }

    return map_v;
}

int get_visible_trees_count(vvi map_v) {
    int sum = 0;

    for (int i = 0; i < map_v.size(); i++) {
        for (int j = 0; j < map_v[i].size(); j++) {
            sum += map_v[i][j];
        }
    }

    return sum;
}

int get_tree_scenic_score(vvi &map, int x, int y) {
    int i = 0;
    int north = 0, south = 0, west = 0, east = 0;
    bool stop_north = false, stop_south = false, stop_west = false, stop_east = false;

    while (!stop_north || !stop_south || !stop_west || !stop_east) {
        i++;
        if (!stop_north) {
            if (x - i < 0) {
                stop_north = true;
            } else {
                north++;

                if (map[x - i][y] >= map[x][y]) {
                    stop_north = true;
                }
            }
        }

        if (!stop_south) {
            if (x + i >= map.size()) {
                stop_south = true;
            } else {
                south++;

                if (map[x + i][y] >= map[x][y]) {
                    stop_south = true;
                }
            }
        }
        if (!stop_west) {
            if (y - i < 0) {
                stop_west = true;
            } else {
                west++;

                if (map[x][y - i] >= map[x][y]) {
                    stop_west = true;
                }
            }
        }

        if (!stop_east) {
            if (y + i >= map[i].size()) {
                stop_east = true;
            } else {
                east++;

                if (map[x][y + i] >= map[x][y]) {
                    stop_east = true;
                }
            }
        }
    }

    return north * east * south * west;
}

int main() {
    freopen("f.in", "r", stdin);

    auto map = generate_map();
    auto map_v = calculate_visibility(map);

    auto visible_trees_count = get_visible_trees_count(map_v);

    int best_scenic_score = INT_MIN;

    for (int i = 0; i < map.size(); i++) {
        for (int j = 0; j < map[i].size(); j++) {
            int scenic_score = get_tree_scenic_score(map, i, j);

            best_scenic_score = max(best_scenic_score, scenic_score);
        }
    }

    printf("Part 1: %d\nPart 2: %d\n", visible_trees_count, best_scenic_score);

    return 0;
}