//-----------------------------------------------------------------------------
//   TwoSum.cpp
//-----------------------------------------------------------------------------

#include <cassert>
#include <unordered_map>
#include <vector>

class Solution
{

public:

    std::vector<int>
    TwoSum
        (
        std::vector<int>& aNumbers,
        int aTarget
        )
    {
        std::vector<int> theResults;
        std::unordered_map<int, int> theHash;

        for( std::size_t theIndex = 0; theIndex < aNumbers.size(); theIndex++ )
        {
            int theNumberToFind = aTarget - aNumbers[theIndex];
            auto theResult = theHash.find( theNumberToFind );
            if( theResult == theHash.end() )
            {
                theHash.emplace( aNumbers[theIndex], theIndex );
            }
            else
            {
                theResults.push_back( theResult->second + 1 );
                theResults.push_back( theIndex + 1 );
            }
        }

        return std::move( theResults );
    }

};


int main( int argc, const char* argv[] )
{
    std::vector<int> theNumbers = { 2, 7, 11, 15 };
    int theTarget = 9;
    Solution theSolution;
    auto theResults = theSolution.TwoSum( theNumbers, theTarget );

    assert( theResults.size() == 2 );
    assert( theResults[0] == 1 );
    assert( theResults[1] == 2 );

    return 0;
}