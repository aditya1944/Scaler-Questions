#include<iostream>
#include<stack>
#include<vector>
std::vector<int> solve(std::vector<int> &arr){
    std::vector<int> returnValue(arr.size(), -1);
    std::stack<int> st;
    st.push(0);
    int index = 0;
    while(index<arr.size()){
        if(st.empty()){
            st.push(index);
            ++index;
        }
        else if(arr[st.top()]<arr[index]){
            returnValue[st.top()] = arr[index];
            st.pop();
        }
        else if(arr[st.top()]>=arr[index]){
            st.push(index);
            ++index;
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