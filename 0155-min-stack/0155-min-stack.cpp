class MinStack {
private:
    struct Node {
        int val;
        int min;
        Node* next;
        Node(int value, int minimum) : val(value), min(minimum), next(nullptr) {}
    };
    
    Node* topNode;

public:
    MinStack() {
        topNode = nullptr;
    }
    
    void push(int value) {
        if (topNode == nullptr) {
            topNode = new Node(value, value);
        } else {
            int currentMin = std::min(value, topNode->min);
            Node* temp = new Node(value, currentMin);
            temp->next = topNode;
            topNode = temp;
        }
    }
    
    void pop() {
        if (topNode == nullptr) return;
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
    }
    
    int top() {
        if (topNode == nullptr) return -1;
        return topNode->val;
    }
    
    int getMin() {
        if (topNode == nullptr) return -1;
        return topNode->min;
    }
};