//Created by Jacob Marx on 2/7/19
#ifndef BINODE_H
#define BINODE_H

class BiNode {

 public:
  BiNode();
  ~BiNode();

  int add(int);
  int remove();
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
