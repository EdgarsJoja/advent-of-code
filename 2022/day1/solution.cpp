#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("f.in", "r", stdin);

    string calories;
    int sum = 0, cal, max_sum = -1;
    vector<int> sums;

    while (getline(cin, calories)) {
        if (calories == "") {
            max_sum = max(max_sum, sum);
            sums.push_back(sum);
            sum = 0;
            continue;
        }

        cal = stoi(calories);
        sum += cal;
    }

    sort(sums.begin(), sums.end());

    int top_sums = 0, top_count = 3;

    while (top_count--) {
        top_sums += sums.back();
        sums.pop_back();
    }

    printf("Part 1: %d\nPart 2: %d\n", max_sum, top_sums);

    return 0;
}
