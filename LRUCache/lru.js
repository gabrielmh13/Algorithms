class LRUCache {
    constructor(capacity) {
        this.capacity = capacity
        this.cache = new Map()
    }
    
    get(key) {
        if (this.cache.has(key)) {
            let temp = this.cache.get(key)
            this.cache.delete(key)
            this.cache.set(key, temp)
            return temp
        }
        return -1
    }
    
    put(key, value) {
        if (this.cache.has(key)) {
         this.cache.delete(key)
        }

        this.cache.set(key, value)
        
        if (this.cache.size > this.capacity) {
            this.cache.delete(this.cache.keys().next().value)
        }
    }
}

const lru = new LRUCache(2)

lru.put(1, 1)
console.log(lru.cache)
lru.put(2, 2)
console.log(lru.cache)
lru.put(3, 3)
console.log(lru.cache)
lru.get(2)
console.log(lru.cache)
lru.put(4, 4)
console.log(lru.cache)
lru.get(2)
console.log(lru.cache)