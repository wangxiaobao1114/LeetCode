//Solution1
class Solution {
private:
    double findKth(vector<int>& nums1, vector<int>& nums2, int K) { //第K个，对应下标K-1
        if (nums1.size() > nums2.size()) {
            return findKth(nums2,nums1,K);
        }
        if (nums1.size() == 0) {
            return nums2[K-1];
        }
        if (nums2.size() == 0) {
            return nums1[K-1];
        }
        if (K == 1) {
            return min(nums1[0], nums2[0]);
        }
        int s = nums1.size();
        int p1 = min( K / 2, s);
        int p2 = K - p1;
        if (nums1[p1 - 1] < nums2[p2 - 1]) { //说明nums1取少了，kth在nums1后半段或nums2前半段
            vector<int> n1(nums1.begin() + p1, nums1.end());
            vector<int> n2(nums2.begin(), nums2.begin() + p2);
            return findKth(n1, n2, K - p1);
        }
        else {
            vector<int> n3(nums1.begin(), nums1.begin() + p1);
            vector<int> n4(nums2.begin() + p2, nums2.end());
            return findKth(n3, n4, K - p2);
        }
     }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int s1 = nums1.size(), s2 = nums2.size();
        int mid = (s1 + s2) / 2;
        if ( (s1 + s2) % 2 == 0 ) {
            return (findKth(nums1, nums2, mid) + findKth(nums1, nums2, mid + 1)) / 2.0; 
        } 
        else {
            return findKth(nums1, nums2, mid + 1);
        }
    }
};
//Solution2
class Solution {
private:
    double findKth(vector<int>& nums1, vector<int>& nums2, int K ,int start1, int start2) { //第K个，对应下标K-1
        if (nums1.size() - start1 > nums2.size() - start2) {
            return findKth(nums2,nums1,K,start2,start1);
        }
        if (nums1.size() - start1 == 0) {
            return nums2[start2 + K - 1];
        }
        if (nums2.size() - start2 == 0) {
            return nums1[start1 + K - 1];
        }
        if (K == 1) {
            return min(nums1[start1], nums2[start2]);
        }
        int s = nums1.size() - start1;
        int p1 =  min( K / 2, s);
        int p2 =  K - p1;
        if (nums1[start1 + p1 - 1] < nums2[start2 + p2 - 1]) { //说明nums1取少了，kth在nums1后半段或nums2前半段
            return findKth(nums1, nums2, K - p1, start1 + p1,start2);
        }
        else {
            return findKth(nums1, nums2, K - p2, start1, start2 + p2);
        }
     }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int s1 = nums1.size(), s2 = nums2.size();
        int mid = (s1 + s2) / 2;
        if ( (s1 + s2) % 2 == 0 ) {
            return (findKth(nums1, nums2, mid,0,0) + findKth(nums1, nums2, mid + 1,0,0)) / 2.0; 
        } 
        else {
            return findKth(nums1, nums2, mid + 1,0,0);
        }
    }
};