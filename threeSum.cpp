#include<vector>
#include<algorithm>
std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
    std::vector<std::vector<int> >returnValue;
    if(nums.size()<3){
        return returnValue;
    }
    std::sort(nums.begin(),nums.end());
    for(int index = 0;index<nums.size()-2;++index){
        if(index==0 || (index>0 && nums[index]!=nums[index-1])){
            //it is good element;
            int left = index+1;
            int right = nums.size()-1;
            int sum = 0 - nums[index];
            while(left<right){
                int currSum = nums[left] + nums[right];
                if(currSum==sum){
                    //cout<<nums[left]<<" "<<nums[right]<<" "<<nums[index]<<endl;
                    std::vector<int> temp ={nums[index],nums[left],nums[right]};
                    returnValue.push_back(temp);
                    while(left<right && nums[left]==nums[left+1]){
                        ++left;
                    }
                    while(left<right && nums[right]==nums[right-1]){
                        --right;
                    }
                    ++left;
                    --right;
                }
                else if(currSum<sum){
                    ++left;
                }
                else{
                    --right;
                }
            }
        }
    }
    return returnValue;
}    