class MyCircularDeque {
private:
int *arr;
int size;
int front;
int rear;
public:
MyCircularDeque(int k) {
size = k;
arr = new int[size];
front = -1;
rear = -1;
}

bool insertFront(int value) {
    if((rear == size-1 && front == 0) || (rear == front - 1)){
        return false;
    }
    else if(front == -1){
        front = rear = 0;
    }
    else if(front == 0){
        front = size-1;
    }else{
        front--;
    }
    arr[front] = value;
    return true;
}

bool insertLast(int value) {
    if((rear == size-1 && front == 0) || (rear == front-1)){
        return false;
    }
    else if(front == -1){
        rear = front = 0;
    }
    else if(rear == size-1 && front!=0){
        rear = 0;
    }
    else{
        rear++;
    }
    arr[rear] = value;
    return true;
}

bool deleteFront() {
    if(front == -1){
        return false;
    }
    else if(front == rear){
        front = rear = -1;
    }
    else if(front == size-1){
        front = 0;
    }
    else{
        front++;
    }
    return true;
}

bool deleteLast() {
    if(rear == -1){
        return false;
    }
    else if(rear == 0 && front!=0){
        rear = size -1;
    }
    else if(front == rear){
        front = rear = -1;
    }
    else{
        rear--;
    }
    return true;
}

int getFront() {
    if(front == -1){
        return -1;
    }
    return arr[front];
    
}

int getRear() {
    if(rear == -1){
        return -1;
    }
    return arr[rear];
}

bool isEmpty() {
    if(front == -1){
        return true;
    }
    return false;
    
}

bool isFull() {
   if((rear == size-1 && front == 0) || (rear == front - 1)){
        return true;
   }
   return false;
}

};