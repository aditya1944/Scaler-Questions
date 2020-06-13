#include<iostream>
#include<vector>
#include<queue>
#include<math.h>
#include<algorithm>
bool compare(std::vector<int> &v1,std::vector<int> &v2){
    long long x1 = v1[0],x2 = v2[0],y1 = v1[1],y2=v2[1];
    int v1Dist = sqrt(pow(x1,2) + pow(y1,2));
    int v2Dist = sqrt(pow(x2,2) + pow(y2,2));
    return v1Dist<=v2Dist;
}
std::vector<std::vector<int> > solve(std::vector<std::vector<int> >&points, int B){
    std::vector<std::vector<int> > result;
    //make a minHeap and start inserting
    std::sort(points.begin(),points.end(),compare);
    int index = 0;
    while(B--){
        result.push_back(points[index++]);
    }
    return result;
}
int main(){
    int N,B;
    std::cin>>N;
    std::vector<std::vector<int> > points(N),results;
    for(int index = 0;index<N;++index){
        std::cin>>points[index][0]>>points[index][1];
    }
    std::cin>>B;
    results = solve(points,B);
    for(auto points: results){
        std::cout<<points[0]<<" "<<points[1]<<std::endl;
    }
    return 0;
}