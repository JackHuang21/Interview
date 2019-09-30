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
	void ReverseString(std::string& str, size_t n);	// �ַ�����ת				
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

void solution::ReverseString(std::string &str, size_t n)
{
	if (n > str.length() || n == 0) return;
	char temp = ' ';
	for (size_t i = 0; i < n/2; i++)
	{
		temp = str[i];
		str[i] = str[n - i - 1];
		str[n - i - 1] = temp;
	}
	for (size_t i = n; i < (str.length() + n)/2; i++)
	{
		temp = str[i];
		str[i] = str[str.length() + n - i - 1];
		str[str.length() + n - i - 1] = temp;
	}
	for (size_t i = 0; i < str.length()/2; i++)
	{
		temp = str[i];
		str[i] = str[str.length() - i - 1];
		str[str.length() - i - 1] = temp;
	}
	return;
}


int main()
{
	solution mySolution;
	std::string test = "helloworld";
	mySolution.ReverseString(test, 5);
	std::cout << test << std::endl;
	return 0;
}