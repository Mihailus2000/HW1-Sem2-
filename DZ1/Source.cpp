#include "BaseDepartment.h"
#include "IndustryDepartment.h"

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>
#include <unordered_map>
#include <iterator>

class BD {
	int numOfBaseD, numOfIndD;
	std::vector<Department*> Container;
	std::string NAME;
	bool Same_typed;
public:
	BD(std::string name, bool Same_Typed) : NAME(name),Same_typed(Same_Typed) {}

	void setDepartment(Department* D_t) {
		Container.push_back(D_t);
	}

};
//std::vector<BD*> BaseData;
std::unordered_map<std::string, BD*> BaseData; // ’–¿Õ»À»Ÿ≈ ¬—≈’ ¡ƒ

bool Commands(std::string CMD) {
	int comand;
	std::string nameOfBD, typeOfD;
	std::unordered_map <std::string, BD*> :: iterator it;

	std::map<std::string, int> MapOfCMD = {
		{"help",0},{"create s_t bd",1},{"create h_t bd",2}, {"add s_t", 3}, {"add h_t", 4} };
	auto ind = MapOfCMD.find(CMD);
	
	if (ind->second == 1) {
		
		std::cout << "Give name to new BD: <";
		std::getline(std::cin, nameOfBD);
		BaseData.insert(std::make_pair(nameOfBD, new BD(nameOfBD, true)));
		return false;
	}
	
	if(ind->second == 2) {
		std::cout << "Give name to new BD: <";
		std::getline(std::cin, nameOfBD);
		BaseData.insert(std::make_pair(nameOfBD, new BD(nameOfBD, false)));
		return false;
	}
	
	if (ind->second == 3) {
		std::cout << "Enter name of BD where add new element:/n";
		std::cout << "<"; std::getline(std::cin, nameOfBD); std::cout << ">\n";
		if (BaseData.find(nameOfBD) != BaseData.end()) {
			it = BaseData.find(nameOfBD);
		}
		std::cout << "Enter type of Department: <b> to base department or <i> to industry department:\n";
		std::cout << "<"; std::getline(std::cin, typeOfD); std::cout << ">\n";
		if (typeOfD == "b" || typeOfD == "i")
			if (typeOfD == "b") {
				it->second->setDepartment(new BaseDepartment(nameOfBD));
			}
			else {
				it->second->setDepartment(new IndustryDepartment(nameOfBD));
			}
		//it->second->setDepartment()
	}

	if (ind == MapOfCMD.end()) {
		std::cout << "Unknown command\n";
		return false;
	}
	return false;
}

int main() {
	

	std::cout << "Welcome to Mihail's Base Date of University!\n";
	bool ENDPROGRAMM = false;
	std::string command;
	std::cout << "Enter \'Help\' to see all available commands OR enter command:\n";
	while (!ENDPROGRAMM) {
		std::cout << "<"; std::getline(std::cin, command); std::cout << ">\n";
		std::transform(command.begin(), command.end(), command.begin(), tolower);
		ENDPROGRAMM = Commands(command);
	}
	return 0;
}