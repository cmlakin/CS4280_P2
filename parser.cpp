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

Token getNextToken(istream&);

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
  //   cout << "Error. Exiting program.";
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
          E(in, tk);
        }
        else {
          cout << "Error. Exiting program.";
        }
      }
      else {
        cout << "Error. Exiting program.";
      }
    }
    else {
      cout << "Error. Exiting program.";
    }

    //return p;  // explicit return
  }
  else {

    //return error();  // explicit return
  }
}
// need help with this one
node_t* R(istream& in, Token tk) {

  if (tk.chars == "Place") {
    // node_t* p = getNode(A); // now we need node ???
    // p->token1 = tk;
    tk = getNextToken(in);
    //p->child = S();
    S(in, tk);

    A(in, tk);
    B(in, tk);
    if (tk.chars == "Home"){
      //done
    }
  }
  else {
    cout << "Error. Exiting program.";
  }
}

node_t* E(istream& in, Token tk) {

  if (tk.chars == "Show") {
    // node_t* p = getNode(A);
    // p->token1 = tk;
    tk = getNextToken(in);
    //p->child = S();
    S(in, tk);

    if (tk.ID == 1002) {
      //done
    }
    else {
      cout << "Error. Exiting program.";
    }
  }
  else {
    //error
  }
}

node_t* A(istream& in, Token tk) {

  if (tk.chars == "Name") {
    // node_t* p = getNode(A);
    // p->token1 = tk;
    tk = getNextToken(in);
    //p->child = S();
    S(in, tk);

    if (tk.ID == 1002) {
      tk = getNextToken(in);

    }
    else {
      cout << "Error. Exiting program.";
    }
  }
  else {
    //error
  }
}

node_t* B(istream& in, Token tk) {

  if (tk.chars == ".") {
    // node_t* p = getNode(A);
    // p->token1 = tk;
    tk = getNextToken(in);
    //p->child = S();
    S(in, tk);

    C(in, tk);
    if (tk.chars == ".") {
      tk = getNextToken(in);
      B(in, tk);
      //done
    }
    else {
      cout << "Error. Exiting program.";
    }
  }
  else if (tk.chars == "/") {
    // node_t* p = getNode(A);
    // p->token1 = tk;
    tk = getNextToken(in);
    //p->child = S();
    S(in, tk);

    Z(in, tk);
  }
  else if (tk.chars == "Assign") {
    // node_t* p = getNode(A);
    // p->token1 = tk;
    tk = getNextToken(in);
    //p->child = S();
    S(in, tk);

    J(in, tk);
  }
  else if (tk.chars == "Spot" || tk.chars == "Move") {
    // node_t* p = getNode(A);
    // p->token1 = tk;
    tk = getNextToken(in);
    //p->child = S();
    S(in, tk);

    K(in, tk);
  }
  else if (tk.chars == "Flip") {
    // node_t* p = getNode(A);
    // p->token1 = tk;
    tk = getNextToken(in);
    //p->child = S();
    S(in, tk);

    L(in, tk);
  }
  else if (tk.chars == "Show") {
    // node_t* p = getNode(A);
    // p->token1 = tk;
    tk = getNextToken(in);
    //p->child = S();
    S(in, tk);

    E(in, tk);
  }
  else if (tk.chars == "{") {
    // node_t* p = getNode(A);
    // p->token1 = tk;
    tk = getNextToken(in);
    //p->child = S();
    S(in, tk);

    F(in, tk);
  }
  else {  // predicts B->(epslon)
    return NULL;
  }
}

node_t* C(istream& in, Token tk) {

  if (tk.chars == "{") {
    // node_t* p = getNode(A);
    // p->token1 = tk;
    tk = getNextToken(in);
    //p->child = S();
    S(in, tk);

    F(in, tk);
  }
  else if (tk.chars == "Here") {
    // node_t* p = getNode(A);
    // p->token1 = tk;
    tk = getNextToken(in);
    //p->child = S();
    S(in, tk);

    G(in, tk);
  }
  else {
    //return error
  }
}


