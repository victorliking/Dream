/*
Given a list of non negative integers, arrange them such that they form the largest number.

For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.
*/

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),[](int a,int b){
            return to_string(a)+to_string(b)>to_string(b)+to_string(a);
        });
        string ret;
        for(int i =0;i<nums.size();i++){
            ret += to_string(nums[i]);
        }
        return ret[0]=='0'?"0":ret;
    }
};