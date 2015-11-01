/*
Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

Note that 1 is typically treated as an ugly number.
*/

class Solution {
public:
    int nthUglyNumber(int n) {
        set<long> cache ={1};
        long t;
        while(n--){
            auto it = cache.begin();
            t = *it;
            cache.erase(*it);
            cache.insert(t*2);
            cache.insert(t*3);
            cache.insert(t*5);
        }
        return t;
    }
};