class Solution {
private:
    vector<int> findDigits(int num) {
        vector<int> arr(10);
        
        while(num > 0) {
            int digit = num % 10;
            arr[digit]++;
            num = num / 10;
        }
        
        return arr;
    }
    bool areEqual(vector<int> arr1, vector<int> arr2) {
        int n = arr1.size();
        for(int i = 0; i < n; i++) {
            if(arr1 != arr2) return false;
        }
        
        return true;
    }
public:
    bool reorderedPowerOf2(int n) {
        vector<int> digits = findDigits(n);
        int num = 1;
        
        for(int i = 0; i < 31; i++) {
            if(areEqual(digits, findDigits(num))) return true;
            num = num << 1;
        }
                
        return false;
    }
};