#include<stack>
#include<iostream>
void insertAtBottom(std::stack<int> &st, int a){
    if(st.empty()){
        st.push(a);
        return;
    }
    int num = st.top();
    st.pop();
    insertAtBottom(st,a);
    st.push(num);
}
void reverse(std::stack<int> &st){
    if(st.empty()){
        return;
    }
    int a = st.top();
    st.pop();
    reverse(st);
    insertAtBottom(st, a);
}

int main(){
    std::stack<int> st;
    st.push(5);
    st.push(4);
    st.push(3);
    st.push(2);
    st.push(1);
    reverse(st);
    while(!st.empty()){
        std::cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}