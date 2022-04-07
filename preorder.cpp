#include <iostream>
#include <stdlib.h>
#include <string>
#include "node.h"
#include "preorder.h"


using namespace std;

void preOrder(node_t* p) {
  if (p == nullptr) {
    return;
  } else {
    for(int i = 0; i < p->level; i++) {
      cout << "  ";
    }
    cout << p->level << " " << p->label << endl;
    for (node_t s: p->children) {
      if (s.children.size() == 0) {
        cout << "  " << s.token.chars << endl;
      }
      else {
        cout << s.label <<  endl;
        preOrder(&s);
      }
    }
  }
}
