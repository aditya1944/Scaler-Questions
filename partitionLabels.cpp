#include<iostream>
#include<vector>
std::vector<int> partitionLabels(std::string S){
    std::vector<int> hash(26);
    //maintains last Index of S.
    for(int index = 0;index<S.length();++index){
        int ch = S[index];
        hash[ch - 'a'] = index;
    }
    std::vector<int> returnValue;
    int start = 0,end = 0;
    for(int index = 0;index<S.size();++index){
        end = std::max(end, hash[S[index]-'a']);
        if(index==end){
            //we reached the partition
            int length = end - start+1;
            returnValue.push_back(length);
            start = end + 1;
        }
    }
    return returnValue;
}
int main(){
    return 0;
}