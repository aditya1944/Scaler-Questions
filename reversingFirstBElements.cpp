#include<iostream>
#include<vector>
#include<queue>
#include<stack>
std::vector<int> solve(std::vector<int> &vec, int K){
    std::queue<int> q;
    for(int index = 0;index<vec.size();++index){
        q.push(vec[index]);
    }
    std::stack<int> st;
    int num = 1;
    while(num<=K){
        int top = q.front();
        st.push(top);
        q.pop();
        ++num;
        //std::cout<<"Csdc";
    }
    std::cout<<st.size()<<std::endl;
    while(!st.empty()){
        int top = st.top();
        q.push(top);
        st.pop();
    }
    int left = vec.size() - K;
    while(left!=0){
        int top = q.front();
        q.pop();
        q.push(top);
        --left;
    }
    int index = 0;
    while(!q.empty()){
        vec[index] = q.front();
        q.pop();
        ++index;
    } 
    return vec;
}
int main(){
    int N,K;
    std::cin>>N;
    std::vector<int> vec(N);
    for(int index = 0;index<N;++index){
        std::cin>>vec[index];
    }
    std::cin>>K;
    std::vector<int> output = solve(vec,K);
    for(int &x: output){
        std::cout<<x<<" ";
    }
    return 0;
}