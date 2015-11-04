/*
Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
*/
class Solution{
public:
	int maxPoints(vector<Point>& points){
		unordered_map<float,int> slopes;
		int maxp =0,n = points.size();
		for(int i =0;i<n;i++){
			slopes.clear();
			int dup =1;
			for(int j =i+1;j<n;j++){
				if(points[j].x == points[i].x && points[j].y == points[i].y){
					dup++;
					continue;
				}
				float slop = (points[j].x == points[i].x) ? INT_MAX : 
                              (float)(points[j].y - points[i].y) / (points[j].x - points[i].x);
                slopes[slope]++;
			}
			maxp = max(maxp,dup);
			for(auto s:slopes){
				if(s.second+dup>maxp)
					maxp = s.second +dup;
			}
		}
		return maxp;
	}
};