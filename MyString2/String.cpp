#include "String.h"
#include <string.h>
#include <iostream>
String::String()
{
	this->str = new char[15];
	num_strings++;
}
String::String(const String& s)
{
	this->len = strlen(s.GetStr());
	this->str = new char[len+1];//����ռ�
	strcpy_s(this->str,strlen(s.GetStr())+1,s.GetStr());
	num_strings++;
}

String::String(const char * s)
{
	this->len = strlen(s);
	this->str = new char[len+1];//û�з���ռ�expression destination != null &&size_in_elements>0 ����ռ�
	strcpy_s(this->str, strlen(s) + 1, s);
	num_strings++;
}

String::~String()
{
	std::cout << str << " \" object deleted \" " << std::endl;
	num_strings--;
	std::cout << num_strings << std::endl;
	delete[] str;
}

char* String::GetStr() const
{
	return this->str;
}

void String::SetStr(char* s) 
{
	//this->str = s;//��������ɱ������ظ�ɾ���ڴ棬��������ʱ���ɾ��һ�Σ���������������ֻ�ɾ��һ��
	len = strlen(s);
	try
	{
		delete[]str;
		str = new char[len+1];
		strcpy_s(str, len + 1, s);
	}
	catch (const std::exception&)
	{
		std::cout << "set error\n";
	}
	
}

String & String::operator=(const String& s)
{
	std::cout << "this is operator =" << std::endl;
	delete[] str;
	len = strlen(s.GetStr());
	str = new char[len + 1];
	strcpy_s(str, len + 1, s.GetStr());
	return *this;
}

String & String::operator=(const char * s)
{
	delete[] str;
	len = strlen(s);
	str = new char[len + 1];
	strcpy_s(str, len + 1, s);
	return *this;
}

ostream& operator<<(ostream & os, String & s)
{
	os << s.str;
	return os;
}

istream & operator>>(istream & is, String& s)
{
	// TODO: �ڴ˴����� return ���
	//ע�����֮ǰ���ַ�����
	while (is&&is.get() != '\n')
		continue;

	char temp[String::CIN_LIMIT];
	is.get(temp, String::CIN_LIMIT);
	/* ��ifstream &get(char *buf, int num, char delim = ��\n��)��
	������ʽ���ַ������� buf ָ������飬ֱ�������� num ���ַ����������� delim ָ�����ַ���
	���ûʹ�� delim �����������ʹ��ȱʡֵ���з���\n���� */
	s = temp;

	//���������ַ�
	while (is&&is.get() != '\n')
		continue;
	return is;
}

bool operator>(const String & s1, const String & s2)
{
	return strcmp(s1.str,s2.str)>0;
}

bool operator<(const String & s1, const String & s2)
{
	return s2>s1;
}

bool operator==(const String & s1, const String & s2)
{
	return strcmp(s1.str,s2.str)==0;
}
