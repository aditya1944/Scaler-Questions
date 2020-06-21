#include<iostream>
#include<vector>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//less_equal is used because array has duplicates
#define ordered_set __gnu_pbds::tree<int, __gnu_pbds::null_type,std::less_equal<int>, __gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update> 
std::vector<int> countSmaller(std::vector<int>& nums){
    //ordered_set is just a macro as written in line no. 7 
    ordered_set o_set;
    std::vector<int> returnValue(nums.size());
    for(int index = nums.size()-1;index>=0;--index){
        int num = nums[index];
        //order of key is a function which return number of values smaller than the specified number.
        returnValue[index] = o_set.order_of_key(num);
        o_set.insert(num);
    }
    return returnValue;
}