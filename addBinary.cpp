#include<iostream>
#include<algorithm>
std::string add(const std::string &str1, const std::string &str2){
    std::string returnValue = "";
    int s1Index = str1.size()-1,s2Index = str2.size()-1, carry=0;
    while(s1Index>=0 && s2Index>=0){
        int currSum = (str1[s1Index] - '0') + (str2[s2Index] - '0') + carry;
        //currSun would be 0 1 2 and 3
        if(currSum==3){
            returnValue.push_back('1');
            carry = 1;
        }
        else if(currSum==2){
            returnValue.push_back('0');
            carry = 1;
        }
        else{
            //std::cout<<" to_string "<<std::to_string(currSum)<<std::endl;
            returnValue+=std::to_string(currSum);
            carry = 0;
        }
        --s1Index;--s2Index;
    }
    while(s1Index>=0){
        int currSum = (str1[s1Index] - '0') + carry;
        //currSun would be 0 1 and 2
        if(currSum==3){
            returnValue.push_back('1');
            carry = 1;
        }
        else if(currSum==2){
            returnValue.push_back('0');
            carry = 1;
        }
        else{
            returnValue+=std::to_string(currSum);
            carry = 0;
        }
        --s1Index;
    }
    while(s2Index>=0){
        int currSum = (str2[s2Index] - '0') + carry;
        //currSun would be 0 1 and 2
        if(currSum==3){
            returnValue.push_back('1');
            carry = 1;
        }
        else if(currSum==2){
            returnValue.push_back('0');
            carry = 1;
        }
        else{
            returnValue+=std::to_string(currSum);
            carry = 0;
        }
        --s2Index;
    }
    if(carry==1){
        returnValue.push_back('1');
    }
    std::reverse(returnValue.begin(),returnValue.end());
    return returnValue;
}
int main(){
    std::string str1,str2;
    std::cin>>str1>>str2;
    std::string output = add(str1,str2);
    std::cout<<output<<std::endl;
    return 0;
}