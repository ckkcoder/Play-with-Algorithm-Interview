#include <iostream>
#include <vector>
using namespace std;

class Solution {

private:
    vector<int> memo;

    // 以 nums[index] 为结尾的最长上升子序列的长度
    int getMaxLength(const vector<int> &nums, int index){

        if( memo[index] != -1 )
            return memo[index];

        int res = 1;
        for( int i = 0 ; i <= index-1 ; i ++ )
            if( nums[index] > nums[i] )
                res = max( res , 1 + getMaxLength(nums,i) );

        memo[index] = res;
        return res;
    }
public:
    int lengthOfLIS(vector<int>& nums) {

        if( nums.size() == 0 )
            return 0;

        memo = vector<int>( nums.size() , -1 );
        int res = 1;
        for( int i = 0 ; i < nums.size() ; i ++ )
            res = max(res, getMaxLength(nums, i));

        return res;
    }
};

int main() {

    int nums1[] = {10, 9, 2, 5, 3, 7, 101, 18}; // 4
    vector<int> vec1(nums1, nums1 + sizeof(nums1)/sizeof(int));

    cout<<Solution().lengthOfLIS( vec1 )<<endl;


    int nums2[] = {4, 10, 4, 3, 8, 9};  // 3
    vector<int> vec2(nums2, nums2 + sizeof(nums2)/sizeof(int));

    cout<<Solution().lengthOfLIS( vec2 )<<endl;


    int nums3[] = {2, 2};   // 1
    vector<int> vec3(nums3, nums3 + sizeof(nums3)/sizeof(int));

    cout<<Solution().lengthOfLIS( vec3 )<<endl;

    int nums4[] = {1, 3, 6, 7, 9, 4, 10, 5, 6}; // 6
    vector<int> vec4(nums4, nums4 + sizeof(nums4)/sizeof(int));

    cout<<Solution().lengthOfLIS( vec4 )<<endl;


    return 0;
}