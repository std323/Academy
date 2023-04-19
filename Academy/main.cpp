#include<iostream>
#include<string>
using std::cin;
using std::cout;
using std::endl;

using namespace std;

class Human
{
	std::string last_name;
	std::string first_name;
	unsigned int age;
public:
	const std::string& get_last_name()const
	{
		return last_name;
	}
	const std::string& get_first_name()const
	{
		return first_name;
	}
	unsigned int get_age()const
	{
		return age;
	}
	void set_last_name(const std::string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const std::string& first_name)
	{
		this->first_name = first_name;
	}
	void set_age(unsigned int age)
	{
		this->age = age;
	}
	//        Constructors:

	Human(const std::string& last_name, const std::string& first_name, unsigned int age)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "HConstructor:\t" << this << endl;
	}
	~Human()
	{
		cout << "HDestructor:\t" << this << endl;
	}

	void info()const
	{
		cout << last_name << " " << first_name << " " << age << " у/о" << endl;
	}

};

class Student : public Human
{
	std::string speciality;
	std::string group;
	double rating;     //успеваемость
	double attendance;  //посещаемость
public:
	const std::string get_speciality()const
	{
		return speciality;
	}
	const std::string get_group()const
	{
		return group;
	}
	double get_rating()const
	{
		return rating;
	}
	double get_attendance()const
	{
		return attendance;
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_group(const std::string& group)
	{
		this->group = group;
	}
	void set_rating(double rating)
	{
		this->rating = rating;
	}
	void set_attendance(double attendance)
	{
		this->attendance = attendance;
	}
	//            Constructors:
	Student
	(
		const std::string& last_name, const std::string& first_name, unsigned int age,
		const std::string& speciality, const std::string& group, double rating, double attendance
	):Human(last_name, first_name, age)
		{
		set_speciality(speciality);
		set_group(group);
		set_rating(rating);
		set_attendance(attendance);
		cout << "SConstructor:\t" << this << endl;
		}
	~Student()
	{
		cout << "SDestructor:\t" << this << endl;
	}

	void info()const
	{
		Human::info();
		cout << speciality << " " << group << " rating:" << rating << ", attendance:" << attendance << endl;

	}
};

class Teacher : public Human
{
	std::string academic_subject;
	unsigned int teacher_work_time;

public:
	const std::string get_academic_subject()const
	{
		return academic_subject;
	}
	unsigned int get_teacher_work_time()const
	{
		return teacher_work_time;
	}
	void set_academic_subject(const std::string& academic_subject)
	{
		this->academic_subject = academic_subject;
	}
	void set_teacher_work_time(unsigned int teacher_work_time)
	{
		this->teacher_work_time = teacher_work_time;
	}
	//            Constructors:
	Teacher
	(
		const std::string& last_name, const std::string& first_name, unsigned int age,
		const std::string& academic_subject, unsigned int teacher_work_time
	) :Human(last_name, first_name, age)
	{
		set_academic_subject(academic_subject);
		set_teacher_work_time(teacher_work_time);
		cout << "TConstructor:\t" << this << endl;
	}
	~Teacher()
	{
		cout << "TDestructor:\t" << this << endl;
	}
	void info()const
	{
		Human::info();
		cout << "Academic_subject: " << academic_subject << ", teacher_work_time: " << teacher_work_time << endl;

	}
};
class Graduate : public Student 
{
	std::string	topic_of_the_thesis;
	std::string directors_of_thesis;
public:
	const std::string get_topic_of_the_thesis()const
	{
		return topic_of_the_thesis;
	}
	const std::string get_directors_of_thesis()const
	{
		return directors_of_thesis;
	}
	void set_topic_of_the_thesis(const std::string& topic_of_the_thesis)
	{
		this->topic_of_the_thesis = topic_of_the_thesis;
	}
	void set_directors_of_thesis(const std::string& directors_of_thesis)
	{
		this->directors_of_thesis = directors_of_thesis;
	}
//                     Constructors:
	Graduate
	(
		const std::string& last_name, const std::string& first_name, unsigned int age,
		const std::string& speciality, const std::string& group, double rating, double attendance,
		const std::string& topic_of_the_thesis, const std::string& directors_of_thesis
	) : Student(speciality, group, rating, attendance)
	{
		set_topic_of_the_thesis(topic_of_the_thesis);
		set_directors_of_thesis(directors_of_thesis);
		cout << "GConstructor:\t" << this << endl;
	}
	~Graduate()
	{
		cout << "GDestructor:\t" << this << endl;
	}
	void info()const
	{
		Student::info();
		cout << "topic_of_the_thesis: " << topic_of_the_thesis << ", directors_of_thesis: " << directors_of_thesis << endl;

	}


};
	

void main()
{
	setlocale(LC_ALL, "");
	/*Human human("Тупенко", "Василий", 18);
	human.info();*/

	Student stud("Pinkman", "Jessie", 25, "Chemistruy", "WW_220", 95, 99);
	stud.info();

	Teacher teach("Ivanov", "Ivan", 40, "Chemistruy", 60);
	teach.info();

	Graduate grad("Pinkman", "Jessie", 25, "Chemistruy", "WW_220", 95, 99, "Mendeleev's table", "Ivanov I.");
	grad.info();

}