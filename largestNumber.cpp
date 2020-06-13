#include<iostream>
#include<vector>
#include<algorithm>
bool compare(int &a, int &b){

    std::string s1 = std::to_string(a);
    std::string s2 = std::to_string(b);
    int index = 0;
    while(index<s1.length() && index<s2.length()){
        if(s1[index]>s2[index]){
            return true;
        }
        else if(s1[index]==s2[index]){
            ++index;
        }
        else{
            return false;
        }
    }
    int compareIndex = index-1;
    if(index<s1.length()){
        if(s1[index]>s2[compareIndex]){
            return true;
        }
        if(s1[index]<s2[compareIndex]){
            return false;
        }
        ++index; 
    }
    if(index<s2.length()){
        if(s2[index]>s1[compareIndex]){
            return false;
        }
        if(s2[index]<s1[compareIndex]){
            return true;
        }
        ++index;
    }
    
}
std::string solve(std::vector<int> &A){
    std::vector<int> arr(A.begin(), A.end());
    std::sort(arr.begin(),arr.end(), compare);
    std::string returnValue = "";
    for(int index = 0;index<arr.size();++index){
        returnValue+=std::to_string(arr[index]);
    }
    return returnValue;
}
int main(){
    int N;
    std::cin>>N;
    std::vector<int> arr(N);
    for(int index = 0;index<N;++index){
        std::cin>>arr[index];
    }
    std::string output = solve(arr);
    std::cout<<output<<std::endl;
    return 0;
}
