#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
std::string removeDuplicateLetters(std::string s) {
    std::stack<char> st;
    std::vector<bool> visited(26,false);
    std::vector<int> frequency(26,0);
    for(int index = 0;index<s.size();++index){
        ++frequency[s[index]-'a'];
    }
    int index = 0;
    while(index<s.length()){
        char ch = s[index];
        if(!visited[ch-'a']){
            //current character is not visited
            if(st.empty()){
                st.push(ch);
                visited[ch-'a'] = true;
                --frequency[ch-'a'];
                ++index;
            }
            else{
                //two conditions
                //1. if(current character is larger than top character)
                if(ch>st.top()){
                    st.push(ch);
                    visited[ch-'a'] = true;
                    --frequency[ch-'a'];
                    ++index;
                }
                //2. if(current character is smaller than top character)
                else{
                    //again two conditions
                    //if(top character is left)
                    if(frequency[st.top()-'a']>0){
                        visited[st.top()-'a'] = false;
                        st.pop();
                    }
                    else{
                        st.push(ch);
                        visited[ch-'a'] = true;
                        --frequency[ch-'a'];
                        ++index;
                    }
                }
            }
        }
        else{
            --frequency[ch-'a'];
            ++index;
        }
    }
    std::string returnValue = "";
    while(!st.empty()){
        returnValue.push_back(st.top());
        st.pop();
    }
    std::reverse(returnValue.begin(),returnValue.end());
    return returnValue;
}
int main(){
    std::string str; 
    std::cin>>str;
    std::cout<<removeDuplicateLetters(str)<<std::endl;
    return 0;
}