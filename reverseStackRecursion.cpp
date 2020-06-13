#include<iostream>
#include<stack>
#include<vector>
void reverseStack(std::stack<int> &st){
    //base case
    if(st.empty()){
        return ;
    }
    int currElement = st.top();
    st.pop();
    reverseStack(st);
    st.push(currElement);
}
int main(){
    std::stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    reverseStack(st);

    while(!st.empty()){
        std::cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}