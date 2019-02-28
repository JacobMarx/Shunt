//Created by Jacob Marx on 2/7/19
#ifndef BITREE_H
#define BITREE_H

struct Node {
  Node() {
    left = NULL;
    right = NULL;
    pre = NULL;
    data = NULL;
  }
  Node* left;
  Node* right;
  Node* pre;
  char* data;
};
//Node* head;
  
class BiTree {

 public:
  BiTree();
  ~BiTree();

  void add(char*);
  char* remove();
  bool isempty();
  Node* getHead();
  
 private:
  Node* head;
};

#endif