node_t* D(istream& in, Token tk) {

  if (tk.chars == "/") {
    // node_t* p = getNode(A);
    // p->token1 = tk;
    tk = getNextToken(in);
    //p->child = S();
    S(in, tk);

    Z(in, tk);
  }
  else if (tk.chars == "Assign") {
    // node_t* p = getNode(A);
    // p->token1 = tk;
    tk = getNextToken(in);
    //p->child = S();
    S(in, tk);

    J(in, tk);
  }
  else if (tk.chars == "Spot" || tk.chars == "Move") {
    // node_t* p = getNode(A);
    // p->token1 = tk;
    tk = getNextToken(in);
    //p->child = S();
    S(in, tk);

    K(in, tk);
  }
  else if (tk.chars == "Flip") {
    // node_t* p = getNode(A);
    // p->token1 = tk;
    tk = getNextToken(in);
    //p->child = S();
    S(in, tk);

    L(in, tk);
  }
  else if (tk.chars == "Show") {
    // node_t* p = getNode(A);
    // p->token1 = tk;
    tk = getNextToken(in);
    //p->child = S();
    S(in, tk);

    E(in, tk);
  }
  else if (tk.chars == "{") {
    // node_t* p = getNode(A);
    // p->token1 = tk;
    tk = getNextToken(in);
    //p->child = S();
    S(in, tk);

    F(in, tk);
  }
  else {
    //return error
  }
}

node_t* F(istream& in, Token tk) {

  if (tk.chars == "{") {
    // node_t* p = getNode(A);
    // p->token1 = tk;
    tk = getNextToken(in);
    //p->child = S();
    S(in, tk);

    if (tk.chars == "If") {
      tk = getNextToken(in);

      if (tk.ID == 1002) {
        tk = getNextToken(in);

        T(in, tk);
        W(in, tk);
        D(in, tk);

        if (tk.chars == "}") {
          //done
        }
      }
    }
    else if (tk.chars  == "Do") {
      // node_t* p = getNode(A);
      // p->token1 = tk;
      tk = getNextToken(in);
      // p->child = S();
      S(in, tk);

      if (tk.chars == "Again") {
        tk = getNextToken(in);

        D(in, tk);
        T(in, tk);
        W(in, tk);

        if (tk.chars == "}") {
          //done
        }
      }
    }
    else {
      cout << "Error. Exiting program.";
    }
  }
  else {
    //return error
  }
}

node_t* G(istream& in, Token tk) {

  if (tk.chars == "Here") {
    // node_t* p = getNode(A);
    // p->token1 = tk;
    tk = getNextToken(in);
    //p->child = S();
    S(in, tk);

    if (tk.ID == 1004) {
      tk = getNextToken(in);

      if (tk.chars == "There") {
        tk = getNextToken(in);
      }
      else {
        cout << "Error. Exiting program.";
      }
    }
    else {
      cout << "Error. Exiting program.";
    }
  }
  else {
    //return error
  }
}

node_t* T(istream& in, Token tk) {

  if (tk.chars == "<<") {
    // node_t* p = getNode(A);
    // p->token1 = tk;
    tk = getNextToken(in);
    //p->child = S();
    S(in, tk);

  }
  else if (tk.chars == "<-") {
    // node_t* p = getNode(A);
    // p->token1 = tk;
    tk = getNextToken(in);
    //p->child = S();
    S(in, tk);

  }
  else {
    //return error
  }
}

