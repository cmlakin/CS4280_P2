#include <iostream>
#include <fstream>
#include "scanner.h"
#include "node.h"
#include "token.h"
#include "parser.h"

using namespace std;

// istream in;
string fileLine;
int lineNum = 0;

//Token getNextToken(istream&);

node_t * parser(istream& in) {
  Token tk;
  node_t* root;
  //cout << "in parser\n";
  if (in.eof()) {
    cout << "Error: Empty file, no content.\n";
    cout << "Exiting program.\n";
  }

  tk = getNextToken(in);
  // cout << "tk.ID = " << tk.ID << endl;
  // cout << "tk.line = " << tk.line << endl;
  // cout << "tk.chars = " << tk.chars << endl;
  // if (tk.ID == EOFtk){
  //   continue;
  // }
  // else {
  //   cout << "Error. Exiting program.\n";
  // }

  root = S(in, tk);
  //cout << "end of parser\n";
  return root;
}

Token getNextToken(istream& in) {
  //cout << "In getNextToken\n";
  if (fileLine.length() == 0){

    getline(in, fileLine);
    if (in.eof()){
      // return eof token - get code from p1
    }
    lineNum++;
    cout << "fileLine = " << fileLine << endl;
  }
  return scanner(fileLine, lineNum);
}

//individual functions written out.
node_t* S(istream& in, Token tk){
  cout << "-- in s\n";
  //node_t* p = getNode(S);
  if (tk.chars == "Name") {
    //p->token1 = tk;
    tk = getNextToken(in);
    //p->child = A();

    // check if valid identifier token
    if (tk.ID == 1002) {
      tk = getNextToken(in);

      // check for specific keyword token
      if (tk.chars == "Spot") {
        tk = getNextToken(in);

        // check if valid identifier token
        if (tk.ID == 1002) {
          tk = getNextToken(in);
          R(in, tk);
          cout << "-- in s\n";
          tk = getNextToken(in);
          E(in, tk);
        }
        else {
          cout << "Error. S1 Exiting program.\n";
        }
      }
      else {
        cout << "Error. S2 Exiting program.\n";
      }
    }
    else {
      cout << "Error. S3 Exiting program.\n";
    }

    //return p;  // explicit return
  }
  else {

    //return error();  // explicit return
  }
}
// need help with this one
node_t* R(istream& in, Token tk) {
  cout << "-- in r\n";
  if (tk.chars == "Place") {
    // node_t* p = getNode(A); // now we need node ???
    // p->token1 = tk;
    tk = getNextToken(in);
    //p->child = S();
    A(in, tk);
    cout << "-- in r2\n";
    //tk = getNextToken(in);
    B(in, tk);
    cout << "-- in r3\n";
    tk = getNextToken(in);
    if (tk.chars == "Home"){
      tk = getNextToken(in);
      //done
    }
  }
  else {
    cout << "Error. R1 Exiting program.\n";
  }
}

node_t* E(istream& in, Token tk) {
  cout << "-- in e\n";
  if (tk.chars == "Show") {
    // node_t* p = getNode(A);
    // p->token1 = tk;
    tk = getNextToken(in);
    //p->child = S();
    //S(in, tk);

    if (tk.ID == 1002) {
      tk = getNextToken(in);
      //done
    }
    else {
      cout << "Error. E1 Exiting program.\n";
    }
  }
  else {
    cout << "Error. E2 Exiting program.\n";
  }
}

node_t* A(istream& in, Token tk) {
  cout << "-- in a\n";
  if (tk.chars == "Name") {
    // node_t* p = getNode(A);
    // p->token1 = tk;
    tk = getNextToken(in);
    //p->child = S();
    // S(in, tk);

    if (tk.ID == 1002) {
      tk = getNextToken(in);

    }
    else {
      cout << "Error. A1 Exiting program.\n";
    }
  }
  else {
    cout << "Error. A2 Exiting program.\n";
  }
}

