#include <stdio.h>
#include <limits.h>
#include <iostream>
using namespace std;

int main() {
    freopen("f.in", "r", stdin);

    int increase_count = 0, last_value = INT_MAX, current_value;

    while (cin >> current_value) {
        if (current_value > last_value) {
            increase_count++;
        }

        last_value = current_value;
    }

    printf("Part 1: %d\n", increase_count);

    return 0;
}
