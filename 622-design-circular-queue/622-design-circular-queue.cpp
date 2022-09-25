class MyCircularQueue {
    
public:
    
    int front=0,rear=-1,size,len=0;
    vector<int>cirQue;
    
    MyCircularQueue(int k) {
        size=k;
        // front=0;
        // rear=0;
        
        cirQue.resize(k);
    }

    bool enQueue(int value) {
        if(isFull())return false;
        
        rear = (rear+1)%size;
        cirQue[rear]=value;
    
        return true;
    }
    
    bool deQueue() {
        if(isEmpty())return false;
        if(front == rear)
        {
            front=0;
            rear=-1;
        }
        else
        {
            front = (front+1)% size;
        }
        
        return true;
    }
    
    int Front() {
        if(isEmpty())return -1;
        
        return cirQue[front];
    }
    
    int Rear() {
        return isEmpty() ? -1 : cirQue[rear];
    }
    
    bool isEmpty() {
        return rear == -1;
    }
    
    bool isFull() {
        return !isEmpty()  && (rear+1)%size == front;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */