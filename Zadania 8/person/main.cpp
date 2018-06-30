#include <algorithm>
#include <iostream>
#include <vector>

class Person
{
private:
    static std::vector<Person*> vec_;
    std::string imie_;
    std::string nazwisko_;

public:
    Person(std::string imie, std::string nazwisko)
        : imie_(imie), nazwisko_(nazwisko)
    {
        vec_.push_back(this);
    }

    Person(const Person& p)
        : imie_(p.imie_), nazwisko_(p.nazwisko_)
    {
        vec_.push_back(this);
    }

    ~Person()
    {
        Person::vec_.erase(std::find(std::begin(Person::vec_),
                                     std::end(Person::vec_), this));
    }

    std::string ImieNazwisko() const
    {
        return imie_ + " " + nazwisko_;
    }

    static void OutputPersons(std::ostream& out)
    {
        out << "lista osob:\n";
        for (auto p : Person::vec_)
        {
            std::cout << p->ImieNazwisko() << '\n';
        }
    }
};

std::vector<Person*> Person::vec_;

class Worker
{
    Person person_;
    std::string position_;
public:
    Worker(const Person& person, std::string position)
        : person_(person)
        , position_(position)
    {
    }
};

void Fun2()
{
    Person s("Dariusz", "Dabacki");
    Person t("Eugeniusz", "Ebacki");
    {
        Person u("Franciszek", "Fabacki");
    }
    Worker w(Person("Grzegorz","Gabacki"),"guard");
    Person::OutputPersons(std::cout);
}

void Fun()
{
    Person* pq = new Person("Bartosz", "Babacki");
    Person r("Czeslaw", "Cabacki");
    Fun2();
    delete pq;
}

void Fun3()
{
    Person* x = new Person("Franciszek", "Fabacki");
    Worker y(*x,"guard");
    delete x;
    Person::OutputPersons(std::cout);
}

int main()
{
    Person p("Adam", "Abacki");
    Fun();
//    Fun3();
    return 0;
}

