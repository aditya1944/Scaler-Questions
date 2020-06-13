#include<iostream>
#include<vector>
#include<climits>
std::vector<int> solve(std::vector<int> &v1, std::vector<int> &v2, int K){
    int v1Size = v1.size(), i1 = 0, i2 = v2.size()-1,v2Size = v2.size();
    std::vector<int> returnValue = {INT_MAX, INT_MAX};
    int closestDistance = INT_MAX;
    while(i1<v1Size && i2>=0){
        int sum = v1[i1] + v2[i2];
        int currDistance = abs(K-sum);
        if(currDistance<closestDistance){
            returnValue[0] = v1[i1];
            returnValue[1] = v2[i2];
            //std::cout<<i1<<" "<<i2;
            closestDistance = currDistance;
        }
        else if(currDistance==closestDistance){
            if(returnValue[0]==v1[i1]){
                returnValue[1] = v2[i2];
            }
        }
        if(sum==K){
            returnValue[0] = v1[i1];
            returnValue[1] = v2[i2];
            return returnValue;
        }
        if(sum>K){
            --i2;
        }
        else if(sum<K){
            ++i1;
        }
    }
    //std::cout<<returnValue[0]<<" "<<returnValue[1]<<std::endl;
    while(i1<v1Size){
        int sum = v1[i1] + v2[0];
        int currDistance = abs(K-sum);
        if(currDistance<closestDistance){
            returnValue[0] = v1[i1];
            returnValue[1] = v2[0];
            closestDistance = currDistance;
        }
        ++i1;
    }
    while(i2>=0){
        int sum = v2[i2] + v1[v1.size()-1];
        int currDistance = abs(K-sum);
        if(currDistance<closestDistance){
            returnValue[0] = v1[v1.size()-1];
            returnValue[1] = v2[i2];
            closestDistance = currDistance;
        }
        else if(currDistance==closestDistance){
            if(returnValue[0]==v1[i1]){
                returnValue[1] = v2[i2];
            }
        }
        --i2;
    }
    
    return returnValue;
}
int main(){
    int N1,N2,K;
    std::cin>>N1>>N2;
    std::vector<int> arr1(N1),arr2(N2);
    for(int index = 0;index<N1;++index){
        std::cin>>arr1[index];
    }
    for(int index = 0;index<N2;++index){
        std::cin>>arr2[index];
    }
    std::cin>>K;
    std::vector<int> output = solve(arr1,arr2,K);
    for(int& x:output){
        std::cout<<x<<" ";
    }
    return 0;
}