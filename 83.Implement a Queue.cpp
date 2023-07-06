#include <bits/stdc++.h> 
int M = 10005;
class Queue {
    int arr[10005];
    int front_p;
    int rear_p;
    int cnt;
public:
    Queue() {
        // Implement the Constructor
        front_p = rear_p = -1;
        cnt=0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        return cnt==0;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        cnt++;
        rear_p = (rear_p+1);
        if(cnt==1)  front_p=rear_p;
        arr[rear_p] = data;
    }

    int dequeue() {
        // Implement the dequeue() function
        if(isEmpty())   return -1;
        cnt--;
        int val = arr[front_p];
        front_p = front_p+1;
        if(isEmpty()){
            front_p = rear_p = -1;
        }
        return val;
    }

    int front() {
        // Implement the front() function
        if(isEmpty())    return -1;
        return arr[front_p];
    }
};