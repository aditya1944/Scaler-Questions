#include<iostream>
#include<stack>
class Node{
    public:
        char ch;
        long long length;
};
std::string solve(const std::string &str, int K){
    std::stack<Node> st;
    char returnValue;
    long long length = 0;
    for(int index = 0;index<str.length();){
        if(str[index]>='a' && str[index]<='z'){
            //then increment the length
            ++length;
            if(length>(long long)K){
                break;
            }
            else{
                Node node;
                node.ch = str[index];
                node.length = length;
                st.push(node);
            }
            ++index;
        }
        else{
            //this character is digit
            int j = index;
            std::string strNum = "";
            while(str[j]>='0' && str[j]<='9'){
                strNum.push_back(str[j]);
                ++j;
            }
            int num = std::stoi(strNum);
            length = (length*num);
            index = j;
        }
    }
    //stack is filled
    while(!st.empty()){
        Node node = st.top();
        //std::cout<<node.ch<<std::endl;
        K = K % node.length;
        if(K==0){
            returnValue = node.ch;
            break;
        }
        st.pop();
    }
    std::string q;
    q.push_back(returnValue);
    return q;
}
int main(){
    int K;
    std::string str;
    std::cin>>str;
    std::cin>>K;
    std::string ch = solve(str, K);
    std::cout<<ch<<std::endl;
    return 0;
}