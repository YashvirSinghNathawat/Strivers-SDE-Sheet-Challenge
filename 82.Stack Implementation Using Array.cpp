#include <bits/stdc++.h> 
// Stack class.
class Stack {
    int *arr;
    int front;
    int cap;
public:
    
    Stack(int capacity) {
        // Write your code here.
        arr = new int[capacity];
        front = -1;
        cap = capacity;
    }

    void push(int num) {
        // Write your code here.
        if(front+1==cap)  return;
        front++;
        arr[front] = num;
    }

    int pop() {
        // Write your code here.
        if(front==-1) return -1;
        int val = arr[front];
        front--;
        return val;
    }
    
    int top() {
        // Write your code here.
        if(front==-1) return -1;
        return arr[front];
    }
    
    int isEmpty() {
        // Write your code here.
        return front==-1;
    }
    
    int isFull() {
        // Write your code here.
        return front+1==cap;
    }
};