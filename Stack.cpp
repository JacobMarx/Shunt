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

int Stack::pop() {
  Node* remove = top;
  in value = top->data;
  top = top->next;
  delete remove;
  return value;
} 

bool Stack::isempty() {
  if(top) return false;
  return true;
}

int Stack::peek() {
  return top->data; 
}

