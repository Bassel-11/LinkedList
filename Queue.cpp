#include <bits/stdc++.h>
#define ll long long
#define Time cerr << "Time Taken: " << (float)clock() / CLOCKS_PER_SEC << " Secs" << "\n";
#define ln cout<<endl;
using namespace std;

const int MAX_SIZE = 100;

class Queue {
 private:
  int items[MAX_SIZE];
  int front;
  int rear;
  int count;

 public:
  Queue() {
    front = 0;
    rear = MAX_SIZE - 1;
    count = 0;
  }

  int length() {
    return count;
  }

  void enqueue(int element) {
    rear = (rear + 1) % MAX_SIZE;
    items[rear] = element;
    count++;
  }

  int dequeue() {
    int element = items[front];
    front = (front + 1) % MAX_SIZE;
    count--;
    return element;
  }

  int search_queue(int item) {
    for (int i = 0; i < count; i++) {
      int index = (front + i) % MAX_SIZE;
      if (items[index] == item) {
        return i;
      }
    }
    return -1;
  }
};

int main() {
  Queue q;
  q.enqueue(1);
  q.enqueue(2);
  q.enqueue(3);
  cout << q.length() << endl; // 3
  cout << q.dequeue() << endl; // 1
  cout << q.search_queue(2) << endl; // 0
  return 0;
}
