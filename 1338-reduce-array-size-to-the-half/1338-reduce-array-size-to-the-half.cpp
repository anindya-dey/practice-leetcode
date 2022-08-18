class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int size = arr.size();
        int half_size = size / 2;
        int count = 0;
        unordered_map<int, int> counts;
        vector<int> frequencies(size + 1);
        
        for(auto a : arr) {
            counts[a] += 1;
        }
        
        for(auto [_, f] : counts) {
            frequencies[f]++;
        }
        
        int f = size;
        while(size > half_size) {
            while(frequencies[f] == 0) --f;
            
            count++;
            size -= f;
            frequencies[f]--;
        }
        
        return count;
    }
};