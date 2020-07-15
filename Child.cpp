#include "Child.h"



void Child::parseChild(const char* childName, int spaceCount, int id)
{

}

void Child::parseAttirubte(const char* key, const char* value)
{
	if (this->attributeSize == attributeCapacity) 
	{
		attributeResize();
	}
	Attribute at = Attribute(key, value);
	this->attributes[attributeSize] = at;
	++attributeSize;
}

void Child::parseId(const char* id)
{
	delete[] this->id;

	this->id = new char[strlen(id) + 1];
	strcpy(this->id, id);
}

void Child::print()
{
	
	for (int i = 0; i < spaceCount; i++)
	{
		if (spaceCount == -1) 
		{
			break;
		}
		std::cout << " ";
	}
	if (strcmp(this->className, "") != 0) 
	{
		std::cout << this->className << ": ";
	}
	std::cout << name<<" ";
	for (size_t i = 0; i < this->attributeSize; i++)
	{
		this->attributes[i].print();
	}
}

const char* Child::getId() const
{
	return this->id;
}

const char* Child::getName() const
{
	return this->name;
}

void Child::setName(const char* name)
{
	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);

}

void Child::showAttributeValueByGivenKey(const char* key)
{
	bool isFound = false;
	for (size_t i = 0; i < this->attributeSize; i++)
	{
		if (strcmp(this->attributes[i].getKey(), key) == 0) 
		{
			isFound = true;

			std::cout << "Value is :" << this->attributes[i].getValue()<<std::endl;
			break;
		}


	}

	if (!isFound) 
	{
	
		std::cout << "No suck key found" << std::endl;
	}
}

void Child::setAttributeValueByGivenKey(const char* key, const char* value)
{
	bool isFound = false;
	for (size_t i = 0; i < this->attributeSize; i++)
	{
		if (strcmp(this->attributes[i].getKey(), key) == 0)
		{
			isFound = true;

			std::cout << "you change value from :" << this->attributes[i].getValue() << "to " << value << std::endl;
			this->attributes[i].setValue(value);
			break;
		}


	}

	if (!isFound)
	{

		std::cout << "No suck key found" << std::endl;
	}
}

void Child::printAttribute()
{
	for (size_t i = 0; i < this->attributeSize; i++)
	{
		this->attributes[i].print();
	}
}

int const Child::getSpaceCount() const
{
	return this->spaceCount;
}

void Child::attributeResize()
{
	Attribute* newAttributes = new Attribute[this->attributeCapacity * 2];
	for (size_t i = 0; i < this->attributeSize; i++)
	{
		newAttributes[i] = this->attributes[i];
	}
	this->attributeCapacity *= 2;
	delete[] this->attributes;
	this->attributes = newAttributes;
}


Child::Child()
{
	
	this->name = new char[1];
	strcpy(name, "");

	this->className = new char[1];
	strcpy(className, "");

	this->attributeCapacity = 8;
	this->attributeSize = 0;
	this->attributes = new Attribute[attributeCapacity];
	
	this->id = new char[1];
	strcpy(id, "");
	spaceCount = 0;

}

Child::Child(const char* name,const char* className, const char* id, const int spaceCount)
{
	
	this->name = new char[strlen(name)+1];
	strcpy(this->name, name);

	this->className = new char[strlen(className) + 1];
	strcpy(this->className, className);
	
	this->attributeCapacity = 8;
	this->attributeSize = 0;
	this->attributes = new Attribute[attributeCapacity];
	this->id = new char[strlen(id)+1];
	strcpy(this->id, id);
	this->spaceCount=spaceCount;
}

Child::~Child()
{
	delete[] this->name;
	delete[] this->id;
	delete[] className;
	delete[] this->attributes;
}

Child::Child(const Child& other)
{
	this->name = new char[strlen(other.name) + 1];
	strcpy(this->name, other.name);

	this->className = new char[strlen(other.className) + 1];
	strcpy(this->className, other.className);

	this->attributeCapacity = other.attributeCapacity;
	this->attributeSize = other.attributeSize;
	this->attributes = new Attribute[attributeCapacity];
	
	this->id = new char[strlen(other.id) + 1];
	strcpy(this->id, other.id);
	
	

	

	for (unsigned int i = 0; i < other.attributeSize; ++i)
	{
		this->attributes[i] = other.attributes[i];
	}

	this->spaceCount = other.spaceCount;
	
}

Child& Child::operator=(const Child& other)
{
	if (this != &other) 
	{
		delete[] this->name;
		delete[] this->id;
		delete[] this->className;
		delete[] this->attributes;

		this->name = new char[strlen(other.name) + 1];
		strcpy(this->name, other.name);

		this->className = new char[strlen(other.className) + 1];
		strcpy(className, other.className);


		this->attributeCapacity = other.attributeCapacity;
		this->attributeSize = other.attributeSize;
		this->attributes = new Attribute[this->attributeCapacity];

		this->id = new char[strlen(other.id) + 1];
		strcpy(this->id, other.id);

		this->spaceCount = other.spaceCount;

		

		for (unsigned int i = 0; i < other.attributeSize; ++i)
		{
			this->attributes[i] = other.attributes[i];
		}

	}
	return *this;
}
