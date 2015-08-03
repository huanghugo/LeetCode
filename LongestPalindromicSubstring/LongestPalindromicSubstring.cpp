//-----------------------------------------------------------------------------
//  LongestPalindromicSubstring .cpp
//-----------------------------------------------------------------------------

#include <iostream>
#include <string>

class Solution
{
public:
    std::string longestPalindrome( std::string s )
    {
        int theFinalPos = 0;
        int theFinalLen = 0;
        for( size_t i = 0; i < s.length(); ++i )
        {
            int theMaxLen = PalindromeLen( s.data(), i, s.length(), false ) + 1;
            if( theMaxLen > theFinalLen )
            {
                theFinalLen = theMaxLen;
                theFinalPos = i;
            }
            theMaxLen = PalindromeLen( s.data(), i, s.length(), true );
            if( theMaxLen > theFinalLen )
            {
                theFinalLen = theMaxLen;
                theFinalPos = i;
            }
        }

        return theFinalLen != 0 ? s.substr( theFinalPos - theFinalLen / 2 - theFinalLen % 2 + 1, theFinalLen ) : s;
    }

    int PalindromeLen( const char* s, int i, int len, bool mid )
    {
        int theMaxLen = 0;
        int left = mid ? i : i - 1;
        int right = i + 1;
        for( ; left >= 0, right < len; --left, ++right )
        {
            if( s[left] != s[right] )
            {
                return theMaxLen;
            }
            theMaxLen += 2;
        }
        return theMaxLen;
    }
};

int main( int argc, const char* argv[] )
{
    Solution sol;
    std::cout << sol.longestPalindrome( "ababa" ) << std::endl; // "ababa"
    std::cout << sol.longestPalindrome( "abcd" ) << std::endl; // "a"
    return 0;
}