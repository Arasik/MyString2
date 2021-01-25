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
	~String(); //����

	char* GetStr() const;
	void SetStr(char* s) ;
	//�����������
	friend ostream& operator<<(ostream& os, String& s);
	friend istream& operator>>(istream& is,String& s);

	String& operator=(const String& s);
	String& operator=(const char* s);

	//���� ����֮��Ĵ�С�Ƚ�
	friend bool operator>(const String& s1,const String& s2);
	friend bool operator<(const String& s1, const String& s2);
	friend bool operator==(const String& s1, const String& s2);
};

