#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
#include<algorithm>
std::string solve(const std::string &str){
    std::string returnValue = "";
    std::unordered_map<char, int> hashMap;
    for(int index = 0;index<str.length();++index){
        ++hashMap[str[index]];
    }
    std::stack<char> st;
    std::vector<bool> visited(26,false);
    int index = 0;
    while(index<str.length()){
        char ch = str[index];
        /*if(index==4){
            std::cout<<hashMap[ch];
        }*/
        if(!visited[ch - 'a']){
            //not visited
            if(st.empty() || st.top()<ch){
                //std::cout<<"cssc"<<std::endl;
                st.push(ch);
                visited[ch - 'a'] = true;
                --hashMap[ch];
                ++index;
            }
            else{
                if(hashMap[st.top()]>0){
                    //mark this as not visited
                    visited[st.top() - 'a'] = false;
                    //visited[ch-'a'] = true;
                    st.pop();
                    std::cout<<"Csscsdc"<<std::endl;
                }
                else{
                    //std::cout<<index<<std::endl;
                    st.push(ch);
                    --hashMap[ch];
                    //std::cout<<ch<<std::endl;
                    visited[ch - 'a'] = true;
                    ++index;
                }
            }
        }
        else{
            //std::cout<<"cssc"<<std::endl;
            --hashMap[ch];
            ++index;
        }
    }
    //std::cout<<st.size()<<std::endl;
    while(!st.empty()){
        char ch = st.top();
        returnValue.push_back(ch);
        st.pop();
    }
    std::reverse(returnValue.begin(),returnValue.end());
    return returnValue;
}
int main(){
    std::string str;
    std::cin>>str;
    std::string output = solve(str);
    std::cout<<output<<std::endl;
    return 0;
}