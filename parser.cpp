#include <iostream>
#include <fstream>
#include "scanner.h"
#include "node.h"
#include "token.h"
#include "buildtree.h"
#include "parser.h"

using namespace std;

string fileLine;
int lineNum = 0;

node_t * parser(istream& in) {
  Token tk;
  Token tkS;

  node_t* root;
  //cout << "in parser\n";
  if (in.eof()) {
    cout << "Error: Empty file, no content.\n";
    cout << "Exiting program.\n";
  }

  tk = getNextToken(in);

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
    //cout << "fileLine = " << fileLine << endl;
  }
  return scanner(fileLine, lineNum);
}

//individual functions written out.
node_t* S(istream& in, Token& tk){

  node_t* p= new node_t('S');
  cout << "in S token.chars = " << tk.chars << endl;

  if (tk.chars == "Name") {
    node_t t(tk);
    p->children.push_back(t);
    cout << "Node = " << p->label << endl;
    cout << t.token.chars << " \n";

    tk = getNextToken(in);
    //p->child = A();
    cout << "in S token.chars = " << tk.chars << endl;
    // check if valid identifier token
    if (tk.ID == 1002) {
      node_t t(tk);
      p->children.push_back(t);
      cout << "Node = " << p->label << endl;
      cout << "size = " << p->children.size() << endl;
      cout << t.token.chars << " \n";

      tk = getNextToken(in);
      cout << "in S token.chars = " << tk.chars << endl;
      // check for specific keyword token
      if (tk.chars == "Spot") {
        tk = getNextToken(in);
        cout << "in S token.chars = " << tk.chars << endl;
        // check if valid identifier token
        if (tk.ID == 1002) {
          tk = getNextToken(in);
          cout << "calling R\n";
          p->children.push_back(t);
          R(in, tk);
          cout << "-- in s after r\n";
          //tk = getNextToken(in);
          cout << "calling E\n";
          E(in, tk);
          cout << "-- in s after e\n";
        }
        else {
          cout << "Error. S1 Exiting program.\n";
          exit(-1);
        }
      }
      else {
        cout << "Error. S2 Exiting program.\n";
        exit(-1);
      }
    }
    else {
      cout << "Error. S3 Exiting program.\n";
      exit(-1);
    }

    //return p;  // explicit return
  }
  else {
    cout << "Error. S4 Exiting program.\n";
    exit(-1);
  }

  return p;
}
// need help with this one
node_t* R(istream& in, Token& tk) {
  node_t* p= new node_t('R');
  cout << "in R token.chars = " << tk.chars << endl;
  if (tk.chars == "Place") {
    // node_t* p= getNode(A); // now we need node ???
    // p->token1 = tk;
    tk = getNextToken(in);
    //p->child = S();
    cout << "calling A\n";
    A(in, tk);
    cout << "-- in r after  a\n";
    cout << "calling B\n";
    B(in, tk);
    cout << "-- in r after b\n";
    cout << "in R token.chars = " << tk.chars << endl;
    if (tk.chars == "Home"){
      tk = getNextToken(in);
      cout << "in R token.chars = " << tk.chars << endl;
      //done
    }
  }
  else {
    cout << "Error. R1 Exiting program.\n";
    exit(-1);
  }
  return p;
}

node_t* E(istream& in, Token& tk) {
  node_t* p= new node_t('E');
  cout << "in E token.chars = " << tk.chars << endl;
  if (tk.chars == "Show") {
    // node_t* p= getNode(A);
    // p->token1 = tk;
    tk = getNextToken(in);
    //p->child = S();
    //S(in, tk);

    cout << "in E token.chars = " << tk.chars << endl;
    if (tk.ID == 1002) {
      tk = getNextToken(in);
      cout << "in E token.chars = " << tk.chars << endl;
      //done
    }
    else {
      cout << "Error. E1 Exiting program.\n";
      exit(-1);
    }
  }
  else {
    cout << "Error. E2 Exiting program.\n";
    exit(-1);
  }
  return p;
}

node_t* A(istream& in, Token& tk) {
  node_t* p= new node_t('A');
  cout << "in A token.chars = " << tk.chars << endl;

  if (tk.chars == "Name") {
    // node_t* p= getNode(A);
    // p->token1 = tk;
    tk = getNextToken(in);
    cout << "in A token.chars = " << tk.chars << endl;
    //p->child = S();
    // S(in, tk);

    if (tk.ID == 1002) {
      tk = getNextToken(in);
      cout << "in A token.chars = " << tk.chars << endl;
    }
    else {
      cout << "Error. A1 Exiting program.\n";
      exit(-1);
    }
  }
  else {
    cout << "Error. A2 Exiting program.\n";
    exit(-1);
  }
  return p;
}

