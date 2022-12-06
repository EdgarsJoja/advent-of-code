#include <bits/stdc++.h>
using namespace std;

tuple<stack<string>, string> read_crates_input() {
    string s, crates_index;
    stack<string> crates;

    while (getline(cin, s)) {
        if (s == "") {
            break;
        }

        if (s[1] != '1') {
            crates.push(s);
        } else {
            crates_index = s;
        }
    }

    return { crates, crates_index };
}

vector<stack<char>> build_stacks(stack<string> crates, int stacks_count) {
    vector<stack<char>> stacks(stacks_count);

    string crate_input;
    while (!crates.empty()) {
        crate_input = crates.top();
        crates.pop();

        for (int i = 0, j = 1; i < stacks_count; i++, j += 4) {
            if (crate_input[j] != ' ') {
                stacks[i].push(crate_input[j]);
            }
        }
    }

    return stacks;
}

string get_stacks_message(vector<stack<char>> stacks) {
    string s = "";

    for (int i = 0; i < stacks.size(); i++) {
        s += stacks[i].top();
    }

    return s;
}

int main() {
    freopen("f.in", "r", stdin);

    auto [crates, crates_index] = read_crates_input();
    int stacks_count = crates_index[crates_index.size() - 2] - '0';

    auto stacks = build_stacks(crates, stacks_count);
    auto stacks_9001 = stacks;

    string s;
    char stack_top;
    int move_count, from_stack, to_stack;

    while (cin >> s >> move_count >> s >> from_stack >> s >> to_stack) {
        stack<char> tmp;

        while (move_count--) {
            // Part 1
            stack_top = stacks[from_stack - 1].top();
            stacks[from_stack - 1].pop();

            stacks[to_stack - 1].push(stack_top);

            // Part 2
            stack_top = stacks_9001[from_stack - 1].top();
            stacks_9001[from_stack - 1].pop();

            tmp.push(stack_top);
        }

        // Part 2
        while (!tmp.empty()) {
            stacks_9001[to_stack - 1].push(tmp.top());
            tmp.pop();
        }
    }

    string message = get_stacks_message(stacks), message_9001 = get_stacks_message(stacks_9001);

    cout << "Part 1: " + message + "\n" << "Part 2: " + message_9001 + "\n";

    return 0;
}
