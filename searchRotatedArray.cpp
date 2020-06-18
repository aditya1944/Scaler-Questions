#include<iostream>
#include<vector>
int search(const std::vector<int> &nums,int target){
    if(nums.size()==0){
        return -1;
    }
    if(nums[0]==target){
        return 0;
    }
    if(nums[nums.size()-1]==target){
        return nums.size()-1;
    }
    int left = 0,right = nums.size()-1;
    while(left<=right){
        int mid = left + (right - left)/2;
        //first determine where mid lies(in which part)
        if(nums[mid]==target){
            return mid;
        }
        if(nums[mid]>=nums[0]){
            //mid lies in 1st part
            //there are two possibility 
            //1. target lies in first part
            //2. target lies in second part
            if(target>nums[0] && target<nums[mid]){
                right = mid - 1;
            }
            if(target>nums[mid] || target < nums[0]){
                left = mid + 1;
            }
        }
        else if(nums[mid]<nums[0]){
            //mid lies in 2nd part
            //there are two possiblity
            // 1. target lies in first part
            // 2. target lies in second part
            //cout<<left<<" "<<right<<endl;
            if(target>nums[0] || target<nums[mid]){
                cout<<left<<" "<<right<<endl;
                right = mid - 1;
            }
            if(target>nums[mid] && target<nums[0]){
                //cout<<left<<" "<<right<<endl;
                left = mid + 1;
            }
        }
        
        //cout<<left<<" "<<right<<endl;
    }
    return -1;
}
int main(){
    return 0;
}