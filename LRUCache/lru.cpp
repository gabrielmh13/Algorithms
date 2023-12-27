#include <iostream>
#include <unordered_map>
#include <list>

class LRUCache {
private:
    int capacity;
    std::unordered_map<int, std::pair<int, std::list<int>::iterator>> cacheMap;
    std::list<int> recentKeys;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (cacheMap.find(key) != cacheMap.end()) {
            recentKeys.erase(cacheMap[key].second);
            recentKeys.push_front(key);
            cacheMap[key].second = recentKeys.begin();
            return cacheMap[key].first;
        }
        return -1;
    }

    void put(int key, int value) {
        if (cacheMap.find(key) != cacheMap.end()) {
            recentKeys.erase(cacheMap[key].second);
        } else if (cacheMap.size() >= capacity) {
            int lastKey = recentKeys.back();
            recentKeys.pop_back();
            cacheMap.erase(lastKey);
        }

        recentKeys.push_front(key);
        cacheMap[key] = { value, recentKeys.begin() };
    }

    const std::list<int>& getRecentKeys() const {
        return recentKeys;
    }

    const std::unordered_map<int, std::pair<int, std::list<int>::iterator>>& getCacheMap() const {
        return cacheMap;
    }
};

int main() {
    LRUCache lru(2);

    lru.put(1, 1);
    std::cout << "LRU Cache: ";
    for (auto const& pair : lru.getCacheMap()) {
        std::cout << pair.first << ":" << pair.second.first << " ";
    }
    std::cout << "Recent Keys: ";
    for (auto const& key : lru.getRecentKeys()) {
        std::cout << key << " ";
    }
    std::cout << std::endl;

    lru.put(2, 2);
    std::cout << "LRU Cache: ";
    for (auto const& pair : lru.getCacheMap()) {
        std::cout << pair.first << ":" << pair.second.first << " ";
    }
    std::cout << "Recent Keys: ";
    for (auto const& key : lru.getRecentKeys()) {
        std::cout << key << " ";
    }
    std::cout << std::endl;

    lru.put(3, 3);
    std::cout << "LRU Cache: ";
    for (auto const& pair : lru.getCacheMap()) {
        std::cout << pair.first << ":" << pair.second.first << " ";
    }
    std::cout << "Recent Keys: ";
    for (auto const& key : lru.getRecentKeys()) {
        std::cout << key << " ";
    }
    std::cout << std::endl;

    lru.get(2);
    std::cout << "LRU Cache: ";
    for (auto const& pair : lru.getCacheMap()) {
        std::cout << pair.first << ":" << pair.second.first << " ";
    }
    std::cout << "Recent Keys: ";
    for (auto const& key : lru.getRecentKeys()) {
        std::cout << key << " ";
    }
    std::cout << std::endl;

    lru.put(4, 4);
    std::cout << "LRU Cache: ";
    for (auto const& pair : lru.getCacheMap()) {
        std::cout << pair.first << ":" << pair.second.first << " ";
    }
    std::cout << "Recent Keys: ";
    for (auto const& key : lru.getRecentKeys()) {
        std::cout << key << " ";
    }
    std::cout << std::endl;

    lru.get(2);
    std::cout << "LRU Cache: ";
    for (auto const& pair : lru.getCacheMap()) {
        std::cout << pair.first << ":" << pair.second.first << " ";
    }
    std::cout << "Recent Keys: ";
    for (auto const& key : lru.getRecentKeys()) {
        std::cout << key << " ";
    }
    std::cout << std::endl;

    return 0;
}
