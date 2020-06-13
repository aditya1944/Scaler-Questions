#include<iostream>
#include<vector>
#include<algorithm>
struct Interval{
    int start;
    int end;
};
bool compare(Interval &i1, Interval &i2){
    return i1.start<i2.start;
}
std::vector<Interval> solve(std::vector<Interval> &A){
    if(A.size()==1){
        return A;
    }
    std::sort(A.begin(),A.end(),compare);
    std::vector<Interval> returnValue;
    for(int index = 0;index<A.size();++index){
        Interval currInterval = A[index];
        //good case
        while(index+1<A.size() && currInterval.end>=A[index+1].start){
            //2 case
            if(currInterval.end>=A[index+1].end){
                //complete overlap
                
            }
            else{
                //partial overlap
                currInterval.end = A[index+1].end;
            }
            ++index;
        }
        returnValue.push_back(currInterval);
    }
    return returnValue;
}
int main(){
    int N;
    std::cin>>N;
    std::vector<Interval> input(N);
    for(int index = 0;index<N;++index){
        std::cin>>input[index].start>>input[index].end;
    }
    std::vector<Interval> output = solve(input);
    for(auto &x: output){
        std::cout<<x.start<<" "<<x.end<<std::endl;
    }
    return 0;
}