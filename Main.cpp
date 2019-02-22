//Created by Jacob Marx on 2/7/19
#include <iostream>
#include "Queue.h"
#include <cstring>

using namespace std;

Queue* shunt(Queue*);
Queue* toInput();
Node* toTree(Queue*);
Queue* toInfix(Queue*);
Queue* toPostfix(Queue*);
bool isOperator(char);
int getAssociativity(char);
int getPrecedence(char);

int main() {
  bool run = true;
  while (run == true) {
    //do char in thingy
    BiTree tree = new BiTree();
    Queue* input = getInput();
    shunt(input);
    cout << "What do you want to convert to? (infix, postfix, or prefix)" << endl;
    //cin stuff
    if (strcmp(in, "infix") == 0) {
      toinfix(BiTree); 
    }
    if (strcmp(in, "prefix") == 0) {

    }
    if (strcmp(in, "postfix") == 0) {
      
    }
  }
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
    if (input->peek() == '(') {
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
	if (input->isempty() == true) {
	  while (stack->isempty() == false) {
	    output->enqueue(stack->pop());
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

Queue* toInfix(Queue* input) {
   
}

Queue* toPrefix(Queue* input) {

}

BiTree*  toTree(Queue* input, BiTree* bitree) {
  Stack* stack = new Stack();
  //add to stack
  //if you are adding operator
  //then you make three with previous two thing in stack
  while (input->isempty() == false) {
    if (isOperator(input->peek()) == true) {
      stack->push(input->dequeue());
      while (stack->isempty() == false) {
	bitree->add(stack->pop());
      }
    }
    else {
    stack->push(input->dequeue());
    }
  }
  return bitree;
  //supposed to reuturn bitree or node?
}
