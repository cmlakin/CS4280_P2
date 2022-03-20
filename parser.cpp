node_t * parser() {

  node_t* root;
  tk = scanner();
  root = S();

  if (tk.ID == EOFtk){
    continue;
  }
  else {
    cout << "Error. Exiting program.";
  }

  return root;
}

node_t* S(){

  node_t* p = getNode(S);
  if (tk.ID == b) { // predict S->bA since bc First(bAa)
    p->token1 = tk; // b needed to be stored
    tk = scanner(); // processing b consume matching tokens
    p->child = A(); // processing A

    return p;  // explicit return
  }
  else if (tk.ID == c) { //predict S->c
    tk = scanner(); // consume c no need to store

    return p;  // explicit return
}

node_t* A() {

  if (tk.ID == d) {  // predicts A->dSa
    node_t* p = getNode(A); // now we need node
    p->token1 = tk; // d needed to be stored
    tk = scanner(); // processing d
    p->child = S(); // processing S

    if (tk.ID == a) {  // processing a
      tk = scanner();
    }
    else {
      cout << "Error. Exiting program.";
    }
  }
  else {  // predicts A->(epslon)
    return NULL;
  }
}