node_t* B(istream& in, Token& tk) {
  node_t* p= new node_t('B');
  if (tk.chars == ".") {
    cout << "in B token.chars = " << tk.chars << endl;
    // node_t* p= getNode(A);
    // p->token1 = tk;
    tk = getNextToken(in);
    //p->child = S();
    //S(in, tk);
    cout << "in B token.chars = " << tk.chars << "\n calling C\n";
    C(in, tk);
    cout << "-- in b  after <C>\n";
    cout << "in B token.chars = " << tk.chars << endl;
    if (tk.chars == ".") {
      tk = getNextToken(in);
      cout << "in B token.chars = " << tk.chars << "\n calling B\n";
      B(in, tk);
      cout << "-- in b after .<B>\n";
      cout << "in B token.chars = " << tk.chars << "\n calling B\n";
      //done
    }
    else {
      cout << "Error. B1 Exiting program.\n";
      exit(-1);
    }
  }
  else if (tk.chars == "/") {
    // node_t* p= getNode(A);
    // p->token1 = tk;
    //p->child = S();
    //S(in, tk);
    cout << "calling D /\n";
    D(in, tk);
    cout << "-- in b after D /\n";
    cout << "in B token.chars = " << tk.chars << endl;
  }
  else if (tk.chars == "Assign") {
    // node_t* p= getNode(A);
    // p->token1 = tk;
    //p->child = S();
    //S(in, tk);
    cout << "calling D Assign\n";
    D(in, tk);
    cout << "-- in b after D Assign\n";
    cout << "in B token.chars = " << tk.chars << endl;

  }
  else if (tk.chars == "Spot" || tk.chars == "Move") {
    // node_t* p= getNode(A);
    // p->token1 = tk;
    //p->child = S();
    //S(in, tk);
    cout << "calling D Spot/Move\n";
    D(in, tk);
    cout << "-- in b after D Spot/Move\n";
    cout << "in B token.chars = " << tk.chars << endl;

  }
  else if (tk.chars == "Flip") {
    // node_t* p= getNode(A);
    // p->token1 = tk;
    //p->child = S();
    //S(in, tk);
    cout << "calling D Flip\n";
    D(in, tk);
    cout << "-- in b after D Flip\n";
    //tk = getNextToken(in);
    cout << "in B token.chars = " << tk.chars << endl;

  }
  else if (tk.chars == "Show") {
    // node_t* p= getNode(A);
    // p->token1 = tk;
    //p->child = S();
    //S(in, tk);
    cout << "calling D Show\n";
    D(in, tk);
    cout << "-- in b after D Show\n";
    //tk = getNextToken(in);
  }
  else if (tk.chars == "{") {
    // node_t* p= getNode(A);
    // p->token1 = tk;
    //p->child = S();
    //S(in, tk);
    cout << "calling D {\n";
    D(in, tk);
    cout << "-- in b after D {\n";
    //tk = getNextToken(in);
  }
  else {  // predicts B->(epslon)
    //return p;
  }
  return p;
}

node_t* C(istream& in, Token& tk) {
  node_t* p= new node_t('C');
  cout << "in C token.chars = " << tk.chars << endl;
  if (tk.chars == "{") {
    // node_t* p= getNode(A);
    // p->token1 = tk;
    //p->child = S();
    //S(in, tk);
    cout << "calling F\n";
    F(in, tk);
    cout << "-- in c after f\n";
    cout << "in C token.chars = " << tk.chars << endl;

  }
  else if (tk.chars == "Here") {
    // node_t* p= getNode(A);
    // p->token1 = tk;
    //p->child = S();
    //S(in, tk);
    cout << "calling G\n";
    G(in, tk);
    cout << "-- in c after g\n";
    cout << "in C token.chars = " << tk.chars << endl;
  }
  else {
    cout << "Error. C Exiting program.\n";
    exit(-1);
  }
  return p;
}


