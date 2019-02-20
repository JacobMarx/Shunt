//Created by Jacob Marx on 2/7/19
#include <iostream>
#include "BiTree.h"

BiTree::BiTree() {
  head = NULL;

}

BiTree::~BiTree() {
  //Do later too lazy
}

Node* BiTree::add(Node* m, Node* r, Node* l) {
  if (head == NULL) {
    head = m;
    head->right == r;
    head->left == l;
  }
  else {
    
  }
  return head;
}

bool BiTree::isempty() {

}
