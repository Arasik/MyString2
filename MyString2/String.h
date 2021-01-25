#pragma once
#include <iostream>
using std::ostream;
using std::istream;
class String
{
public:
	static int num_strings;
	static const int CIN_LIMIT = 80;
private:
	char* str;
	int len;
	
public:
	String();
	String(const String & s);
	String(const char * s);
	~String(); //析构

	char* GetStr() const;
	void SetStr(char* s) ;
	//重载输入输出
	friend ostream& operator<<(ostream& os, String& s);
	friend istream& operator>>(istream& is,String& s);

	String& operator=(const String& s);
	String& operator=(const char* s);

	//重载 对象之间的大小比较
	friend bool operator>(const String& s1,const String& s2);
	friend bool operator<(const String& s1, const String& s2);
	friend bool operator==(const String& s1, const String& s2);
};

