#include <string>
#include<iostream>
#include "Person.h"
using namespace std;

Person::Person() {
	firstName = "";
	lastName = "";
	payRate = 0;
	hoursWorked = 0;
	companyName = "";
	employeeID = 0;

}
string Person::getFirstName() {
	return firstName;
}
void Person::setFirstName(string fname) {
	firstName = fname;
}
string Person::getLastName() {
	return lastName;
}
void Person::setLastName(string lName) {
	lastName = lName;
}
float Person::getPayRate() {
	return payRate;

}
void Person::setPayRate(float rate) {
	payRate = rate;
}

float Person::getHoursWorked() {
	return hoursWorked;
}
void Person::setHoursWorked(float hours) {
	hoursWorked = hours;
}
int Person::getEmployeeId() {
	return employeeID;
}
void Person::setEmployeeId(int id) {
	employeeID = id;
}
string Person::getCompanyName() {
	return companyName;
}
void Person::setCompanyName(string coName) {
	companyName = coName;
}
float  Person::totalPay() {
	return hoursWorked * payRate;
}
string Person::fullName() {
	return firstName + " " + lastName;
}