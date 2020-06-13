#include<iostream>
#include<vector>
std::vector<int> lps(std::string &str){
    std::vector<int> lpsArray(str.size());
    lpsArray[0] = 0;
    int i = 0, j = 1; 
    while(j<str.size()){
        if(str[i]==str[j]){
            lpsArray[j] = i+1;
            ++j;
            ++i;
        }   
        else{
            if(i!=0){
                i = lpsArray[i-1];
            }
            else{
                lpsArray[j] = 0;
                ++j;
            }
        }
    }
    return lpsArray;
}
std::vector<int> KMP(std::string &str, std::string &patt){
    // search for
    int strPtr = 0, pattPtr = 0;
    std::vector<int> lpsArray = lps(patt);
    while(strPtr<str.size()){
        if(patt[pattPtr]==str[strPtr]){
            ++pattPtr;
            ++strPtr;
        }
        else{
            ++pattPtr;
            ++strPtr;
        }
        if(strPtr==patt.size()){
            
        }
    }
}
int main(){
    std::string str,patt;
    std::cin>>str>>patt;
    //search all occurences of patt in str;
    std::vector<int> output = KMP(str, patt);
    for(int &x: output){
        std::cout<<x<<" ";
    }
    return 0;
}