#include <iostream>
#include <string>
using namespace std;


// Базовый класс Burger
class Burger {
protected:
    int carb, 
    fats, protein, 
    callories;
public:
    Burger() {
        carb = 700;
        fats = 500;
        protein = 20;
        callories = 1000;
    }
    virtual int get_Сarb() {
        return carb;
    }
    virtual int get_Fats() {
        return fats;
    }
    virtual int get_Callories() {
        return callories;
    }
    virtual int get_Protein() {
        return protein;
    }
    void get_Result() {
        cout << "Углеводы: " << this -> get_Сarb() << endl
            << "Жиры: " << this -> get_Fats() << endl
            << "Белки: "<<this -> get_Protein() << endl
            << "Каллории: " << this -> get_Callories() << endl
            << "----------" << endl;
    }

};


// Класс bread, наследующийся от Burger
class bread :public Burger {
protected:
    Burger* burger;
public:
    bread(Burger* b) {
        burger = b;
        carb = 20;
        protein = 5;
    }
    int getСarb() {
        return carb + burger->get_Сarb();
    }
    int getProtein() {
        return  protein + burger->get_Protein();;
    }
    int getFats() {
        return burger->get_Fats();
    }
    int getCallories() {
        return burger->get_Callories();
    }
};


// Класс cutlet, наследующийся от Burger
class cutlet :public Burger {
protected:
    Burger* burger;
public:
    cutlet(Burger* b) {
        burger = b;
        protein = 25;
        callories = -5;
    }
    int getCallories() {
        return callories + burger -> get_Callories();
    }
    int getProtein() {
        return  protein + burger -> get_Protein();
    }
    int getFats() {
        return burger -> get_Fats();
    }
    int getСarb() {
        return burger -> get_Сarb();
    }
};


// Класс cheese, наследующийся от Burger
class cheese :public Burger {
protected:
    Burger* burger;
public:
    cheese(Burger* b) {
        burger = b;
        fats = 30;
        callories = 5;
    }
    int getCallories() {
        return callories + burger -> get_Callories();
    }
    int getFats() {
        return  fats + burger -> get_Fats();
    }
    int getСarb() {
        return burger -> get_Сarb();
    }
    int getProtein() {
        return burger -> get_Protein();
    }
};


// Класс sauce, наследующийся от Burger
class sauce :public Burger {
protected:
    Burger* burger;
public:
    sauce(Burger* b) {
        burger = b;
        callories = 20;
        carb = 5;
    }
    int getCallories() {
        return callories + burger -> get_Callories();
    }
    int getСarb() {
        return  carb + burger -> get_Сarb();;
    }
    int getProtein() {
        return burger -> get_Protein();
    }
    int getFats() {
        return  burger -> get_Fats();
    }
};


int main()
{
    setlocale(LC_ALL, "ru");
    Burger* c = new Burger;
    
    c = new bread(c);
    c->get_Result();

    c = new sauce(c);
    c->get_Result();
    
    c = new cheese(c);
    c->get_Result();
    
    c = new cutlet(c);
    c->get_Result();
    return 0;
}