node_t* B(istream& in, Token tk) {
  cout << "-- in b\n";
  if (tk.chars == ".") {
    // node_t* p = getNode(A);
    // p->token1 = tk;
    tk = getNextToken(in);
    //p->child = S();
    //S(in, tk);

    C(in, tk);
    cout << "-- in b\n";
    tk = getNextToken(in);
    if (tk.chars == ".") {
      tk = getNextToken(in);
      B(in, tk);
      cout << "-- in b\n";
      tk = getNextToken(in);
      //done
    }
    else {
      cout << "Error. B1 Exiting program.\n";
    }
  }
  else if (tk.chars == "/") {
    // node_t* p = getNode(A);
    // p->token1 = tk;
    tk = getNextToken(in);
    //p->child = S();
    //S(in, tk);

    Z(in, tk);
    cout << "-- in b\n";
    tk = getNextToken(in);
  }
  else if (tk.chars == "Assign") {
    // node_t* p = getNode(A);
    // p->token1 = tk;
    tk = getNextToken(in);
    //p->child = S();
    //S(in, tk);

    J(in, tk);
    cout << "-- in b\n";
    tk = getNextToken(in);
  }
  else if (tk.chars == "Spot" || tk.chars == "Move") {
    // node_t* p = getNode(A);
    // p->token1 = tk;
    tk = getNextToken(in);
    //p->child = S();
    //S(in, tk);

    K(in, tk);
    cout << "-- in b\n";
    tk = getNextToken(in);
  }
  else if (tk.chars == "Flip") {
    // node_t* p = getNode(A);
    // p->token1 = tk;
    tk = getNextToken(in);
    //p->child = S();
    //S(in, tk);

    L(in, tk);
    cout << "-- in b\n";
    tk = getNextToken(in);
  }
  else if (tk.chars == "Show") {
    // node_t* p = getNode(A);
    // p->token1 = tk;
    tk = getNextToken(in);
    //p->child = S();
    //S(in, tk);

    E(in, tk);
    cout << "-- in b\n";
    tk = getNextToken(in);
  }
  else if (tk.chars == "{") {
    // node_t* p = getNode(A);
    // p->token1 = tk;
    tk = getNextToken(in);
    //p->child = S();
    //S(in, tk);

    F(in, tk);
    cout << "-- in b\n";
    tk = getNextToken(in);
  }
  else {  // predicts B->(epslon)
    return NULL;
  }
}

node_t* C(istream& in, Token tk) {
  cout << "-- in c\n";
  if (tk.chars == "{") {
    // node_t* p = getNode(A);
    // p->token1 = tk;
    // tk = getNextToken(in);
    //p->child = S();
    //S(in, tk);

    F(in, tk);
    cout << "-- in c\n";
    tk = getNextToken(in);
  }
  else if (tk.chars == "Here") {
    // node_t* p = getNode(A);
    // p->token1 = tk;
    tk = getNextToken(in);
    //p->child = S();
    //S(in, tk);

    G(in, tk);
    cout << "-- in c\n";
    tk = getNextToken(in);
  }
  else {
    cout << "Error. C Exiting program.\n";
  }
}


node_t* D(istream& in, Token tk) {
  cout << "-- in d\n";
  if (tk.chars == "/") {
    // node_t* p = getNode(A);
    // p->token1 = tk;
    tk = getNextToken(in);
    //p->child = S();
    //S(in, tk);

    Z(in, tk);
    cout << "-- in d\n";
    tk = getNextToken(in);
  }
  else if (tk.chars == "Assign") {
    // node_t* p = getNode(A);
    // p->token1 = tk;
    tk = getNextToken(in);
    //p->child = S();
    //S(in, tk);

    J(in, tk);
    cout << "-- in d\n";
    tk = getNextToken(in);
  }
  else if (tk.chars == "Spot" || tk.chars == "Move") {
    // node_t* p = getNode(A);
    // p->token1 = tk;
    tk = getNextToken(in);
    //p->child = S();
    //S(in, tk);

    K(in, tk);
    cout << "-- in d\n";
    tk = getNextToken(in);
  }
  else if (tk.chars == "Flip") {
    // node_t* p = getNode(A);
    // p->token1 = tk;
    tk = getNextToken(in);
    //p->child = S();
    //S(in, tk);

    L(in, tk);
    cout << "-- in d\n";
    tk = getNextToken(in);
  }
  else if (tk.chars == "Show") {
    // node_t* p = getNode(A);
    // p->token1 = tk;
    tk = getNextToken(in);
    //p->child = S();
    //S(in, tk);

    E(in, tk);
    cout << "-- in d\n";
    tk = getNextToken(in);
  }
  else if (tk.chars == "{") {
    // node_t* p = getNode(A);
    // p->token1 = tk;
    tk = getNextToken(in);
    //p->child = S();
    //S(in, tk);

    F(in, tk);
    cout << "-- in d\n";
    tk = getNextToken(in);
  }
  else {
    cout << "Error. D Exiting program.\n";
  }
}

