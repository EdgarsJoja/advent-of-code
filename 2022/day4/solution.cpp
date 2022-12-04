#include <bits/stdc++.h>
using namespace std;

bool overlaps_fully(int a, int b, int c, int d) {
    return (a >= c && b <= d) || (c >= a && d <= b);
}

bool overlaps(int a, int b, int c, int d) {
    return (b >= c && a <= d) || (d >= a && c <= b);
}

int main() {
    freopen("f.in", "r", stdin);

    int elf_1_low, elf_1_high, elf_2_low, elf_2_high;
    int full_overlap_count = 0, overlap_count = 0;
    char c;

    while (cin >> elf_1_low >> c >> elf_1_high >> c >> elf_2_low >> c >> elf_2_high) {
        if (overlaps_fully(elf_1_low, elf_1_high, elf_2_low, elf_2_high)) {
            full_overlap_count++;
        }

        if (overlaps(elf_1_low, elf_1_high, elf_2_low, elf_2_high)) {
            overlap_count++;
        }
    }

    printf("Part 1: %d\nPart 2: %d\n", full_overlap_count, overlap_count);

    return 0;
}
