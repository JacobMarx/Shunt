#ifndef QUEUE_H
#define QUEUE_H

class Queue {
 public:
  Queue();
  ~Queue();

  int enqueue(int);
  int dequeue();
  int peek();
  bool isempty();
  
 private:
  struct Node {
    Node* head;
    Node* tail;
    int data;
  }
};

#endif
