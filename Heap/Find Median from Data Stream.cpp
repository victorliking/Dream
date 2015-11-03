/*
Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.

Examples: 
[2,3,4] , the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Design a data structure that supports the following two operations:

void addNum(int num) - Add a integer number from the data stream to the data structure.
double findMedian() - Return the median of all elements so far.
For example:

add(1)
add(2)
findMedian() -> 1.5
add(3) 
findMedian() -> 2
*/

class MedianFinder{
	multiset<int,less<int>> min_bst;
	multiset<int,greater<int>> max_bst;
public:
	void addNum(int num){
		if(max_bst.emtpy()||num>*max_bst.begin()){
			min_bst.insert(num);
			if(min_bst.size()>max_bst.size()+1){
				max_bst.insert(*min_bst.begin());
				min_bst.erase(min_bst.begin());
			}
			else {
				max_bst.insert(num);
				if(max_bst.size()>min_bst.size()){
					min_bst.insert(*max_bst.begin());
					max_bst.erase(max_bst.begin());
				}
			}
		}
	}
	doule findMedian(){
		if(min_bst.size()==max_bst.size()) return ((double)*min_bst.begin()+(double)*max_bst.begin())/2.0;
        else return *min_bst.begin();
	}
}