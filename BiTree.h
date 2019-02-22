//Created by Jacob Marx on 2/7/19
#ifndef BITREE_H
#define BITREE_H

class BiTree {

 public:
  BiTree();
  ~BiTree();

  void add(char*);
  //prob not needed
  char* lmr(Node*);
  char* mlr(Node*);
  char* lrm(Node*);
  char* remove();
  bool isempty();
  
 private:
  struct Node {
    Node() {
      left = NULL;
      right = NULL;
      data - 0;
    }
    Node* left;
    Node* right;
    int data;
  }
  Node* head;
};

#endif
