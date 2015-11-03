/*
There are two sorted arrays nums1 and nums2 of size m and n respectively. Find the median of the two sorted arrays. 
The overall run time complexity should be O(log (m+n)).
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        int total =  size1+ size2;
        if(total&0x1)
            return helper(nums1.begin(),size1,nums2.begin(),size2,total/2+1);
        else
             return (helper(nums1.begin(),size1,nums2.begin(),size2,total/2)+ helper(nums1.begin(),size1,nums2.begin(),size2,total/2+1))/2.0;
    }

private:
    int helper(vector<int>::iterator A, int size1, vector<int>:: iterator B, int size2, int k){
        if(size1>size2) return helper(B,size2,A,size1,k);
        if(size1==0) return B[k-1];
        if(k==1) return min(*A,*B);
        
        int ia = min(size1,k/2), ib = k -ia;
        if(*(A+ia-1)<*(B+ib-1))
            return helper(A+ia,size1-ia,B,size2,k-ia);
        else if(*(A+ia-1)>*(B+ib-1))
            return helper(A,size1,B+ib,size2-ib,k-ib);
        else 
            return *(A+ia-1);
        
    }
};