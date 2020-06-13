#include<iostream>
#include<vector>
void helper(std::vector<std::vector<int> > &matx, int currentX, int currentY, int &result, const int &totalNoOfPlaces,int traversedPlaces){
    int val = matx[currentX][currentY];
    if(val==2){
        //it has reached the ending point
        //std::cout<<traversedPlaces<<std::endl;
        //std::cout<<totalNoOfPlaces<<" "<<traversedPlaces;
        if(totalNoOfPlaces==traversedPlaces){
            ++result;
        }
        return;
    }
    else{
        //either it is 1 or 0
        //std::cout<<currentX<<" "<<currentY<<std::endl;
        if(val==0){
            ++traversedPlaces;
        }
        //mark this vertex as -1;
        matx[currentX][currentY] = -1;
        //increment the traversed Places count;
        //++traversedPlaces;
        //going left
        if(currentY-1>=0 && matx[currentX][currentY-1]!=-1){
            helper(matx,currentX, currentY-1, result, totalNoOfPlaces,traversedPlaces);
        }
        //going right
        if(currentY+1<matx[0].size() && matx[currentX][currentY+1]!=-1){
            helper(matx,currentX, currentY+1, result, totalNoOfPlaces,traversedPlaces);
        }
        //going up
        if(currentX-1>=0 && matx[currentX-1][currentY]!=-1){
            helper(matx,currentX-1, currentY, result, totalNoOfPlaces,traversedPlaces);
        }
        //going down
        if(currentX+1<matx.size() && matx[currentX+1][currentY]!=-1){
            helper(matx,currentX+1, currentY, result, totalNoOfPlaces,traversedPlaces);
        }
        if(val==0)
            matx[currentX][currentY] = 0;
    }
}
int solve(std::vector<std::vector<int> > &matx){
    //find start position
    //find end position
    int startX=-1, startY=-1;
    int noOfPlaces = 0,returnValue = 0;
    for(int rowIndex = 0;rowIndex<matx.size();++rowIndex){
        for(int colIndex = 0;colIndex<matx[rowIndex].size();++colIndex){
            int val = matx[rowIndex][colIndex];
            if(val==1){
                startX=rowIndex;
                startY=colIndex;
            }
            if(val==0){
                //it is walkable
                ++noOfPlaces;
            }
        }
    }
    //now use helper function
    //mark starting point as -1;
    //std::cout<<"csdcsdc : "<<noOfPlaces<<std::endl;
    helper(matx,startX,startY,returnValue,noOfPlaces,0);
    return returnValue;
}
int main(){
    int N,M;
    std::cin>>N>>M;
    std::vector<std::vector<int> > matx(N,std::vector<int>(M,0));
    for(int rowIndex = 0;rowIndex<N;++rowIndex){
        for(int colIndex = 0;colIndex<M;++colIndex){
            std::cin>>matx[rowIndex][colIndex];
        }
    }
    int output = solve(matx);
    std::cout<<output<<std::endl;
    return 0;
}