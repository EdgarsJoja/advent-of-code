#include <bits/stdc++.h>
using namespace std;

int find_marker_position(string s, int marker_size) {
    deque<char> last_chars;

    for (int i = 0, j; i < s.length(); i++) {
        bool is_unique = true;

        for (j = 0; j < last_chars.size(); j++) {
            if (last_chars[j] == s[i]) {
                is_unique = false;
                break;
            }
        }

        if (is_unique && last_chars.size() >= marker_size - 1) {
            return i + 1;
        }

        if (!is_unique && last_chars.size() < marker_size) {
            char item_to_be_removed = '?';

            while (item_to_be_removed != s[i] && !last_chars.empty()) {
                item_to_be_removed = last_chars[0];
                last_chars.pop_front();
            }
        }

        last_chars.push_back(s[i]);

        if (last_chars.size() > marker_size - 1) {
            last_chars.pop_front();
        }
    }

    return -1;
}

int main() {
    freopen("f.in", "r", stdin);

    string s;
    int marker_position, message_position;

    cin >> s;

    marker_position = find_marker_position(s, 4);
    message_position = find_marker_position(s, 14);

    printf("Part 1: %d\nPart 2: %d\n", marker_position, message_position);

    return 0;
}
