#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

class CommissionEmployee {
public:
	CommissionEmployee(const string&, const string&, const string&, double = 0.0, double = 0.0);
	void setFirstName(const string&);
	string getFirstName()const;
	void setLastName(const string&);
	string getLastName()const;
	double earning()const;
	string toString()const;
	double getGrossSales()const;
	double getCommissionRate()const;

protected: //자식에서 private로 접근하는방법 1 : private에 있는 것들을 protected로 바꾸어준다. 자식한정 접근가능
	string firstName;
	string lastName;
	string socialSecurityNumber;
	double grossSales;
	double commissionRate;
};

class BasePlusCommissionEmployee :public CommissionEmployee { //부모를 가져오는 방법
public:
	BasePlusCommissionEmployee(const string&, const string&, const string&, double = 0.0, double = 0.0, double = 0.0);
	double earning()const;
	string toString()const;
private:
	double baseSalary;
};

CommissionEmployee::CommissionEmployee(const string& f, const string& l, const string& s, double sales, double rate) {
	firstName = f;
	lastName = l;
	socialSecurityNumber = s;
	grossSales = sales;
	commissionRate = rate;
}

void CommissionEmployee::setFirstName(const string& f) {
	firstName = f;
}

string CommissionEmployee::getFirstName()const {
	return firstName;
}

void CommissionEmployee::setLastName(const string& l) {
	lastName = l;
}

string CommissionEmployee::getLastName()const {
	return lastName;
}

double CommissionEmployee::earning()const {
	return commissionRate * grossSales;
}

string CommissionEmployee::toString() const {
	ostringstream os;
	os << fixed << setprecision(2);
	os << "commission employee : " << firstName << " " << lastName << "\nsocial security number : " << socialSecurityNumber << "\ngross sales : " << grossSales << "\ncommission rate : " << commissionRate;
	return os.str();
}

double CommissionEmployee::getGrossSales()const {
	return grossSales;
}

double CommissionEmployee::getCommissionRate()const {
	return commissionRate;
}

//자식 생성자 만드는 법
BasePlusCommissionEmployee::BasePlusCommissionEmployee(const string& f, const string& l, const string& s, double sales, double rate, double base) : CommissionEmployee(f, l, s, sales, rate) {
	baseSalary = base;
}

double BasePlusCommissionEmployee::earning()const {
	return baseSalary + getGrossSales() * getCommissionRate(); //자식에서 private로 접근하는방법 2 : get 함수로 접근한다(가장좋은방법 but 속도가 아주 조금 느릴 수도 있음)
}

//double BasePlusCommissionEmployee::earnings()const {
//	return baseSalary + CommissionEmployee::earning(); //자식에 있는 메소드 스킵 후 부모에 있는 메소드 호출 방법 : 앞에 명시해줌
//}

string BasePlusCommissionEmployee::toString() const {
	ostringstream os;
	os << fixed << setprecision(2);
	os << "commission employee : " << firstName << " " << lastName << "\nsocial security number : " << socialSecurityNumber << "\ngross sales : " << grossSales << "\ncommission rate : " << commissionRate << "\nBase salary: " << baseSalary;
	return os.str();
}



int main() {
	CommissionEmployee yu("park", "yonguk", "12211615", 10000, 0.05);
	BasePlusCommissionEmployee yyu("park", "yonguk", "12211615", 20000, 0.05, 500);
	cout << yu.toString() << '\n';
	cout << "Total earning is : " << yu.earning() << '\n';
	cout << yyu.toString() << '\n';
	cout << "Total earning is : " << yyu.earning() << '\n';
}