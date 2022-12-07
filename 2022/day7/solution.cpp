#include <bits/stdc++.h>
#include "filesystem.cpp"
using namespace std;


Directory root = Directory();
Directory* current_position = &root;
int global_sum = 0, global_min_delete = INT_MAX, free_space, delete_at_least;

vector<string> split_string(string s, char deliminator = ' ') {
    vector<string> res;

    istringstream ss(s);
    while (!ss.eof()) {
        string word;
        getline(ss, word, deliminator);

        res.push_back(word);
    }

    return res;
}

int get_line_type(vector<string> words) {
    if (words[0] == "$") {
        return 0;
    }

    if (words[0] == "dir") {
        return 1;
    }

    return 2;
}

void handle_command(Directory* &current_position, vector<string> words) {
    string command = words[1];

    if (command == "ls") {
        return;
    }

    string directory_name = words[2];

    if (directory_name == "/") {
        current_position = &root;
        return;
    }

    if (directory_name == "..") {
        current_position = &*current_position->parent;
        return;
    }

    current_position = &*current_position->directories[directory_name];
}

void handle_directory(Directory* &current_position, vector<string> words) {
    string directory_name = words[1];
    current_position->addDirectory(directory_name);
}

void handle_file(Directory* &current_position, vector<string> words) {
    int file_size =  stoi(words[0]);
    string file_name = words[1];

    current_position->addFile(file_name, file_size);
}

int sum_directories_sizes(Directory* dir) {
    for (map<string, Directory*>::iterator it = dir->directories.begin(); it != dir->directories.end(); it++) {
        global_sum += sum_directories_sizes(it->second);
    }

    if (dir->size >= delete_at_least && dir->size < global_min_delete) {
        global_min_delete = dir->size;
    }

    return dir->size <= 100000 ? dir->size : 0;
}

int main() {
    freopen("f.in", "r", stdin);

    string line;

    while (getline(cin, line)) {
        if (line == "") {
            break;
        }

        vector<string> words = split_string(line);
        int type = get_line_type(words);

        // @todo: Reduce duplication.
        switch (type) {
            case 0:
                handle_command(current_position, words);
                break;
            case 1:
                handle_directory(current_position, words);
                break;
            case 2:
                handle_file(current_position, words);
                break;
        };
    }

    // Calculate all tree sizes
    root.get_size();

    free_space = 70000000 - root.size;
    delete_at_least = 30000000 - free_space;

    sum_directories_sizes(&root);

    printf("Part 1: %d\nPart 2: %d\n", global_sum, global_min_delete);

    return 0;
}
