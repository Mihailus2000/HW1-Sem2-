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
#include "Exceptions.h"
#include <sstream>
#include <experimental/filesystem>


namespace fs = std::experimental::filesystem;

//------------------------------------------------------------------------------
//int X, Y;
//
//void gotoXY(short x, short y)
//{
//  HANDLE    StdOut = GetStdHandle(STD_OUTPUT_HANDLE);
//  COORD    coord = { x, y };
//  SetConsoleCursorPosition(StdOut, coord);
//}
//void whereXY(int& X, int& Y)
//{
//  HANDLE                        StdOut1 = GetStdHandle(STD_OUTPUT_HANDLE);
//  CONSOLE_SCREEN_BUFFER_INFO    csbi1;
//  GetConsoleScreenBufferInfo(StdOut1, &csbi1);
//  X = csbi1.dwCursorPosition.X;
//
//  HANDLE                        StdOut2 = GetStdHandle(STD_OUTPUT_HANDLE);
//  CONSOLE_SCREEN_BUFFER_INFO    csbi2;
//  GetConsoleScreenBufferInfo(StdOut2, &csbi2);
//  Y = csbi2.dwCursorPosition.Y;
//}
//-----------------------------------------------------------------------------


//void Parser(int NumOfValues, std::string value1, std::string value2, std::string value3, std::string CMDin, std::string CMDout) {
//  if (CMDin == "") {
//      //exception
//  }
//  std::string tmp;
//  for (int i = 0; i < CMDin.size(); i++) {
//
//  }
//
//}

class BD {
	int numOfD = 0;
	std::vector<Department*> Container;
	std::string NAME;
public:
	BD(std::string name) : NAME(name) {
	}
	std::string getName() { return NAME; }
	void removeDepartment(std::string name) {
		bool IfFind = false;
		int index = 0;
		for (const auto i : Container) {
			
			if (i->getNameOfDep() == name) {
				IfFind = true;
				Container.erase(Container.begin() + index);
				std::vector<Department*>(Container).swap(Container);
				break;
			}
			index++;
		}
		if (IfFind) {
			std::cout << "\tDepartment successfuly removed.\n";
			numOfD--;
			WriteToFile();
		}
		else
			throw "Error: Department \'" + name + "\' not found!";
	}
	void addElOfContainer(Department* el) {
		Container.push_back(el);
		numOfD++;
	}
	void sortByAlfabet() {
		std::vector<std::pair<std::string, int>> TmpVector;
		int j = 0;
		for (auto i : Container) {
			TmpVector.emplace_back(std::make_pair(i->getNameOfDep(), j));
			j++;
		}
		std::sort(TmpVector.begin(), TmpVector.end());
		std::vector<Department*> TmpContainer;
		for (int i = 0; i < Container.size(); i++) {
			TmpContainer.emplace_back(Container.at(TmpVector[i].second));
		}
		Container = TmpContainer;
		WriteToFile();
	}
	void calcNumOfDisciplines() {
		std::cout << "\tList of disciplines in departments: \n";
		for (auto i : Container) {
			std::cout << i->getNameOfDep() << " : " << i->calcNumOfSubjects() << std::endl;
		}
		std::cout << std::endl;
	}
	void sortByCountOfSubdep() {
		std::vector<std::pair<int, int>> TmpVector;
		int j = 0;
		for (auto i : Container) {
			TmpVector.emplace_back(std::make_pair(i->getNumOfSub(), j));
			j++;
		}
		std::sort(TmpVector.begin(), TmpVector.end());
		std::vector<Department*> TmpContainer;
		for (int i = 0; i < Container.size(); i++) {
			TmpContainer.emplace_back(Container.at(TmpVector[i].second));
		}
		Container = TmpContainer;
		WriteToFile();
	}
	void setDepartment(Department* D_t) {
		Container.push_back(D_t);
		numOfD++;
		WriteToFile();
	}
	int getNumOfD() { return numOfD; }

