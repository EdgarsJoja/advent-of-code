#include <bits/stdc++.h>
using namespace std;

map<char, int> choice_value = {{'A', 1}, {'B', 2}, {'C', 3}};
map<char, int> round_result_value = {{'L', 0}, {'D', 3}, {'W', 6}};
map<char, char> choice_translator = {{'X', 'A'}, {'Y', 'B'}, {'Z', 'C'}};

map<char, int> real_round_result_value = {{'X', 0}, {'Y', 3}, {'Z', 6}};


bool is_winning(char person_to_check, char enemy) {
    return (person_to_check == 'B' && enemy == 'A') || (person_to_check == 'C' && enemy == 'B') || (person_to_check == 'A' && enemy == 'C');
}

bool is_loosing(char person_to_check, char enemy) {
    return person_to_check != enemy && !is_winning(person_to_check, enemy);
}

char translate_move(char move) {
    return choice_translator[move];
}

char calculate_result(char enemy_move, char my_move) {
    if (enemy_move == my_move) {
        return 'D';
    }

    return is_winning(my_move, enemy_move) ? 'W' : 'L';
}

char calculate_move(char enemy_move, char required_result) {
    if (required_result == 'Y') {
        return enemy_move;
    }

    if (required_result == 'Z') {
        return is_winning('A', enemy_move) ? 'A' : (is_winning('B', enemy_move) ? 'B' : 'C');
    }

    return is_loosing('A', enemy_move) ? 'A' : (is_loosing('B', enemy_move) ? 'B' : 'C');
}

int main() {
    freopen("f.in", "r", stdin);

    char enemy_move, my_move;
    int part_1_sum = 0, part_1_round_result, part_2_sum = 0, part_2_round_result;

    while (cin >> enemy_move >> my_move) {
        char translated_move = translate_move(my_move);
        part_1_round_result = choice_value[translated_move] + round_result_value[calculate_result(enemy_move, translated_move)];

        char calculated_move = calculate_move(enemy_move, my_move);
        part_2_round_result = choice_value[calculated_move] + real_round_result_value[my_move];

        part_1_sum += part_1_round_result;
        part_2_sum += part_2_round_result;
    }

    printf("Part 1: %d\nPart 2: %d\n", part_1_sum, part_2_sum);

    return 0;
}
