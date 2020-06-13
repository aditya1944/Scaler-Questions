#include <string>
#include<vector>
#include<algorithm>
#include<iostream>
class RevRot
{
public:
    static std::string revRot(const std::string &strng, unsigned int sz){
        std::string returnValue = "";
        if(strng.length()==0){
            returnValue = "";
            return returnValue;
        }
        //std::string str = strng;
        int noOfChunks = strng.length()/sz;
        std::vector<std::string> chunks(noOfChunks);
        for(int chunkIndex = 0;chunkIndex<noOfChunks;++chunkIndex){
            int startIndex = chunkIndex*sz;
            chunks[chunkIndex] = strng.substr(startIndex,sz);
        }
        for(int chunkIndex = 0;chunkIndex<noOfChunks;++chunkIndex){
            std::string currChunk = chunks[chunkIndex];
            int sum = 0;
            for(int index = 0;index<chunkIndex;++index){
                sum+=(currChunk[index] - '0');
            }
            if(sum%2==0){
                std::reverse(currChunk.begin(), currChunk.end());
            }
            else{
                std::rotate(currChunk.begin(), currChunk.begin()+1, currChunk.end()); 
            }
            //std::cout<<currChunk<<std::endl;
            returnValue.append(currChunk);
        }
        return returnValue;
    }
};
int main(){
    std::string str = "12345677899";
    std::string output = RevRot::revRot(str,3);
    std::cout<<output<<std::endl;
    return 0;
}

// 1,23,4,6,7,8,3,24,4,3,6,565
// 0,1, 2,3,4,5,6,7, 8,9,10,12
