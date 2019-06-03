#include "IndustryDepartment.h"

void IndustryDepartment::printInfo() {
	
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
				std::cout.width(33 + nameOf_j_Disc.length());
				std::cout << nameOf_j_Disc;
				std::cout.width(18 - nameOf_j_Disc.length() + 12 + std::to_string(numOfTeachers_j_Disc).length());
				std::cout << std::to_string(numOfTeachers_j_Disc) << std::endl;

				std::cout << std::endl;
			}
		}
	}
	else {
		std::cout << "| Warning : No subdepartments in " << nameOfDepartment << " |\n";
	}
	
	if (numOfOrganizations != 0) {
		if (numOfOrganizations != 0) {
			std::cout << "\tName of organization";
			std::cout.width(31);
			std::cout << "Name of discipline";
			std::cout.width(31);
			std::cout << "Number of teachers\n";
			for (int i = 0; i < numOfOrganizations; i++) {
				std::cout << "\t" << getInfo()->getVecOrganizations(i).getNameOfOrganization();
				for (int j = 0; j < 83 - getInfo()->getVecOrganizations(i).getNameOfOrganization().length(); j++) { std::cout << "-"; }
				std::cout << std::endl;
				for (int j = 0; j < getInfo()->getVecOrganizations(i).getNumOfDisciplines(); j++) {
					std::string nameOf_j_Disc = getInfo()->getVecOrganizations(i).getVecDisc(j).getName();
					int numOfTeachers_j_Disc = getInfo()->getVecOrganizations(i).getVecDisc(j).getNumOfTeachers();
					std::cout << "\t";
					std::cout.width(33 + nameOf_j_Disc.length());
					std::cout << nameOf_j_Disc;
					std::cout.width(18 - nameOf_j_Disc.length() + 12 + std::to_string(numOfTeachers_j_Disc).length());
					std::cout << std::to_string(numOfTeachers_j_Disc) << std::endl;

					std::cout << std::endl;
				}
			}
		}
	}
	else {
		std::cout << "| Warning : No organizations in " << nameOfDepartment << " |\n";
	}
	std::cout << std::endl;
}

void IndustryDepartment::FillDepartment() {
	bool err;
	std::cout << "Enter SaEC of \'" << nameOfDepartment << "\' : ";
	std::getline(std::cin, SaEC);

	
	err = true;
	do {
		std::cout << "Enter number of subdepartments of \'" << nameOfDepartment << "\' : ";
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
		setInfo(1);
	}
	std::cout << "\n\n";
	
	err = true;
	do {
		std::cout << "Enter number of organizations of \'" << nameOfDepartment << "\' : ";
		std::cin >> numOfOrganizations;
		if (std::cin.fail() || numOfOrganizations <= 0) {
			std::cout << "\tError : Wrong input, try again:\n";
			std::cin.clear();
			std::cin.ignore(std::cin.rdbuf()->in_avail());

		}
		else
			err = false;

	} while (err);
	std::cin.ignore(256, '\n');
	for (int i = 0; i < numOfOrganizations; i++) {
		std::cout << "\n\t / Fill " << i + 1 << " organization's profile /\n";
		setInfo(2);
	}
}