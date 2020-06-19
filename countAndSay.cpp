#include<iostream>
#include<vector>
int countFreq(const std::string &str, int &index){
    char ch = str[index];
    int freq = 0;
    while(index<str.size() && str[index]==ch){
        ++index;
        ++freq;
    }
    return freq;
}
std::string countAndSay(int A){
    if(A==1){
        return "1";
    }
    if(A==2){
        return "11";
    }
    std::string prev = "11";
    for(int index = 3;index<=A;++index){
        //fill dp[index] using dp[index-1];
        //std::string prev = dp[index-1];
        std::string curr = "";
        int j = 0;
        while(j<prev.length()){
            char ch = prev[j];
            int freq = countFreq(prev, j);
            //std::cout<<ch<<" "<<freq<<std::endl; 
            curr+=std::to_string(freq);
            curr+=std::to_string(ch - '0');
        }
        prev = curr;
    }
    return prev;
}
int main(){
    int A;
    std::cin>>A;
    std::string output = countAndSay(A);
    std::cout<<output<<std::endl;
    return 0;
}