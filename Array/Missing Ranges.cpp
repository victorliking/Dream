/*
Given a sorted integer array where the range of elements are [lower, upper] inclusive, return its missing ranges.

For example, given [0, 1, 3, 50, 75], lower = 0 and upper = 99, return ["2", "4->49", "51->74", "76->99"].
*/
class Solution{
public:
	vector<string> findMissingRange(vector<int>&nums,int lower, int upper){
		vector<string> ret;
		int n = nums.size();
		int start = lower;
		for(int i =0;i<n;){
			while(i<n&&start==nums[i]){
				i++;
				start++;
			}
			if(start>=upper+1) return ret;
			if(i==n) break;
			ret.push_back(get_range(start,nums[i]-1));
			start =nums[i];
		}
		if(nums.empty()||nums[n-1]<upper){
			ret.push_back(get_range(start,upper));
		}
		return ret;
	}	

	 string get_range(int start, int end){
        if(start==end) return to_string(start);
        return to_string(start)+"->"+to_string(end);
    }
};