#pragma once
#include <iostream>
#include <string>
#include <vector>


class InIt {
	std::vector<Subdepartment> vecSubDep; // вектор кафедр
	std::vector<Organization> vecOrganizations; // вектор организаций
public:
	Subdepartment getVecSubDep(int index) { return (vecSubDep[index]); }
	Organization getVecOrganizations(int index) { return vecOrganizations[index]; }
};

struct Discipline {
	std::string name;
	int numberOfTeachers;
};

class Subdepartment : public Discipline {
private:
	std::string nameOfSubdep;
	int numOfDisciplines;
	std::vector<Discipline> vecDisc;  
	
public:
	Discipline getVecDisc(int index) {
		return vecDisc[index];
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
	std::vector<Discipline> vecDisc;

public:
	Discipline getVecDisc(int index) {
		return vecDisc[index];
	}
	std::string getNameOfOrganization() {
		return nameOfOrganization;
	}
	int getNumOfDisciplines() {
		return numOfDisciplines;
	}
	
};

