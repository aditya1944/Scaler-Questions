#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
bool compare(std::vector<int> &v1, std::vector<int> &v2){
    double d1 = sqrt(v1[0]*v1[0] + v1[1]*v1[1]);
    double d2 = sqrt(v2[0]*v2[0] + v2[1]*v2[1]);
    return d1<d2;
}
std::vector<std::vector<int> > solve(std::vector<std::vector<int> >&vec, int K){
    std::vector<std::vector<int> > returnValue(K);
    std::sort(vec.begin(),vec.end(), compare);
    for(int index = 0;index<K;++index){
        returnValue[index] = vec[index];
    }
    return returnValue;
}
int main(){
    int N,K;
    std::cin>>N;
    std::vector<std::vector<int> >vec(N,std::vector<int>(2,0));
    for(int index = 0;index<N;++index){
        std::cin>>vec[index][0]>>vec[index][1];
    }
    std::cin>>K;
    std::vector<std::vector<int> > output = solve(vec,K);
    for(auto &x: output){
        for(int y:x){
            std::cout<<y<<" ";
        }
        std::cout<<std::endl;
    }
    return 0;
}