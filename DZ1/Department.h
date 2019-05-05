#pragma once
#include "Subdepartment and Organization.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>
#include "gotoXY.h"



class Department : public Subdepartment, public Organization, public InIt 	 {

	
public:
	
	Department() = default;
	virtual ~Department() = default;
	
	/*virtual Organization getVecOrganizations(int index) = 0;
	virtual Subdepartment getVecSubDep(int index) = 0;*/
	virtual void setSaEC(std::string) = 0;
	virtual void setNameDep(std::string) = 0;
	virtual void setnumOfSub(int) = 0;
	virtual void setnumOfOrgan(int) = 0;
	virtual void setSub(InIt*) = 0;
	virtual void setInfo(int) = 0;
	virtual InIt* getInfo() = 0;
	virtual int getNumOfSub() = 0;
	virtual int getNumOfOrganizations() = 0;
	virtual int calcNumOfSubjects() = 0;

	virtual std::string getSaEC() = 0;
	virtual std::string getNameOfDep() = 0;
	virtual std::string getClass() = 0;
	virtual void printInfo() = 0;
	virtual void readFromFile() = 0;


};
