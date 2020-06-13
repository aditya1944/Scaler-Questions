#include<iostream>
#include<vector>
int main(){
    std::string str = "_asd_sdcsdc_csdc_";//_sdcsc_cdscsc_csccs_csdcscs";
    int first = 0;
    std::vector<std::string> vec;
    while(first<str.length()){
        int second = str.find_first_of('_',first);
        if(first!=second){
            if(second==std::string::npos){
                second = str.length();
            }
            vec.push_back(str.substr(first, second-first));
        }
        first = second+1;
    }
    for(auto x:vec){
        std::cout<<x<<" ";
    }
    return 0;
}