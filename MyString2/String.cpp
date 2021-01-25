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
	this->str = new char[len+1];//分配空间
	strcpy_s(this->str,strlen(s.GetStr())+1,s.GetStr());
	num_strings++;
}

String::String(const char * s)
{
	this->len = strlen(s);
	this->str = new char[len+1];//没有分配空间expression destination != null &&size_in_elements>0 分配空间
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
	//this->str = s;//这样会造成编译器重复删除内存，在析构的时候会删除一次，程序结束编译器又会删除一次
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
	// TODO: 在此处插入 return 语句
	//注意清除之前的字符缓存
	while (is&&is.get() != '\n')
		continue;

	char temp[String::CIN_LIMIT];
	is.get(temp, String::CIN_LIMIT);
	/* ：ifstream &get(char *buf, int num, char delim = ’\n’)；
	这种形式把字符读入由 buf 指向的数组，直到读入了 num 个字符或遇到了由 delim 指定的字符，
	如果没使用 delim 这个参数，将使用缺省值换行符’\n’。 */
	s = temp;

	//清除多余的字符
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