node_t* V(istream& in, Token tk) {

  if (tk.chars == "+") {
    // node_t* p = getNode(A);
    // p->token1 = tk;
    tk = getNextToken(in);
    //p->child = S();
    S(in, tk);
  }
  else if (tk.chars == "%") {
    // node_t* p = getNode(A);
    // p->token1 = tk;
    tk = getNextToken(in);
    //p->child = S();
    S(in, tk);
  }
  else if (tk.chars == "&") {
    // node_t* p = getNode(A);
    // p->token1 = tk;
    tk = getNextToken(in);
    //p->child = S();
    S(in, tk);
  }
  else {
    // return error
  }
}

node_t* H(istream& in, Token tk) {

  if (tk.chars == "/") {
    //node_t* p = getNode(A);
    //p->token1 = tk;
    tk = getNextToken(in);
    //p->child = S();
    S(in, tk);

    Z(in, tk);
  }
  else {  // predicts A->(epslon)
    //return error
  }
}

node_t* J(istream& in, Token tk) {

  if (tk.chars == "Assign") {
    //node_t* p = getNode(A);
    //p->token1 = tk;
    tk = getNextToken(in);
    //p->child = S();
    S(in, tk);

    if (tk.ID == 1002) {  // processing a
      tk = getNextToken(in);

      D(in, tk);
    }
    else {
      cout << "Error. Exiting program.";
    }
  }
  else {
    // return error;
  }
}

node_t* K(istream& in, Token tk) {

  if (tk.chars == "Spot") {
    //node_t* p = getNode(A);
    //p->token1 = tk;
    tk = getNextToken(in);
    //p->child = S();
    S(in, tk);

    if (tk.ID == 1004) {
      tk = getNextToken(in);

      if (tk.chars == "Show") {
        tk = getNextToken(in);

        if (tk.ID == 1004) {
          tk = getNextToken(in);
        }
        else {
          cout << "Error. Exiting program.";
        }
      }
      else {
        cout << "Error. Exiting program.";
      }
    }
  }
  else   if (tk.chars == "Move") {
    //node_t* p = getNode(A);
    //p->token1 = tk;
    tk = getNextToken(in);
    //p->child = S();
    S(in, tk);

      if (tk.ID == 1002) {
        tk = getNextToken(in);

        if (tk.chars == "Show") {
          tk = getNextToken(in);

          if (tk.ID == 1002) {
            tk = getNextToken(in);
          }
          else {
            cout << "Error. Exiting program.";
          }
        }
        else {
          cout << "Error. Exiting program.";
        }
      }
      else {
        cout << "Error. Exiting program.";
      }
  }
  else {
    //return error
  }
}

node_t* L(istream& in, Token tk) {

  if (tk.chars == "Flip") {
    //node_t* p = getNode(A);
    //p->token1 = tk;
    tk = getNextToken(in);
    //p->child = S();
    S(in, tk);

    if (tk.ID == 1002) {
      tk = getNextToken(in);
    }
    else {
      cout << "Error. Exiting program.";
    }
  }
  else {
    //return error;
  }
}

node_t* W(istream& in, Token tk) {

  if (tk.ID == 1004) {
    //node_t* p = getNode(A);
    //p->token1 = tk;
    tk = getNextToken(in);
    //p->child = S();
    S(in, tk);

    if (tk.chars == ".") {
      tk = getNextToken(in);
    }
    else if (tk.chars == "+" || tk.chars == "%" || tk.chars == "&"){
      V(in, tk);

      if (tk.ID == 1004) {
        tk = getNextToken(in);
      }
      else {
        cout << "Error. Exiting program.";
      }

    }
    else {
      cout << "Error. Exiting program.";
    }
  }
  else {
    //return error
  }
}

node_t* Z(istream& in, Token tk) {

  if (tk.ID == 1002) {
    //node_t* p = getNode(A);
    //p->token1 = tk;
    tk = getNextToken(in);
    //p->child = S();
    S(in, tk);
  }
  else if (tk.ID == 1004) {
    // node_t* p = getNode(A);
    // p->token1 = tk;
    tk = getNextToken(in);
    //p->child = S();
    S(in, tk);
  }
  else {
    //return error
  }
}
