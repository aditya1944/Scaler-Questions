#include<iostream>
std::string solve(const std::string &A, const std::string &B){
    //check if A is subsequence of B or not
    if(A.size()>B.size()){
        return "NO";
    }
    int AIndex = 0;
    for(auto &ch: B){
        if(ch==A[AIndex]){
            ++AIndex;
        }
    }
    if(AIndex==A.length()){
        return "YES";
    }
    return "NO";
}
int main(){
    std::string A,B;
    std::cin>>A>>B;
    std::string output = solve(A,B);
    std::cout<<output<<std::endl;
    return 0;
}