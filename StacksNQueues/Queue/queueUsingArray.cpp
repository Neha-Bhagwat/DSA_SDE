// Implement a Queue using an Array. Queries in the Queue are of the following type:
// (i) 1 x   (a query of this type means  pushing 'x' into the queue)
// (ii) 2     (a query of this type means to pop an element from the queue and print the popped element. If the queue is empty then return -1)

// We just have to implement the functions push and pop and the driver code will handle the output.

// Examples:

// Input: Queries = 1 2 1 3 2 1 4 2
// Output: 2 3
// Explanation: For query 1 2 the queue will be {2} 1 3 the queue will be {2 3} 2   poped element will be 2 the queue will be {3} 1 4 the queue will be {3 4} 2 popped element will be 3 

/*

The structure of the class is
class MyQueue {
private:
    int arr[100005];
    int front;
    int rear;

public :
    MyQueue(){front=0;rear=0;}
    void push(int);
    int pop();
};
 */

// Function to push an element x in a queue.
void MyQueue ::push(int x) {
    // Your Code
    arr[rear] = x;
    rear++;
}

// Function to pop an element from queue and return that element.
int MyQueue ::pop() {
    // Your Code
    if(front - rear == 0) return -1;
    front++;
    return arr[front-1];
}
