#include "Engine.h"

char* Engine::removeFirstAndLastSimbol(const char* line)
{
	char* parsedLine = new char[strlen(line) - 1];
	for (size_t i = 1; i < strlen(line)-1; i++)
	{
		parsedLine[i - 1] = line[i];
	}
	parsedLine[strlen(line) - 2] = '\0';
	
	

	return parsedLine;
}

char* Engine::getArgument(const char* line,int space)
{
	

	char* argument = new char[strlen(line) +1];
	for (size_t i = space+1; i < strlen(line); i++)
	{
		char symbol = line[i];
		if (line[i] == '>') 
		{
			argument[i-space-1] = '\0';
			break;
		}
		if (line[i] == ' ') 
		{
			argument[i-space-1] = '\0';
			break;
		}
		
		argument[i -1-space] = line[i];
	}
	return argument;
}

char* Engine::getValue(const char* line)
{
	char* argument = new char[strlen(line) + 1];
	strcpy(argument, "");
	int startIndex = 0;
	int endIndex = 0;
	for (size_t i = 1; i < strlen(line); i++)
	{
		if (line[i] == '>') 
		{
			startIndex = i + 1;
		}
		if (line[i] == '<') 
		{
			endIndex = i;
			break;
		}
	}

	int g = 0;
	for (int i = startIndex; i < endIndex; i++)
	{
		argument[g] = line[i];
		g++;

	}
	argument[g] = '\0';
	return argument;
}

bool Engine::hasChild(const char* line,const char* argument)
{
	char* endArgument = new char[strlen(argument) + 4];
	strcpy(endArgument, "");
	strcat(endArgument, "<");
	strcat(endArgument,"/");
	strcat(endArgument, argument);
	strcat(endArgument, ">");

	

	int count = 1;
	for (int i = strlen(line)-1; i>=0; i--)
	{
		char symbol = line[i];

		if (count == strlen(endArgument)) 
		{
			break;
		}
		
		if (line[i] != endArgument[strlen(endArgument) - count]) 
		{
			delete[] endArgument;
			return true;
		}
		count++;
		

	}
	

	
	
	return false;
}

void Engine::parseClass(std::ifstream& ifs)
{
	char* line = new char[100];

	ifs.getline(line, 99);
	char* clasLine = removeFirstAndLastSimbol(line);

	char* splitetLine;
	char* id;
	splitetLine = strtok(clasLine, " ");
	xml.parseClass(splitetLine);

	while (splitetLine != NULL)
	{
		splitetLine = strtok(NULL, "=");
		char* key = strtok(NULL, "=");
		if (key != NULL) {
			key = removeFirstAndLastSimbol(key);
			if (strcmp(splitetLine, "id") == 0)
			{
				id = splitetLine;
				if (!xml.isIdUnique(splitetLine))
				{
					strcat(id, "_");
					char buffer[15];
					strcat(id, itoa(xml.count(id), buffer, 10));
					
				}
				xml.parseId(id);

			}
			else {

				xml.parseAttirubeToChild(splitetLine, key);
			}
			
		}
	}
	delete[] line;
}

int Engine::getWhiteSpace(const char* line)
{
	int count = 0;
	for (size_t i = 0; i < strlen(line); i++)
	{
		if (line[i] != ' ') 
		{
			break;

		};
		++count;
	}
	return count;
}

char* Engine::removeSpace( char* line)
{
	bool s = true;
	char* newLine = new char[strlen(line) + 1];
	int simbol = 0;
	for (size_t i = 0; i < strlen(line); i++)
	{
		if (s) {
			if (line[i] == ' ')
			{
				continue;
			}
		}
		if (line[i] != ' ') 
		{
			s = false;
		}

		newLine[simbol] = line[i];
		simbol++;
	}
	newLine[simbol] = '\0';
	delete[] line;
	return newLine;
}

bool Engine::hasEnd(char* line)
{
	int g = 0;
	for (size_t i = 0; i < strlen(line); i++)
	{
		if (line[i] == '>') 
		{
			g++;
		}
		if (g == 2) 
		{
			return true;
		}
	}

	return false;
}

char* Engine::getClassName(const char* line)
{
	int index = 0;
	char* className = new char[strlen(line) + 1];
	for (size_t i = 0; i < strlen(line); i++)
	{
		if (line[i] == ' ') 
		
		{
			continue;
		}
		if (line[i] == '<') 
		{
			continue;
		}
		if (line[i] == '>') 
		{
			break;
		}
		className[index] = line[i];
		index++;
	}
	className[index] = '\0';
	return className;
}

Engine::Engine() :xml()
{
	
}

