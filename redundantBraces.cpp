#include<iostream>
#include<stack>
int solve(const std::string& str){
    std::stack<char> st;
    int returnValue = 0;
    for(int index = 0;index<str.size();++index){
        char ch = str[index];
        if(ch==')'){
            //two possiblities
            //(a) or ((a+b))
            int count = 0;
            while(st.top()!='('){
                ++count;
                st.pop();
            }
            st.pop();
            std::cout<<st.size()<<" ";
            if(count<=1){
                //std::cout<<index<<std::endl;
                ++returnValue;
            }
        }
        else{
            st.push(ch);
        }
    }
    return returnValue;
}
int main(){
    std::string str;
    std::cin>>str;
    int output = solve(str);
    std::cout<<output<<std::endl;
    return 0;
}