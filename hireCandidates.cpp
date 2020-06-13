#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
std::pair<bool,int> isPossible(const std::vector<int> &baseArray, int noOfPersons, int totalAmount){
    //check if noOfPersons is valid number or not
    std::vector<int> finalArray(baseArray.size());
    for(int index = 0;index<baseArray.size();++index){
        int finalCost = baseArray[index] + ((index+1)*noOfPersons);
        finalArray[index] = finalCost;
    }
    std::sort(finalArray.begin(),finalArray.end());
    //std::cout<<finalArray[0]<<" "<<finalArray[1]<<" end";
    int currAmount = 0,checkNoOfPersons = 0;
    for(int val:finalArray){
        currAmount+=val;
        if(currAmount>totalAmount){
            currAmount-=val;
            break;
        }
        ++checkNoOfPersons;
        if(checkNoOfPersons==noOfPersons){
            break;
        }
    }
    std::pair<bool, int> returnValue;
    if(checkNoOfPersons>=noOfPersons){
        returnValue.first = true;
        returnValue.second = currAmount;
        return returnValue;
    }
    returnValue.first = false;
    return returnValue;
}
std::vector<int> solve(int A, std::vector<int> &baseArray){
    //base price for every student is given in baseArray
    int countOfStudents = 0;
    //min Value of students which can be hired is 0
    //max Value of student which can be hired is baseArrary.size()
    int left = 0,right=baseArray.size();
    std::vector<int> ans(2);
    while(left<=right){
        int mid = left + (right-left)/2;
        std::pair<bool, int> flag = isPossible(baseArray, mid,A);
        if(flag.first){
            left = mid+1;
            //std::cout<<flag.second<<" ";
            ans[0] = mid;
            ans[1] = flag.second;
        }
        else{
            right = mid-1;
        }
    }
    return ans;
}
int main(){
    int N,A;
    std::cin>>N;
    std::vector<int> vec(N);
    for(int index = 0;index<N;++index){
        std::cin>>vec[index];
    }
    std::cin>>A;
    std::vector<int> output(2);
    output = solve(A,vec);
    for(auto &val: output){
        std::cout<<val<<" ";
    }
    return 0;
}