/*
Design and implement a TwoSum class. It should support the following operations: add and find.

add - Add the number to an internal data structure.
find - Find if there exists any pair of numbers which sum is equal to the value.

For example,
add(1); add(3); add(5);
find(4) -> true
find(7) -> false
*/

class TwoSum {
public:
    unordered_map<int,int> map;
	void add(int number) {
	    map[number]++;
	}

	bool find(int value) {
	    for(auto iter = map.begin();iter!=map.end();iter++){
	        int gap = value -iter->first;
	        int v = iter->first;
	        if((v==gap&&iter->second>1)||(gap!=v&&map.find(gap)!=map.end()))
	        return true;
	    }
	    return false;
	}
};