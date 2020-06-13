#include<iostream>
#include<vector>
bool isPossible(const std::vector<int>& books, int noOfStudents, int pagesAssigned){
    bool returnValue = false;
    for(int index = 0;index<books.size();){
       int currentPage = 0;
       while(index<books.size() && currentPage<pagesAssigned){
            currentPage+=books[index];
            if(currentPage>=pagesAssigned){
                --noOfStudents;
                break;
            }
            ++index;
       }
       if(noOfStudents==0){
           returnValue = true;
           break;
       }
    }
    return returnValue;
}
int solve(const std::vector<int> &books, int noOfStudents){
    int returnValue,low = 1,high= 100000;
    while(low<=high){
        int pagesAssigned = low + (high-low)/2;
        if(isPossible(books, noOfStudents, pagesAssigned)){
            returnValue = pagesAssigned;
            low = pagesAssigned+1;
        }
        else{
            high = pagesAssigned-1;
        }
    }
    return returnValue;
}
int main(){
    int N,noOfStudents;
    std::cin>>N;
    std::vector<int> books(N,0);
    for(int index = 0;index<N;++index){
        std::cin>>books[index];
    }
    std::cin>>noOfStudents;
    int output = solve(books, noOfStudents);
    std::cout<<output<<std::endl;
    return 0;
}