#include<unordered_map>
#include<list>
/*struct compare{
    bool operator()(const std::pair<int,int> &p1, const std::pair<int,int>& p2){
        //first one is key and second one is frequency;
        //page with least frequency will be poped out
        //use min Heap on second value of pairs
        return p1.second>p2.second;
    }
};*/
class LRUCache {
    private:
        int capacity;
        //store key and value
        std::unordered_map<int,int> hashMap;
        std::list<int> lst;
    public:
        LRUCache(int _capacity) {
            capacity = _capacity;
        }
        int get(int key) {
            if(hashMap.find(key)==hashMap.end()){
                //key not in frame;
                return -1;
            }
            lst.remove(key);
            lst.push_front(key);
            return hashMap[key];
        }
        void put(int key, int value) {
            if(hashMap.find(key)!=hashMap.end()){
                //hashMap has the value;
                hashMap[key] = value;
                lst.remove(key);
                lst.push_front(key);
                return;
            }
            //hashMap do not have key;
            hashMap[key] = value;
            if(hashMap.size()>capacity){
                //need to remove the minimum used element
                int lastVal = lst.back();
                hashMap.erase(lastVal);
                lst.pop_back();
            }
            lst.push_front(key);
        }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */