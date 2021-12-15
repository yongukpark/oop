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

protected: //�ڽĿ��� private�� �����ϴ¹�� 1 : private�� �ִ� �͵��� protected�� �ٲپ��ش�. �ڽ����� ���ٰ���
	string firstName;
	string lastName;
	string socialSecurityNumber;
	double grossSales;
	double commissionRate;
};

class BasePlusCommissionEmployee :public CommissionEmployee { //�θ� �������� ���
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

//�ڽ� ������ ����� ��
BasePlusCommissionEmployee::BasePlusCommissionEmployee(const string& f, const string& l, const string& s, double sales, double rate, double base) : CommissionEmployee(f, l, s, sales, rate) {
	baseSalary = base;
}

double BasePlusCommissionEmployee::earning()const {
	return baseSalary + getGrossSales() * getCommissionRate(); //�ڽĿ��� private�� �����ϴ¹�� 2 : get �Լ��� �����Ѵ�(����������� but �ӵ��� ���� ���� ���� ���� ����)
}

//double BasePlusCommissionEmployee::earnings()const {
//	return baseSalary + CommissionEmployee::earning(); //�ڽĿ� �ִ� �޼ҵ� ��ŵ �� �θ� �ִ� �޼ҵ� ȣ�� ��� : �տ� �������
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