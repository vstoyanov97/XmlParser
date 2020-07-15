
#include <fstream>
#include "Engine.h"
#include <iostream>

int main()
{
	
	
	
	Engine engine=Engine();
	engine.showCommand();
	while (true)
	{
		int num;
		std::cin >> num;
		std::cin.clear();
		std::cin.ignore();

		if (num == 10) 
		{
			break;
		}
		if (num == 1) 
		{
			char* fileName = new char[100];
			std::cout << "Enter File name: ";
			std::cin.getline(fileName, 99);
			std::cin.clear();
			std::ifstream ifs(fileName, std::ios::in);
			engine.readFromFile(ifs);
			ifs.close();
			std::cout << "You parse xml succesfuly " << std::endl;

			delete[] fileName;
		}
		if (num == 2) 
		{
			engine.print();
		}
		if (num == 3) 
		{
			std::cout << "Enter id ";
			char* id = new char[100];
			std::cin.getline(id, 99);
			std::cin.clear();

			std::cout << "Enter key ";
			char* key = new char[100];
			std::cin.getline(key, 99);
			std::cin.clear();
			engine.selectKeyByGivenId(id,key);
			delete[] id;
			delete[] key;
		}
		if (num == 4) 
		{ 
			std::cout << "Enter id ";
			char* id = new char[100];
			std::cin.getline(id, 99);
			std::cin.clear();

			std::cout << "Enter key ";
			char* key = new char[100];
			std::cin.getline(key, 99);
			std::cin.clear();

			std::cout << "Enter value ";
			char* value = new char[100];
			std::cin.getline(value, 99);
			std::cin.clear();
			engine.setValueByGidenKey(id, key, value);
			delete[] id;
			delete[] key;
			delete[] value;
		}
		if (num == 5) 
		
		{
			std::cout << "Enter id";
			char* id = new char[100];
			std::cin.getline(id, 99);
			std::cin.clear();
			engine.printAttributeByGivenId(id);
			delete[] id;

		}
		if (num == 7) 
		{
			std::cout << "Enter id";
			char* id = new char[100];
			std::cin.getline(id, 99);
			std::cin.clear();
			engine.showTextByGivenId(id);
			delete[] id;
		}
		if (num == 9) 
		{
			std::cout << "Enter id";
			char* id = new char[100];
			std::cin.getline(id, 99);
			std::cin.clear();
			engine.createChildByGivenId(id);
			delete[] id;
		}
	}
	
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
