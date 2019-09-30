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
	bool Find(int target, std::vector<std::vector<int>> array);	// ��ָOffer ��ά�����еĲ���
	void replaceSpace(char *str, int length);		// ��ָOffer �滻�ո�
	ListNode* ReverseList(ListNode* head);			// ��ָOffer �����ӡ������
	
};

bool solution::Find(int target, std::vector<std::vector<int>> array)
{	
	// ���ÿһ�����ݽ��ж��ֲ���
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
	ListNode* pNode = head;	// ��ǰ�ڵ�
	ListNode* pPrev = NULL;	// ָ��ǰ�ڵ����һ���ڵ�
	ListNode* pNext = NULL;	// ָ��ǰ�ڵ����һ���ڵ�
	ListNode* pNewHead = NULL;	// ������ͷָ��
	
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