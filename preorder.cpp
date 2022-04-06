#include <iostream>
#include <stdlib.h>
#include <string>
#include "node.h"
#include "preorder.h"


using namespace std;

void preOrder(node_t* p, ofstream& out) {
  if (p == nullptr) {
    return;
  } else {
    for(int i = 0; i < p->level; i++) {
      out << "  ";
    }
    out << p->level << " " << p->value << " ";
    for (string s: p->words) out << s << " ";
    out << endl;
    preOrder(p->left, out);
    preOrder(p->right, out);
  }
}
