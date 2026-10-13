class CustomStack {
public:
    stack<int> st;
    int s = 0;
    CustomStack(int maxSize) { s = maxSize; }

    void push(int x) {
        if (st.size() == s)
            return;
        st.push(x);
    }

    int pop() {
        if (st.empty())
            return -1;
        int x = st.top();
        st.pop();
        return x;
    }

    void increment(int k, int val) {
        stack<int> a;
        while (st.size() > k) {
            a.push(st.top());
            st.pop();
        }
        while (!st.empty())
            a.push(st.top() + val), st.pop();
        while (!a.empty())
            st.push(a.top()), a.pop();
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */