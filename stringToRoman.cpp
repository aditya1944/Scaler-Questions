#include<iostream>
#include<math.h>
#include<unordered_map>
#include<vector>
std::string solve(int N){
    std::string returnValue = "";
    int num[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000}; 
    std::string sym[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"}; 
    int i=12;     
    while(N>0) 
    { 
      int div = N/num[i]; 
      N = N%num[i]; 
      while(div--) 
      { 
        returnValue+=sym[i];
      } 
      i--; 
    }
    return returnValue;
}
int main(){
    int N;
    std::cin>>N;
    std::string output = solve(N);
    std::cout<<output<<std::endl;
    return 0;
}