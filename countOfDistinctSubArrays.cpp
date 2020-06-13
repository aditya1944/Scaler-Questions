#include<unordered_set>
#include<vector>
#define mod 1000000007
void incrementLeft(std::unordered_set<int> &hash, int &left,std::vector<int> &vec, int val){
    while(vec[left]!=val){
        ++left;
        hash.erase(vec[left]);
    }
    ++left;
}
int solve(std::vector<int> &A) {
    std::unordered_set<int> hash;
    int left = 0,right = -1,currWindowLen = 0;
    int returnValue = 0;
    while(right+1<A.size()){
        ++right;
        if(hash.find(A[right])!=hash.end()){
            incrementLeft(hash,left,A,A[right]);    
        }
        else{
            hash.insert(A[right]);
        }
        returnValue = (returnValue + (right - left + 1))%mod;//got it complete this
    }
    return returnValue;
    //done
}