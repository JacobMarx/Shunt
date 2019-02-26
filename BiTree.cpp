//Created by Jacob Marx on 2/7/19
#include <iostream>
#include "BiTree.h"

BiTree::BiTree() {
  head = NULL;

}

BiTree::~BiTree() {
  //Do later too lazy
}

void BiTree::add(char* in) {
  Node* curr = NULL;
  if (head == NULL) {
    if (*in == '+' || *in == '-' || *in == '*' || *in  == '/') {
      head->data = in;
    }
    if (head->left == NULL) {
      head->left->data == in;
    }
    if (head->right == NULL) {
      head->right->data == in;
    }
  }
  else {
    if (*in == '+' || *in == '-' || *in == '*' || *in == '/') {
      curr = head;
      head->data == in;
      head->left = curr;
    }
    else {
      head->right->data = in;
    }
    curr->pre = head;
  }
}

bool BiTree::isempty() {
  if (head == NULL) {
    return true;
  }
  return false;
}

Node* BiTree::getHead() {
  return head;
}

/*
Node* BiTree::getNode() {
  
}
*/
