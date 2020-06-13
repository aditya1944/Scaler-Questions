#include<iostream>
#include<unordered_set>
#include<vector>
#include<math.h>
int solve(int N){
    int returnValue,tempN = N,sizeOfDigit = (int)log10(N) + 1;
    std::vector<int> prefixMul(sizeOfDigit), numberArr(sizeOfDigit);
    int index = 0, prev=1;
    std::unordered_set<int> hash;
    while(tempN!=0){
        int digit = tempN%10;
        if(hash.find(digit)!=hash.end()){
            return 0;
        }
        hash.insert(digit);
        prefixMul[index] = prev * digit;
        numberArr[index] = digit;
        prev = prefixMul[index];
        ++index;
        tempN/=10;
    }
    hash.clear();
    /*for(int& x: prefixMul){
        std::cout<<x<<" ";
    }*/
    for(int left = 0;left<sizeOfDigit;++left){
        for(int right = left;right<sizeOfDigit;++right){
            int currentWindowProduct = (left==0)?prefixMul[right]:prefixMul[right]/prefixMul[left-1];
            if(hash.find(currentWindowProduct)!=hash.end()){
                return 0;
            }
            hash.insert(currentWindowProduct);
        }
    }
    return 1;
}
int main(){
    int N;
    std::cin>>N;
    int output = solve(N);
    std::cout<<output<<std::endl;
    return 0;
}