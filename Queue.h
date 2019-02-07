//Created by Jacob Marx on 2/7/19
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
    Node() {
      next = NULL;
      previous = NULL;
      data = 0;
    }
    Node* next;
    Node* previous;
    int data;
  };
  Node* head;
  Node* tail;
};

#endif
