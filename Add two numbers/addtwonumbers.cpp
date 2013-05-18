#include <iostream>
#include <cassert>

using namespace std;

struct ListNode
{
    int val;
    struct ListNode* next;
    ListNode(int x):val(x),next(NULL){}
};

ListNode* AddTwoNumbers(ListNode* lhs,ListNode* rhs)
{
    assert(lhs != NULL && rhs != NULL);
    
    //带头结点的
    ListNode* result = new ListNode(0);
    ListNode* trail = result;
    bool carryFlag = 0;

    while(lhs && rhs)
    {
	int ltmp = lhs->val;
	int rtmp = rhs->val;
	//三元操作符的优先级比加号的优先级低，所以这里的结果一直是1;
	int sum = (ltmp + rtmp + (carryFlag ? 1 : 0));
    
	if(sum >= 10)
	{
	    carryFlag = 1;
	    sum -= 10;
	}
	else
	{
	    carryFlag = 0;
	}
	
	ListNode* node = new ListNode(sum);
	trail->next = node;
	trail = node;

	lhs = lhs->next;
	rhs = rhs->next;
    }

    if(lhs)
    {
	trail->next = lhs;
	while(carryFlag && lhs)
	{
	    int sum = lhs->val + 1;

	    if(sum >= 10)
	    {
		sum = 0;
		carryFlag = 1;
		lhs->val = sum;
		trail = lhs;
		lhs = lhs->next;
	    }
	    else
	    {
		carryFlag = 0;
		lhs->val = sum;
	    }
	}
	
    }

    if(rhs)
    {
	trail->next = rhs;
	while(carryFlag && rhs)
	{
	    int sum = rhs->val + 1;

	    if(sum >= 10)
	    {
		sum -= 10;
		carryFlag = 1;
		rhs->val = sum;
		trail = rhs;
		rhs = rhs->next;
	    }
	    else
	    {
		carryFlag = 0;
		rhs->val = sum;
	    }
	}
    }
    //这个时候要增加一个节点
    if(carryFlag)
    {
	ListNode* lastNode = new ListNode(1);
	trail->next = lastNode;
    }
    ListNode* p = result->next;
    delete result;

    return p;
}

int main()
{
    ListNode* lhs = new ListNode(0);
    ListNode* rhs = new ListNode(2);
    
    cout << AddTwoNumbers(lhs,rhs)->val << endl;

    return 0;
}
