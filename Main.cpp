//Created by Jacob Marx on 2/7/19
#include <iostream>
#include <cstring>
#include "Queue.h"
#include "BiTree.h"
#include "Stack.h"

using namespace std;

Queue* shunt(Queue*);
Queue* toInput();
BiTree* toTree(Queue*);
Queue* toInfix(Node*, Queue*);
Queue* toPrefix(Node*, Queue*);
Queue* toPostfix(Node*, Queue*);
bool isOperator(char);
int getAssociativity(char*x);
int getPrec(char*);
Queue* clearQ(Queue*);
void print(Queue*);
char* clear(char*);

int main() {
  bool run = true;
  while (run == true) {
    char in[8];
    clear(in);
    BiTree* tree = new BiTree();
    Queue* input = toInput();
    Queue* printQ = new Queue();
    shunt(input);
    print(input);
    print(shunt(input));
    cout << "What do you want to convert to? (infix, postfix, or prefix)" << endl;
    cin.get(in, 8);
    cin.clear();
    cin.ignore(1000, '\n');
    if (strcmp(in, "infix") == 0) {
      toInfix(tree->getHead(), printQ);
      print(printQ);
      clearQ(printQ);
    }
    if (strcmp(in, "prefix") == 0) {
      toPrefix(tree->getHead(), printQ);
      print(printQ);
      clearQ(printQ);
    }
    if (strcmp(in, "postfix") == 0) {
      toPostfix(tree->getHead(), printQ);
      print(printQ);
      clearQ(printQ);
    }
  }
  Queue* input = toInput();
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
    || getPrec(input->peek()) == getPrec(stack->peek()) && getAssociativity(input->peek()) == 1
	 && getAssociativity(stack->peek()) == 1 || getPrec(input->peek()) < getPrec(stack->peek()) && *stack->peek() != '(') {
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

char* clear(char* arr) {
  for(unsigned int i = 0; i < strlen(arr); i++) {
    arr[i] = '\0';
  }
}

int getPrec(char* input) {
  int prec = 0;
  if (*input == '^') prec = 4;
  if (*input == '*' || *input == '/') prec = 3;
  if (*input = '+' || *input == '-') prec = 2;
  return prec;
}

int getAssociativity(char* input) {
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

Queue* toInfix(Node* input, Queue* out) {
  if (input->left != NULL) {
    out->enqueue(print(input->left));
  }
  out->enqueue(input->data);
  if (input->right != NULL) {
    out->enqueue(print(input->right));
  }
  return out;
}

Queue* toPostfix(Node* input, Queue* out) {
  if (input->data != NULL) {
    if (input->left != NULL) {
    out->enqueue(toPostfix(input->left));
    }
    if (input->right != NULL) {
    out->enqueue(toPostfix(input->right));
    }
    out->enqueue(input->data);
  }
  return out;
}

Queue* toPrefix(Node* input, Queue* out) {
  if (input->data != NULL) {
    out->enqueue(input->data);
    if (input->left != NULL) {
      out->enqueue(toPrefix(input->left));
    }
    if (input->right != NULL) {
      out->enqueue(toPrefix(input->right));
    }
  }
  return out;
}

BiTree* toTree(Queue* input, BiTree* bitree) {
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

void print(Queue* in) {
  while (in->isempty != true) {  
    cout << in->dequeue();
  }
  cout << endl;
}

Queue* clearQ(Queue* q) {
  while (q->isempty == false) {
    q->dequeue();
  }
  return q;
}
