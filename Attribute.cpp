#include "Attribute.h"

Attribute::Attribute()
{
	this->value = new char[1];
	this->key = new char[1];
	strcpy(value, "");
	strcpy(key, "");
}

Attribute::Attribute(const char* key, const char* value)
{
	this->key = new char[strlen(key) + 1];
	strcpy(this->key, key);
	this->value = new char[strlen(value) + 1];
	strcpy(this->value, value);
}

Attribute::~Attribute()
{
	delete[] key;
	delete[] value;
}

Attribute::Attribute(const Attribute& other)
{
	this->value = new char[strlen(other.value) + 1];
	strcpy(this->value, other.value);

	this->key = new char[strlen(other.key) + 1];
	strcpy(this->key, other.key);

}

Attribute& Attribute::operator=(const Attribute& other)
{
	if (this != &other) 
	{
		delete[] this->value;
		delete[] this->key;

		this->value = new char[strlen(other.value) + 1];
		strcpy(this->value, other.value);
		this->key = new char[strlen(other.key) + 1];
		strcpy(this->key, other.key);
	}
	return *this;
}

void Attribute::print()
{
	std::cout << " " << key;
	std::cout << " :" <<value<<" ";
}

const char* Attribute::getKey() const
{
	return this->key;
}

const char* Attribute::getValue() const
{
	return this->value;
}

void Attribute::setValue(const char* value)
{
	delete[] this->value;
	this->value = new char[strlen(value) + 1];
	strcpy(this->value, value);
}
