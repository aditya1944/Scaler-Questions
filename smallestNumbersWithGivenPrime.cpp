#include<iostream>
#include<queue>
#include<algorithm>
#include<set>
std::vector<int> solve(int A, int B, int C, int D) {
    std::set<int> se;
    se.insert(A);
    se.insert(B);
    se.insert(C);
    std::vector<int> returnValue;
    while(returnValue.size()<D){
        int top = *(se.begin());
        se.erase(top);
        returnValue.push_back(top);
        se.insert(A*top);
        se.insert(B*top);
        se.insert(C*top);
    }
    return returnValue;
}
int main(){
    return 0;
}