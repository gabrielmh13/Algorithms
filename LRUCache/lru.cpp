#include <iostream>
#include <list>
#include <unordered_map>

class LRUCache {
public:
    LRUCache(int cap)
        : capacity(cap){}

    int get(int key){
        if(cacheMap.find(key) != cacheMap.end()){
            recentKeys.erase(cacheMap[key].second);
            recentKeys.push_front(key);
            cacheMap[key].second = recentKeys.begin();
            return cacheMap[key].first;
        }
        return -1;
    }

    void put(int key, int value){
        if(cacheMap.find(key) != cacheMap.end()){
            recentKeys.erase(cacheMap[key].second);
        } else if (cacheMap.size() >= capacity) {
            int lastKey = recentKeys.back();
            recentKeys.pop_back();
            cacheMap.erase(lastKey);
        }

        recentKeys.push_front(key);
        cacheMap[key] = { value, recentKeys.begin() };
    }

    void print_cache(){
        std::cout << "LRU Cache: ";
        for (auto const& pair : cacheMap) {
            std::cout << pair.first << ":" << pair.second.first << "  ";
        }

        std::cout << " | ";

        std::cout << "Recent Keys: ";
        for (auto const& key : recentKeys) {
            std::cout << key << " ";
        }
        std::cout << std::endl;
    }

private:
    int capacity;
    std::unordered_map<int, std::pair<int, std::list<int>::iterator>> cacheMap;
    std::list<int> recentKeys;
};

int main(){
    LRUCache lru(3);

    lru.put(1, 100);
    lru.print_cache();

    lru.put(2, 200);
    lru.print_cache();

    lru.put(3, 300);
    lru.print_cache();

    lru.get(2);
    lru.print_cache();

    lru.put(4, 400);
    lru.print_cache();

    lru.get(2);
    lru.print_cache();

    return 0;
}