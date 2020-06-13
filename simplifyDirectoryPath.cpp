#include<iostream>
#include<stack>
#include<vector>
std::string solve(std::string &str){
    std::vector<std::string> vec;
    std::string returnValue = "";
    int index = 0;
    std::string dot = ".";
    std::string back = "..";
    while(index<str.length()){
        if(str[index]=='/'){
            //start of "word" or "." or ".."
            int j = index+1;
            std::string temp = "";
            while(j<str.size() && str[j]!='/'){
                temp+=str[j];
                ++j;
            }
            if(temp == back){
                if(!vec.empty())
                    vec.pop_back();
            }
            else if(temp==dot){
                //do nothing
            }
            else{
                if(temp.size()!=0)
                    vec.push_back(temp);
            }
            index = j;
        }
        
    }
    index = 0;
    while(index<vec.size()){
        returnValue+="/";
        returnValue+=vec[index];
        ++index;
    }
    /*while(!st.empty()){
        std::cout<<st.top()<<std::endl;
        st.pop();
    }*/
    if(returnValue.empty()){
        returnValue+="/";
    }
    return returnValue;
}
//"/c/"
int main(){
    std::string str = "";
    std::cin>>str;
    std::string output = solve(str);
    std::cout<<output<<std::endl;
    return 0;
}