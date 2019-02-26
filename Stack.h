//Created by Jacob Marx on 2/7/19
#ifndef STACK_H
#define STACK_H

class Stack {
 public:
  Stack();
  ~Stack();
  
  void push(char*);
  
  char* pop();
  bool isempty();
  char* peek();

 private:
  struct Node {
    Node() {
      next = NULL;
      data = NULL;
    }
    Node* next;
    char* data;
  };
  Node* top;
};
#endif