node_t* F(istream& in, Token tk) {
  cout << "-- in f\n";
  if (tk.chars == "{") {
    if (tk.chars == "If") {
      // node_t* p = getNode(A);
      // p->token1 = tk;
      tk = getNextToken(in);
      //p->child = S();
      //S(in, tk);



      if (tk.ID == 1002) {
        tk = getNextToken(in);
        T(in, tk);
        cout << "-- in f\n";
        tk = getNextToken(in);
        W(in, tk);
        cout << "-- in f\n";
        tk = getNextToken(in);
        D(in, tk);
        cout << "-- in f\n";
        tk = getNextToken(in);

        if (tk.chars == "}") {
          tk = getNextToken(in);
          //done
        }
      }
    }
    else if (tk.chars  == "Do") {
      // node_t* p = getNode(A);
      // p->token1 = tk;
      tk = getNextToken(in);
      // p->child = S();
      //S(in, tk);

      if (tk.chars == "Again") {
        tk = getNextToken(in);
        D(in, tk);
        cout << "-- in f\n";
        tk = getNextToken(in);
        T(in, tk);
        cout << "-- in f\n";
        tk = getNextToken(in);
        W(in, tk);
        cout << "-- in f\n";
        tk = getNextToken(in);

        if (tk.chars == "}") {
          tk = getNextToken(in);
          //done
        }
      }
    }
  }
  else {
    cout << "Error. F Exiting program.\n";
  }

}

node_t* G(istream& in, Token tk) {
  cout << "-- in g\n";
  if (tk.chars == "Here") {
    // node_t* p = getNode(A);
    // p->token1 = tk;
    tk = getNextToken(in);
    //p->child = S();
    //S(in, tk);

    if (tk.ID == 1004) {
      tk = getNextToken(in);

      if (tk.chars == "There") {
        tk = getNextToken(in);
      }
      else {
        cout << "Error. G1 Exiting program.\n";
      }
    }
    else {
      cout << "Error. G2 Exiting program.\n";
    }
  }
  else {
    cout << "Error. G3 Exiting program.\n";
  }
}

node_t* T(istream& in, Token tk) {
  cout << "-- in t\n";
  if (tk.chars == "<<") {
    // node_t* p = getNode(A);
    // p->token1 = tk;
    tk = getNextToken(in);
    //p->child = S();
    //S(in, tk);

  }
  else if (tk.chars == "<-") {
    // node_t* p = getNode(A);
    // p->token1 = tk;
    tk = getNextToken(in);
    //p->child = S();
    //S(in, tk);

  }
  else {
    cout << "Error. T Exiting program.\n";
  }
}

node_t* V(istream& in, Token tk) {
  cout << "-- in v\n";
  if (tk.chars == "+") {
    // node_t* p = getNode(A);
    // p->token1 = tk;
    tk = getNextToken(in);
    //p->child = S();
    //S(in, tk);
  }
  else if (tk.chars == "%") {
    // node_t* p = getNode(A);
    // p->token1 = tk;
    tk = getNextToken(in);
    //p->child = S();
    //S(in, tk);
  }
  else if (tk.chars == "&") {
    // node_t* p = getNode(A);
    // p->token1 = tk;
    tk = getNextToken(in);
    //p->child = S();
    //S(in, tk);
  }
  else {
    cout << "Error. V Exiting program.\n";
  }
}

