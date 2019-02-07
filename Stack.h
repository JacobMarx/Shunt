//Created by Jacob Marx on 2/7/19
#ifndef
#define

class Stack {
 public:
  Stack();
  ~Stack();
  
  int push(int);
  int pop();
  bool isempty();
  int peek();

 private:
  struct Node {
    Node() {
      next = NULL;
      data = 0;
    }
    Node* next;
    int data;
  }
  Node* top;
}


#endif