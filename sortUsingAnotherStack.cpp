#include<iostream>
#include<vector>
#include<stack>
std::vector<int> solve(std::vector<int> &vec){
    if(vec.empty()){
        return vec;
    }
    std::stack<int> st;
    while(!vec.empty()){
        int temp = vec.back();
        vec.pop_back();
        if(st.empty()){
            st.push(temp);
        }
        else{
            if(temp<=st.top()){
                //just insert in st
                st.push(temp);
            }
            else{
                //find a position such that vec top < temp1
                while(!st.empty() && st.top()<temp){
                    int temp1 = st.top();
                    st.pop();
                    vec.push_back(temp1);
                }
                st.push(temp);
            }
        }
    }
    while(!st.empty()){
        vec.push_back(st.top());
        st.pop();
    }
    return vec;
}
int main(){
    int N;
    std::cin>>N;
    std::vector<int> vec(N);
    for(int index = 0;index<N;++index){
        std::cin>>vec[index];
    }
    std::vector<int>  output  = solve(vec);
    for(int &x: output){
        std::cout<<x<<" ";
    }
    return 0;
}