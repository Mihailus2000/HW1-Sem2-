#include "BaseDepartment.h"
//#include "Subdepartment and Organization.h"
#include "IndustryDepartment.h"

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>
#include <unordered_map>
#include <iterator>
#include <conio.h>
#include <Windows.h>

////------------------------------------------------------------------------------
//int X, Y;
//
//void gotoXY(short x, short y)
//{
//	HANDLE    StdOut = GetStdHandle(STD_OUTPUT_HANDLE);
//	COORD    coord = { x, y };
//	SetConsoleCursorPosition(StdOut, coord);
//}
//void whereXY(int &X, int &Y)
//{
//	HANDLE                        StdOut = GetStdHandle(STD_OUTPUT_HANDLE);
//	CONSOLE_SCREEN_BUFFER_INFO    csbi;
//	GetConsoleScreenBufferInfo(StdOut, &csbi);
//	X = csbi.dwCursorPosition.X;
//	
//	HANDLE                        StdOut = GetStdHandle(STD_OUTPUT_HANDLE);
//	CONSOLE_SCREEN_BUFFER_INFO    csbi;
//	GetConsoleScreenBufferInfo(StdOut, &csbi);
//	Y = csbi.dwCursorPosition.Y;
//}
////------------------------------------------------------------------------------
class BD {
	int numOfBaseD, numOfIndD;
	std::vector<Department*> Container;
	std::string NAME;
	std::string PATH = "";
	bool Same_typed;
public:
	BD(std::string name, bool Same_Typed) : NAME(name), Same_typed(Same_Typed) {}

	void setDepartment(Department* D_t) {
		Container.push_back(D_t);
	}


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
	}

};

	//std::vector<BD*> BaseData;
	std::unordered_map<std::string, BD*> BaseData; // ХРАНИЛИЩЕ ВСЕХ БД

	

	int main() {
		
		std::cout << "Welcome to Mihail's Base Date of University!\n"; 
		bool ENDPROGRAMM = false;
		std::string command;
		std::cout << "Enter \'Help\' to see all available commands OR enter command:\n";
		while (!ENDPROGRAMM) {
			std::cout << "<"; std::getline(std::cin, command); gotoXY(X, Y); std::cout << ">\n";
			std::transform(command.begin(), command.end(), command.begin(), tolower);
			ENDPROGRAMM = Commands(command);
		}
		return 0;
	}
