#include <bits/stdc++.h>
using namespace std;

class Directory {
    public:
        Directory* parent;
        map<string, Directory*> directories;
        map<string, int> files;
        int size = -1;

        void addFile(string name, int size) {
            this->files[name] = size;
        }

        void addDirectory(string name) {
            if (this->directories.find(name) != this->directories.end()) {
                return;
            }

            Directory* dir = new Directory();
            dir->parent = this;

            this->directories[name] = dir;
        }

        int get_size() {
            if (this->size != -1) {
                return this->size;
            }

            this->size = 0;
            for (map<string, int>::iterator it = this->files.begin(); it != this->files.end(); it++) {
                this->size += it->second;
            }

            for (map<string, Directory*>::iterator it = this->directories.begin(); it != this->directories.end(); it++) {
                this->size += it->second->get_size();
            }

            return this->size;
        }
};
