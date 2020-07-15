#include "Xml.h"

void Xml::childResize()
{
	Child* newChild = new Child[this->childCapacity * 2];
	for (size_t i = 0; i < this->childSize; i++)
	{
		newChild[i] = this->childs[i];
	}
	this->childCapacity *= 2;
	delete[] this->childs;
	this->childs = newChild;
}

void Xml::allIdResize()
{
	Id* newId = new Id[this->allIdCapacity * 2];
	for (size_t i = 0; i < this->allIdSize; i++)
	{
		newId[i] = this->allId[i];
	}
	this->allIdCapacity *= 2;
	delete[] this->allId;
	this->allId = newId;
}

void Xml::attributeResize()
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

int Xml::getChildIndexByGivenId(const char* id)
{
	int index = -1;
	for (size_t i = 0; i < this->childSize; i++)
	{
		if (strcmp(id, childs[i].getId()) == 0) 
		{
			index = i;
			return index;
		}
	}
	return index;
}

Xml::Xml()
{
	className = new char[1];
	strcpy(className, "");
	this->id = new char[1];
	strcpy(this->id, "");
	
	this->childCapacity = 8;
	this->childs = new Child[childCapacity];
	this->childSize = 0;
	
	this->attributeCapacity = 8;
	this->attributes = new Attribute[attributeCapacity];
	this->attributeSize = 0;
	
	this->allId = new Id[8];
	this->allIdSize = 0;
	this->allIdCapacity = 8;
	
}

Xml::Xml(const char* className )
{
	this->className = new char[strlen(className) + 1];
	strcpy(this->className, className);
	this->id = new char[1];
	strcpy(this->id, "");
	this->childCapacity = 8;
	this->childs = new Child[childCapacity];
	this->childSize = 0;
	this->attributeCapacity = 8;
	this->attributes = new Attribute[attributeCapacity];
	this->attributeSize = 0;

	this->allId = new Id[8];

	this->allIdSize = 0;
	this->allIdCapacity = 8;
}

Xml::~Xml()
{
	delete[] className;
	delete[] childs;
	delete[] attributes;
	delete[] allId;
}

Xml& Xml::operator=(const Xml& other)
{
	if (this != &other) 
	{
		delete[] className;
		delete[] childs;
		delete[] attributes;
		delete[] allId;
		delete[] id;

		this->className = new char [strlen(other.className) + 1];
		strcpy(this->className, other.className);

		this->childs = new Child[other.childCapacity];
		
		this->id = new char[strlen(other.id) + 1];
		strcpy(this->id, other.id);

		for (unsigned int i = 0; i < other.childSize; ++i)
		{
			this->childs[i] = other.childs[i];
		}
		this->childCapacity = other.childCapacity;
		this->childSize = other.childSize;

		this->attributes = new Attribute[other.attributeCapacity];

		for (unsigned int i = 0; i < other.attributeSize; ++i)
		{
			this->attributes[i] = other.attributes[i];
		}
		this->attributeCapacity = other.attributeCapacity;
		this->attributeSize = other.attributeSize;

		this->allIdCapacity = other.allIdCapacity;
		this->allIdSize = other.allIdSize;
		
		this->allId = new Id[other.allIdCapacity];

		
		for (unsigned int i = 0; i < other.allIdSize; ++i)
		{
			this->allId[i] = other.allId [i] ;
		}
		
	}
	return *this;
}

Xml::Xml(const Xml& other)
{
	this->className = new char[strlen(other.className) + 1];
	strcpy(this->className, other.className);

	this->id = new char[strlen(other.id)+1];
	strcpy(this->id, other.id);

	this->childs = new Child[other.childCapacity];
	this->childCapacity = other.childCapacity;
	this->childSize = other.childSize;

	for (size_t i = 0; i < this->childSize; ++i)
	{
		this->childs[i] = other.childs[i];
	}

	this->attributes = new Attribute[other.attributeCapacity];

	for (unsigned int i = 0; i < other.attributeSize; ++i)
	{
		this->attributes[i] = other.attributes[i];
	}
	this->attributeCapacity = other.attributeCapacity;
	this->attributeSize = other.attributeSize;

	this->allIdCapacity = other.allIdCapacity;
	this->allIdSize = other.allIdSize;

	this->allId = new Id[other.allIdCapacity];


	for (unsigned int i = 0; i < other.allIdSize; ++i)
	{
		this->allId[i] = other.allId[i];
	}
	
}

void Xml::parseClass(const char* className)
{
	delete[] this->className;
	this->className = new char[strlen(className) + 1];
	strcpy(this->className, className);
}

void Xml::parseChild(const Child& child)
{
	if (this->childSize >= childCapacity) 
	{
		childResize();
	}
	this->childs[childSize] = child;
	++this->childSize;
}


