#include<vector>
#include<algorithm>
std::vector<int> solve(std::vector<int> &A, std::vector<std::vector<int> > &B) {
    std::vector<int> returnValue(B.size());
    //make prefixSum Array
    //make prefixXor Array
    std::vector<long long> prefixSum(A.size(),0);
    std::vector<long long> prefixXor(A.size(),0);
    prefixSum[0]=prefixXor[0] = A[0];
    for(int index = 1;index<A.size();++index){
        prefixSum[index] = (long long)A[index] + prefixSum[index-1];
        prefixXor[index] = (long long)A[index]^prefixSum[index-1];
    }
    for(int queryIndex = 0;queryIndex<B.size();++queryIndex){
        int start1 = B[queryIndex][0];
        int end1 = B[queryIndex][1];
        int start2 = B[queryIndex][2];
        int end2 = B[queryIndex][3];
        int length1 = end1-start1,length2 = end2-start2;
        if(length1!=length2){
            returnValue[queryIndex] = 0;
        }
        else{
            //length is same
            //compare prefix Sum and xor Value
            long long subarraySum1 = (start1==0)?prefixSum[end1]:prefixSum[end1]-prefixSum[start1-1];
            long long subarraySum2 = (start2==0)?prefixSum[end2]:prefixSum[end2]-prefixSum[start2-1];
            if(subarraySum2!=subarraySum1){
                returnValue[queryIndex] = 0;
            }
            else{
                //length and sum is same 
                //now use xor 
                long long subarrayXor1 = (start1==0)?prefixXor[end1]:prefixXor[end1]^prefixXor[start1-1];
                long long subarrayXor2 = (start2==0)?prefixXor[end2]:prefixXor[end2]^prefixXor[start2-1];
                if(subarrayXor1!=subarrayXor2){
                    returnValue[queryIndex] = 0;
                }
                else{
                    //length sum and xor is same
                    std::vector<int> subArray1(length1+1);
                    for(int index = start1;index<=end1;++index){
                        subArray1[index-start1] = A[index];
                    }
                    std::sort(subArray1.begin(),subArray1.end());
                    std::vector<int> subArray2(length2+1);
                    for(int index = start2;index<=end2;++index){
                        subArray2[index-start2] = A[index];
                    }
                    std::sort(subArray2.begin(),subArray2.end());
                    if(subArray2==subArray1){
                        returnValue[queryIndex]=1;
                    }
                    else{
                        returnValue[queryIndex]=0;
                    }
                }
            }
        }
    }
    return returnValue;
}