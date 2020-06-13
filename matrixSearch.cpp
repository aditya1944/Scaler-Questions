#include<iostream>
#include<vector>
#include<algorithm>
int search(std::vector<std::vector<int> >&matx, int num){
    int found = 0;//not found;
    for(int rowIndex = 0;rowIndex<matx.size();++rowIndex){
        if(num<matx[rowIndex][0]){
            break;
        }
        else if(num>=matx[rowIndex][0] && num<=matx[rowIndex][matx[0].size()-1]){
            bool find = std::binary_search(matx[rowIndex].begin(),matx[rowIndex].end(),num);
            if(find==false){
                return 0;
            }
            else{
                return 1;
            }
        }
    }
    return found;
}
int main(){
    int N,M,num;
    std::cin>>N>>M>>num;
    std::vector<std::vector<int> >matx(N,std::vector<int>(M,0));
    for(int rowIndex = 0;rowIndex<N;++rowIndex){
        for(int colIndex = 0;colIndex<M;++colIndex){
            std::cin>>matx[rowIndex][colIndex];
        }
    }
    int output = search(matx, num);
    return 0;
}