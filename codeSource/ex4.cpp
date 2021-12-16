#include <iostream>
#include <list>

using namespace std;

// definition de class Person: 
class Person{
    public:
    string nom;
    string prenom;
    string age;

    Person(string nm,string pr, string ag);
    ~Person();
};

// definition de constructeur et destructeur:
Person::Person(string nm,string pr, string ag)
       :nom(nm),prenom(pr),age(ag){}
Person::~Person(){
}

// une fonction pour compare deux person selon leur nom et prenom
// pou la methode sort()
bool comparePerson(Person personOne,Person personTwo){
    if(personOne.nom == personTwo.nom){
        // si les deux personnes ont la meme nom
        if(personOne.prenom == personTwo.prenom){
            // si les deux personnes ont les meme nom et prenom
            cout << "1\n";
            return true;
        }else{
            cout << "2\n";
            return personOne.prenom > personTwo.prenom;
        }
    } else{
            cout << "3\n";
        return personOne.nom > personTwo.nom;
    }
}

int main(int argc, char const *argv[])
{
    list <Person> people;
    list <Person>::iterator peopleItr;
    string tempN,tempP,tempA;

    for(int i=0; i<4;i++){
        cout << "entre les information de personne " << i << " :\n";
        cout << "nom:\n";
        cin >> tempN;
        cout << "prenom:\n";
        cin >> tempP;
        cout << "age:\n";
        cin >> tempA;

        // creation un instance de class Person:
        Person temp = Person(tempN,tempP,tempA);
        // insertion l'instance dans la liste people:
        people.push_back(temp);
    }

    // triage de list
    people.sort(comparePerson);
    people.reverse();
    // affichage des valeurs de la list people:
    cout << "=====les personnes dans la list======\n";
    for(peopleItr = people.begin();peopleItr != people.end();peopleItr++){
        cout << "Donnes de personne \n";
        cout << "nom: " << peopleItr->nom << endl;
        cout << "prenom: " << peopleItr->prenom << endl;
        cout << "age: " << peopleItr->age << endl;
    }
       
    return 0;
}