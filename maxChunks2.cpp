#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
int maxChunksToSorted(std::vector<int> &arr)
{
    std::vector<int> temp(arr.begin(), arr.end());
    std::sort(temp.begin(), temp.end());
    std::multiset<int> se1, se2;
    const int n = arr.size();
    int chunks = 0, index = 0;
    while (index < n)
    {
        if (se2.find(arr[index]) != se2.end())
        {
            //it means se2 has the arr[index]
            // do not insert it in se1
            // instead delete from se2
            se2.erase(se2.find(arr[index]));
        }
        else
        {
            //se2 do not have arr[index];
            se1.insert(arr[index]);
        }
        if (se1.find(temp[index]) != se1.end())
        {
            //it means se1 has the temp[index]
            // do not insert it in se2
            // instead delete from se1
            //delete first occurence
            se1.erase(se1.find(temp[index]));
        }
        else
        {
            //se1 do not have temp[index];
            se2.insert(temp[index]);
        }
        //cout<<se1.size()<<" "<<se2.size()<<endl;
        //if(se1.)
        if (se1.size() == 0 && se2.size() == 0)
        {
            ++chunks;
        }
        ++index;
    }
    return chunks;
}
int main()
{
}