#include<math.h>
#include<vector>
#include<climits>
int fun(int num1, int num2, int num3){
    int diff1 = abs(num1-num2);
    int diff2 = abs(num2-num3);
    int diff3 = abs(num2-num2);
    int returnValue = std::max(diff1, std::max(diff2, diff3));
    return returnValue;
}
int minimize(const std::vector<int> &A, const std::vector<int> &B, const std::vector<int> &C){
    int AIndex = 0;
    int returnValue = INT_MAX;
    while(AIndex<A.size()){
        int AVal = A[AIndex], BIndex = 0,CIndex = 0;
        while(BIndex<B.size() && CIndex<C.size()){
            int BVal = B[BIndex],CVal = C[CIndex];
            returnValue = std::min(returnValue,fun(AVal,BVal,CVal));
            if(BVal<CVal){
                ++BIndex;
            }
            else{
                ++CIndex;
            }
        }
        while(BIndex<B.size()){
            //C has reached its limits
            int CVal = C[C.size()-1];
            returnValue = std::min(returnValue,fun(AVal,B[BIndex],CVal));
            ++BIndex;
        }
        while(CIndex<C.size()){
            //B has reached its limits
            int BVal = B[B.size()-1];
            returnValue = std::min(returnValue,fun(AVal,BVal,C[CIndex]));
            ++CIndex;
        }
        ++AIndex;
    }
    return returnValue;
}