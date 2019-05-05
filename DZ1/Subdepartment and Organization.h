#pragma once
#include <Windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <complex.h>


class InIt;

class Discipline {
private:
	std::string name;
	int numberOfTeachers;
public:
	Discipline(std::string nm, int cntTeachs) : name(nm), numberOfTeachers(cntTeachs) {}
	Discipline(std::string nm) : name(nm) {
		FillDiscipline();
	}
	Discipline() {}
	std::string getName() { return name; }
	
	void setNumTeach(int cnt) { numberOfTeachers = cnt; }

	int getNumOfTeachers() { return numberOfTeachers; }
	
	void FillDiscipline() {
		
		bool err = true;
		do {
			std::cout << "\tEnter number of teachers : ";
			std::cin >> numberOfTeachers;
			if (std::cin.fail() || numberOfTeachers <= 0) {
				std::cout << "\tError : Wrong input, try again:\n";
				std::cin.clear();
				std::cin.ignore(std::cin.rdbuf()->in_avail());

			}
			else
				err = false;

		} while (err);
		
		std::cin.ignore(256, '\n');;
	}
};

class Subdepartment : public Discipline {
private:
	std::string nameOfSubdep;
	int numOfDisciplines;
	std::vector<Discipline*> vecDisc;  
	
public:
	Subdepartment(std::string name, int num) : nameOfSubdep(name), numOfDisciplines(num) {}
	Subdepartment(std::string name) : nameOfSubdep(name){
		FillSubDepartment();
	}
	Subdepartment() {}
	~Subdepartment() {
		vecDisc.clear();
	}
	void setVecDisc(std::vector<Discipline*> elVect) { vecDisc = elVect; }
	bool findDiscipline(std::string nameOfDisc) {
		for (auto i : vecDisc) {
			if (i->getName() == nameOfDisc)
				return true;
		}
		return false;
	}
	void FillSubDepartment() {
		
		
		bool err = true;
		do {
			std::cout << "Enter number of disciplines of subdepartment \'" << nameOfSubdep << "\' : ";
			std::cin >> numOfDisciplines; 
			if (std::cin.fail() || numOfDisciplines <= 0) {
				std::cout << "\tError : Wrong input, try again:\n";
				std::cin.clear();
				std::cin.ignore(std::cin.rdbuf()->in_avail());

			}
			else
				err = false;

		} while (err);
		
		std::cin.ignore(256, '\n');

		for (int i = 0; i < numOfDisciplines; i++) {
			std::string name;
			std::cout << "Enter name of " << i+1 << " discipline of subdepartment \'" << nameOfSubdep << "\' : ";
			std::getline(std::cin, name);
			vecDisc.push_back(new Discipline(name));
		}
	}

	void setNumDisc(int cnt) { numOfDisciplines = cnt; }
	void setDisc(std::vector< Discipline*> tmp) { vecDisc = tmp; }

	Discipline getVecDisc(int index) {
		return *vecDisc[index];
	}
	std::string getNameOfSubdep() {
		return nameOfSubdep;
	}
	int getNumOfDisciplines() {
		return numOfDisciplines;
	}
};

class Organization : public Discipline {
private:
	std::string nameOfOrganization;
	int numOfDisciplines;
	std::vector<Discipline*> vecDisc;

public:
	Organization(std::string name, int num) : nameOfOrganization(name), numOfDisciplines(num) {}
	Organization(std::string name) : nameOfOrganization(name){
		FillOrganization();
	}
	Organization() {}
	~Organization() {
		vecDisc.clear();
	}
	bool findDiscipline(std::string nameOfDisc) {
		for (auto i : vecDisc) {
			if (i->getName() == nameOfDisc)
				return true;
		}
		return false;
	}
	void setVecDisc(std::vector<Discipline*> elVect) { vecDisc = elVect; }
	
	void FillOrganization() {

		
		bool err = true;
		do {
			std::cout << "Enter number of disciplines of organization \'" << nameOfOrganization << "\' : ";
			std::cin >> numOfDisciplines;
			if (std::cin.fail() || numOfDisciplines <= 0) {
				std::cout << "\tError : Wrong input, try again:\n";
				std::cin.clear();
				std::cin.ignore(std::cin.rdbuf()->in_avail());

			}
			else
				err = false;

		} while (err);
		
		std::cin.ignore(256, '\n');

		for (int i = 0; i < numOfDisciplines; i++) {
			std::string name;
			std::cout << "Enter name of organization \'" << nameOfOrganization << "\' : ";
			std::getline(std::cin, name);
			vecDisc.push_back(new Discipline(name));
		}
	}

	void setNumDisc(int cnt) { numOfDisciplines = cnt; }
	void setDisc(std::vector< Discipline*> tmp) { vecDisc = tmp; }

	Discipline getVecDisc(int index) {
		return *vecDisc[index];
	}
	std::string getNameOfOrganization() {
		return nameOfOrganization;
	}
	int getNumOfDisciplines() {
		return numOfDisciplines;
	}
	
	
};

class InIt {
	std::vector<Subdepartment*> vecSubDep; // вектор кафедр
	std::vector<Organization*> vecOrganizations; // вектор организаций
public:
	~InIt() {
		vecSubDep.clear();
		vecOrganizations.clear();
	}
	InIt() = default;
	int calcSumCount(std::string type) {
		int sum = 0;
		for (auto i : vecSubDep) {
			sum += i->getNumOfDisciplines();
		}
		if (type == "IND") {
			for (auto i : vecOrganizations) {
				sum += i->getNumOfDisciplines();
			}
		}
		return sum;
	}
	void FillSubDep(std::string name) {
		bool error;
		std::string nameSubDepa;
		do {
			error = false;
			std::cout << "Enter name of Subdepartment of \'" << name << "\' : ";   std::getline(std::cin, nameSubDepa);
			for (auto i : vecSubDep) {
				if (i->getNameOfSubdep() == nameSubDepa) {
					std::cout << "Error : subdepartment already exists! Try again: \n";
					error = true;
				}
			}
		} while (error);
		vecSubDep.push_back(new Subdepartment(nameSubDepa));
	}

	void FillOrgaiz(std::string name) {
		bool error;
		std::string OrganizName;
		do {
			error = false;
			std::cout << "Enter name of Organization \'" << name << "\' : "; std::getline(std::cin, OrganizName);
			for (auto i : vecOrganizations) {
				if (i->getNameOfOrganization() == OrganizName) {
					std::cout << "Error : organization already exists! Try again: \n";
					error = true;
				}
			}
		} while (error);
		vecOrganizations.push_back(new Organization(OrganizName));
	}
	
	void setVecSbDp(std::vector<Subdepartment*> tmpVec) {
		vecSubDep = tmpVec;
	}
	void setVecOrgan(std::vector<Organization*> tmpVec) {
		vecOrganizations = tmpVec;
	}
	Subdepartment getVecSubDep(int index) { return (*vecSubDep[index]); }
	Organization getVecOrganizations(int index) { return *vecOrganizations[index] ; }
};