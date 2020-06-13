#include<iostream>
int solve(const std::string &str){
    //string contains '.' and 'x'
    //'.' means unoccupied Seat and 'x' means occupied Seat
    //find median person 
    //median person is the person such that people sitting on the left of it is equal to the person right on it
    int totalPersons = 0;
    const int n = str.length();
    int medianIndex = 0;
    for(int index = 0;index<n;++index){
        //count total people in the row
        if(str[index]=='x'){
            ++totalPersons;
        }
    }
    if(totalPersons%2==0){
        //left of median will one less than right of the median
        int personCount = totalPersons/2;
        int index = 0;
        while(1){
            if(str[index]=='x'){
                --personCount;
            }
            if(personCount==0){
                break;
            }
            ++index;
        }  
        medianIndex = index; 
    }
    else{
        //left of median will be equal to right of median
        int personCount = totalPersons/2 + 1;
        int index = 0;
        while(1){
            if(str[index]=='x'){
                --personCount;
            }
            if(personCount==0){
                break;
            }
            ++index;
        }  
        medianIndex = index; 
    }
    int totalHops,leftHops=0,rightHops=0;
    //calculating hops required by person sitting on left of median
    int emptyPlace=medianIndex-1;
    for(int index = medianIndex-1;index>=0;--index){
        if(str[index]=='x'){
            //this index is filled
            leftHops = leftHops + (emptyPlace - index);
            --emptyPlace;
        }   
    }
    emptyPlace = medianIndex+1;
    for(int index = medianIndex+1;index<n;++index){
        if(str[index]=='x'){
            //this index is filled
            rightHops = rightHops + (index - emptyPlace);
            ++emptyPlace;
        }
    }
    //std::cout<<"lefthops: "<<leftHops;
    //std::cout<<"righthops: "<<rightHops;
    totalHops = leftHops + rightHops;
    return totalHops;
}
int main(){
    std::string str;
    std::cin>>str;
    int output = solve(str);
    std::cout<<output<<std::endl;
    return 0;
}