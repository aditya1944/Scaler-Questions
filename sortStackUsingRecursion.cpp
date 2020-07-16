#include<stack>
#include<iostream>
void insertInStack(std::stack<int> &st, int a){
    if(st.empty()){
        st.push(a);
        return;
    }
    //we have some element in stack
    if(st.top()<a){
        st.push(a);
        return;
    }
    int top = st.top();
    st.pop();
    insertInStack(st,a);
    st.push(top);
}
void sort(std::stack<int> &st){
    if(st.empty()){
        return;
    }
    int top = st.top();
    st.pop();
    sort(st);
    insertInStack(st,top);
}
int main(){
    std::stack<int> st;
    st.push(9);
    st.push(10);
    st.push(2);
    st.push(1);
    sort(st);
    while(!st.empty()){
        std::cout<<st.top()<<std::endl;
        st.pop();
    }
    return 0;
}