node_t* D(istream& in, Token& tk) {
  node_t* p= new node_t('D');
  cout << "in D token.chars = " << tk.chars << endl;
  if (tk.chars == "/") {
    // node_t* p= getNode(A);
    // p->token1 = tk;
    //p->child = S();
    //S(in, tk);
    cout << "calling H\n";
    H(in, tk);
    cout << "-- in d after H\n";
    cout << "in D after H token.chars = " << tk.chars << endl;
  }
  else if (tk.chars == "Assign") {
    // node_t* p= getNode(A);
    // p->token1 = tk;
    //p->child = S();
    //S(in, tk);
    cout << "calling J\n";
    J(in, tk);
    cout << "-- in d after j\n";
    cout << "in D after J token.chars = " << tk.chars << endl;

  }
  else if (tk.chars == "Spot" || tk.chars == "Move") {
    // node_t* p= getNode(A);
    // p->token1 = tk;
    //p->child = S();
    //S(in, tk);
    cout << "calling K\n";
    K(in, tk);
    cout << "-- in d after k\n";
    cout << "in D token.chars = " << tk.chars << endl;
  }
  else if (tk.chars == "Flip") {
    // node_t* p= getNode(A);
    // p->token1 = tk;
    //p->child = S();
    //S(in, tk);
    cout << "calling L\n";
    L(in, tk);
    cout << "-- in d after l\n";
    cout << "in D token.chars = " << tk.chars << endl;
  }
  else if (tk.chars == "Show") {
    // node_t* p= getNode(A);
    // p->token1 = tk;
    //tk = getNextToken(in);
    //p->child = S();
    //S(in, tk);
    cout << "calling E\n";
    E(in, tk);
    cout << "-- in d after e\n";
    cout << "in D token.chars = " << tk.chars << endl;
  }
  else if (tk.chars == "{") {
    // node_t* p= getNode(A);
    // p->token1 = tk;
    //tk = getNextToken(in);
    //p->child = S();
    //S(in, tk);
    cout << "calling F\n";
    F(in, tk);
    cout << "-- in d after f\n";
    cout << "in D token.chars = " << tk.chars << endl;
  }
  else {
    cout << "Error. D Exiting program.\n";
    exit(-1);
  }
  return p;
}

node_t* F(istream& in, Token& tk) {
  node_t* p= new node_t('F');
  cout << "in F token.chars = " << tk.chars << endl;
  if (tk.chars == "{") {
    tk = getNextToken(in);
    cout << "in F token.chars = " << tk.chars << endl;
    if (tk.chars == "If") {
      // node_t* p= getNode(A);
      // p->token1 = tk;
      tk = getNextToken(in);
      cout << "in F token.chars = " << tk.chars << endl;
      //p->child = S();
      //S(in, tk);

      if (tk.ID == 1002) {
        tk = getNextToken(in);
        cout << "in F token.chars = " << tk.chars << "\n calling T\n";
        T(in, tk);
        cout << "-- in f after t\n calling W\n";
        W(in, tk);
        cout << "-- in f after w\ncalling D\n";
        D(in, tk);
        cout << "-- in f after d\n";
        cout << "in F token.chars = " << tk.chars << endl;

        if (tk.chars == "}") {
          tk = getNextToken(in);
          cout << "in F token.chars = " << tk.chars << endl;
          //done
        }
        else {
          cout << "Error. F1 Exiting program.\n";
          exit(-1);
        }
      }
      else {
        cout << "Error. F2 Exiting program.\n";
        exit(-1);
      }
    }
    else if (tk.chars  == "Do") {
      // node_t* p= getNode(A);
      // p->token1 = tk;
      tk = getNextToken(in);
      cout << "in F token.chars = " << tk.chars << endl;
      // p->child = S();
      //S(in, tk);

      if (tk.chars == "Again") {
        tk = getNextToken(in);
        cout << "in F token.chars = " << tk.chars << "\ncalling D\n";
        D(in, tk);
        cout << "-- in f after d\ncalling T\n";
        T(in, tk);
        cout << "-- in f after t\ncalling W\n";
        W(in, tk);
        cout << "-- in f after w\n";
        tk = getNextToken(in);
        cout << "in F token.chars = " << tk.chars << endl;

        if (tk.chars == "}") {
          tk = getNextToken(in);
          cout << "in F token.chars = " << tk.chars << endl;
          //done
        }
        else {
          cout << "Error. F3 Exiting program.\n";
          exit(-1);
        }
      }
      else {
        cout << "Error. F2 Exiting program.\n";
        exit(-1);
      }
    }
  }
  else {
    cout << "Error. F Exiting program.\n";
    exit(-1);
  }
  return p;
}

