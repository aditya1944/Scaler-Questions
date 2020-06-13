#include<iostream>
#include<vector>
std::string getNum(char ch){
    std::string returnValue;
    if(ch=='1'){
        returnValue = "";
    }
    if(ch=='2'){
        returnValue="abc";
    }
    else if(ch=='3'){
        returnValue="def";
    }
    else if(ch=='4'){
        returnValue="ghi";
    }
    else if(ch=='5'){
        returnValue="jkl";
    }
    else if(ch=='6'){
        returnValue="mno";
    }
    else if(ch=='7'){
        returnValue="pqrs";
    }
    else if(ch=='8'){
        returnValue = "tuv";
    }
    else if(ch=='9'){
        returnValue = "wxyz";
    }
    return returnValue;
}
std::vector<std::string> getString(std::string str){
    std::vector<std::string> returnValue;
    for(int index = 0;index<str.length();++index){
        returnValue.push_back(getNum(str[index]));
    }
    return returnValue;
}
void helper(std::vector<std::string> &returnValue, int listIndex, std::vector<std::string> &list, std::string output ){
    if(listIndex==list.size()){
        returnValue.push_back(output);
        return;
    }
    for(int index = 0;index<list[listIndex].size();++index){
        helper(returnValue,listIndex+1,list, output+list[listIndex][index]);
    }
}
std::vector<std::string> solve(std::string &str){
    std::vector<std::string> list = getString(str);
    std::vector<std::string> returnValue;
    //now generate the strings and store in returnValue
    int listIndex = 0;
    std::string output = "";
    helper(returnValue, listIndex, list,output);
    return returnValue;
}
int main(){
    std::string str;
    std::cin>>str;
    std::vector<std::string> vec = solve(str);
    for(int index = 0;index<vec.size();++index){
        std::cout<<vec[index]<<" ";
    }
    std::cout<<std::endl;
    return 0;
}