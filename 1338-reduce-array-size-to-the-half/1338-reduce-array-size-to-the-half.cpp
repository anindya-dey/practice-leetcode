class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int size = arr.size();
        int half_size = size / 2;
        int count = 0;
        unordered_map<int, int> counts;
        multimap<int, int, greater<int>> frequencies;
        
        for(auto a : arr) {
            counts[a] += 1;
        }
        
        for(auto i : counts) {
            frequencies.insert({i.second, i.first});
        }
        
        for(auto j : frequencies) {
            size -= j.first;
            count += 1;
            
            if(size <= half_size) break;
        }
        
        return count;
    }
};