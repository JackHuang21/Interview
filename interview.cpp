#include <iostream>
#include <string>
#include <vector>
#include <stack>

struct ListNode {
	int val;
	struct ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class solution
{
public:
	bool Find(int target, std::vector<std::vector<int>> array);	// 剑指Offer 二维数组中的查找
	void replaceSpace(char *str, int length);		// 剑指Offer 替换空格
	ListNode* ReverseList(ListNode* head);			// 剑指Offer 倒序打印单链表
	
};

bool solution::Find(int target, std::vector<std::vector<int>> array)
{	
	// 针对每一行数据进行二分查找
	for (unsigned int i = 0; i < array.size(); i++)
	{
		if (array[i].empty()) continue;
		size_t low = 0;
		size_t high = array[i].size() - 1;
		if (target > array[i].at(high) || target < array[i].at(low)) continue;
		while (low <= high)
		{
			size_t mid = (low + high) / 2;
			if (target < array[i].at(mid)) high = mid - 1;
			else if (target > array[i].at(mid)) low = mid + 1;
			else return true;
		}
	}
	return false;
}


ListNode* solution::ReverseList(ListNode* head)
{
	ListNode* pNode = head;	// 当前节点
	ListNode* pPrev = NULL;	// 指向当前节点的上一个节点
	ListNode* pNext = NULL;	// 指向当前节点的下一个节点
	ListNode* pNewHead = NULL;	// 新链表头指针
	
	while (pNode != NULL)
	{
		pNext = pNode->next;
		if (pNext == NULL) pNewHead = pNode;
		pNode->next = pPrev;
		pPrev = pNode;
		pNode = pNext;
	}

	return pNewHead;
	
}



int main()
{
	solution mySolution;
	std::vector<std::vector<int>> array = { {1, 2, 3}, {2, 3, 4}, {3, 4, 5} };
	std::cout << mySolution.Find(5, array) << std::endl;
	return 0;
}