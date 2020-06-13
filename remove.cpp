#include<iostream>
#include<algorithm>
#include<vector>
int main(){
    std::vector<int> vec = {1,2,3,4,5,6,2,2,2,5,6,7,10};
    //remove 2 from it
    vec.erase(std::remove(vec.begin(),vec.end(),2),vec.end()); 
    for(int index = 0;index<vec.size();++index){
        std::cout<<vec[index]<<" ";
    }
    return 0;
}