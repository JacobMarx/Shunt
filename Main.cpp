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
  char move;
  /*While not empty
    char token is peek
    if token is operand, enqueue
    else {
    special stuff for operators
    }
   */
  while (input->isempty() == false && stack->isempty() == false) {
    if (input->peek() >= '0' && <= '9') {
      stack->push(input->dequeue());
    }
    else {
      //try to make more efficent
      if (input->peek() = '+' || input->peek() == '-') {
	if (stack->peek() == '-' || stack->peek() == '*') {
	  output->enqueue(stack->pop());
	  stack->push(input->dequeue());
	}
	if (stack->peek() == ')' || stack->isempty == true) {
	  stack->push(input->dequeue())            ;
	}
	if (stack->peek() == '+' || stack->peek() == '-') {
	  output->enqueue(stack->pop());
	  stack->push(input->dequeue());
	}
	//this is good
	if (input->peek() == ')') {
	  while (stack->peek() != '(') {
	    output->enqueue(stack->pop());
	  }
	  while (stack->peek() == '(') {
	    delete stack->pop();
	  }
	}
      }

    }
  }
  
}

int getpresedence(char input) {
  if (input == '^') 
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
