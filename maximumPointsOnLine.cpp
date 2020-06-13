#include<iostream>
#include<unordered_map>
#include<vector>
#include<climits>
#include<algorithm>
int solve(std::vector<int> &A, std::vector<int> &B){
    int returnValue = INT_MIN;
    int size = A.size();
    std::unordered_map<std::string, int> hashMap;
    for(int i = 0;i<size;++i){
        int x1 = A[i],y1 = B[i];
        for(int j = i+1; j<size;++j){
            int x2 = A[j], y2 = B[j];
            int numerator = y2 - y1;
            int denominator = x2 - x1;
            std::string str = "";
            if((numerator<0 && denominator>=0 ) || (numerator>=0 && denominator<0 )){
                str+='-';
                numerator = std::abs(numerator);
                denominator = std::abs(denominator);
            }
            else if(numerator<0 && denominator<0){
                numerator = std::abs(numerator);
                denominator = std::abs(denominator);
            }
            //now neutralize numaerator and denominator
            if(denominator!=0 && numerator!=0){
                int gcd = std::__gcd(numerator,denominator);
                numerator = numerator/gcd;
                denominator = denominator/gcd;
            }
            std::string strIntercept;
            if(denominator==0){
                //as if now take one possiblity 
                strIntercept = "Inf";
            }
            else{
                int intercept;
                intercept = y2 - (numerator * (x1/denominator));
                strIntercept = std::to_string(intercept);
            }
            //make string and store
            str += std::to_string(numerator) + std::to_string(denominator) + strIntercept;
            if(hashMap.find(str)!=hashMap.end()){
                ++hashMap[str];
            }
            else{
                ++hashMap[str];
                ++hashMap[str];
            }
            returnValue = std::max(returnValue, hashMap[str]);
        }
    }
    for(auto &x:hashMap){
        std::cout<<x.first<<" "<<x.second<<std::endl;
    }
    return returnValue;
}
int main(){
    int N;
    std::cin>>N;
    std::vector<int> XArray(N);
    std::vector<int> YArray(N);
    for(int index = 0;index<N;++index){
        std::cin>>XArray[index];
    }
    for(int index = 0;index<N;++index){
        std::cin>>YArray[index];
    }
    int output = solve(XArray,YArray);
    std::cout<<output<<std::endl;
    return 0;
}