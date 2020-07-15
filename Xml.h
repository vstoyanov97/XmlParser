#pragma once
#pragma warning(disable: 4996)
#include "Child.h"
#include "Attribute.h"
#include "Id.h"
#include <cstring>
#include <iostream>
class Xml
{
private:
	char* className;
	char* id;
	Child* childs;
	Attribute* attributes;
	Id* allId;
	unsigned int childSize;
	unsigned int childCapacity;
	unsigned int attributeCapacity;
	unsigned int attributeSize;
	unsigned int allIdSize;
	unsigned int allIdCapacity;

	void childResize();
	void allIdResize();
	void attributeResize();
	int getChildIndexByGivenId(const char* id);
	
public:
	Xml();
	Xml(const char* className);
	~Xml();
	Xml& operator= (const Xml& other);
	Xml(const Xml& other);
	void parseClass(const char* className);
	void parseChild(const Child& child);
	void parseAttirubte(const char* key, const char* value);
	void parseAttirubeToChild(const char* key, const char* value);
	bool isIdUnique(const char* id);
	int count(const char* id);
	void parseId(const char* id);
	void addId(const char* id);
	void print();
	void selectKeyByGivenId(const char* id, const char* key);
	void setValueByGivenIdAndKey(const char* id, const char* key, const char* value);
	void printAttributeByGivenKey(const char* id);
	void showTextByGivenId(const char* id);
	void createChild(const char* id);
};

