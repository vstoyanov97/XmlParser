#pragma once
#pragma warning(disable: 4996)
#include "Xml.h"
#include <fstream>
#include <iostream>

class Engine
{private:
	Xml xml;
	char* removeFirstAndLastSimbol(const char* line);
	char* getArgument(const char* line,int space);
	char* getValue(const char* line);
	bool hasChild(const char* line,const char* argument);
	void parseClass(std::ifstream& ifs);
	int getWhiteSpace(const char* line);
	char* removeSpace(char* line);
	bool hasEnd(char* line);
	char* getClassName(const char* line);
	
public:
	Engine();
	
	void showCommand();
	void readFromFile(std::ifstream& ifs);
	void print();
	void selectKeyByGivenId(const char* id,const char*  key);
	void setValueByGidenKey(const char* id, const char* key, const char* value);
	void printAttributeByGivenId(const char* id);
	void showTextByGivenId(const char* id);
	void createChildByGivenId(const char* id);
};

