#include<iostream>
#include<string>
using std::cin;
using std::cout;
using std::endl;

#define delimiter "\n-------------------------------------\n"

#define HUMAN_TAKE_PARAMETERS const std::string& last_name, const std::string& first_name, unsigned int age
#define HUMAN_GIVE_PARAMETERS last_name, first_name, age

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

	Human(HUMAN_TAKE_PARAMETERS)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "HConstructor:\t" << this << endl;
	}
	virtual ~Human()
	{
		cout << "HDestructor:\t" << this << endl;
	}

	virtual void info()const
	{
		cout << last_name << " " << first_name << " " << age << " у/о" << endl;
	}

};

#define STUDENT_TAKE_PARAMETERS const std::string& speciality, const std::string& group, double rating, double attendance
#define STUDENT_GIVE_PARAMETERS speciality, group, rating, attendance

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
	Student(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETERS) :Human(HUMAN_GIVE_PARAMETERS)
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

#define TECHER_TAKE_PARAMETERS const std::string& academic_subject, unsigned int teacher_work_time
#define TECHER_GIVE_PARAMETERS academic_subject, teacher_work_time
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
	Teacher(HUMAN_TAKE_PARAMETERS, TECHER_TAKE_PARAMETERS) :Human(HUMAN_GIVE_PARAMETERS)
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
	Graduate(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETERS, const std::string& topic_of_the_thesis, const std::string& directors_of_thesis
	) : Student(HUMAN_GIVE_PARAMETERS, STUDENT_GIVE_PARAMETERS)
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

/*class Teacher : public Human
{
	std::string speciality;
	unsigned int experience;
public:

	const std::string& get_speciality()const
	{
		return speciality;
	}
	unsigned int get_experience()const
	{
		return experience;
	}
	void set_speciality(std::string speciality)
	{
		this->speciality = speciality;
	}
	void set_experience(unsigned int experience)
	{
		this->experience = experience;
	}


};*/

//#define INHERITANCE
#define POLYMORPHISM
void main()
{
	setlocale(LC_ALL, "");
#ifdef INHERITANCE
	/*Human human("Тупенко", "Василий", 18);
human.info();*/

	Student stud("Pinkman", "Jessie", 25, "Chemistruy", "WW_220", 95, 99);
	stud.info();

	Teacher teacher("Ivanov", "Ivan", 40, "Chemistruy", 60);
	teacher.info();

	Graduate grad("Pinkman", "Jessie", 25, "Chemistruy", "WW_220", 95, 99, "Mendeleev's table", "Ivanov I.");
	grad.info();

#endif // INHERITANCE

	Human* group[] =
	{
		new Student("Pinkman", "Jessie", 25,  "Chemistruy", "WW_220", 95, 98),
		new Teacher("White", "Walter", 50, "Chemistruy", 20),
		new Graduate("Shreder", "Hank", 40, "Criminalistic", "OBN", 90, 70, "HOW to catch", "Walter White"),
		new Student("Vercetti", "Tomas", 30, "Theft", "Vice", 98, 100),
		new Teacher("Diaz", "Ricardo", 50, "Weapons distibution", 60)

	};
	cout << delimiter << endl;
	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		group[i]->info();
		cout << delimiter << endl;
	}
	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		delete group[i];
	}

}