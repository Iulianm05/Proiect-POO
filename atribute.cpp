//
// Created by Marin Iulian on 10/26/2022.
//

#include "atribute.h"

atribute::atribute() =default;
atribute::atribute(int a, int d, int p, int s, int drib): attacking(a),defending(d),passing(p),Strength(s),dribling(drib){

    //std::cout<<"c attributes\n";
}
atribute::~atribute()=default;
std::ostream& operator<<(std::ostream& os, const atribute& atribute1){
    os<<"Atac: "<<atribute1.attacking<<", dribling: "<<atribute1.dribling<<", Strength: "<<atribute1.Strength<<", defending: "<<atribute1.defending<<", pase: "<<atribute1.passing<<std::endl;
    return os;
}

int atribute::getAttacking() const {
    return attacking;
}

int atribute::getDefending() const {
    return defending;
}

int atribute::getPassing() const {
    return passing;
}

int atribute::getStrength() const {
    return Strength;
}

int atribute::getDribling() const {
    return dribling;
}
