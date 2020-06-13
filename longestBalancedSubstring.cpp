#include<iostream>
#include<stack>
struct Node{
    char bracketType;
    int index;
};
//{ => 1, < => 2, [ => 3, ( => 4

char getReverse(char ch){
    if(ch=='}'){
        return '{';
    }
    else if(ch=='>'){
        return '<';
    }
    else if(ch==']'){
        return '[';
    }
    else if(ch==')'){
        return '(';
    }
}
int LBSlength(const std::string A){
    std::stack<Node> st;
    int maxLength = 0;
    Node node = {'~',-1};
    st.push(node);
    for(int index = 0;index<A.size();++index){
        char ch = A[index];
        if(ch=='{' || ch =='<' || ch == '[' || ch == '('){
            Node node;
            node.bracketType = ch;
            node.index = index;
            st.push(node);
        }
        else{
            //ch is among closing bracket
            //top value of stack has 5 possiblities
            //1. -1
            //2. openBracket of different type
            //3. openBracket of same type
            //4. closeBracket of same type
            //5. closeBracket of different type;
            Node topNode = st.top();
            if(topNode.bracketType==getReverse(ch)){
                st.pop();
                int currLength = index -  st.top().index;
                maxLength = std::max(maxLength, currLength);
            }
            else if(topNode.bracketType!=getReverse(ch)){
                Node node;
                node.bracketType = ch;
                node.index = index;
                st.push(node);
            }
        }
    }
    return maxLength;
}
int main(){
    std::string str;
    std::cin>>str;
    int output = LBSlength(str);
    std::cout<<output<<std::endl;
    return 0;
}