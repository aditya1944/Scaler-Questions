#include<iostream>
#include<vector>
#include<stack>
int solve(const std::vector<std::string> &vec){
    std::stack<int> st;
    for(int index = 0;index<vec.size();++index){
        std::string str = vec[index];
        if(str=="+"){
            int n1 = st.top();
            st.pop();
            int n2 = st.top();
            st.pop();
            n1 = n1 + n2;
            st.push(n1);
        }
        else if(str=="-"){
            int n1 = st.top();
            st.pop();
            int n2 = st.top();
            st.pop();
            n1 = n2 - n1;
            st.push(n1);
        }
        else if(str=="*"){
            int n1 = st.top();
            st.pop();
            int n2 = st.top();
            st.pop();
            n1 = n1 * n2;
            st.push(n1);
        }
        else if(str=="/"){
            int n1 = st.top();
            st.pop();
            int n2 = st.top();
            st.pop();
            n1 = n2 / n1;
            st.push(n1);
        }
        else{
            //it is number
            int num = std::stoi(str);
            st.push(num);
        }
    }
    return st.top();
}
int main(){
    int N;
    std::cin>>N;
    std::vector<std::string> vec(N);
    for(int index = 0;index<N;++index){
        std::cin>>vec[index];
    }
    int output = solve(vec);
    std::cout<<output<<std::endl;
    return 0;
}