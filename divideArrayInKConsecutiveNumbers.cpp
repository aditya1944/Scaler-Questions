#include<vector>
#include<map>
#include<iostream>
    bool isPossibleDivide(std::vector<int>& nums, int k) {
        if(nums.size()%k!=0 || nums.size()==0){
            return false;
        }
        if(k==1){
            return true;
        }
        std::map<int, int> mp;
        for(const int& val: nums){
            ++(mp[val]);
        }
        int  i = nums.size()/k;
        while(i--){
            int prevNum = mp.begin()->first;
            --mp[prevNum];
            if(mp[prevNum]==0){
                mp.erase(prevNum);
            }
            //check if prevNum+1 exisits in map with frequency > 0
            int temp = k-1;
            while(temp--){
                if(mp[prevNum+1]>0){
                    //we have the next element in array
                    --mp[prevNum+1];
                    if(mp[prevNum+1]==0){
                        mp.erase(prevNum+1);
                    }
                    prevNum = prevNum+1;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
int main(){
    std::vector<int> nums = {1,2,3,3,4,4,5,6};
    std::cout<<isPossibleDivide(nums,4);
    return 0;
}