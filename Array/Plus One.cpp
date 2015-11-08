/*
Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.

Hide Company Tags
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        add(digits,1);
        return digits;
    }
    
    void add(vector<int>&digits,int digit){
        int carry = digit;
        for(auto it = digits.rbegin();it!=digits.rend();it++){
            *it += carry;
            carry = *it/10;
            *it %= 10;
        }
        if(carry>0) digits.insert(digits.begin(),1);
    }
};