#include<iostream>
#include<vector>
#include<stack>
std::vector<int> solve(std::vector<int> &vec){
    std::vector<int> returnValue(vec.size(),-1);
    std::stack<int> st;
    int index = vec.size()-1;
    while(index>=0){
        if(st.empty()){
            st.push(index);
            --index;
        }
        else if(vec[index]>=vec[st.top()]){
            st.push(index);
            --index;
        }
        else{
            returnValue[st.top()] = vec[index];
            st.pop();
        }
    }
    return returnValue;
}
int main(){
    int N;
    std::cin>>N;
    std::vector<int> vec(N);
    for(int index = 0;index<N;++index){
        std::cin>>vec[index];
    }
    std::vector<int> output = solve(vec);
    for(int &x: output){
        std::cout<<x<<" ";
    }
    return 0;
}