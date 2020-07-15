#pragma once
#pragma warning(disable: 4996)
#include "Attribute.h"
#include <iostream>

class Child
{    
private:
	char* name;
	char* id;
	char* className;
	int spaceCount;
	Attribute* attributes;
	
	unsigned int attributeCapacity;
	unsigned int attributeSize;
	
	void attributeResize();
	
public:
	Child();
	Child(const char* name,const char* className,const char* id,const int spaceCount);
	~Child();
	Child(const Child& other);
	Child& operator=(const Child& other);
	void parseChild(const char* childName, int spaceCount, int id);
	void parseAttirubte(const char* key, const char* value);
	void parseId(const char* id);
	void print();
	const char* getId()const;
	const char* getName()const;
	void setName(const char* name);
	void showAttributeValueByGivenKey(const char* key);
	void setAttributeValueByGivenKey(const char* key, const char* value);
	void printAttribute();
	int const getSpaceCount()const;
};