node_t* H(istream& in, Token tk) {
  cout << "-- in h\n";
  if (tk.chars == "/") {
    //node_t* p = getNode(A);
    //p->token1 = tk;
    tk = getNextToken(in);
    //p->child = S();
    //S(in, tk);

    Z(in, tk);
    cout << "-- in h\n";
    tk = getNextToken(in);
  }
  else {
    cout << "Error. H Exiting program.\n";
  }
}

node_t* J(istream& in, Token tk) {
  cout << "-- in j\n";
  if (tk.chars == "Assign") {
    //node_t* p = getNode(A);
    //p->token1 = tk;
    tk = getNextToken(in);
    //p->child = S();
    //S(in, tk);

    if (tk.ID == 1002) {
      tk = getNextToken(in);
      D(in, tk);
      cout << "-- in j\n";
      tk = getNextToken(in);
    }
    else {
      cout << "Error. J1 Exiting program.\n";
    }
  }
  else {
    cout << "Error. J2 Exiting program.\n";
  }
}

node_t* K(istream& in, Token tk) {
  cout << "-- in k\n";
  if (tk.chars == "Spot") {
    //node_t* p = getNode(A);
    //p->token1 = tk;
    tk = getNextToken(in);
    //p->child = S();
    //S(in, tk);

    if (tk.ID == 1004) {
      tk = getNextToken(in);

      if (tk.chars == "Show") {
        tk = getNextToken(in);

        if (tk.ID == 1004) {
          tk = getNextToken(in);
        }
        else {
          cout << "Error. K1 Exiting program.\n";
        }
      }
      else {
        cout << "Error. K2 Exiting program.\n";
      }
    }
  }
  else   if (tk.chars == "Move") {
    //node_t* p = getNode(A);
    //p->token1 = tk;
    tk = getNextToken(in);
    //p->child = S();
    //S(in, tk);

      if (tk.ID == 1002) {
        tk = getNextToken(in);

        if (tk.chars == "Show") {
          tk = getNextToken(in);

          if (tk.ID == 1002) {
            tk = getNextToken(in);
          }
          else {
            cout << "Error. K3 Exiting program.\n";
          }
        }
        else {
          cout << "Error. K4 Exiting program.\n";
        }
      }
      else {
        cout << "Error. K5 Exiting program.\n";
      }
  }
  else {
    cout << "Error. K6 Exiting program.\n";
  }
}

node_t* L(istream& in, Token tk) {
  cout << "-- in l\n";
  if (tk.chars == "Flip") {
    //node_t* p = getNode(A);
    //p->token1 = tk;
    tk = getNextToken(in);
    //p->child = S();
    //S(in, tk);

    if (tk.ID == 1002) {
      tk = getNextToken(in);
    }
    else {
      cout << "Error. L1 Exiting program.\n";
    }
  }
  else {
    cout << "Error. L2 Exiting program.\n";
  }
}

node_t* W(istream& in, Token tk) {
  cout << "-- in w\n";
  if (tk.ID == 1004) {
    //node_t* p = getNode(A);
    //p->token1 = tk;
    tk = getNextToken(in);
    //p->child = S();
    //S(in, tk);

    if (tk.chars == ".") {
      tk = getNextToken(in);
    }
    else if (tk.chars == "+" || tk.chars == "%" || tk.chars == "&"){
      tk = getNextToken(in);
      V(in, tk);
      cout << "-- in w\n";
      tk = getNextToken(in);
      if (tk.ID == 1004) {
        tk = getNextToken(in);
      }
      else {
        cout << "Error. W1 Exiting program.\n";
      }

    }
    else {
      cout << "Error. W2 Exiting program.\n";
    }
  }
  else {
    cout << "Error. W3 Exiting program.\n";
  }
}

node_t* Z(istream& in, Token tk) {
  cout << "-- in w\n";
  if (tk.ID == 1002) {
    //node_t* p = getNode(A);
    //p->token1 = tk;
    tk = getNextToken(in);
    //p->child = S();
    //S(in, tk);
  }
  else if (tk.ID == 1004) {
    // node_t* p = getNode(A);
    // p->token1 = tk;
    tk = getNextToken(in);
    //p->child = S();
    //S(in, tk);
  }
  else {
    cout << "Error. Z Exiting program.\n";
  }
}
