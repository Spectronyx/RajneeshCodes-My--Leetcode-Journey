class MyQueue {
public:
    stack<int> input;   // For pushing new elements
    stack<int> output;  // For popping/peeking
    
    MyQueue() {}
    
    void push(int x) {
        // Step 1: Move all from output to input
        while(!output.empty()) {
            input.push(output.top());
            output.pop();
        }
        
        // Step 2: Push new element to input
        input.push(x);
        
        // Step 3: Move all back to output
        while(!input.empty()) {
            output.push(input.top());
            input.pop();
        }
    }
    
    int pop() {
        int top = output.top();
        output.pop();
        return top;
    }
    
    int peek() {
        return output.top();
    }
    
    bool empty() {
        return output.empty();
    }
};