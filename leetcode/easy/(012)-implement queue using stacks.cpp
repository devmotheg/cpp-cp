/* Solution #1 */

class MyQueue {
    stack<int> input, output;
    
public:
    void push(int x) {
        input.push(x);
    }
    
    int pop(void) {
        int x = peek();
        output.pop();
        return x;
    }
    
    int peek(void) {
        if (output.empty())
            while (input.size())
                output.push(input.top()), input.pop();
        return output.top();
    }
    
    bool empty(void) {
        return input.empty() && output.empty();
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

/* Solution #2 */

class MyQueue {
    stack<int> fifo;
    
public:
    void push(int x) {
        if (empty()) fifo.push(x);
        else {
            int y = pop();
            push(x);
            fifo.push(y);
        }
    }
    
    int pop(void) {
        int x = fifo.top(); fifo.pop(); return x;
    }
    
    int peek(void) {
        return fifo.top();
    }
    
    bool empty(void) {
        return fifo.empty();
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
