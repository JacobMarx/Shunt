//Created by Jacob Marx on 2/7/19
#include <iostream>
#include "Stack.h"

using namespace std;

Stack::Stack() {
  top = NULL;

}

Stack::~Stack() {
  //do this later too lazy
}



void Stack::push(char* i) {
  if (top == NULL) {
    top = new Node();
    top->data = i;
  }
  else {
    Node* newNode = new Node();
    newNode->data = i;
    newNode->next = top;
    top = newNode;
  }
}

char* Stack::pop() {
  Node* remove = top;
  char* value = top->data;
  top = top->next;
  delete remove;
  return value;
} 

bool Stack::isempty() {
  if(top) return false;
  return true;
}

char* Stack::peek() {
  if (top == NULL) {
    return 0;
  }
  return top->data; 
}


