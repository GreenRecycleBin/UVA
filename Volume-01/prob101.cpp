#include <iostream>
#include <stack>
#include <string>

using namespace std;

static int block[25]; // which stack a blog belongs to
static stack<int> s[25], tmpStack;

void popBlocksOnTopOfBlockToOrigin(int a)
{
  while (s[block[a]].top() != a) {
    int top = s[block[a]].top();
    s[top].push(top);
    block[top] = top;
    s[block[a]].pop();
  }
}

void reverseOrderOfPileStartingFromBlock(int a)
{
  while (s[block[a]].top() != a) {
    int top = s[block[a]].top();
    tmpStack.push(top);
    s[block[a]].pop();
  }

  s[block[a]].pop();
  tmpStack.push(a);
}

void pushTmpStackToPile(int a)
{
  while (!tmpStack.empty()) {
    int top = tmpStack.top();
    s[block[a]].push(top);
    block[top] = block[a];
    tmpStack.pop();
  }
}

void moveOnto(int a, int b)
{
  if (a != b && block[a] != block[b]) {
    popBlocksOnTopOfBlockToOrigin(a);
    popBlocksOnTopOfBlockToOrigin(b);

    s[block[a]].pop();
    s[block[b]].push(a);
    block[a] = block[b];
  }
}

void moveOver(int a, int b)
{
  if (a != b && block[a] != block[b]) {
    popBlocksOnTopOfBlockToOrigin(a);

    s[block[a]].pop();
    s[block[b]].push(a);
    block[a] = block[b];
  }
}

void pileOver(int a, int b)
{
  if (a != b && block[a] != block[b]) {
    reverseOrderOfPileStartingFromBlock(a);
    pushTmpStackToPile(b); 
  }
}

void pileOnto(int a, int b)
{
  if (a != b && block[a] != block[b]) {
    popBlocksOnTopOfBlockToOrigin(b); 
    pileOver(a, b);
  }
}

void printNStacks(int n)
{
  for (int i = 0; i < n; i++) {
    cout << i << ":";

    while (!s[i].empty()) {
      tmpStack.push(s[i].top());
      s[i].pop();
    }

    while (!tmpStack.empty()) {
      cout << " " << tmpStack.top();
      tmpStack.pop();
    }

    cout << endl;
  }
}

int main()
{
  int stackNo, argument1, argument2;
  string command1, command2;

  cin >> stackNo;

  for (int i = 0; i < stackNo; i++) {
    s[i].push(i);
    block[i] = i;    
  }

  while (cin >> command1) {
    if (!command1.compare("quit")) {
      break;
    }
    else {
      cin >> argument1 >> command2 >> argument2;

      if (!command1.compare("move")) {
        if (!command2.compare("onto")) {
          moveOnto(argument1, argument2);
        }
        else if (!command2.compare("over")) {
          moveOver(argument1, argument2);
        }
      }
      else if (!command1.compare("pile")) {
        if (!command2.compare("onto")) {
          pileOnto(argument1, argument2);
        }
        else if (!command2.compare("over")) {
          pileOver(argument1, argument2);
        }
      }
    }
  }

  printNStacks(stackNo);

  return 0;
}
