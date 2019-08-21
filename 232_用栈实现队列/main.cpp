class MyQueue {
    stack<int> stPush, stPop; // 压入栈 弹出栈
public:
    /** Initialize your data structure here. */
    MyQueue() {}
    // push栈向pop栈倒数据
    void pushToPop(){
        // 如果pop栈为空 push栈向pop栈倒数据
        if(stPop.empty()){
            int val = 0;
            while(!stPush.empty()){
                val = stPush.top();
                stPush.pop();
                stPop.push(val);
            }
        }
        
    }
        
    /** Push element x to the back of queue. */
    void push(int x) {
        stPush.push(x);
    }
    
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        pushToPop();
        int val = stPop.top();
        stPop.pop();
        return val;
    }
    
    /** Get the front element. */
    int peek() {
        pushToPop();
        return stPop.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return stPush.empty() && stPop.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */