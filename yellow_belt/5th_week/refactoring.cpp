#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person {
public:
    Person(const string& name) : Name(name) {}
    virtual void Walk(const string& destination) const {
        cout << GetType() << ": " << Name << " walks to: " << destination << endl;
    };
    virtual string GetType() const = 0;
    const string Name;
};

class Student : public Person {
public:
    Student(const string& name, const string& favouriteSong) 
        : Person(name), FavouriteSong(favouriteSong)
    {}

    void Learn() const {
        cout << GetType() << ": " << Name << " learns" << endl;
    }

    void Walk(const string& destination) const override {
        Person::Walk(destination);
        SingSong();
    }

    void SingSong() const {
        cout << GetType() << ": " << Name << " sings a song: " << FavouriteSong << endl;
    }

    string GetType() const override { return "Student"; }

private:
    const string FavouriteSong;
};


class Teacher : public Person {
public:

    Teacher(const string& name, const string& subject) 
        : Person(name), Subject(subject)
    {}

    void Teach() const {
        cout << GetType() << ": " << Name << " teaches: " << Subject << endl;
    }

    void Walk(const string& destination) const override {
        Person::Walk(destination);
    }

    string GetType() const override { return "Teacher"; }

private:
    const string Subject;
};


class Policeman : public Person {
public:
    Policeman(const string& name) 
        : Person(name)
    {}
    
    void Check(const Person& p) const {
        const string type = p.GetType();
        cout << GetType() << ": " 
             << Name << " checks " << type 
             << ". " << type << "'s " 
             << "name is: " << p.Name << endl;
    }

    void Walk(const string& destination) const override {
        Person::Walk(destination);
    }

    string GetType() const override { return "Policeman"; }
};

void VisitPlaces(const Person& person, const vector<string>& places) {
    for (const auto& p : places) {
        person.Walk(p);
    }
}


int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");
    vector<string> places = {"Moscow", "London"};
    VisitPlaces(t, places);
    p.Check(s);
    VisitPlaces(s, places);
    return 0;
}
