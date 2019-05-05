#include "BaseDepartment.h"

//void BaseDepartment::WriteToFile() {
//	std::ofstream fout;
//	fout.open(PATH, std::ios_base::app);
//	fout << "{" << this->nameOfDepartment << ":{" << this->SaEC << "},{";
//	for (int i = 0; i < numOfSubdepartments; i++) {
//		fout << Subdepartments[i].nameOfSubdep << ":{";
//		for (int j = 0; j < Subdepartments[i].numOfDisciplines; j++) {
//			fout << Subdepartments[i].Disciplines[j].name << ":<" <<
//				Subdepartments[i].Disciplines[j].numberOfTeachers << ">";
//			if (j != j < Subdepartments[i].numOfDisciplines - 1)
//				fout << ";";
//			else
//				fout << "}";
//		}
//		if (i != numOfSubdepartments - 1)
//			fout << "/";
//		else
//			fout << "}";
//	}
//
//}

void BaseDepartment::readFromFile(/*std::string*/) {}


void BaseDepartment::printInfo() {
	
	if (numOfSubdepartments != 0) {
		std::cout << "\t\t\t | Info about department \'" << nameOfDepartment << "\' |" << std::endl;
		std::cout << "\tName of subdepartment";
		std::cout.width(30);
		std::cout << "Name of discipline";
		std::cout.width(31);
		std::cout << "Number of teachers\n";
		for (int i = 0; i < numOfSubdepartments; i++) {
			std::cout << "\t" << getInfo()->getVecSubDep(i).getNameOfSubdep();
			for (int j = 0; j < 81 - getInfo()->getVecSubDep(i).getNameOfSubdep().length(); j++) { std::cout << "-"; }
			std::cout << std::endl;
			for (int j = 0; j < getInfo()->getVecSubDep(i).getNumOfDisciplines(); j++) {
				std::string nameOf_j_Disc = getInfo()->getVecSubDep(i).getVecDisc(j).getName();
				int numOfTeachers_j_Disc = getInfo()->getVecSubDep(i).getVecDisc(j).getNumOfTeachers();
				std::cout << "\t";
				//std::cout.clear();
				std::cout.width(33 + nameOf_j_Disc.length());
				std::cout << nameOf_j_Disc;
				//std::cout.clear();
				std::cout.width(18 - nameOf_j_Disc.length() + 12 + std::to_string(numOfTeachers_j_Disc).length());
				//int tmp = 18 - nameOf_j_Disc.length() + 12 + std::to_string(numOfTeachers_j_Disc).length();
				std::cout << std::to_string(numOfTeachers_j_Disc) << std::endl;

				std::cout << std::endl;
			}
		}
	}
	else {
		std::cout << "| Warning : No subdepartments in " << nameOfDepartment << " |\n";
	}
	//std::cout << "sum: " << sumOfSub;
	std::cout << std::endl;
}

void BaseDepartment::FillDepartment() {
	std::cout << "Enter SaEC of \'" << nameOfDepartment << "\' : ";
	std::getline(std::cin, SaEC);
	
	std::cout << "Enter number of subdepartments of \'" << nameOfDepartment << "\' : " ;
	bool err = true;
	do {
		std::cin >> numOfSubdepartments;
		if (std::cin.fail() || numOfSubdepartments <= 0) {
			std::cout << "\tError : Wrong input, try again:\n";
			std::cin.clear();
			std::cin.ignore(std::cin.rdbuf()->in_avail());
		}
		else
			err = false;

	} while (err);
	std::cin.ignore(256, '\n');
	for (int i = 0; i < numOfSubdepartments; i++) {
		std::cout << "\n\t / Fill " << i + 1 << " subdepartment's profile /\n";
		setInfo(-1);
	}
}