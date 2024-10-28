class RandomizedCollection {
private:
    std::unordered_map<int, std::unordered_set<int>> map;
    std::vector<int> list;

public:
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        bool ans = map.count(val) > 0;
        map[val].insert(list.size());
        list.push_back(val);
        return !ans;
    }
    
    bool remove(int val) {
        if (map.count(val) == 0) return false;

        int indexVal = *map[val].begin();

        map[val].erase(indexVal);
        if (map[val].empty()) map.erase(val);

        if (indexVal != list.size() - 1) {
            int lastValue = list.back();

            map[lastValue].erase(list.size() - 1);
            map[lastValue].insert(indexVal);

            list[indexVal] = lastValue;
        }

        list.pop_back();
        return true;
    }
    
    int getRandom() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dist(0, list.size() - 1);
        int ind = dist(gen);
        return list[ind];
    }
};