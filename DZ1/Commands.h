#pragma once
#include <iostream>
#include <unordered_map>
#include <string>
#include <map>


bool Commands(std::string CMD) {
	int comand;
	std::string nameOfBD, typeOfD;
	std::unordered_map <std::string, BD*> ::iterator it;

	std::map<std::string, int> MapOfCMD = {
		{"help",0},{"create",1}, {"add", 2} };
	auto ind = MapOfCMD.find(CMD);
	if (ind->second == 0) {
		std::cout << "\t*************************************************************HELP*************************************************************\n";
		std::cout << "\t >> help()											|| Display all available commands\n";
		std::cout << "\t >> create(NAME)									|| Create new DB with name = NAME\n";
		std::cout << "\t >> calc(DB NAME,DEPARTMENT NAME/ORGANIZATION NAME)	|| Calculate number of disciplines\n";
		std::cout << "\t >> find(DB NAME,DEPARTMENT NAME)					|| Search Department by NAME (and output)\n";
		std::cout << "\t >> add(DB NAME)									|| Add new Department in DB \n";
		std::cout << "\t >> remove(DB NAME,DEPARTMENT NAME)					|| Remove Department from DB ";
		std::cout << "\t >> sort(DB NAME,<name>/<num>)						|| Sort records by name -> add <name> !WITHOUT corner scopes!\n";
		std::cout << "\t													|| Sort records by number of Subdepartments ->\n";
		std::cout << "\t													|| -> add <num> !WITHOUT corner scopes!\n";
		std::cout << "\t >>pick(DB NAME,<name>/<num>,<...>)					|| Pick new DB from records of DB \"DB NAME\".\n";
		std::cout << "\t													|| If by name of discipline -> add <name> !WITHOUT corner scopes!\n";
		std::cout << "\t													|| If by number of Subdepartments -> add <num> !WITHOUT corner scopes!\n";
		std::cout << "\t													|| And instead of <...>, write name or number accordingly to the command\n";
		std::cout << "\t >>output(DB NAME)									|| Display content of DB\n";
		std::cout << "\t >>list()											|| Diplay all Data bases\n";
		std::cout << "\t******************************************************************************************************************************\n";

	}

	if (ind->second == 1) {

		std::cout << "Give name to new BD: <";
		std::getline(std::cin, nameOfBD);
		std::cout << ">\n";
		BaseData.insert(std::make_pair(nameOfBD, new BD(nameOfBD, true)));
		std::ofstream file;

		file.open(nameOfBD + ".txt", std::ios_base::app);
		if (file.is_open())
			std::cout << "App: OK\n";
		file.close();
		return false;
	}

	/*if (ind->second == 2) {
		std::cout << "Give name to new BD: <";
		std::getline(std::cin, nameOfBD);
		BaseData.insert(std::make_pair(nameOfBD, new BD(nameOfBD, false)));
		return false;
	}*/

	if (ind->second == 2) {
		std::cout << "Enter name of BD where add new element: ";
		std::cout << "<"; whereXY(X, Y); std::getline(std::cin, nameOfBD);
		gotoXY(X, Y);
		std::cout << ">\n";
		if (BaseData.find(nameOfBD) != BaseData.end()) {
			it = BaseData.find(nameOfBD);
		}
		std::cout << "Enter type of Department: <b> to base department or <i> to industry department:\n";
		std::cout << "<"; whereXY(X, Y); std::getline(std::cin, typeOfD);
		gotoXY(X, Y);
		std::cout << ">\n";

		if (typeOfD == "b" || typeOfD == "i") {
			if (typeOfD == "b") {
				it->second->setDepartment(new BaseDepartment(nameOfBD));
			}
			else {
				it->second->setDepartment(new IndustryDepartment(nameOfBD));
			}
		}
		//it->second->setDepartment()
	}

	if (ind == MapOfCMD.end()) {
		std::cout << "Unknown command\n";
		return false;
	}
	return false;
}