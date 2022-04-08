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
    // this should generate the left hand side spaces
    // for(int i = 0; i < p->level; i++) {
    //   cout << "  ";
    // }
    cout << p->label << endl;
    for (node_t s: p->children) {
      for(int i = 0; i < p->level; i++) {
        cout << "  ";
      }
      if (s.children.size() == 0) {
        if (s.token.ID == 1002){
          cout << "Identifier " << s.token.chars << endl;
        }
        else if (s.token.ID == 1004) {
          cout << "Number " << s.token.chars << endl;
        }
        else {
          cout << s.token.chars << endl;
        }
      }
      else {
        preOrder(&s);
      }
    }
  }
}
