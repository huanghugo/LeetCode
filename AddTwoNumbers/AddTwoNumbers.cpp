//-----------------------------------------------------------------------------
//   AddTwoNumbers.cpp
//-----------------------------------------------------------------------------

#include <vector>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode* addTwoNumbers( ListNode* l1, ListNode* l2 )
    {
        ListNode* head = nullptr;
        ListNode** tail = &head;
        int remain = 0;
        while( l1 || l2 )
        {
            if( l1 )
            {
                remain += l1->val;
                l1 = l1->next;
            }
            if( l2 )
            {
                remain += l2->val;
                l2 = l2->next;
            }
            *tail = new ListNode( remain % 10 );
            tail = &( *tail )->next;
            remain /= 10;
        }
        if( remain != 0 )
        {
            *tail = new ListNode( remain );
        }

        return head;
    }
};

ListNode* construct( std::vector<int> numbers )
{
    ListNode* head = nullptr;
    ListNode** cur = &head;
    for( int value : numbers )
    {
        *cur = new ListNode( value );
        cur = &( *cur )->next;
    }
    return head;
}

int main( int argc, const char* argv[] )
{
    ListNode* first = construct( { 2, 4, 3 } );
    ListNode* second = construct( { 5,6,4 } );

    Solution theSolution;
    auto theResult = theSolution.addTwoNumbers( first, second );

    return 0;
}
