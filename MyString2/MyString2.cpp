#include <iostream>
#include "String.h"
#include "HashTable.hpp"
int String::num_strings = 0;

///hhh
int main()
{
	const char * s = "str";
	String str(s);
	std::cout << str.GetStr()<<std::endl;


	//ʹ��Ĭ�ϵĹ��캯��ʱ��ʹ��set����ô��
	String *str2 = new String();
	char tempStr[100];
	std::cin >> tempStr;
	str2->SetStr(tempStr);
	std::cout << str2->GetStr()<<std::endl;

	//���ƹ��캯��
	String strTest;
	strTest = str;
	std::cout << strTest.GetStr() << std::endl;
	String *str3 = new String(strTest);

	std::cout <<"main's"<<String::num_strings<<std::endl;
	//�����������
	std::cout << *str3 << "\n";
	//������������
	std::cin >> *str3;
	std::cout << *str3 << "\n";
	//���ԱȽ������������
	if (*str3 > str)
	{
		std::cout << "yes str3 > str \n";
	}
	else if(*str3 < str)
	{
		std::cout << "no str3 < str \n";
	}
	else
	{
		std::cout << "oh str3 = str \n";
	}

	delete str2;
	delete str3;

	//hash
	HashTable<int, int> h;

	for (int i = 0; i < 10; i++)
	{
		h.insert(i, i + 1);
	}
	h.find(1);
	return 0;
}

