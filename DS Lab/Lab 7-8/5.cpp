#include <iostream>
using namespace std;

class CircularQueue {
private:
    static const int MAX_SIZE = 5;
    int arr[MAX_SIZE];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    bool IsEmpty() {
        return front == -1 && rear == -1;
    }

    bool IsFull() {
        return (rear + 1) % MAX_SIZE == front;
    }

    void Enqueue(int data) {
        if (IsFull()) {
            cout << "Queue is full. Cannot enqueue element." << endl;
            return;
        }
        if (IsEmpty()) {
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % MAX_SIZE;
        }
        arr[rear] = data;
        cout << "Enqueued " << data << " into the queue." << endl;
    }

    void Dequeue() {
        if (IsEmpty()) {
            cout << "Queue is empty. Cannot dequeue element." << endl;
            return;
        }
        int dequeuedElement = arr[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }
        cout << "Dequeued " << dequeuedElement << " from the queue." << endl;
    }

    int Count() {
        if (IsEmpty()) {
            return 0;
        }
        return (rear - front + MAX_SIZE) % MAX_SIZE + 1;
    }

    void Reverse() {
        int count = Count();
        if (count <= 1) {
            return;
        }

        int i = front, j = rear;
        while (i < j) {
            swap(arr[i], arr[j]);
            i = (i + 1) % MAX_SIZE;
            j = (j - 1 + MAX_SIZE) % MAX_SIZE;
        }
        cout << "Queue reversed." << endl;
    }
};

int main() {
    CircularQueue queue;
    queue.Enqueue(10);
    queue.Enqueue(20);
    queue.Enqueue(30);

    cout << "Number of elements in the queue: " << queue.Count() << endl;

    queue.Dequeue();
    cout << "Number of elements in the queue after dequeue: " << queue.Count() << endl;

    queue.Reverse();

    return 0;
}
