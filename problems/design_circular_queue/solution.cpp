class MyCircularQueue {
public:
    int n;
    
    MyCircularQueue(int k) {
        n = k;
    }
    
    int nums[1000];
    int front = 0;
    int rear = -1;
    int x = 0;
    
    bool enQueue(int value) {
        if(x==n){
            return false;
        }
        nums[(rear+1)%n] = value;
        rear = (rear+1)%n;
        x++;
        return true;
    }
    
    bool deQueue() {
        if(x==0){
            return false;
        }
        front = (front+1)%n;
        x--;
        return true;
    }
    
    int Front() {
        if(x==0){
            return -1;
        }
        return nums[front];
    }
    
    int Rear() {
        if(x==0){
            return -1;
        }
        return nums[rear];
    }
    
    bool isEmpty() {
        if(x==0){
            return true;
        }
        return false;
    }
    
    bool isFull() {
        if(x==n){
            return true;
        }
        return false;
    }
};