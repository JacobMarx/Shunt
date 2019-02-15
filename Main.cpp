//Created by Jacob Marx on 2/7/19
#include <iostream>
#include "Queue.h"
#include <cstring>

using namespace std;

Queue* shunt(Queue*);
Queue* getInput();
bool isOperator(char);
int getAssociativity(char);
int getPrecedence(char);

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
  while (stack->isempty() == false
    || getPresedence(input->peek()) == getPresedence(stack->peek()) && getAssociativity(input->peek()) == 1
	   && getAssociativity(stack->peek()) == 1 || getPresedence(input->peek()) < getPresedence(stack->peek()) && stack->peek != '(') {
      output->enqueue(stack->pop());
    }
    stack->push(input->dequeue());
    else {
      //try to make more efficent
      
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

int getPrecedence(char input) {
  int presedence = 0;
  if (input == '^') presedence = 4;
  if (input == '*' || input == '/') presedence = 3;
  if (input = '+' || input == '-') presedence = 2;
  return presedence;
}

int getAssociativity(char input) {
  int associativity = 0;
  int left = 1;
  int right = 2;
  if (input == '^') associativity = right;
  if (input == '*' || input == '/' || input == '+' || input == '-') associativity = left;
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