void Engine::readFromFile(std::ifstream& ifs)
{
	parseClass(ifs);
	while (!ifs.eof())
	{
		char* line = new char[100];
		
		bool foundIdAttribute = false;

		ifs.getline(line, 99);
		int getSpaceCount = this->getWhiteSpace(line);
		if (getSpaceCount == 0) 
		{
			delete[] line;
			break;
		}

		char* getArgument = this->getArgument(line,getSpaceCount);
		//line = removeSpace(line);
		line = removeFirstAndLastSimbol(line);
		
		char* id=new char[1];
		strcpy(id, "");

		bool haschild = this->hasChild(line, getArgument);


		bool foundId = false;
		char* splitetLine;
		splitetLine = strtok(line, " ");

		Child c = Child(getArgument,"", id, getSpaceCount);
		while (splitetLine != NULL)
		{
			splitetLine = strtok(NULL, "=");
			char* key = strtok(NULL, " ");
			if (key != NULL) {
				key = removeFirstAndLastSimbol(key);

				if (strcmp(splitetLine, "id") == 0)
				{
					foundId = true;
					delete[] id;
					id = key;
					if (!xml.isIdUnique(splitetLine))
					{

						strcat(id, "_");
						char buffer[15];
						strcat(id, itoa(xml.count(id), buffer, 10));

						c.parseId(id);




					}
					else 
					{
						c.parseId(id);
					}


				}
				else {


					c.parseAttirubte(splitetLine, key);
				}
			}
			//splitetLine = strtok(NULL, " ");
		}

		if (!foundId)
		{
			delete[] id;
			id = new char[40];
			strcat(id, getArgument);
			strcat(id, "CustomId");
			while (true)
			{
				if (xml.isIdUnique(id))
				{
					break;
				}
				strcat(id, "I");
				c.parseId(id);
			}
		}
		
		xml.parseChild(c);
		

		if (haschild) 
		{
			char* endArgument = new char[strlen(getArgument) + 4];
			strcpy(endArgument, "");

			strcat(endArgument, "</");
			strcat(endArgument, getArgument);
			strcat(endArgument, ">");
			int n = 0;

			while (true)
			{
				delete[] line;
				line = new char[100];
				ifs.getline(line, 99);
				
				int getSpaceCountCurrent = this->getWhiteSpace(line);
				char* getArgumentCurrent = this->getArgument(line, getSpaceCountCurrent);
				char* className = this->getClassName(line);
				line = removeSpace(line);
				
				if (strcmp(endArgument, line) == 0) 
				{
					break;
				}

				if (hasEnd(line)) 
				{
					int n = 9;
					getArgumentCurrent = this->getValue(line);
				}
				
				
				
				line = removeFirstAndLastSimbol(line);
				char* idCurrent =new char[1];
				strcpy(id, "");
				
				bool foundId =false;
				char* splitetLineCurrent;
				splitetLineCurrent = strtok(line, " ");

				Child d = Child(getArgumentCurrent,className, idCurrent, getSpaceCountCurrent);
				while (splitetLineCurrent != NULL)
				{
					splitetLineCurrent = strtok(NULL, "=");
					char* keyCurrent = strtok(NULL, "=");
					if (keyCurrent != NULL) {
						keyCurrent = removeFirstAndLastSimbol(keyCurrent);

						if (strcmp(splitetLineCurrent, "id") == 0)
						{
							foundId = true;
							delete[] idCurrent;
							idCurrent = keyCurrent;
							if (!xml.isIdUnique(splitetLineCurrent))
							{

								strcat(idCurrent, "_");
								char buffer[15];
								strcat(idCurrent, itoa(xml.count(id), buffer, 10));

								d.parseId(idCurrent);
								

								

							}
							else
							{
								d.parseId(idCurrent);
							}

							
						}
						else {
							

							d.parseAttirubte(splitetLine, keyCurrent);
						}
					}
				}
				
				if(!foundId)
				{
					delete[] idCurrent;
					idCurrent = new char[40];
					strcpy(idCurrent, "");
						
					strcat(idCurrent, getArgumentCurrent);
					strcat(idCurrent, "CustomId");
					while (true)
					{
						if (xml.isIdUnique(idCurrent))
						{
							break;
						}
						strcat(idCurrent, "I");
					}
				}
				d.parseId(idCurrent);
				xml.parseChild(d);
			}
		}
		
		delete[] line;
		
	}
	
}

void Engine::print()
{
	xml.print();
}

void Engine::selectKeyByGivenId(const char* id, const char* key)
{
	xml.selectKeyByGivenId(id, key);
}

void Engine::setValueByGidenKey(const char* id, const char* key, const char* value)
{
	xml.setValueByGivenIdAndKey(id, key, value);
}

void Engine::printAttributeByGivenId(const char* key)
{
	xml.printAttributeByGivenKey(key);
}

void Engine::showTextByGivenId(const char* id)
{
	xml.showTextByGivenId(id);
}

void Engine::createChildByGivenId(const char* id)
{
	xml.createChild(id);
}

void Engine::showCommand()
{
	std::cout << "Open file: 1" << std::endl;
	std::cout << "Print: 2" << std::endl;
	std::cout << "Select <id> <key>: 3" << std::endl;
	std::cout << "Set <id> <key> <value>: 4" << std::endl;
	std::cout << "Children <id>: 5" << std::endl;
	std::cout << "Text <id>: 7" << std::endl;
	std::cout << "Newchild <id>: 9" << std::endl;
	std::cout << "Exit: 10" << std::endl;


}