node_t* G(istream& in, Token& tk) {
  node_t* p= new node_t('G');
  cout << "in G token.chars = " << tk.chars << endl;
  if (tk.chars == "Here") {
    // node_t* p= getNode(A);
    // p->token1 = tk;
    tk = getNextToken(in);
    cout << "in G token.chars = " << tk.chars << endl;
    //p->child = S();
    //S(in, tk);

    if (tk.ID == 1004) {
      tk = getNextToken(in);
      cout << "in G token.chars = " << tk.chars << endl;

      if (tk.chars == "There") {
        tk = getNextToken(in);
        cout << "in G token.chars = " << tk.chars << endl;
      }
      else {
        cout << "Error. G1 Exiting program.\n";
        exit(-1);
      }
    }
    else {
      cout << "Error. G2 Exiting program.\n";
      exit(-1);
    }
  }
  else {
    cout << "Error. G3 Exiting program.\n";
    exit(-1);
  }
  return p;
}

node_t* T(istream& in, Token& tk) {
  node_t* p= new node_t('T');
  cout << "in T token.chars = " << tk.chars << endl;
  if (tk.chars == "<<") {
    // node_t* p= getNode(A);
    // p->token1 = tk;
    tk = getNextToken(in);
    cout << "in T token.chars = " << tk.chars << endl;
    //p->child = S();
    //S(in, tk);

  }
  else if (tk.chars == "<-") {
    // node_t* p= getNode(A);
    // p->token1 = tk;
    tk = getNextToken(in);
    cout << "in T token.chars = " << tk.chars << endl;
    //p->child = S();
    //S(in, tk);

  }
  else {
    cout << "Error. T Exiting program.\n";
    exit(-1);
  }
}

node_t* V(istream& in, Token& tk) {
  node_t* p= new node_t('V');
  cout << "in V token.chars = " << tk.chars << endl;
  if (tk.chars == "+") {
    // node_t* p= getNode(A);
    // p->token1 = tk;
    tk = getNextToken(in);
    cout << "in V token.chars = " << tk.chars << endl;
    //p->child = S();
    //S(in, tk);
  }
  else if (tk.chars == "%") {
    // node_t* p= getNode(A);
    // p->token1 = tk;
    tk = getNextToken(in);
    cout << "in V token.chars = " << tk.chars << endl;
    //p->child = S();
    //S(in, tk);
  }
  else if (tk.chars == "&") {
    // node_t* p= getNode(A);
    // p->token1 = tk;
    tk = getNextToken(in);
    cout << "in V token.chars = " << tk.chars << endl;
    //p->child = S();
    //S(in, tk);
  }
  else {
    cout << "Error. V Exiting program.\n";
    exit(-1);
  }
  return p;
}

node_t* H(istream& in, Token& tk) {
  node_t* p= new node_t('H');
  cout << "in H token.chars = " << tk.chars << endl;
  if (tk.chars == "/") {
    //node_t* p= getNode(A);
    //p->token1 = tk;
    tk = getNextToken(in);
    cout << "in H token.chars = " << tk.chars << "\ncalling Z\n";
    //p->child = S();
    //S(in, tk);

    Z(in, tk);
    cout << "-- in h after z\n";
    cout << "in H token.chars = " << tk.chars << endl;
  }
  else {
    cout << "Error. H Exiting program.\n";
    exit(-1);
  }
  return p;
}

node_t* J(istream& in, Token& tk) {
  node_t* p= new node_t('J');
  cout << "in J token.chars = " << tk.chars << endl;
  if (tk.chars == "Assign") {
    //node_t* p= getNode(A);
    //p->token1 = tk;
    tk = getNextToken(in);
    cout << "in J token.chars = " << tk.chars << endl;
    //p->child = S();
    //S(in, tk);

    if (tk.ID == 1002) {
      tk = getNextToken(in);
      cout << "in J token.chars = " << tk.chars << "\ncalling D()\n";
      D(in, tk);
      cout << "-- in j after D\n";
      tk = getNextToken(in);
      cout << "in J token.chars = " << tk.chars << endl;
    }
    else {
      cout << "Error. J1 Exiting program.\n";
      exit(-1);
    }
  }
  else {
    cout << "Error. J2 Exiting program.\n";
    exit(-1);
  }
  return p;
}

