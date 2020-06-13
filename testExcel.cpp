#include<iostream>
#include<vector>
#include<fstream>
int main(){
    std::fstream file;
    file.open("q.xls",std::ios::in);
    std::vector<std::string> lines;
    while(file.is_open()){
        std::string line;
        while(std::getline(file, line)){
            lines.push_back(line);
        }
        file.close();
    }
    for(auto val: lines){
        std::cout<<val<<std::endl;
    }
    return 0;
}