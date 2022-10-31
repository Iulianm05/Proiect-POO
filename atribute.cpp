//
// Created by Marin Iulian on 10/26/2022.
//

#include "atribute.h"

atribute::atribute() =default;
atribute::atribute(int a, int d, int p, int s, int drib) {
    this->attacking=a;
    this->dribling=drib;
    this->strenght=s;
    this->passing=p;
    this->defending=d;
    //std::cout<<"c attributes\n";
}
atribute::~atribute() {}
std::ostream& operator<<(std::ostream& os, const atribute& atribute1){
    os<<"Atac: "<<atribute1.attacking<<", dribling: "<<atribute1.dribling<<", strenght: "<<atribute1.strenght<<", defending: "<<atribute1.defending<<", pase: "<<atribute1.passing<<std::endl;
    return os;
}
