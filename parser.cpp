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
  cout << "in parser\n";
  if (in.eof()) {
    cout << "Error: Empty file, no content.\n";
    cout << "Exiting program.\n";
  }

  tk = getNextToken(in);
  cout << "tk.ID = " << tk.ID << endl;
  cout << "tk.line = " << tk.line << endl;
  cout << "tk.chars = " << tk.chars << endl;
  // if (tk.ID == EOFtk){
  //   continue;
  // }
  // else {
  //   cout << "Error. Exiting program.";
  // }

  //root = S(tk);
  cout << "end of parser\n";
  return root;
}

Token getNextToken(istream& in) {
  cout << "In getNextToken\n";
  if (fileLine.length() == 0){

    getline(in, fileLine);
    if (in.eof()){
      // return eof token - get code from p1
    }
    lineNum++;
  }
  return scanner(fileLine, lineNum);
}

// individual functions written out.
// node_t* S(istream& in, Token tk){
//
//   node_t* p = getNode(S);
//   if (tk.ID == "Name") { // predict S->bA since bc First(bAa)
//     p->token1 = tk; // needed to be stored
//     tk = getNextToken(); // processing and consume matching tokens
//     p->child = A(); // processing
//
//     if (tk.ID == "Identifier") {  // processing
//       tk = scanner();
//
//       if (tk.ID == "Spot") {  // processing
//         tk = scanner();
//
//         if (tk.ID == "Identifier") {  // processing
//           tk = scanner();
//
//           //R();
//           //E();
//         }
//         else {
//           cout << "Error. Exiting program.";
//         }
//       }
//       else {
//         cout << "Error. Exiting program.";
//       }
//     }
//     else {
//       cout << "Error. Exiting program.";
//     }
//
//     return p;  // explicit return
//   }
//   else {
//
//     //return error();  // explicit return
//   }
// }
// // need help with this one
// node_t* R(istream& in, Token tk) {
//
//   if (tk.ID == "Place") {  // predicts A->dSa
//     node_t* p = getNode(A); // now we need node ???
//     p->token1 = tk; // d needed to be stored
//     tk = scanner(); // processing d
//     p->child = S(); // processing S
//
//     if (tk.ID == "Name"){
//       //A();
//     }
//   }
//   else {  // predicts A->(epslon)
//     return NULL;
//   }
// }
//
// node_t* E(istream& in, Token tk) {
//
//   if (tk.ID == "Show") {  // predicts A->dSa
//     node_t* p = getNode(A); // now we need node
//     p->token1 = tk; // d needed to be stored
//     tk = scanner(); // processing d
//     p->child = S(); // processing S
//
//     if (tk.ID == "Show") {  // processing a
//       tk = scanner();
//
//       if (tk.ID == "Identifier") {  // processing a
//         tk = scanner();
//       }
//       else {
//         cout << "Error. Exiting program.";
//       }
//     }
//     else {
//       cout << "Error. Exiting program.";
//     }
//   }
//   else {  // predicts A->(epslon)
//     return NULL;
//   }
// }
//
// node_t* A(istream& in, Token tk) {
//
//   if (tk.ID == "Name") {  // predicts A->dSa
//     node_t* p = getNode(A); // now we need node
//     p->token1 = tk; // d needed to be stored
//     tk = scanner(); // processing d
//     p->child = S(); // processing S
//
//     if (tk.ID == "Name") {  // processing a
//       tk = scanner();
//
//       if (tk.ID == "Identifier") {  // processing a
//         tk = scanner();
//       }
//       else {
//         cout << "Error. Exiting program.";
//       }
//     }
//     else {
//       cout << "Error. Exiting program.";
//     }
//   }
//   else {  // predicts A->(epslon)
//     return NULL;
//   }
// }
//
// //need help with this one
// node_t* B(istream& in, Token tk) {
//
//   if (tk.ID == ".") {  // predicts A->dSa
//     // node_t* p = getNode(A); // now we need node
//     // p->token1 = tk; // d needed to be stored
//     // tk = scanner(); // processing d
//     // p->child = S(); // processing S
//
//     if (tk.ID == a) {  // processing a
//       tk = scanner();
//     }
//     else {
//       cout << "Error. Exiting program.";
//     }
//   }
//   else {  // predicts B->(epslon)
//     return NULL;
//   }
// }
// // need help
// node_t* C(istream& in, Token tk) {
//
//   if (tk.ID == d) {  // predicts A->dSa
//     // node_t* p = getNode(A); // now we need node
//     // p->token1 = tk; // d needed to be stored
//     // tk = scanner(); // processing d
//     // p->child = S(); // processing S
//
//     if (tk.ID == a) {  // processing a
//       tk = scanner();
//     }
//     else {
//       cout << "Error. Exiting program.";
//     }
//   }
//   else {
//     //return error
//   }
// }
//
// // need help
// node_t* D(istream& in, Token tk) {
//
//   if (tk.ID == d) {  // predicts A->dSa
//     // node_t* p = getNode(A); // now we need node
//     // p->token1 = tk; // d needed to be stored
//     // tk = scanner(); // processing d
//     // p->child = S(); // processing S
//
//     if (tk.ID == a) {  // processing a
//       tk = scanner();
//     }
//     else {
//       cout << "Error. Exiting program.";
//     }
//   }
//   else {
//     //return error
//   }
// }
//
// node_t* F(istream& in, Token tk) {
//
//   if (tk.ID == "{") {  // predicts A->dSa
//     // node_t* p = getNode(A); // now we need node
//     // p->token1 = tk; // d needed to be stored
//     // tk = scanner(); // processing d
//     // p->child = S(); // processing S
//
//     if (tk.ID == "If") {  // processing a
//       tk = scanner();
//
//       if (tk.ID == "Idetifier") {  // processing a
//         tk = scanner();
//
//         // call T W D
//       }
//     }
//     else if (tk.ID  == "{") {
//       // node_t* p = getNode(A); // now we need node
//       // p->token1 = tk; // d needed to be stored
//       // tk = scanner(); // processing d
//       // p->child = S(); // processing S
//
//       if (tk.ID == "Do") {  // processing a
//         tk = scanner();
//
//         if (tk.ID == "Again") {  // processing a
//           tk = scanner();
//
//           // call D T W
//         }
//       }
//     }
//     else {
//       cout << "Error. Exiting program.";
//     }
//   }
//   else {
//     //return error
//   }
// }
//
// node_t* G(istream& in, Token tk) {
//
//   if (tk.ID == "Here") {  // predicts A->dSa
//     node_t* p = getNode(A); // now we need node
//     p->token1 = tk; // d needed to be stored
//     tk = scanner(); // processing d
//     p->child = S(); // processing S
//
//     if (tk.ID == "Number") {  // processing a
//       tk = scanner();
//
//       if (tk.ID == "There") {  // processing a
//         tk = scanner();
//       }
//       else {
//         cout << "Error. Exiting program.";
//       }
//     }
//     else {
//       cout << "Error. Exiting program.";
//     }
//   }
//   else {
//     //return error
//   }
// }
//
// node_t* T(istream& in, Token tk) {
//
//   if (tk.ID == "<<") {  // predicts A->dSa
//     node_t* p = getNode(A); // now we need node
//     p->token1 = tk; // d needed to be stored
//     tk = scanner(); // processing d
//     p->child = S(); // processing S
//
//   }
//   else if (tk.ID == "<-") {
//     node_t* p = getNode(A); // now we need node
//     p->token1 = tk; // d needed to be stored
//     tk = scanner(); // processing d
//     p->child = S(); // processing S
//
//   }
//   else {
//     //return error
//   }
// }
//
// node_t* V(istream& in, Token tk) {
//
//   if (tk.ID == "+") {  // predicts A->dSa
//     node_t* p = getNode(A); // now we need node
//     p->token1 = tk; // d needed to be stored
//     tk = scanner(); // processing d
//     p->child = S(); // processing S
//   }
//   else if (tk.ID == "%") {  // predicts A->dSa
//     node_t* p = getNode(A); // now we need node
//     p->token1 = tk; // d needed to be stored
//     tk = scanner(); // processing d
//     p->child = S(); // processing S
//   }
//   else if (tk.ID == "&") {  // predicts A->dSa
//     node_t* p = getNode(A); // now we need node
//     p->token1 = tk; // d needed to be stored
//     tk = scanner(); // processing d
//     p->child = S(); // processing S
//   }
//   else {
//     // return error
//   }
// }
//
// node_t* H(istream& in, Token tk) {
//
//   if (tk.ID == "/") {  // predicts A->dSa
//     node_t* p = getNode(A); // now we need node
//     p->token1 = tk; // d needed to be stored
//     tk = scanner(); // processing d
//     p->child = S(); // processing S
//
//
//   }
//   else {  // predicts A->(epslon)
//     //return error
//   }
// }
//
// node_t* J(istream& in, Token tk) {
//
//   if (tk.ID == "Assign") {  // predicts A->dSa
//     node_t* p = getNode(A); // now we need node
//     p->token1 = tk; // d needed to be stored
//     tk = scanner(); // processing d
//     p->child = S(); // processing S
//
//     if (tk.ID == "Identifier") {  // processing a
//       tk = scanner();
//
//       //D();
//     }
//     else {
//       cout << "Error. Exiting program.";
//     }
//   }
//   else {
//     // return error;
//   }
// }
//
// node_t* K(istream& in, Token tk) {
//
//   if (tk.ID == "Spot") {  // predicts A->dSa
//     node_t* p = getNode(A); // now we need node
//     p->token1 = tk; // d needed to be stored
//     tk = scanner(); // processing d
//     p->child = S(); // processing S
//
//     if (tk.ID == "Number") {  // processing a
//       tk = scanner();
//
//       if (tk.ID == "Show") {  // processing a
//         tk = scanner();
//
//         if (tk.ID == "Number") {  // processing a
//           tk = scanner();
//         }
//         else {
//           cout << "Error. Exiting program.";
//         }
//       }
//       else {
//         cout << "Error. Exiting program.";
//       }
//     }
//     else   if (tk.ID == "Move") {  // predicts A->dSa
//         node_t* p = getNode(A); // now we need node
//         p->token1 = tk; // d needed to be stored
//         tk = scanner(); // processing d
//         p->child = S(); // processing S
//
//         if (tk.ID == "Identifier") {  // processing a
//           tk = scanner();
//
//           if (tk.ID == "Show") {  // processing a
//             tk = scanner();
//
//             if (tk.ID == "Identifier") {  // processing a
//               tk = scanner();
//             }
//             else {
//               cout << "Error. Exiting program.";
//             }
//           }
//           else {
//             cout << "Error. Exiting program.";
//           }
//         }
//     else {
//       cout << "Error. Exiting program.";
//     }
//   }
//   else {
//     //return error
//   }
// }
//
// node_t* L(istream& in, Token tk) {
//
//   if (tk.ID == "Flip") {  // predicts A->dSa
//     // node_t* p = getNode(A); // now we need node
//     // p->token1 = tk; // d needed to be stored
//     // tk = scanner(); // processing d
//     // p->child = S(); // processing S
//
//     if (tk.ID == "Identifier") {  // processing a
//       tk = scanner();
//     }
//     else {
//       cout << "Error. Exiting program.";
//     }
//   }
//   else {  // predicts A->(epslon)
//     //return error;
//   }
// }
// //need help
// node_t* W(istream& in, Token tk) {
//
//   if (tk.ID == "Number") {  // predicts A->dSa
//     node_t* p = getNode(A); // now we need node
//     p->token1 = tk; // d needed to be stored
//     tk = scanner(); // processing d
//     p->child = S(); // processing S
//
//     if (tk.ID == ".") {  // processing a
//       tk = scanner();
//     }
//     else if(){
//       //V();
//     }
//     else {
//       cout << "Error. Exiting program.";
//     }
//   }
//   else {
//     //return error
//   }
// }
//
// node_t* Z(istream& in, Token tk) {
//
//   if (tk.ID == "Identifier") {  // predicts A->dSa
//     node_t* p = getNode(A); // now we need node
//     p->token1 = tk; // d needed to be stored
//     tk = scanner(); // processing d
//     p->child = S(); // processing S
//
//     if (tk.ID == a) {  // processing a
//       tk = scanner();
//     }
//     else {
//       cout << "Error. Exiting program.";
//     }
//   }
//   if (tk.ID == "Number") {  // predicts A->dSa
//     node_t* p = getNode(A); // now we need node
//     p->token1 = tk; // d needed to be stored
//     tk = scanner(); // processing d
//     p->child = S(); // processing S
//
//     if (tk.ID == a) {  // processing a
//       tk = scanner();
//     }
//     else {
//       cout << "Error. Exiting program.";
//     }
//   }
//   else {
//     //return error
//   }
// }