	Department* getDepartment(int index) { return Container[index]; }
	void WriteToFile() {
		std::ofstream fout;
		fout.open(NAME, std::ios_base::out);
		fout << Container.size() << std::endl;
		for (int ind = 0; ind < Container.size(); ind++) {
			Department* Elem_Department = Container[ind];
			fout << Elem_Department->getNameOfDep() << "|" << Elem_Department->getSaEC() << "|" << Elem_Department->getClass() << "|" << Elem_Department->getNumOfSub() << "\\" ;

			for (int i = 0; i < Elem_Department->getNumOfSub(); i++) {
				InIt* ElemInfoOfParts = Elem_Department->getInfo();
				Subdepartment SubDepElm = ElemInfoOfParts->getVecSubDep(i);
				fout << SubDepElm.getNameOfSubdep() << "|" << SubDepElm.getNumOfDisciplines() << "|";

				for (int j = 0; j < SubDepElm.getNumOfDisciplines(); j++) {
					Discipline DiscElem = SubDepElm.getVecDisc(j);
					fout << DiscElem.getName() << "/" << DiscElem.getNumOfTeachers();
					if (j == SubDepElm.getNumOfDisciplines() - 1) 
						fout << "\\";
					else
						fout << "|";                     
				}
				//if (i != Elem_Department->getNumOfSub() - 1) //?????
				//	fout << "/";
				//else
				//	fout << "}";                                      
			}
			if (Elem_Department->getClass() == "IND") {
				fout << ";" << Elem_Department->getNumOfOrganizations() << "\\"; 
				
				for (int i = 0; i < Elem_Department->getNumOfOrganizations(); i++) {
					InIt* ElemInfoOfParts = Elem_Department->getInfo();
					Organization SubDepElm = ElemInfoOfParts->getVecOrganizations(i);
					fout << SubDepElm.getNameOfOrganization() << "|" << SubDepElm.getNumOfDisciplines() << "|";    

					for (int j = 0; j < SubDepElm.getNumOfDisciplines(); j++) {
						Discipline DiscElem = SubDepElm.getVecDisc(j);
						fout << DiscElem.getName() << "/" << DiscElem.getNumOfTeachers();
						if (j == SubDepElm.getNumOfDisciplines() - 1) 
							fout << "\\";
						else
							fout << "|";                                 
					}
					//if (i != Elem_Department->getNumOfSub() - 1) //?????
					//	fout << "/";
					//else
					//	fout << "}";                     
				}
			}
			if (ind == Container.size() - 1)
				fout.close();                                                            
			else
				fout << std::endl;
		}


	};

