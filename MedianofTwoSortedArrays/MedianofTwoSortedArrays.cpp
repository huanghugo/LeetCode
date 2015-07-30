//-----------------------------------------------------------------------------
//  MedianofTwoSortedArrays .cpp
//-----------------------------------------------------------------------------

#include <vector>
#include <algorithm>

class Solution
{
public:
    double findMedianSortedArrays( std::vector<int>& nums1, std::vector<int>& nums2 )
    {
        double prev = 0;
        int totalNum = nums1.size() + nums2.size();
        for( std::size_t i1 = 0, i2 = 0; i1 < nums1.size() || i2 < nums2.size(); )
        {
            double curr;
            if( i1 != nums1.size() && i2 != nums2.size() )
            {
                // both not empty
                if( nums1[i1] < nums2[i2] )
                {
                    curr = nums1[i1++];
                }
                else if( nums1[i1] >= nums2[i2] )
                {
                    curr = nums2[i2++];
                }
            }
            else if ( i1 == nums1.size() )
            {
                // s1 empty
                curr = nums2[i2++];
            }
            else if ( i2 == nums2.size() )
            {
                // s2 empty
                curr = nums1[i1++];
            }

            if( i1 + i2 == totalNum / 2 + 1 )
            {
                return totalNum % 2 ? curr : ( prev + curr ) / 2;
            }
            prev = curr;
        }
    }
};

int main( int argc, const char* argv[] )
{
    Solution sol;
    std::vector<int> num1;
    std::vector<int> num2;
    num2.push_back( 2 );
    num2.push_back( 3 );
    double rel = sol.findMedianSortedArrays( num1, num2 ); //2.5
    return 0;
}