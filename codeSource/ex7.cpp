#include <iostream>
#include <list>

using namespace std;

// class Animal
class Animal{
    protected:
    string nom;
    int age;
    string genre;

    public:
    void setNom(string nom);
    void setAge(int age);
    void setGenre(string genre);
    string getNom();
    int getAge();
    string getGenre();
};

void Animal::setNom(string nom){
    this ->nom = nom;
}
void Animal::setAge(int age){
    this ->age = age;
}
void Animal::setGenre(string genre){
    this ->genre = genre;
}
string Animal::getNom(){
    return this ->nom;
}
int Animal::getAge(){
    return this ->age;
}
string Animal::getGenre(){
    return  this ->genre;
}
// class Repas, Element
class Element{
    private:
    string nom;
    string type;
    public:
    void setNom(string nom){
        this->nom = nom;
    }
    void setType(string type){
        this -> type = type;
    }
    string getNom(){
        return this->nom;
    }
    string getType(){
        return this -> type;
    }
};

class Repas{
    private:
    string nom;
    int heure;
    string description;
    list <Element> elementsList;
    public:
    void setNom(string nom){
        this->nom = nom;
    }
    void setHeure(int heure){
        this->heure = heure;
    }
    void setDescription(string description){
        this->description = description;
    }
    void setElementsList(list <Element> elementsList){
        this->elementsList = elementsList;
    }
    string getNom(){
        return this->nom;
    }
    int getHeure(){
        return this->heure;
    }
    string getDescription(){
        return this->description;
    }
    list <Element> getElementsList(){
        return this->elementsList;
    }
};
// class Chat
class Chat: public Animal{
    private:
    string type;
    Repas chatRepas;
    public:
    void setType(string type){
        this -> type = type;
    }
    void setRepas(Repas chatRepas){
        this->chatRepas = chatRepas;
    }
    string getType(){
        return this -> type;
    }
    Repas getRepas(){
        return this->chatRepas;
    }
    void sauter(){
        cout << "hyaaa3\n";
    }
};
// class Race
class Race{
    protected:
    string specifite;
    bool isRaceHybride(){
        if (specifite=="hybride"){
            return true;
        }
        return false;
    }
    public:
    void setSpecifite(string specifite){
        this->specifite = specifite;
    }
    string getSpecifite(){
        return this->specifite;
    }
};

// class Chien
class Entraineur;
class Chien:public Animal,Race{
    private:
    string taille;
    list <Entraineur> entraineurList;
    public:
    //setters
    void setTaille(string taille){
        this->taille = taille;
    }
    void setEntraineurList(list <Entraineur> entraineurList){
        this->entraineurList = entraineurList; 
    }
    // getters
    string getTaille(){
        return this->taille;
    }
    list <Entraineur> getEntraineurList(){
        return this->entraineurList;
    }
    // other
    bool isChass3(){
        return true;
    }
};

// class Entraineur
class Entraineur{
    private:
    string nom;
    string description;
    list <Chien> chienList;
    public:
    // setters
    void setNom(string nom){
        this->nom = nom;
    }
    void setDescription(string description){
        this->description = description;
    }
    void setChienList(list <Chien> chienList){
        this->chienList = chienList;
    }
    // getters
    string getNom(){
        return this->nom;
    }
    string getDescription(){
        return this->description;
    }
    list <Chien> getChienList(){
        return this->chienList;
    }
};

// class Compitition
class Compitition{
    private:
    string date;
    string nom;
    Chien chien;
    Entraineur entraineur;
    public:
    int ordre;
    // setters
    void setDate(string date){
        this->date = date;
    }
    void setNom(string nom){
        this->nom = nom;
    }
    void setChien(Chien chien){
        this->chien = chien;
    }
    void setEntraineur(Entraineur entraineur){
        this->entraineur = entraineur;
    }
    // getters
    string getDate(){
        return this->date;
    }
    string getNom(){
        return this->nom;
    }
    Chien getChien(){
        return this->chien;
    }
    Entraineur getEntraineur(){
        return this->entraineur;
    }
};

int main(int argc, char const *argv[])
{
    // Elements
    list <Element> myElements;
    Element el1,el2;
    el1.setNom("Element 1");
    el1.setType("Type 1");
    el2.setNom("Element 2");
    el2.setType("Type 2");
    myElements.push_back(el1);
    myElements.push_back(el2);
    // Repas
    Repas myRepas;
    myRepas.setNom("Repas 1");
    myRepas.setHeure(3);
    myRepas.setDescription("Description 1");
    myRepas.setElementsList(myElements);
    // Chat
    Chat tom;
    tom.setNom("Tom");
    tom.setGenre("male");
    tom.setAge(3);
    tom.setRepas(myRepas);
    tom.setType("blue");
    tom.sauter();
    // Chien
    Chien spike;
    spike.setNom("Spike");
    spike.setGenre("male");
    spike.setAge(5);
    spike.setTaille("4");
    list <Chien> chienList;
    chienList.push_back(spike);
    //entraineur
    Entraineur myEntraineur;
    myEntraineur.setNom("Johan");
    myEntraineur.setChienList(chienList);
    myEntraineur.setDescription("Excptional coach.");
    list <Entraineur> entraineurList;
    entraineurList.push_back(myEntraineur);
    spike.setEntraineurList(entraineurList);
    // compition
    Compitition firstCompitition;
    firstCompitition.setNom("LALIGA");
    firstCompitition.setDate("25/08/2021");
    firstCompitition.setChien(spike);
    firstCompitition.setEntraineur(myEntraineur);

    // affichage des information:

    cout << "==========Competition=======\n";
    cout << firstCompitition.getNom() << "\n";
    cout << firstCompitition.getDate() << "\n";
    cout << firstCompitition.getEntraineur().getNom() << "\n";
    cout << firstCompitition.getEntraineur().getDescription() << "\n";
    cout << firstCompitition.getChien().getNom() << "\n";


    list <Element>::iterator elementIterator;
    cout << "==========Iterator=======\n";
    elementIterator = myRepas.getElementsList().begin(); 
    cout << elementIterator->getNom() << "\n";
    cout << elementIterator->getType() << "\n";
    
    
    return 0;
}