	void ReadFromFile() {
		char symbol;
		std::ifstream fin(NAME);
		Department* resEl = nullptr;
		Discipline* elDisc;
		std::vector<Discipline*>* vecDisc;
		std::vector<Subdepartment*>* vecSubd;
		std::vector<Organization*>* vecOrgan;
		Subdepartment* elSub;
		Organization* elOrg;
		InIt* InfoEl;

		std::string DepName = "", SubDepName="", DiscName = "", cntTeach = "", OrganizName = "", NYK="", Type="";
		int numOfDep = 0, numOfSubdep = 0, numOfOrg = 0, numOfDisc = 0, numOfTeachers = 0;
		std::string tmp, infoStr = "";
		std::getline(fin, tmp, '\n');
		numOfDep = atoi(tmp.c_str());
		numOfD = numOfDep;
		for(int i = 0; i < numOfDep;i++){
			InfoEl = new InIt;
			vecSubd = new std::vector<Subdepartment*>;
			vecOrgan = new std::vector<Organization*>;
			

			std::getline(fin, infoStr, '\n');
			DepName=infoStr.substr(0, infoStr.find("|"));
			infoStr.erase(0, infoStr.find("|")+1);
			NYK = infoStr.substr(0, infoStr.find("|"));
			infoStr.erase(0, infoStr.find("|") + 1);
			Type = infoStr.substr(0, infoStr.find("|"));
			infoStr.erase(0, infoStr.find("|") + 1);
			if (Type == "BASE") {
				resEl = new BaseDepartment();
			}
			if (Type == "IND") {
				resEl = new IndustryDepartment();
			}
			resEl->setNameDep(DepName);
			resEl->setSaEC(NYK);

			numOfSubdep = atoi(infoStr.substr(0, infoStr.find("\\")).c_str());
			resEl->setnumOfSub(numOfSubdep);
			
			infoStr.erase(0, infoStr.find("\\") + 1);
			
			for (int j = 0; j < numOfSubdep; j++) {

				SubDepName = infoStr.substr(0, infoStr.find("|"));
				
				
				infoStr.erase(0, infoStr.find("|") + 1);

				numOfDisc = atoi(infoStr.substr(0, infoStr.find("|")).c_str());
				infoStr.erase(0, infoStr.find("|") + 1);
				elSub = new Subdepartment(SubDepName, numOfDisc);
				
				vecDisc = new std::vector<Discipline*>;

				for (int k = 0; k < numOfDisc; k++) {
					DiscName = infoStr.substr(0, infoStr.find("/"));
					infoStr.erase(0, infoStr.find("/") + 1);

					
					if (k == numOfDisc - 1) {
						numOfTeachers = atoi(infoStr.substr(0, infoStr.find("\\")).c_str());
						infoStr.erase(0, infoStr.find("\\") + 1);
					}
					else {
						numOfTeachers = atoi(infoStr.substr(0, infoStr.find("|")).c_str());
						infoStr.erase(0, infoStr.find("|") + 1);
					}
					elDisc = new Discipline(DiscName, numOfTeachers);
					vecDisc->emplace_back(elDisc);

				}
				elSub->setVecDisc(*vecDisc);
				vecSubd->emplace_back(elSub);

			}
			if (Type == "IND"){
				infoStr.erase(0, infoStr.find(";") + 1);
				numOfOrg = atoi(infoStr.substr(0, infoStr.find("\\")).c_str());
				infoStr.erase(0, infoStr.find("\\") + 1);
				resEl->setnumOfOrgan(numOfOrg);
				for (int j = 0; j < numOfOrg; j++) {

					OrganizName = infoStr.substr(0, infoStr.find("|"));
					

					infoStr.erase(0, infoStr.find("|") + 1);

					numOfDisc = atoi(infoStr.substr(0, infoStr.find("|")).c_str());
					infoStr.erase(0, infoStr.find("|") + 1);
					elOrg = new Organization(OrganizName, numOfDisc);

					vecDisc = new std::vector<Discipline*>;

					for (int k = 0; k < numOfDisc; k++) {
						DiscName = infoStr.substr(0, infoStr.find("/"));
						infoStr.erase(0, infoStr.find("/") + 1);

						if (k == numOfDisc - 1) {
							numOfTeachers = atoi(infoStr.substr(0, infoStr.find("\\")).c_str());
							infoStr.erase(0, infoStr.find("\\") + 1);
						}
						else {
							numOfTeachers = atoi(infoStr.substr(0, infoStr.find("|")).c_str());
							infoStr.erase(0, infoStr.find("|") + 1);
						}
						elDisc = new Discipline(DiscName, numOfTeachers);
						elDisc->setNumTeach(numOfTeachers);
						vecDisc->emplace_back(elDisc);

					}
					elOrg->setVecDisc(*vecDisc);
					vecOrgan->emplace_back(elOrg);

				}

			}

			InfoEl->setVecSbDp(*vecSubd);
			InfoEl->setVecOrgan(*vecOrgan);
			resEl->setSub(InfoEl);
			Container.emplace_back(resEl);
		}
		
	}
};
//std::vector<BD*> BaseData;

std::unordered_map<std::string, BD*> BaseData; // ХРАНИЛИЩЕ ВСЕХ БД