void Xml::parseAttirubte(const char* key, const char* value)
{
	if (this->attributeCapacity == attributeSize) 
	{
		this->attributeResize();
	}

	this->attributes[attributeSize] = Attribute(key, value);
	++this->attributeSize;
}

void Xml::parseAttirubeToChild(const char* key, const char* value)
{
	this->childs[this->childSize].parseAttirubte(key, value);
}

bool Xml::isIdUnique(const char* id)
{
	for (size_t i = 0; i < this->allIdSize; i++)
	{
		if (strcmp(this->allId[i].getId(), id) == 0) 
		{
			return false;
		}
	}
	return true;
}

int Xml::count(const char* id)
{
	int count = 0;
	for (size_t i = 0; i < this->allIdSize; i++)
	{
		if (strcmp(id, allId[i].getId()) == 0) 
		{
			
			this->allId[i].setCount(allId[i].getCount() + 1);
			count = allId[i].getCount();
			break;
		}
	}
	
	return 0;
}

void Xml::parseId(const char* id)
{
	if (allIdSize == allIdCapacity) 
	{
		allIdResize();
	}
	Id currentId = Id(id, 0);
	this->allId[allIdSize] = currentId;
	++allIdSize;
	delete[] this->id;

	this->id = new char[strlen(id) + 1];
	strcpy(this->id, id);

}

void Xml::addId(const char* id)
{
	if (allIdSize == allIdCapacity)
	{
		allIdResize();
	}
	Id currentId = Id(id, 0);
	this->allId[allIdSize] = currentId;
	++allIdSize;
}

void Xml::print()
{
	std::cout << "Class Name " << this->className<<std::endl;

	for (size_t i = 0; i < this->childSize; i++)
	{
		this->childs[i].print();
		std::cout << std::endl;
	}

}

void Xml::selectKeyByGivenId(const char* id, const char* key)
{
	if (strcmp(id, this->id) == 0) 
	{
		bool isFound = false;
		for (size_t i = 0; i < this->attributeSize; i++)
		{
			if (strcmp(this->attributes[i].getKey(), key) == 0)
			{
				isFound = true;

				std::cout << "Value is :" << this->attributes[i].getValue() << std::endl;
				break;
			}


		}

		if (!isFound)
		{

			std::cout << "No suck key found" << std::endl;
		}
	}

	int index = this->getChildIndexByGivenId(id);

	if (index == -1) 
	{
		std::cout << "No such id exist" << std::endl;
		return;
	}
	this->childs[index].showAttributeValueByGivenKey(key);
	
}

void Xml::setValueByGivenIdAndKey(const char* id, const char* key, const char* value)
{
	if (strcmp(id, this->id) == 0)
	{
		bool isFound = false;
		for (size_t i = 0; i < this->attributeSize; i++)
		{
			if (strcmp(this->attributes[i].getKey(), key) == 0)
			{
				isFound = true;

				std::cout << "you change value from :" << this->attributes[i].getValue() << "to " <<value<<std::endl;
				this->attributes[i].setValue(value);
				break;
			}


		}

		if (!isFound)
		{

			std::cout << "No suck key found" << std::endl;
		}
	}
	
	int index = this->getChildIndexByGivenId(id);
	if (index == -1)
	{
		std::cout << "No such id exist" << std::endl;
		return;
	}
	this->childs[index].setAttributeValueByGivenKey(key, value);

}

void Xml::printAttributeByGivenKey(const char* id)
{
	if (strcmp(id, this->id) == 0) 
	{
		for (size_t i = 0; i < this->attributeSize; i++)
		{
			this->attributes[i].print();
		}
		return;
	}
	int index = this->getChildIndexByGivenId(id);
	if (index == -1)
	{
		std::cout << "No such id exist" << std::endl;
		return;
	}
	this->childs[index].printAttribute();
}

void Xml::showTextByGivenId(const char* id)
{
	if (strcmp(id, this->id) == 0) 
	{
		std::cout << "Text is " << this->className;
		return;
	}
	int index = this->getChildIndexByGivenId(id);
	if (index == -1)
	{
		std::cout << "No such id exist" << std::endl;
		return;
	}
	std::cout << "Text is ";
	this->childs[index].getName();
	std::cout<<std::endl;
}

void Xml::createChild(const char* id)
{
	char* name = new char[100];
	std::cout << "Enter name ";
	std::cin.getline(name, 99);
	
	char* className = new char[100];
	std::cout << "Enter class name ";
	std::cin.getline(className, 99);
	Child g = Child(name, className, id, this->childs[childSize-1].getSpaceCount() + 2);

	if (this->childCapacity == this->childSize) 
	{
		this->childResize();
	}
	this->childs[childSize] = g;
	this->childSize++;
	std::cout << "You added new child succesfully" << std::endl;
}
