//Created by Jacob Marx on 2/7/19
#include <iostream>
#include "Queue.h"

using namespace std;

Queue::Queue() {
  tail = NULL;
  head = NULL;
  data = 0;
  // tail->data = 5;
}

Queue::~Queue() {
  // do this i to lazy right now
}

void Queue::enqueue(char* i) {
  if (tail == NULL && head == NULL) {
    tail = new Node(i);
    head = new Node(i);
  }
  else {
    Node* newNode = new Node();
    newNode->data = i;
    newNode->next = head;
    head->previous = newNode;
    head = newNode;
  }
}

char* Queue::dequeue() {
  char* value = tail->data;
  tail = tail->previous;
  delete tail->next;
  return value;
}

char* Queue::peek() {
  return tail->data;
}

bool Queue::isempty() {
  if (head) return false;
  return true;
}
/*
int Queue::getData() {
  //return tail->data;
}
*/

