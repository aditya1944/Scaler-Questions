#include<iostream>

#include<unordered_map>
std::string minWindow(std::string s, std::string t) {
    if(s.empty() || t.empty()){
        return "";
    }
    //find a window of min length which contains all character in t
    int left = 0,right = 0,minLength = s.size();
    int leftIndex = 0,rightIndex = 0;
    std::unordered_map<char, int> window,subMap;
    for(const char&c:t ){
        ++(subMap[c]);
    }
    //submap is ready
    int formed = 0;
    int required = subMap.size();
    while(right<s.size()){
        char ch = s[right];
        if(subMap.find(ch)!=subMap.end()){
            //this character is in t
            ++window[ch];
            if(window[ch]==subMap[ch]){
                ++formed;
            }
            while(left<=right && formed==required){
                if(minLength>right - left + 1){
                    //we got an candidate
                    minLength = right - left + 1;
                    leftIndex = left;
                    rightIndex = right;
                }
                char leftCh = s[left];
                if(subMap.find(leftCh)!=subMap.end()){
                    --(window[leftCh]);
                    if(window[leftCh]<subMap[leftCh]){
                        --formed;
                    }
                }
                ++left;
            }
        }
        ++right;
    }   
    std::string returnValue = s.substr(leftIndex,minLength);
    return returnValue;    
}
int main(){
    std::string s = "ADBEBANC",t="ABC";
    //std::string s = "AABC",t="ABC";
    std::cout<<minWindow(s,t)<<std::endl;
    return 0;
}