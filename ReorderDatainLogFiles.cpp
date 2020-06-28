#include<iostream>
#include<vector>
#include<algorithm>
bool compare(const std::string &log1, const std::string &log2){
    //determine if log1 and log2 is number or word
    bool log1IsAlpha = isalpha(log1.back());
    bool log2IsAlpha = isalpha(log2.back());
    if(log1IsAlpha==log2IsAlpha){
        if(!log1IsAlpha){
            //both are number type
            return false;
        }
        else{
            //both are word type
            int index1 = log1.find(' ') + 1;
            int index2 = log2.find(' ') + 1;
            std::string suffix1 = log1.substr(index1);
            std::string suffix2 = log2.substr(index2);
            if(suffix1!=suffix2){
                return suffix1<suffix2;
            }
            else{
                return log1<=log2;
            }
        }
    }
    //they are different
    if(log1IsAlpha){
        return true;
    }
    return false;
}
std::vector<std::string> reorderLogFiles(std::vector<std::string>& logs) {
    std::stable_sort(logs.begin(),logs.end(),compare);
    return logs;
}
int main(){
    std::vector<std::string>  vec = {"dig2 3 6","dig1 8 1 5 1"};
    vec = reorderLogFiles(vec);
    for(auto s: vec){
        std::cout<<s<<std::endl;
    }
    return 0;
}
    