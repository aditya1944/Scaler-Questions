#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
int solve(std::vector<int> &arr, int K){
    std::sort(arr.begin(),arr.end());
    //use three pointers approach
    int distance = INT_MAX;
    int returnValue;
    int size = arr.size();
    for(int i = 0;i<size;++i){
        int sumLeft = K-arr[i];
        //std::cout<<"Cscsdc";
        //now find j, k such that
        int j = 0, k = arr.size()-1;
        while(j<k){
            //std::cout<<"Cscsdc";
            if(j!=i && k!=i){
                int tempSum = arr[i] + arr[j] + arr[k];
                if(tempSum>K){
                    if(distance>(tempSum-K)){
                        distance = tempSum-K;
                        returnValue = tempSum;
                    }
                }
                else if(tempSum<K){
                    if(distance>(K-tempSum)){
                        distance = K-tempSum;
                        returnValue = tempSum;
                    }
                }
                else{
                    return 0;
                }
                if(arr[j]+arr[k]<sumLeft){
                    ++j;
                }
                else if(arr[j]+arr[k]>sumLeft){
                    --k;
                }
            }
            else{
                if(j==i){
                    ++j;
                }
                if(k==i){
                    --k;
                }
            }
        }
    }
    return returnValue;
}
int main(){
    int N,K;
    std::cin>>N>>K;
    std::vector<int> vec(N);
    for(int index = 0;index<N;++index){
        std::cin>>vec[index];
    }
    int output = solve(vec,K);
    std::cout<<output<<std::endl;
    return 0;
}