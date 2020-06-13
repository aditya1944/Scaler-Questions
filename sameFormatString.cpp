#include<iostream>
void move(int &BIndex, const std::string &B){   
    char ch = B[BIndex];
    while(BIndex<B.size() && B[BIndex]==ch){
        ++BIndex;
    }
}
int solve(const std::string &A, const std::string &B){
    int returnValue=1;
    int AIndex = 0;
    int BIndex = 0;
    //B has duplicates
    if(A.size()>B.size()){
        return 0;
    }
    while(AIndex<A.size() && BIndex<B.size()){
        if(A[AIndex]!=B[BIndex]){
            returnValue = 0;
            break;
        }
        //move BIndex
        move(BIndex,B);
        ++AIndex;
    }
    if(BIndex<B.size()){
        returnValue = 0;
    }
    return returnValue;
}
int main(){
    std::string A,B;
    std::cin>>A>>B;
    int output = solve(A,B);
    std::cout<<output<<std::endl;
    return 0;
}