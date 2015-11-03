/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
*/

class Solution{
public:
	int trap(vector<int>& height) {
        int max =0, pos,water =0;
        for(int i =0;i<height.size();i++){
            if(height[i]>max) pos=i,max =height[i];
        }
        
        for(int i =0,peak=0;i<pos;i++){
            if(height[i]>peak) peak = height[i];
            else water+=peak-height[i];
        }
        for(int i =height.size()-1,peak=0;i>pos;i--){
            if(height[i]>peak) peak = height[i];
            else water += peak-height[i];
        }
        
        return water;
    }
}