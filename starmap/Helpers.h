#ifndef HELPERS_H
#define HELPERS_H
#include "Star.h"
#include <string>
#include <cstddef>
// If you want to add any helper classes,
// here's some space to do it in.

// implement heap and kd tree
#endif

struct Entry {
  float score;
  Star star;

  bool operator < (const Entry& other) const {
    return this->score < other.score;
  }
};

struct Node {
    int point[2];
    Node* left;
    Node* right;
}

   

void insert(Entry newEntry, Entry* root, size_t depth){
    unsigned cd = depth % 3; 

    switch (cd){
        case 0:
        if (newEntry.)
        break;
        if ()
        case 1:
        break;

        case 2:
        break;
    }
    if (root == nullptr){ root = newEntry; return;}
    if (newEntry.star[depth] < root.star[depth] && root->left != nullptr) insert(newEntry, root->left, depth+1);
}
