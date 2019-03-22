
//#include "Person.cpp"
#include "Person.h"
#include <iostream> 
#include <vector>
# include <fstream>
#include <iomanip>
#include <iterator> 
using namespace std;
//vector<dataType> Name
void readFile(vector<Person> &empl)
{

	string lName;
	string fName;
	int id;
	string coName;
	float  rate;
	float  hours;
	fstream Personfile;
	Personfile.open("Text.txt");
	Person employee;
	while (Personfile >> fName >> lName >> id >> coName >> rate >> hours)
	{

		//Personfile >> firstName;
		//Personfile >> lastName;
		//Personfile >> hoursWorked;
		//Personfile >> payRate;
		cout << fName << "  " << lName << "  " << id << "  " << coName << "  " << rate << "  " << hours << "  " << endl;

		employee.setFirstName(fName);
		//cout << empl[i].getFirstName();
		employee.setLastName(lName);
		//cout << empl[i].getLastName();
		employee.setEmployeeId(id);
		employee.setCompanyName(coName);
		employee.setHoursWorked(hours);
		//cout << empl[i].getHoursWorked();
		employee.setPayRate(rate);
		//cout << empl[i].getPayRate();


		empl.push_back(employee);
	}

	Personfile.close();
	cout << "_____________________________________________________________________" << endl;
}

//Vector <mydatatype> the name
void getCompanies(vector <string> &Ncompany, vector<Person> &empl) {

	for (int i = 0; i < empl.size(); i++) {

		Ncompany.push_back(empl.at(i).getCompanyName());
	}
}

void printHighestPaid(vector<Person> &empl) {
	float HighestP = 0;

	HighestP = empl.at(0).totalPay();
	for (int i = 1; i < empl.size(); i++) {
		if (HighestP < empl.at(i).totalPay()) {
			HighestP = empl.at(i).totalPay();
		}
	}
	for (int N = 0; N < empl.size(); N++)
	{
		if (empl[N].totalPay() == HighestP) {
			cout << "Highest Pay is:" << empl[N].fullName() << endl;
			cout << "Employee ID is:" << empl[N].getEmployeeId() << endl;
			cout << "Employer Name is:" << empl[N].getCompanyName() << endl;
			cout << "The total pay is:" << setprecision(2) << fixed <<
				//Sets the decimal precision
				empl[N].totalPay() << endl;
		}
	}
	cout << "_____________________________________________________________________" << endl;
}


void separateAndSave(vector<Person> &empl, vector<string> &Ncompany) {

	for (int i = 0; i < Ncompany.size(); i++) {
		ofstream outfile;
		float total = 0;
		outfile.open(Ncompany[i] + ".txt");
		outfile << Ncompany[i] + ".txt" << endl;

		outfile << "_________________________________________________" << endl;
		for (int s = 0; s < empl.size(); ++s) {
			if (empl.at(s).getCompanyName() == Ncompany.at(i)) {
				total = total + empl.at(s).totalPay();
				outfile << left << setw(19) << empl[s].fullName() << " " << setw(4) <<
					empl[s].getEmployeeId() << setw(10) << left << Ncompany[s] << setw(10) << " " << empl[s].totalPay() << endl;

			}
		}
		outfile << setprecision(2) << fixed << endl;
		outfile << "Total Pay: " << total << endl;
		outfile.close();
	}


}
int main() {
	vector<Person> empl;
	vector<string> Ncompany;

	readFile(empl);
	getCompanies(Ncompany, empl);
	printHighestPaid(empl);
	separateAndSave(empl, Ncompany);

	
	return 0;



}