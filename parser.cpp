#include <iostream>
#include <fstream>
#include "scanner.h"
#include "parser.h"

using namespace std;

node_t * parser(istream& in) {
  Token tk;
  //node_t* root;
  tk = scanner();
  //root = S();

  if (tk.ID == EOFtk){
    continue;
  }
  else {
    cout << "Error. Exiting program.";
  }

  return tk;
}
// individual functions written out.
// node_t* S(){
//
//   node_t* p = getNode(S);
//   if (tk.ID == "Name") { // predict S->bA since bc First(bAa)
//     p->token1 = tk; // b needed to be stored
//     tk = scanner(); // processing b consume matching tokens
//     p->child = A(); // processing A
//
//     if (tk.ID == "Identifier") {  // processing a
//       tk = scanner();
//
//       if (tk.ID == "Spot") {  // processing a
//         tk = scanner();
//
//         if (tk.ID == "Identifier") {  // processing a
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
// node_t* R() {
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
// node_t* E() {
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
// node_t* A() {
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
// node_t* B() {
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
// node_t* C() {
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
// node_t* D() {
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
// node_t* F() {
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
// node_t* G() {
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
// node_t* T() {
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
// node_t* V() {
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
// node_t* H() {
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
// node_t* J() {
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
// node_t* K() {
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
// node_t* L() {
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
// node_t* W() {
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
// node_t* Z() {
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
