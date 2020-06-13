#include<iostream>
#include<vector>
#include<stack>
#include<unordered_set>
#include<climits>
void trimFun(std::string &output){
    //trim start
    int startIndex = 0;
    while(output[startIndex]!=')' && output[startIndex]!='('){
        ++startIndex;
    }
    while(startIndex<output.size() && output[startIndex]!='('){
        if(output[startIndex]==')')
            output.erase(startIndex,1);
        else
            ++startIndex;
    }
    //trim end
    int endIndex = output.size()-1;
    while(output[endIndex]!=')' && output[endIndex]!='('){
        --endIndex;
    }
    while(endIndex>=0 && output[endIndex]!=')'){
        if(output[endIndex]=='(')
            output.erase(endIndex,1);
        else
            --endIndex;
    }
}
bool checkIfValidString(const std::string &input){
    bool returnValue;
    std::stack<int> st;
    for(int index = 0;index<input.length();++index){
        if(input[index]=='('){
            st.push(1);
        }
        else if(input[index]==')'){
            if(st.empty()){
                return false;
            }
            st.pop();
        }
    }
    if(!st.empty()){
        returnValue = false;
    }
    if(st.empty()){
        returnValue = true;
    }
    return returnValue;
}
void helper(std::unordered_set<std::string> &hash, int noOfOpenBrackets, int noOfCloseBrackets, std::string input, int &maxLength){
    if(/*input.size()==maxLength && */noOfOpenBrackets==noOfCloseBrackets && checkIfValidString(input)){
        maxLength = std::max(maxLength, (int)input.size());
        if(input.size()>=maxLength){
            hash.insert(input);
        }
        return ;
    }
    if(maxLength>INT_MIN && input.size()<maxLength){
        return;
    }
    if(noOfOpenBrackets==input.length() || noOfCloseBrackets==input.length()){
        return;
    }
    if(noOfOpenBrackets>noOfCloseBrackets){
        //you have to remove open brackets
        //one by one remove it 
        for(int index = 0;index<input.size();++index){
            if(input[index]=='('){
                std::string temp = input;
                temp.erase(index,1);
                helper(hash, noOfOpenBrackets-1,noOfCloseBrackets,temp, maxLength);
            }
        }
    }
    if(noOfOpenBrackets<=noOfCloseBrackets){
        for(int index = 0 ;index<input.size();++index){
            if(input[index]==')'){
                std::string temp = input;
                temp.erase(index,1);
                helper(hash, noOfOpenBrackets,noOfCloseBrackets-1,temp,maxLength);
            }
        }
    }
}
std::vector<std::string> solve(std::string input){
    //remove the close brackets from start
    //remove the open brackets from end
    trimFun(input);
    //std::cout<<input<<std::endl;
    
    int noOfOpenBrackets = 0;
    int noOfCloseBrackets = 0;
    for(int index = 0;index<input.size();++index){
        if(input[index]=='('){
            ++noOfOpenBrackets;
        }
        else if(input[index]==')'){
            ++noOfCloseBrackets;
        }
    }
    bool isValidString = checkIfValidString(input);
    //std::cout<<isValidString<<std::endl;
    if(isValidString){
        std::vector<std::string> returnValue;
        returnValue.push_back(input);
        return returnValue;
    }
    int diff = noOfCloseBrackets-noOfOpenBrackets;
    if(diff<0){
        diff = diff*(-1);
    }
    //std::cout<<diff<<std::endl;
    int maxLength = INT_MIN;
    std::unordered_set<std::string> hash; 
    helper(hash, noOfOpenBrackets, noOfCloseBrackets,input,maxLength);
    std::vector<std::string> returnValue;
    for(auto x: hash){
        if(x.length()==maxLength){
            returnValue.push_back(x);
        }
    }
    return returnValue;
}
int main(){
    std::string str;
    std::cin>>str;
    //std::cout<<checkIfValidString("(a)()()");
    std::vector<std::string> output;
    output = solve(str);
    for(int index = 0;index<output.size();++index){
        std::cout<<output[index]<<std::endl;
    }
    return 0;
}