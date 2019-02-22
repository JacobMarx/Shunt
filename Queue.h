//Created by Jacob Marx on 2/7/19
#ifndef QUEUE_H
#define QUEUE_H

class Queue {
 public:
  Queue();
  ~Queue();

  void enqueue(char*);
  
  char* dequeue();
  char* peek();
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
    char* data;
  };
  Node* head;
  Node* tail;
};

#endif
