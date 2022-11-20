

#ifndef MAIN_CPP_ATRIBUTE_H
#define MAIN_CPP_ATRIBUTE_H
#include <string>
#include <iostream>


class atribute {
    int attacking=0;
    int defending=0;
    int passing=0;
    int Strength=0;
    int dribling=0;
public:
    atribute();
    atribute(int a, int d, int p, int s, int drib);

    int getAttacking() const;

    int getDefending() const;

    int getPassing() const;

    int getStrength() const;

    int getDribling() const;

    friend std::ostream& operator<<(std::ostream& os, const atribute& atribute1);
    ~atribute();
};


#endif //MAIN_CPP_ATRIBUTE_H
