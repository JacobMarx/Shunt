//Created by Jacob Marx on 2/7/19
#include <iostream>
#include "Queue.h"
#include <cstring>

using namespace std;

Queue* shunt(Queue*);
Queue* getInput();
bool isOperator(char);

int main() {
  Queue* input = getInput();
  shunt(input);
  return 0;
}

Queue* shunt(Queue* input) {
  Stack* stack = new Stack();
  Queue* output = new Queue();
  /*While not empty
    char token is peek
    if token is operand, enqueue
    else {
    special stuff for operators
    }
   */
  while (input->isempty() == false) {
    if (input->peek() >= '0' && <= '9') {
      
    }
    else {

    }
  }
  
}

Queue* toInput() {
  Queue* input = new Queue();
  char in = 0;
  while((in == cin.get()) != '\n') {
    if (in >= '0' && <= '9' ||
	isOperator(in)) {
      input->enqueue(in);
    }
  }
  return input;
}

bool isOperator(char input) {
  if (input == '+' || input == '*' ||
      input == '/' || input == '-' ||
      input == '(' || input == ')') {
    return true;
  }
}
