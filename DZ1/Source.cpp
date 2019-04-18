#include "BaseDepartment.h"
//#include "Subdepartment and Organization.h"
#include "IndustryDepartment.h"
//#include "Commands.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>
#include <unordered_map>
#include <iterator>
#include <Windows.h>


//------------------------------------------------------------------------------
int X, Y;

void gotoXY(short x, short y)
{
	HANDLE    StdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD    coord = { x, y };
	SetConsoleCursorPosition(StdOut, coord);
}
void whereXY(int &X, int &Y)
{
	HANDLE                        StdOut1 = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO    csbi1;
	GetConsoleScreenBufferInfo(StdOut1, &csbi1);
	X = csbi1.dwCursorPosition.X;
	
	HANDLE                        StdOut2 = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO    csbi2;
	GetConsoleScreenBufferInfo(StdOut2, &csbi2);
	Y = csbi2.dwCursorPosition.Y;
}
//-----------------------------------------------------------------------------


//void Parser(int NumOfValues, std::string value1, std::string value2, std::string value3, std::string CMDin, std::string CMDout) {
//	if (CMDin == "") {
//		//exception
//	}
//	std::string tmp;
//	for (int i = 0; i < CMDin.size(); i++) {
//
//	}
//
//}

class BD {
	int numOfD;
	std::vector<Department*> Container;
	std::string NAME;
	std::string PATH = "";
	bool Same_typed;
public:
	BD(std::string name, bool Same_Typed) : NAME(name), Same_typed(Same_Typed) {}
	void setDepartment(Department* D_t) {
		Container.push_back(D_t);
	}
	int getNumOfD() { return numOfD; }
	Department* getDepartment(int index) { return Container[index]; }
	void WriteToFile() {
			std::ofstream fout;
		fout.open(PATH, std::ios_base::app);
		fout << "{";										// Начало (1)	
		for (int ind = 0; ind < Container.size(); ind++) {
	
			Department* Elem_Department = Container[ind];
	
			fout << "{" << Elem_Department->getNameOfDep() << ":{" << Elem_Department->getSaEC() << "},{"; //Начало (2),(3)
			for (int i = 0; i < Elem_Department->getNumOfSub(); i++) {
				InIt* ElemInfoOfParts = Elem_Department->getInfo();
				Subdepartment SubDepElm = ElemInfoOfParts->getVecSubDep(i);
	
				fout << SubDepElm.getNameOfSubdep() << ":{"; //Начало (4)
	
				for (int j = 0; j < SubDepElm.getNumOfDisciplines(); j++) {
					Discipline DiscElem = SubDepElm.getVecDisc(j);
					fout << DiscElem.name << ":<" <<
						DiscElem.numberOfTeachers << ">";
					if (j != /*j <*/ SubDepElm.getNumOfDisciplines() - 1) //????
						fout << ";";
					else
						fout << "}";						// Конец (4)
				}
				if (i != Elem_Department->getNumOfSub() - 1) //?????
					fout << "/";
				else
					fout << "}";							// Конец (3)					
			}
	
			if (Elem_Department->getClass() == "IND") {
				fout << ",{";								// Начало (3)
				for (int i = 0; i < Elem_Department->getNumOfOrganizations(); i++) {
					InIt* ElemInfoOfParts = Elem_Department->getInfo();
					Organization SubDepElm = ElemInfoOfParts->getVecOrganizations(i);
	
					fout << SubDepElm.getNameOfOrganization() << ":{";		// Начало (4)
	
					for (int j = 0; j < SubDepElm.getNumOfDisciplines(); j++) {
						Discipline DiscElem = SubDepElm.getVecDisc(j);
						fout << DiscElem.name << ":<" <<
							DiscElem.numberOfTeachers << ">";
						if (j != /*j <*/ SubDepElm.getNumOfDisciplines() - 1) //????
							fout << ";";
						else
							fout << "}";									// Конец (4)
					}
					if (i != Elem_Department->getNumOfSub() - 1) //?????
						fout << "/";
					else
						fout << "}";						// Конец (3)
				}
			}
	
			if (ind == Container.size() - 1)
				fout << "}";																				// Конец (2)
			else
				fout << "&";
		}
		fout << "}";								// Конец (1)
	};

};
	//std::vector<BD*> BaseData;
	
std::unordered_map<std::string, BD*> BaseData; // ХРАНИЛИЩЕ ВСЕХ БД
	
bool Commands(std::string CMD) {
	int comand;
	std::string nameOfBD, typeOfD, nameOfDepart;
	std::unordered_map <std::string, BD*> ::iterator it;
	BD* Obj = nullptr;   //??????????????????
	std::map<std::string, int> MapOfCMD = {
		{"help",0},{"create",1}, {"calc", 2},{"find",3},{"add",4},{"remove",5},{"sort",6},{"pick",7},{"output",8},{"list",9} };
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

		std::cout << "Give name to new BD: <"; whereXY(X, Y);
		std::getline(std::cin, nameOfBD);
		gotoXY(X, Y); std::cout << ">\n";
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
		std::cout << "Enter NAME of DataBase: <"; whereXY(X, Y); std::getline(std::cin, nameOfBD); gotoXY(X, Y); std::cout << ">\n";
		auto It = BaseData.find(nameOfBD);
		if (It != BaseData.end()) {
		Obj	= It->second;
		}
		else {
			//exception
		}
		for (int i = 0; i < Obj->getNumOfD(); i++) {
			Department* ElDep = Obj->getDepartment(i);
			ElDep->calcNumOfSubjects();
			
		}
	}
	if (ind->second == 3) {
		std::cout << "Enter NAME of DataBase: <"; whereXY(X, Y); std::getline(std::cin, nameOfBD); gotoXY(X, Y); std::cout << ">\n";
		std::cout << "Enter NAME of Department: <"; whereXY(X, Y); std::getline(std::cin, nameOfDepart); gotoXY(X, Y); std::cout << ">\n";
		auto It = BaseData.find(nameOfBD);
		if (It != BaseData.end()) {
			Obj = It->second;
		}
		else {
			//exception
		}
		bool findDep = false;
		Department* tmp;
		for (int i = 0; i < Obj->getNumOfD(); i++) {
			Department* ElDep = Obj->getDepartment(i);
			if (ElDep->getNameOfDep() == nameOfDepart) {
				findDep = true;
				tmp = ElDep;
			}
		}
		if (findDep)
		{
			tmp->getInfo();
		}
	}

	if (ind->second == 4) {
		std::cout << "Enter name of BD where add new element: ";
		std::cout << "<";
		std::getline(std::cin, nameOfBD);
		std::cout << ">\n";
		if (BaseData.find(nameOfBD) != BaseData.end()) {
			it = BaseData.find(nameOfBD);
		}
		std::cout << "Enter type of Department: <b> to base department or <i> to industry department:\n";
		std::cout << "<";
		std::getline(std::cin, typeOfD);
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

	int main() {
		std::string CMD,v1, v2, v3;
		int numOfValues;
		std::cout << "Welcome to Mihail's Base Date of University!\n"; 
		bool ENDPROGRAMM = false;
		std::string command;
		std::cout << "Enter \'>> help()\' to see all available commands OR enter command:\n";
		while (!ENDPROGRAMM) {
			std::cout << ">> "; std::getline(std::cin, command);
			std::transform(command.begin(), command.end(), command.begin(), tolower);			
			ENDPROGRAMM = Commands(command);
		}
		return 0;
	}
