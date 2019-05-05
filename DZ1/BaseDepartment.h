#pragma once
#include "Department.h"

#include <vector>



class BaseDepartment : public Department {
private:
	const std::string classOfDepartment = "BASE";
	std::string SaEC;			 //Scientific and educational complex
	std::string nameOfDepartment;
	int numOfSubdepartments;
	InIt* Subdep = new InIt;

	//std::vector<Subdepartment> vecSubDep; // вектор кафедр
public:
	BaseDepartment() {};
	
	BaseDepartment(std::string name) : nameOfDepartment(name) {
		FillDepartment();
	}
	virtual ~BaseDepartment(){
		delete Subdep;
	};

	virtual void setSaEC(std::string info) { SaEC = info; }
	virtual void setNameDep(std::string name) { nameOfDepartment = name; }
	virtual void setnumOfSub(int num) { numOfSubdepartments = num; }
	virtual void setnumOfOrgan(int) { throw "Something go wrong in 28 letter BaseDepartment!!"; };
	virtual void setSub(InIt* element) { Subdep = element; }

	//virtual Subdepartment getVecSubDep(int index) { return (vecSubDep[index]); }
	virtual InIt* getInfo() { return Subdep; }
	virtual void setInfo(int tmp) { Subdep->FillSubDep(nameOfDepartment); }
	
	void FillDepartment();
	virtual int getNumOfSub() { return numOfSubdepartments; }
	virtual void printInfo();
	virtual std::string getSaEC() { return SaEC; }
	virtual std::string getNameOfDep() { return nameOfDepartment; }
	virtual std::string getClass() { return classOfDepartment; }
	virtual int getNumOfOrganizations() { return -1; } //CODE ERROR
	virtual void readFromFile(/*std::string*/);
	virtual int calcNumOfSubjects() { return Subdep->calcSumCount(classOfDepartment); };
};

