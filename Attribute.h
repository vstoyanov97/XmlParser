#pragma once
#pragma warning(disable: 4996)
#include <cstring>
#include <iostream>

class Attribute
{
private:
	char* value;
	char* key;
public:
	Attribute();
	Attribute(const char* key, const char* value);
	~Attribute();
	Attribute(const Attribute& other);
	Attribute& operator=(const Attribute& other);
	void print();
	const char* getKey()const;
	const char* getValue()const;
	void setValue(const char* value);
};

