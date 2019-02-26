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

void Stack::push(char* i) {
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

char* Stack::pop() {
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

char* Stack::peek() {
  return top->data; 
}