std::vector<std::string> parser(const std::string CMDFrUser) {
	std::string command = "", tmp;
	bool fl1 = true;
	int cntObr = 0, cntCbr = 0, posObr = -1, posCbr = -1;
	std::vector<std::string> parameters;

	for (int i = 0; i < CMDFrUser.length(); i++)
	{
		if (CMDFrUser[i] == '(') {
			if (cntObr == 0) {
				cntObr++;
				posObr = i;
			}
			else {
				throw "Inalid syntax of command!";
			}

		}
		if (CMDFrUser[i] == ')') {
			if (cntCbr == 0) {
				cntCbr++;
				posCbr = i;
			}
			else {
				throw "Inalid syntax of command!";
			}
		}
	}
	if (cntObr == 0) {
		if (cntCbr == 0) {
			parameters.emplace_back(CMDFrUser);
			return parameters;
		}
		else {
			throw "Inalid syntax of command!";
		}
	}
	else {
		if (cntCbr != 1)
			throw "Inalid syntax of command!";
	}

	if (posObr > posCbr)
		throw "Inalid syntax of command!";

	if (posObr == 0 || posCbr != CMDFrUser.length() - 1)
		throw "Inalid syntax of command!";
	int i = 0;
	while (CMDFrUser[i] != '(') {
		command += CMDFrUser[i];
		++i;
	}
	std::transform(command.begin(), command.end(), command.begin(), tolower);

	parameters.emplace_back(command);

	auto subStr = CMDFrUser.substr(posObr + 1, posCbr - posObr - 1);
	bool isEmpty = true;
	for (int j = 0; j < subStr.length(); j++) {
		if (subStr[j] != ' ' && subStr[j] != '  ') {
			isEmpty = false;
			break;
		}
	}
	if (isEmpty) {
		return parameters;
	}

	std::string param;
	std::stringstream ss(subStr);
	while (std::getline(ss, param, ',')) {
		parameters.emplace_back(param);
	}
	return parameters;
}

void addBDFromFiles() {
	std::vector<std::string> strList;
	
		std::string path = "C:\\Users\\Mic-PC\\Documents\\MGTU IM BAUMANA\\Алгоритмические языки\\2-ой семестр\\ДЗ\\1.1\\DZ1\\DZ1";
		for (const auto& entry : fs::directory_iterator(path)) {
			if (entry.path().extension() == ".txt") {
				std::cout << entry.path().filename() << std::endl;
				strList.emplace_back(entry.path().filename().generic_string());
			}
		}
		
		for (int i = 0; i < strList.size(); ++i) {
			std::string FileName = strList[i];
			BaseData.insert(std::make_pair(FileName, new BD(FileName)));
			// копирование информации из файла в объект
			BaseData.find(FileName)->second->ReadFromFile();

		}

	
}

