#include<stack>
std::stack<int> st;
int currMin = -1;
class MinStack{
    public:
        MinStack();
        void push(int);
        void pop();
        int top();
        int getMin();
};

MinStack::MinStack(){
    while(!st.empty()){
        st.pop();
    }
    currMin = -1;
}

void MinStack::push(int x){
    //check if curr_min is smaller than x or not
    if(st.empty()){
        st.push(x);
        currMin = x;
        return;
    }
    if(currMin<=x){
        st.push(x);
    }
    else{
        //x is smaller than currMin
        //1. store the difference(newMin - currMin) in stack
        //2. update the min
        int newMin = x;
        st.push(newMin - currMin);
        currMin = x;
    }
}
void MinStack::pop(){
    if(st.empty()){
        return;
    }
    if(st.top()<0){
        //then it is difference(newMin  - prevMin) = diff
        //prevMin = newMin - diff
        //1. update the min
        currMin = currMin - st.top();
    }
    st.pop();
}
int MinStack::top(){
    if(st.empty()){
        return -1;
    }
    if(st.top()<0){
        //diff = newMin - prevMin
        return currMin;
    }
    else{
        return st.top();   
    }
}
int MinStack::getMin(){
    if(st.empty()){
        return -1;
    }
    return currMin;
}