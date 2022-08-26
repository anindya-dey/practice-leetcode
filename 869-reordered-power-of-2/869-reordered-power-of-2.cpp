/*
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
*/

class Solution {
private:
    long counter(int N) {
        long res = 0;
        for (; N; N /= 10) res += pow(10, N % 10);
        return res;
    }
public:
    bool reorderedPowerOf2(int N) {
        long c = counter(N);
        for (int i = 0; i < 32; i++)
            if (counter(1 << i) == c) return true;
        return false;
    }
};
