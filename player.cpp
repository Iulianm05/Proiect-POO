//
// Created by Marin Iulian on 10/26/2022.
//
#include <iostream>
#include "player.h"

player::player() = default;
player::player(std::string nume, int ovv, std::string position, atribute atributes_):atributes{atributes_}{
    this->nume_player=nume;
    this->Overall=ovv;
    this->position=position;
    // std::cout<<"c player\n";


//    this->attacking=a;
//    this->dribling=drib;
//    this->strenght=s;
//    this->passing=p;
//    this->defending=d;
}

std::ostream& operator<<(std::ostream& os, const player& player1){
    os<<"Nume player: "<<player1.nume_player<<", overall: "<<player1.Overall<<", pozitie: "<<player1.position<<std::endl;
    return os;
}
player::~player() {
    //std::cout<<"dest player\n";
}