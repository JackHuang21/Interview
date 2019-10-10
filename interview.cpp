#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <stack>
#include <algorithm>
#include <cassert>

struct ListNode {
	int val;
	struct ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class solution
{
public:
	bool Find(int target, std::vector<std::vector<int>> array);	// ��ָOffer ��ά�����еĲ���
	ListNode* ReverseList(ListNode* head);			// ��������
	ListNode* ReverseListByRecursion(ListNode* head);	// ������ת�õݹ鷽��
	ListNode* FindTheKNode(ListNode* head, int k);	// ���ҵ�K���ڵ�
	ListNode* FindCenterNode(ListNode* head); // ���������м�ڵ�
	void ReverseString(std::string& str, size_t n);	// �ַ�����ת	
	bool FindBrotherStr(std::string str, std::string target);	// �����ֵ��ַ���
	int StrToInt(std::string str);	// �ַ���ת����
	char FindFirstSingleChar(std::string str);	// ���ҵ�һ��ֻ����һ�ε��ַ�
	int LongestPalindrome(std::string str);	// ������Ӵ�
	bool isLinkListCross(ListNode* listA, ListNode* listB);	// �ж������������Ƿ��ཻ
	
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

ListNode* solution::ReverseListByRecursion(ListNode* head)
{
	if (head == NULL || head->next == NULL)
		return head;
	ListNode* newNode = this->ReverseListByRecursion(head->next);
	head->next->next = head;
	head->next = NULL;

	return newNode;
}

ListNode* solution::FindTheKNode(ListNode* head, int k)
{
	ListNode* p1 = head;
	ListNode* p2 = head;
	int i = k;

	for (; i > 0 && p1 != NULL; i--)
	{
		p1 = p1->next;
	}
	if (i > 0) return NULL;
	while (p1 != NULL)
	{
		p1 = p1->next;
		p2 = p2->next;
	}
	return p2;
}

ListNode* solution::FindCenterNode(ListNode* head)
{
	ListNode* p1 = head;
	ListNode* p2 = head;
	if (head == NULL) return NULL;
	while (p1 != NULL && p1->next != NULL)
	{
		p1 = p1->next->next;
		p2 = p2->next;
	}
	return p2;
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

bool solution::FindBrotherStr(std::string str, std::string target)
{
	size_t targetLen = target.length();
	if (targetLen > str.length()) return false;
	for (size_t i = 0; i < str.length(); i++)
	{
		size_t j = i;
		for (; j < targetLen + i; j++)
		{
			if (target.find(str[j]) == std::string::npos) break;
		}
		if (j == targetLen + i) return true;
	}
	return false;
}

int solution::StrToInt(std::string str)
{
	unsigned int res = 0;
	bool isMinus = false;
	const int intMax = int(unsigned(~0) >> 1);
	const int intMin = -int(unsigned(~0) >> 1) - 1;
	
	if (str[0] == '-' || str[0] == '+')
	{
		str = str.substr(1, str.length() - 1);
		str[0] == '-' ? isMinus = true : isMinus = true;
	}

	for (size_t i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i])) continue;
		int temp = str[i] - '0';
		if (!isMinus && (res > intMax / 10 || (res == intMax / 10 && temp >= intMax % 10)))
		{
			res = intMax;
			break;
		}
		if (isMinus && (res > unsigned(intMin) / 10 || (res == unsigned(intMin) / 10 && temp >= unsigned(intMin) % 10)))
		{
			res = intMin;
			break;
		}
		res = res * 10 + temp;
	}
	return isMinus ? -int(res) : int(res);
}


char solution::FindFirstSingleChar(std::string str)
{
	int* list = new int[CHAR_MAX]();
	char res = '\0';
	for (size_t i = 0; i < str.length(); i++) (*(list + str[i])) ++;
	for (size_t i = 0; i < str.length(); i++)
	{
		if (*(list + str[i]) == 1)
		{
			res = str[i];
			break;
		}
	}
	delete[] list;
	return res;
}

int solution::LongestPalindrome(std::string str)
{
	unsigned int res = 0;
	size_t strLen = str.length();
	for (size_t i = 0; i < strLen; i++)
	{
		str.insert(i*2, "#");
	}
	str = "$" + str + "#";
	std::cout << str << std::endl;
	unsigned* PalindromeLen = new unsigned[str.length()]();
	size_t mx = 0;
	size_t id = 0;
	for (size_t i = 1; i < str.length(); i++)
	{
		PalindromeLen[int(i)] = mx > i ? std::min(PalindromeLen[int(2 * id - i)], mx - i) : 1;
		while (str[i + PalindromeLen[i]] == str[i - PalindromeLen[i]]) PalindromeLen[i]++;
		if (i + PalindromeLen[i] > mx)
		{
			mx = i + PalindromeLen[i];
			id = i;
		}
	}
	for (size_t i = 0; i < str.length(); i++)
		if (PalindromeLen[int(i)] > res) res = PalindromeLen[i];
	delete[] PalindromeLen;
	return res - 1;
}


bool solution::isLinkListCross(ListNode* listA, ListNode* listB)
{
	// �ж������������Ƿ���ڻ� 
	bool res = false;
	ListNode* p1 = listA;
	ListNode* p2 = listA;
	bool isListAHaveCircle = false;
	bool isListBHaveCircle = false;
	ListNode* pListACircleNode = NULL;
	ListNode* pListBCircleNode = NULL;

	assert(listA != NULL);
	assert(listB != NULL);
	
	while (p1 != NULL && p1->next != NULL)
	{
		p1 = p1->next->next;
		p2 = p2->next;
		if (p1 == p2)
		{
			pListACircleNode = p1;
			isListAHaveCircle = true;
			break;
		}
	}
	
	p1 = listB;
	p2 = listB;
	while (p1 != NULL && p1->next != NULL)
	{
		p1 = p1->next->next;
		p2 = p2->next;
		if (p1 == p2)
		{
			pListBCircleNode = p2;
			isListBHaveCircle = true;
			break;
		}
	}
	p1 = NULL;
	p2 = NULL;

	// �޻������
	if (!isListAHaveCircle && !isListBHaveCircle)
	{
		p1 = listA->next;
		p2 = listB->next;
		while (p1 != NULL) p1 = p1->next;
		while (p2 != NULL) p2 = p2->next;
		if (p1 == p2) res = true;
		p1 = NULL;
		p2 = NULL;
	}

	// ����һ���л������
	if ((isListAHaveCircle && !isListBHaveCircle) || (isListBHaveCircle && !isListBHaveCircle)) res = false;

	// ���������������
	if (isListAHaveCircle && isListBHaveCircle)
	{
		p1 = pListACircleNode->next;
		while (p1 != pListACircleNode)
		{
			if (p1 == pListBCircleNode)
			{
				res = true;
				break;
			}
			p1 = p1->next;
		}
	}
	p1 = NULL;
	p2 = NULL;
	return res;
}

int main()
{
	solution mySolution;
	std::string src = "12212321";
	std::cout << mySolution.StrToInt(src) << std::endl;
	return 0;
}