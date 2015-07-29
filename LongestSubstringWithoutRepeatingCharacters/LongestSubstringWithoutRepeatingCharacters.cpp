//-----------------------------------------------------------------------------
//  LongestSubstringWithoutRepeatingCharacters.cpp
//-----------------------------------------------------------------------------

#include <string>
#include <algorithm>
#include <iostream>

class Solution
{
public:
    int lengthOfLongestSubstring( std::string s )
    {
        int record[256];
        memset( record, -1, sizeof( int ) * 256 );

        int maxLength = 0;
        int lastRepeatPos = -1;
        for( size_t i = 0; i < s.length(); ++i )
        {
            if( record[s[i]] != -1 && record[s[i]] > lastRepeatPos )
            {
                // repeat, calc the max length and update the last repeat location
                maxLength = std::max( maxLength, static_cast<int>( i - lastRepeatPos - 1) );
                lastRepeatPos = record[s[i]];
            }
            record[s[i]] = i;
        }

        return std::max( maxLength, static_cast<int>( s.length() - lastRepeatPos - 1 ) );
    }
};

int main( int argc, const char* argv[] )
{
    return 0;
}