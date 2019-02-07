//Created by Jacob Marx on 2/7/19
#incldue <iostream>
#inlcude "Stack.h"

using namespace std;

Stack::Stack() {
  top = NULL;
  data = 0;
}

Stack::~Stack() {
  //do this later too lazy
}

int Stack::push(int i) {
  Node* newNode = new Node();
  newNode->data = i;
  if (top == NULL) {
    top = newNode;
  }
  else {
    newNode->next = top;
    top = newNode;
  }
}

