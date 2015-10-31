/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/

#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if(n<=0) return 0;
        if(n==1) return 1;
        if(n==2) return 2;
        if(n==3) return 3;
        else return climbStairs(n-1)+climbStairs(n-2)+climbStairs(n-3);
    }
};

int main(){
	Solution a;
	cout<<a.climbStairs(4)<<endl;
	return 0;

}

