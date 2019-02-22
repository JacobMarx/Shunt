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
  if (head == NULL) {
    if (in->data == '+' || in->data == '-' || in->data == '*' || in->data == '/') {
      head = in;
    }
    if (head->left == NULL) {
      head->left == in;
    }
    if (head->right == NULL) {
      head->right == in;
    }
  }
  else {
    if (in->data == '+' || in->data == '-' || in->data == '*' || in->data == '/') {
      Node* curr = head;
      head == in;
      head->left = curr;
    }
    else {
      head->right = in;
    }
  }
}

bool BiTree::isempty() {

}

char* BiTree::lmr(Node* node) {
  
}
