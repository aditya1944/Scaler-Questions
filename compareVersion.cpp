#include<iostream>
#include<string_view>
void trim(std::string_view &str){
    int index =0;
    while(str[index]=='0'){
        ++index;
    }
    str = str.substr(index);
}
int compare(std::string_view &str1, std::string_view &str2){
    // if str1 is small return true otherwise false;
    if(str1.size()<str2.size()){
        return -1;
    }
    else if(str1.size()>str2.size()){
        return 1;
    }
    for(int index = 0;index<std::min(str1.size(),str2.size()); ++index){
        if((str1[index]-'0') > (str2[index]-'0')){
            return 1;
        }
        else if((str1[index]-'0') < (str2[index]-'0')){
            return -1;
        }
    }
    return 0;
}
int solve(std::string &str1, std::string &str2){
    //2
    //1.34
    std::string dummyString = "";
    std::string_view s1(str1),s2(str2),dummyView(dummyString);
    int flag = 0;
    while(1){
        size_t p1Index = s1.find_first_of('.');
        size_t p2Index = s2.find_first_of('.');
        std::string_view temp1, temp2;
        if(p1Index==std::string::npos){
            temp1 = s1;
        }
        else if(p1Index!=std::string::npos){
            temp1 = s1.substr(0,p1Index);
        }
        if(p2Index==std::string::npos){
            temp2 = s2;
        }
        else if(p2Index!=std::string::npos){
            temp2 = s2.substr(0,p2Index);
        }
        if(temp1==dummyView && temp2==dummyView){
            break;
        }
        trim(temp1);
        //std::cout<<temp1<<std::endl;
        trim(temp2);
        //now compare temp1 and temp2
        int val = compare(temp1,temp2);
        std::cout<<val<<std::endl;
        if(val==1){
            return 1;
        }
        else if(val==-1){
            return -1;
        }
        if(p1Index!=std::string::npos){
            s1 = s1.substr(p1Index+1);
        }
        else if(p1Index==std::string::npos){
            s1 = dummyView;
        }
        if(p2Index!=std::string::npos){
            s2 = s2.substr(p2Index+1);
        }
        else if(p2Index==std::string::npos){
            s2 = dummyView;
        }
    }
    return 0;
}
int main(){
    std::string str1, str2;
    std::cin>>str1>>str2;
    int output = solve(str1, str2);
    std::cout<<output<<std::endl;
    return 0;
}