node_t* K(istream& in, Token& tk) {
  node_t* p= new node_t('K');
  cout << "in K token.chars = " << tk.chars << endl;
  if (tk.chars == "Spot") {
    //node_t* p= getNode(A);
    //p->token1 = tk;
    tk = getNextToken(in);
    cout << "in K token.chars = " << tk.chars << endl;
    //p->child = S();
    //S(in, tk);

    if (tk.ID == 1004) {
      tk = getNextToken(in);
      cout << "in K token.chars = " << tk.chars << endl;

      if (tk.chars == "Show") {
        tk = getNextToken(in);
        cout << "in K token.chars = " << tk.chars << endl;

        if (tk.ID == 1004) {
          tk = getNextToken(in);
          cout << "in K token.chars = " << tk.chars << endl;
        }
        else {
          cout << "Error. K1 Exiting program.\n";
          exit(-1);
        }
      }
      else {
        cout << "Error. K2 Exiting program.\n";
        exit(-1);
      }
    }
  }
  else   if (tk.chars == "Move") {
    //node_t* p= getNode(A);
    //p->token1 = tk;
    tk = getNextToken(in);
    cout << "in K token.chars = " << tk.chars << endl;
    //p->child = S();
    //S(in, tk);

      if (tk.ID == 1002) {
        tk = getNextToken(in);
        cout << "in K token.chars = " << tk.chars << endl;

        if (tk.chars == "Show") {
          tk = getNextToken(in);
          cout << "in K token.chars = " << tk.chars << endl;

          if (tk.ID == 1002) {
            tk = getNextToken(in);
            cout << "in K token.chars = " << tk.chars << endl;
          }
          else {
            cout << "Error. K3 Exiting program.\n";
            exit(-1);
          }
        }
        else {
          cout << "Error. K4 Exiting program.\n";
          exit(-1);
        }
      }
      else {
        cout << "Error. K5 Exiting program.\n";
        exit(-1);
      }
  }
  else {
    cout << "Error. K6 Exiting program.\n";
    exit(-1);
  }
  return p;
}

node_t* L(istream& in, Token& tk) {
  node_t* p= new node_t('L');
  cout << "in L token.chars = " << tk.chars << endl;
  if (tk.chars == "Flip") {
    //node_t* p= getNode(A);
    //p->token1 = tk;
    tk = getNextToken(in);
    cout << "in L token.chars = " << tk.chars << endl;
    //p->child = S();
    //S(in, tk);

    if (tk.ID == 1002) {
      tk = getNextToken(in);
      cout << "in L token.chars = " << tk.chars << endl;
    }
    else {
      cout << "Error. L1 Exiting program.\n";
      exit(-1);
    }
  }
  else {
    cout << "Error. L2 Exiting program.\n";
    exit(-1);
  }
}

node_t* W(istream& in, Token& tk) {
  node_t* p= new node_t('W');
  cout << "in W token.chars = " << tk.chars << endl;
  if (tk.ID == 1004) {
    //node_t* p= getNode(A);
    //p->token1 = tk;
    tk = getNextToken(in);
    cout << "in W token.chars = " << tk.chars << endl;
    //p->child = S();
    //S(in, tk);

    if (tk.chars == ".") {
      tk = getNextToken(in);
      cout << "in W token.chars = " << tk.chars << endl;
    }
    else if (tk.chars == "+" || tk.chars == "%" || tk.chars == "&"){
      tk = getNextToken(in);
      cout << "in W token.chars = " << tk.chars << "\ncalling V()\n";
      V(in, tk);
      cout << "-- in w after v\n";
      tk = getNextToken(in);
      cout << "in W token.chars = " << tk.chars << endl;
      if (tk.ID == 1004) {
        tk = getNextToken(in);
        cout << "in W token.chars = " << tk.chars << endl;
      }
      else {
        cout << "Error. W1 Exiting program.\n";
        exit(-1);
      }

    }
    else {
      cout << "Error. W2 Exiting program.\n";
      exit(-1);
    }
  }
  else {
    cout << "Error. W3 Exiting program.\n";
    exit(-1);
  }
  return p;
}

node_t* Z(istream& in, Token& tk) {
  node_t* p= new node_t('Z');
  cout << "in Z token.chars = " << tk.chars << endl;
  if (tk.ID == 1002) {
    //node_t* p= getNode(A);
    //p->token1 = tk;
    tk = getNextToken(in);
    cout << "in Z token.chars = " << tk.chars << endl;
    //p->child = S();
    //S(in, tk);
  }
  else if (tk.ID == 1004) {
    // node_t* p= getNode(A);
    // p->token1 = tk;
    tk = getNextToken(in);
    cout << "in Z token.chars = " << tk.chars << endl;
    //p->child = S();
    //S(in, tk);
  }
  else {
    cout << "Error. Z Exiting program.\n";
    exit(-1);
  }
  return p;
}
