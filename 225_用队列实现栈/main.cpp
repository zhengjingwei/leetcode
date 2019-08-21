class MyStack {
    queue<int> q;
public:
    /** Initialize your data structure here. */
    MyStack() {}
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    // O(n)
    int pop() {
        int size = q.size() -1;
        // 将前n-1个元素后插
        for (int i = 0; i < size; ++i){
            q.push(q.front());
            q.pop();
        }
        int ret = q.front();
        q.pop();
        return ret;
    }
    
    /** Get the top element. O(1)*/
    int top() {
        return q.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */