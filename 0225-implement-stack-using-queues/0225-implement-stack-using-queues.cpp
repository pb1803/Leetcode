class MyStack {
public:
    MyStack() {
        
    }
    queue <int> q;

    void push(int x) {
     if(q.size()==0) q.push(x);
     else 
     {
        q.push(x);
        for(int i=1;i<q.size();i++)
        { int l = q.front();
            q.push(l);
            q.pop();
        }
     }    
    }
    
    int pop() {
       int temp = q.front();
       q.pop();
       return temp; 
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
       if(q.size()==0) return true;
       else return false; 
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