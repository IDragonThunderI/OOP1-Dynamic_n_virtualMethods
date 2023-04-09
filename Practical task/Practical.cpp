#include <iostream>
#include <typeinfo>

using namespace std;

/*=============== КЛАСС ПЕРСОНА ===============*/

class Persona
{
private:
	string fullname;
	string gender;
	string birthday;
	string phoneNumber;

public:
	Persona();
	virtual ~Persona() = 0 {}
	void setData(string fullname, string gender, string birthday, string phoneNumber);
	string getFullname() const { return fullname; }
	string getGender() const { return gender; }
	string getBirthday() const { return birthday; }
	string getPhoneNumber() const { return phoneNumber; }
	virtual void print() = 0;
	virtual void classInfo() = 0;

};

Persona::Persona()
{
	fullname = gender = birthday = phoneNumber = "Unknown";
}

void Persona::setData(string fullname, string gender, string birthday, string phoneNumber)
{
	if(fullname != "")
		this->fullname = fullname;
	if(gender != "")
		this->gender = gender;
	if(birthday != "")
		this->birthday = birthday;
	if(phoneNumber != "")
		this->phoneNumber = phoneNumber;
}

/*=============== КЛАСС СТУДЕНТ ===============*/

class Student : public Persona
{
private:
	string institute;
	string course;
	string group;

public:
	Student();
	Student(string fullname, string gender, string birhday, string phoneNumber, string institute, string course, string group);
	~Student() {}
	void setData(string institute, string course, string group);
	Student& getData();
	void print();
	void classInfo();
};

Student::Student()
{
	institute = course = group = "Unknown";
}

Student::Student(string fullname, string gender, string birhday, string phoneNumber, string institute, string course, string group)
{
	Persona::setData(fullname, gender, birhday, phoneNumber);
	setData(institute, course, group);
}

void Student::setData(string institute, string course, string group)
{
	if(institute != "")
		this->institute = institute;
	if(course != "")
		this->course = course;
	if(group != "")
		this->group = group;
}

Student& Student::getData()
{
	return *this;
}

void Student::print()
{
	cout << "\nФИО: " << getFullname();
	cout << "\nПол: " << getGender();
	cout << "\nДата рождения: " << getBirthday();
	cout << "\nНомер телефона: " << getPhoneNumber();
	cout << "\nИнститут: " << institute;
	cout << "\nКурс: " << course;
	cout << "\nГруппа: " << group << "\n\n";
}

void Student::classInfo()
{
	string className = typeid(*this).name();
	cout << "Класс: " << className.erase(0, 6) << "\n";
}

/*=============== КЛАСС ПРЕПОДАВАТЕЛЬ ===============*/

class Teacher : public Persona
{
private:
	string discipline;
	string experience;
	string salary;

public:
	Teacher();
	Teacher(string fullname, string gender, string birthday, string phoneNumber, string discipline, string experience, string salary);
	~Teacher() {}
	void setData(string discipline, string experience, string salary);
	Teacher& getData();
	void print();
	void classInfo();

};

Teacher::Teacher()
{
	discipline = experience = salary = "Unknown";
}

Teacher::Teacher(string fullname, string gender, string birthday, string phoneNumber, string discipline, string experience, string salary)
{
	Persona::setData(fullname, gender, birthday, phoneNumber);
	setData(discipline, experience, salary);
}

void Teacher::setData(string discipline, string experience, string salary)
{
	if(discipline != "")
		this->discipline = discipline;
	if(experience != "")
		this->experience = experience;
	if(salary != "")
		this->salary = salary;
}

Teacher& Teacher::getData()
{
	return *this;
}

void Teacher::print()
{
	cout << "\nФИО: " << getFullname();
	cout << "\nПол: " << getGender();
	cout << "\nДата рождения: " << getBirthday();
	cout << "\nНомер телефона: " << getPhoneNumber();
	cout << "\nДисциплина: " << discipline;
	cout << "\nСтаж работы: " << experience;
	cout << "\nЗарплата: " << salary << "\n\n";
}

void Teacher::classInfo()
{
	string className = typeid(*this).name();
	cout << "Класс: " << className.erase(0, 6) << "\n";
}

/*=============== КЛАСС ЗАВКАФЕДРОЙ ===============*/

class DepartmentHead : public Teacher
{
private:
	string department;
	string dateOfAppointment;

public:
	DepartmentHead();
	DepartmentHead(Teacher& teacher, string department, string dateOfAppointment);
	~DepartmentHead() {}
	void setData(string department, string dateOfAppointment);
	DepartmentHead& getData();
	void print();
	void classInfo();
};

DepartmentHead::DepartmentHead()
{
	department = dateOfAppointment = "Unknown";
}

DepartmentHead::DepartmentHead(Teacher& teacher, string department, string dateOfAppointment) : Teacher::Teacher(teacher)
{
	setData(department, dateOfAppointment);
}

void DepartmentHead::setData(string department, string dateOfAppointment)
{
	if(department != "")
		this->department = department;
	if(dateOfAppointment != "")
		this->dateOfAppointment = dateOfAppointment;
}

DepartmentHead& DepartmentHead::getData()
{
	return *this;
}

void DepartmentHead::print()
{
	cout << "\nКафедра: " << department;
	cout << "\nДата назначения: " << dateOfAppointment;
	Teacher::print();
}

void DepartmentHead::classInfo()
{
	string className = typeid(*this).name();
	cout << "Класс: " << className.erase(0, 6) << "\n";
}

/*=============== MAIN ===============*/

int main()
{
	system("chcp 1251 > nul");

	Persona* list[3];

	Student stud("Рекечинский Андрей Алексеевич", "Мужской", "21.11.2003", "88005553535", "ИМФиИТ", "2", "МОб-2102а");
	Teacher teach("Иванов Иван Иванович", "Мужсокй", "12.05.1981", "88003339191", "ООП", "8 лет", "40000 Р");
	DepartmentHead dthd(teach.getData(), "Прикладная математика и информатика", "03.09.2016");

	list[0] = &stud;
	list[1] = &teach;
	list[2] = &dthd;

	for (int i = 0; i < 3; i++)
	{
		list[i]->classInfo();
		list[i]->print();
		cout << "===============================================\n\n";
	}

	system("pause");
	return 0;
}