#include<string>
#include "List.h"
int main()
{

	List<int> list1;
	list1.push_front(100);
	list1.push_front(200);
	list1.push_front(300);
	list1.push_back(777);
	std::cout << list1.back() << std::endl; //777
	list1.pop_back();
	std::cout << list1.back() << std::endl; //100
	std::cout << list1.front() << std::endl; //300
	list1.pop_front();
	std::cout << list1.front() << std::endl; //200
	List<int> list2;
	list2.push_back(616);
	list2.push_front(515);
	list2.push_front(313);
	list2.push_back(777);
	for (List<int>::iterator it = list2.begin(); it != list2.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	List<std::string> list3;
	list3.push_back("vidi");
	list3.push_back("vici");
	List<std::string>::iterator iter = list3.begin();
	list3.insert(iter, "Veni");
	for (List<std::string>::iterator it = list3.begin(); it != list3.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	List<std::string> list4;
	list4.push_back("Divide");
	list4.push_back("et");
	list4.push_back("impera");
	for (List<std::string>::iterator it = list4.begin(); it != list4.end(); it++)
	{
		std::cout << *it << " ";
	}
	List<std::string>::iterator mid = ++list4.begin();
	list4.erase(mid);
	std::cout << std::endl;
	for (List<std::string>::iterator it = list4.begin(); it != list4.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	system("pause");
	return 0;
}
