#include "Id.h"

Id::Id()
{
	this->id = new char[1];
	strcpy(this->id, "");
	this->cout = 0;
}

Id::~Id()
{
	delete[] this->id;
}

Id::Id(const char* id, int count)
{
	this->id = new char[strlen(id)+1];
	strcpy(this->id, id);
	this->cout = count;
}

Id::Id(const Id& other)
{
	this->id = new char[strlen(other.id) + 1];
	strcpy(this->id, other.id);
	this->cout = other.cout;
}

Id& Id::operator=(const Id& other)
{
	if (this != &other) 
	{
		delete[] this->id;

		this->id = new char[strlen(other.id)+1];

		this->cout = other.cout;
	}
	return *this;
}

const char* Id::getId() const
{
	return this->id;
}

void Id::setCount(int count) 
{
	this->cout = count;
}

const int Id::getCount() const
{
	return this->cout;
}
