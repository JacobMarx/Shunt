//Created by Jacob Marx on 2/7/19
#include <iostream>
#include "Queue.h"

using namespace std;

Queue::Queue() {
  tail = NULL;
  qhead = NULL;
  // tail->data = 5;
}

Queue::~Queue() {
  // do this i to lazy right now
}

void Queue::enqueue(char* i) {
  if (tail == NULL && qhead == NULL) {
    tail = new Node();
    tail->data = i;
    qhead = tail;
  }
  else {
    Node* newNode = new Node();
    newNode->data = i;
    newNode->next = qhead;
    qhead->previous = newNode;
    qhead = newNode;
  }
}

char* Queue::dequeue() {
  if (tail == qhead) {
    char* value = tail->data;
    tail = NULL;
    qhead = NULL;
    return value;
  }
  if (tail != NULL) {
    char* value = tail->data;
    tail = tail->previous;
    if (tail->next != NULL) {
      cout << "not null" << endl;
    }
    delete tail->next;
    return value;
  }
  return 0;
}

char* Queue::peek() {
  return tail->data;
}

bool Queue::isempty() {
  if (qhead) return false;
  return true;
}
/*
int Queue::getData() {
  //return tail->data;
}
*/