bool Commands(std::vector<std::string> CMD) {
	int comand;
	std::string nameOfBD, typeOfD, nameOfDepart;
	std::unordered_map <std::string, BD*> ::iterator it, newIt;
	BD* Obj = nullptr;
	BD* newObj = nullptr;   //??????????????????
	std::map<std::string, int> MapOfCMD = {
		{"help",0},{"create",1}, {"calc", 2},{"find",3},{"add",4},{"remove",5},{"sort",6},{"pick",7},{"output",8},{"list",9},{"exit",10},{"delete",11} };
	auto ind = MapOfCMD.find(CMD[0]);
	if (ind == MapOfCMD.end()) {
		std::cout << "Unknown command\n";
		return false;
	}
	if (ind->second == 0) {

		if (CMD.size() != 1) {
			std::cout << "| Warning : Extra parameters founded |\n\n"; // Добавить желтую подсветку
		}
		std::cout << "\t********************************************************HELP*******************************************************\n";
		std::cout << "\t >> help                              || Display all available commands\n";
		std::cout << "\t >> create(BD_NAME)                   || Create new DB with name = NAME\n";
		std::cout << "\t >> calc(BD_NAME)                     || Calculate number of disciplines\n";
		std::cout << "\t >> find(BD_NAME,DEP_NAME)            || Search Department by DEP_NAME in BD_NAME (and output)\n";
		std::cout << "\t >> add(BD_NAME,DEP_NAME, DEP_T)      || Add new Department DEP_NAME with type: DEP_T = i(industrial) / b(base) in DB_NAME \n";
		std::cout << "\t >> remove(BD_NAME,DEP_NAME)          || Remove Department from DB\n";
		std::cout << "\t >> sort(BD_NAME,MODE)	              || Sort records by name or number. If you choose name, MODE = num, else MODE = name\n";
		std::cout << "\t >> pick(BD_NAME,BD_NEW,MODE,PARAM)   || Pick new DB from records of DB_NAME and create new BD BD_NEW by MODE:\n";
		std::cout << "\t                                      || If by number of subdepartments(bigger then PARAM) -> MODE = num, if by name of discipline(PARAM) -> MODE = disc\n";
		std::cout << "\t >> output(BD_NAME)                   || Display content of DB_NAME \n";
		std::cout << "\t >> list                              || Display all Data bases\n";
		std::cout << "\t >> exit                              || Close program\n";
		std::cout << "\t >> delete(BD_NAME)                   || Delete BD_NAME\n";
		std::cout << "\t********************************************************************************************************************\n";
		return false;
	}

	if (ind->second == 1) {
		if (CMD.size() != 2)
			throw "Error: Invalid parameters\n\t >> create(BD_NAME)                   || Create new DB with name = NAME\n";

		/*std::cout << "Give name to new BD: ";
		std::getline(std::cin, nameOfBD);*/
		nameOfBD = CMD[1];
		std::string tmpname = nameOfBD + ".txt";
		if (BaseData.find(tmpname) != BaseData.end()) {
			throw "| Warning : File \'" + nameOfBD + "\' already EXISTS!\n\n";
		}
		BaseData.insert(std::make_pair(nameOfBD+".txt", new BD(nameOfBD + ".txt")));
		std::ofstream file(tmpname);
		file.open(tmpname);
		if (file.is_open()) {
			std::cout << "BD created\n";
			file << 0;
		}
		else
			throw "Error: File wasn't open!!\n\n";
		file.close();
		return false;
	}
	
	if (ind->second == 2) {
		/*std::cout << "Enter NAME of DataBase: <";
		std::getline(std::cin, nameOfBD);*/
		if (CMD.size() != 2)
			throw "Error: Invalid parameters\n\t >> calc(BD_NAME)                     || Calculate number of disciplines\n";
		nameOfBD = CMD[1];
		auto It = BaseData.find(nameOfBD + ".txt");
		if (It != BaseData.end()) {
			It->second->calcNumOfDisciplines();
		}
		else {
			throw "Error: Unknown BD";
		}

		return false;
	}

	if (ind->second == 3) {
		if (CMD.size() != 3)
			throw "Error: Invalid parameters\n\t >> find(BD_NAME,DEP_NAME)            || Search Department by DEP_NAME in BD_NAME (and output)\n";
		nameOfBD = CMD[1];
		nameOfDepart = CMD[2];
		auto It = BaseData.find(nameOfBD + ".txt");
		if (It != BaseData.end()) {
			Obj = It->second;
		}
		else {
			throw "Error: Unknown BD";
		}
		bool findDep = false;
		Department* tmp = nullptr;
		for (int i = 0; i < Obj->getNumOfD(); i++) {
			Department* ElDep = Obj->getDepartment(i);
			if (ElDep->getNameOfDep() == nameOfDepart) {
				findDep = true;
				tmp = ElDep;
			}
		}
		if (findDep)
		{
			//InIt* findEl = nullptr;
			//findEl = tmp->getInfo();
			tmp->printInfo();
		}
		else {
			std::string error = "Department \"" + nameOfDepart + "\" NOT FOUNDED";
			throw  error;
		}
		return false;
	}
		
	if (ind->second == 4) {
		/*std::cout << "Enter name of BD where add new element: ";
		std::cout << "<";
		std::getline(std::cin, nameOfBD);
		std::cout << ">\n";*/
		if (CMD.size() != 4)
			throw "Error: Invalid parameters\n\t >> add(BD_NAME,DEP_NAME, DEP_T)      || Add new Department DEP_NAME with type: DEP_T = i(industrial) / b(base) in DB_NAME \n";
		nameOfBD = CMD[1];
		nameOfDepart = CMD[2];
		typeOfD = CMD[3];
		if (BaseData.find(nameOfBD+".txt") != BaseData.end()) {
			it = BaseData.find(nameOfBD+".txt");
		}
		else {
			throw "Base data doesn't exist!";
		}
		/*std::cout << "Enter type of Department: \"b\"> to base department or \"i\"> to industry department:\n";
		std::getline(std::cin, typeOfD);
*/
		for (int i = 0; i < it->second->getNumOfD();i++) {
			if (it->second->getDepartment(i)->getNameOfDep() == nameOfDepart) {
				throw "| Warning : department already exists! |\n\n";
			}
		}

		if (typeOfD == "b" || typeOfD == "i") {
			if (typeOfD == "b") {
				it->second->setDepartment(new BaseDepartment(nameOfDepart));
			}
			else {
				it->second->setDepartment(new IndustryDepartment(nameOfDepart));
			}
		}
		else {
			throw "Unknown parameter DEP_T : Available only \'b\' or \i'\'";
		}
		//it->second->setDepartment()

		return false;
	}

	if (ind->second == 5) {
		if (CMD.size() != 3)
			throw "Error: Invalid parameters\n\t >> remove(BD_NAME,DEP_NAME)          || Remove Department from DB\n";
		nameOfBD = CMD[1];
		nameOfDepart = CMD[2];
		auto It = BaseData.find(nameOfBD + ".txt");
		if (It != BaseData.end()) {
			Obj = It->second;
		}
		else {
			throw "Error: Unknown BD";
		}
		Obj->removeDepartment(nameOfDepart);
		return false;
	}

	if (ind->second == 6) {
		
		if (CMD.size() != 3)
			throw "Error: Invalid parameters\n\t >> sort(BD_NAME,MODE)	              || Sort records by name or number. If you choose name, MODE = num, else MODE = name\n";
		nameOfBD = CMD[1];
		std::string mode = CMD[2];
		auto It = BaseData.find(nameOfBD + ".txt");
		if (It != BaseData.end()) {
			Obj = It->second;
		}
		else {
			throw "Error: Unknown BD";
		}
		if (mode == "num" || mode == "name") {
			if (mode == "num") {
				Obj->sortByCountOfSubdep();
			}
			else {
				Obj->sortByAlfabet();
			}
		}
		else {
			throw "Unknown parameter MODE : Available only \'num\' or \name'\'";
		}
		std::cout << "\t DB \'" << nameOfBD << "\' successful sorted!\n\n";
		return false;
	}
	
	if (ind->second == 7) {
		std::string newBD_Name, mode, nameOfDisc;
		
		int n;
		if (CMD.size() != 5)
			throw "Error: Invalid parameters\n\t >> pick(BD_NAME,BD_NEW,MODE,PARAM)	  || Pick new DB from records of DB_NAME and create new BD BD_NEW by MODE:\n\t >>                                      || If by number of subdepartments(bigger then PARAM) -> MODE = num, if by name of discipline(PARAM) -> MODE = disc\n";
		nameOfBD = CMD[1];
		newBD_Name = CMD[2];
		
		std::string tmpname = newBD_Name + ".txt";
		if (BaseData.find(tmpname) != BaseData.end()) {
			throw "| Warning : File \'" + newBD_Name + "\' already EXISTS!\n\n";
		}
		//BaseData.insert(std::make_pair(newBD_Name, new BD(newBD_Name + ".txt")));
		
		//newIt = ;
		newObj = new BD(newBD_Name+".txt");

		mode = CMD[3];

		auto It = BaseData.find(nameOfBD + ".txt");
		if (It != BaseData.end()) {
			Obj = It->second;
		}
		else {
			throw "Error: Unknown BD /'" + nameOfBD + "\'!";
		}
		if (mode == "num" || mode == "disc") {
			if (mode == "num") {
				try {
					n = std::stoi(CMD[4]);
				}
				catch (std::exception& e) {
					throw "Error: wrong value of PARAM!";
				}
				if (n <= 0) {
					throw "Error: wrong value of PARAM!";
				}

				for (auto i = 0; i < Obj->getNumOfD(); i++) {
					if (Obj->getDepartment(i)->getNumOfSub() > n) {
						newObj->addElOfContainer(Obj->getDepartment(i));
					}
				}
			}
			else {
				InIt* tmp = nullptr;
				nameOfDisc = CMD[4];
				for (auto i = 0; i < Obj->getNumOfD(); i++) {
					bool find = false;
					tmp = Obj->getDepartment(i)->getInfo();
					for (auto j = 0; j < Obj->getDepartment(i)->getNumOfSub(); j++) {
						if (tmp->getVecSubDep(j).findDiscipline(nameOfDisc)) {
							find = true;
							break;
						}
					}
					if (find) {
						newObj->addElOfContainer(Obj->getDepartment(i));
					}
				}
			}

			if (newObj->getNumOfD() == 0) {
				/*remove(tmpname.c_str());*/
				throw "Error : No suitable departments found! BD NOT created!";
			}
			else {
				int saveBD = 0;

				std::cout << "\n\n\t\tPicked BD : \n\n";
				for (int i = 0; i < newObj->getNumOfD(); i++) {
					newObj->getDepartment(i)->printInfo();
				}

				std::cout << "\tDo you want to save picked BD? [\'1\' - Yes / Anything else - false] : ";
				std::cin >> saveBD;
				if (std::cin.fail()) {
					/*std::cout << "\tError : Wrong input, try again:\n";*/
					std::cin.clear();
					std::cin.ignore(std::cin.rdbuf()->in_avail());
					std::cout << "\tBD not saved\n\n";
					return false;
				}
				else {
					std::cin.ignore(std::cin.rdbuf()->in_avail());
					if (saveBD == 1) {
						BaseData.insert(std::make_pair(newBD_Name + ".txt", newObj));
						std::ofstream file(tmpname);
						file.open(tmpname);
						if (!file.is_open()) {
							remove(tmpname.c_str());
							throw "Sorry: File does't saved!!\n\n";
						}
						file.close();
						newObj->WriteToFile();
					}
					else {
						std::cout << "\tBD not saved\n\n";
						return false;
					}
				}
			}
		}
		std::cout << "\tPicking successful completed! \n";
		return false;
	}

	if (ind->second == 8) {
		if (CMD.size() != 2) {
			throw "Error: Invalid parameters\n\t >> output(BD_NAME)                   || Display content of DB_NAME \n";
		}
		nameOfBD = CMD[1];
		auto It = BaseData.find(nameOfBD + ".txt");
		if (It != BaseData.end()) {
			Obj = It->second;
		}
		else {
			throw "Error: Unknown BD";
		}
		if (Obj->getNumOfD() > 0) {
			for (int i = 0; i < Obj->getNumOfD(); i++) {
				Obj->getDepartment(i)->printInfo();
			}
		}
		else {
			throw " | Warning : empty BD \'" + nameOfBD + "\'! |\n\n";
		}
		return false;
	}
	if (ind->second == 9) {
		if (CMD.size() != 1) {
			std::cout << "| Warning : Extra parameters founded |\n\n"; // Добавить желтую подсветку
		}
		std::cout << std::endl;
		std::cout << " List of available Base Dates WITH expansion: \n";
		for (auto i : BaseData) {
			/*std::string nameAndType = i.second->getName();
			for (int j = nameAndType.length()-1; j >= 0; j--) {
				if (nameAndType[j] == '.') {
					nameAndType = nameAndType.substr(0, j);
				}
			}*/
			std::cout << "\t\'" << i.second->getName() << "\'\n";
		}
		return false;
	}
	if (ind->second == 10) {
		if (CMD.size() != 1) {
			std::cout << "| Warning : Extra parameters founded |\n\n"; // Добавить желтую подсветку
		}
		return true;
	}

	if (ind->second == 11) {
		if (CMD.size() != 2) {
			throw "Error: Invalid parameters\n\t >> delete(BD_NAME)                   || Delete BD_NAME\n";
		}
		nameOfBD = CMD[1];
		auto It = BaseData.find(nameOfBD + ".txt");
		if (It != BaseData.end()) {
			BaseData.erase(It);
			remove((nameOfBD+".txt").c_str());
		}
		else {
			throw "Error: Unknown BD";
		}
		std::cout << "\tDelete successful complete! \n";
		return false;
	}
	
	return false;
}

int main() {
	std::cout << "Welcome to Mihail's Base Date of University!\n";
	bool ENDPROGRAMM = false;
	std::string command;
	addBDFromFiles();
	std::cout << "Enter \'>> help\' to see all available commands OR enter command:\n";
	while (!ENDPROGRAMM) {
		std::cout << ">> ";
		try
		{
			std::getline(std::cin, command);
			if (command == "")
				throw Exception("Empty input!");


			/*std::transform(command.begin(), command.end(), command.begin(), tolower);*/
			ENDPROGRAMM = Commands(parser(command));
			std::cout << "#----------------------------------------------------------------------------------------------------#\n";
		}
		catch (const Exception & exc)
		{
			std::cout << exc.what() << std::endl;
		}
		catch (const char* ex) {
			std::cout << ex << std::endl;
		}
		catch (char ex) {
			std::cout << ex << std::endl;
		}
		catch (std::string ex) {
			std::cout << ex << std::endl;
		}
	}
	std::cout << "Thanks for using my program!\n";

	return 0;
}