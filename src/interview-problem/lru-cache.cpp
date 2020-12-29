#include<bits/stdc++.h>

using namespace std;

struct Entry{
    int value;
    list<int>::iterator itr;
};

class LRUCache {
public:
    int cap;
    unordered_map<int, Entry> cache;
    list<int> eviction;
    
    
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(cache.find(key) != cache.end()){
            eviction.erase(cache[key].itr);
            eviction.push_front(key);
            cache[key].itr = eviction.begin();
            return cache[key].value;
        }
        
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()){
            eviction.erase(cache[key].itr);
        }else{
            if(cache.size() == cap){
                cache.erase(eviction.back());
                eviction.pop_back();
            }
        }
        eviction.push_front(key);
        cache[key] = {value, eviction.begin()};
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */