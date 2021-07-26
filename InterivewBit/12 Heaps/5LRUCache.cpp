/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Least Recently Used Cache
class LRUCache {
private:
    typedef list<int> LI;
    typedef pair<int, LI::iterator> PII;
    typedef unordered_map<int, PII> HIPII;

    HIPII cache; // -> {key, {value, iterator pointing to the node}}
    LI used;     // -> {key}
    int _capacity;

    void touch(HIPII::iterator it) {
        int key = it->first;

        used.erase(it->second.second);
        used.push_front(key);

        it->second.second = used.begin();
    }

public:
    LRUCache(int capacity): _capacity(capacity) {

    }

    int get(int key) {
        auto it = cache.find(key);

        if (it == cache.end()) return -1; // Not present
        touch(it);                       // Top pe laga do
        return it->second.first;
    }

    void put(int key, int value) {
        auto it = cache.find(key);

        if (it != cache.end()) touch(it);
        else {
            // If capacity is reached, then remove from cache and list
            if (cache.size() == _capacity) {
                cache.erase(used.back());
                used.pop_back();
            }

            used.push_front(key);
        }

        cache[key] = {value, used.begin()};
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */