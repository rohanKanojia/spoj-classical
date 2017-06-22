#include <cstdio>

/*
// Times out!!!
class Node {
  int data;
  Node *next;
public:
  Node() { }
  Node(int aElem) : data(aElem), next(NULL) { }
  int getData()             { return data;  }
  Node *getNext()           { return next;  }
  void setData(int aElem)   { data = aElem; }
  void setNext(Node *pNext) { next = pNext; }
};

int josephusCircle(int N) {
  Node *pHead, *pTail;
  pHead = pTail = new Node(1);
  for(int i = 2; i <= N; i++) {
    Node *pNewNode = new Node(i);
    pTail->setNext(pNewNode);
    pTail = pNewNode;
  }
  pTail->setNext(pHead); // Making it circular

  for(int count = 0; count < N-1; count++) {
    for(int i = 0; i < count; i++)
      pHead = pHead->getNext();

    Node *toDelete = pHead->getNext();
    pHead->setData(toDelete->getData());
    pHead->setNext(toDelete->getNext());
    delete toDelete;
  }
  return pHead->getData();
}
*/

int josephusCircle(int N) {
  int nRet = 0;
  for(int i = 2; i <= N; i++)
    nRet = (nRet + N+1 - i) % i;
  return nRet+1;
}

int main() {
  int T;
  scanf("%d", &T);

  while(T--) {
    int N;
    scanf("%d", &N);

    printf("%d\n", josephusCircle(N));
  }
  return 0;
}
