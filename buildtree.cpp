

#include <iostream>
#include <cassert>
#include <stdlib.h>
#include "node.h"
#include "buildtree.h"

using namespace std;
node_t* root = nullptr;

node_t* getRoot() {
  return root;
}

void insert(char value, const string& uWord) {

  node_t* child = new node_t(value); // create new node_t which will be inserted

  if (root == nullptr) {
    root = child; // new child becomes root
    child->words.push_back(uWord);
    child->level = 0;
    return;
  }

  int countLevels = 0;
  node_t* parent = nullptr;
  node_t* p = root;			// start from p = root
  while (p != nullptr) {	// keep searching for empty spot to insert our new node_t
    parent = p;
    if (value < p->value) {
      p = p->left;
      //p->words.push_back(uWord);
      countLevels++;
    }
    else if (value > p->value){
      p = p->right;
      //p->words.push_back(uWord);
      countLevels++;
    }
    else if (value == p->value){
      p->words.push_back(uWord);
      //for (const string& s: p->words) cout << s << " ";
      break;
    }
  }	// while loop exits when p->left or p->right = null ptr

  if (value < parent->value) {
    assert(parent->left == nullptr);	// double-check to see if while loop worked correctly
    parent->left = child;	// insert our new node_t
    child->words.push_back(uWord);
    child->level = countLevels;
  }
  else if (value > parent->value) { // same as above
    assert(parent->right == nullptr);
    parent->right = child;
    child->words.push_back(uWord);
    child->level = countLevels;
  }
  else {
    ;
  }
  child->parent = parent;
}
