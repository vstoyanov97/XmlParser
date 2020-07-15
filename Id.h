#pragma once
#pragma warning(disable: 4996)
#include <cstring>


class Id
{
private:
	char* id;
	int cout;
public:
	Id();
	~Id();
	Id(const char* id, int count);
	Id(const Id& other);
	Id& operator=(const Id& other);
	const char* getId()const;
	void setCount(int count);
	const int getCount()const;
};

