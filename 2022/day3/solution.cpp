#include <bits/stdc++.h>
using namespace std;

string get_duplicate_characters(string s1, string s2) {
    set<char> char_set;
    string duplicate;

    for (int i = 0; i < s1.length(); i++) {
        char_set.insert(s1[i]);
    }

    for (int i = 0; i < s2.length(); i++) {
        if (char_set.find(s2[i]) != char_set.end()) {
            duplicate += s2[i];
        }
    }

    return duplicate;
}

char is_lowercase(char c) {
    return c >= 97 && c <= 122;
}

int get_priority(char c) {
    if (is_lowercase(c)) {
        return c - 96;
    }

    return c - 38;
}

int main() {
    freopen("f.in", "r", stdin);

    string rucksack, compartment_1, compartment_2;
    int part_1_priority_sum = 0, part_2_priority_sum = 0;
    vector<string> team_rucksacks;

    while (cin >> rucksack) {
        // Part 1
        int compartment_size = rucksack.length() / 2;

        compartment_1 = rucksack.substr(0, compartment_size);
        compartment_2 = rucksack.substr(compartment_size, compartment_size);

        char item_type = get_duplicate_characters(compartment_1, compartment_2)[0];

        part_1_priority_sum += get_priority(item_type);

        // Part 2
        team_rucksacks.push_back(rucksack);

        if (team_rucksacks.size() == 3) {
            string first_2_rucksacks_duplicates = get_duplicate_characters(team_rucksacks[0], team_rucksacks[1]);
            string all_rucksacks_duplicates = get_duplicate_characters(first_2_rucksacks_duplicates, team_rucksacks[2]);

            part_2_priority_sum += get_priority(all_rucksacks_duplicates[0]);

            team_rucksacks.clear();
        }
    }

    printf("Part 1: %d\nPart 2: %d\n", part_1_priority_sum, part_2_priority_sum);

    return 0;
}
