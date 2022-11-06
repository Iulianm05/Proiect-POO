//
// Created by Marin Iulian on 10/26/2022.
//
#include <iostream>
#include "player.h"

player::player() = default;
player::player(const std::string &nume, int ovv, const std::string &position, const atribute &atributes_){
    this->nume_player=nume;
    this->Overall=ovv;
    this->position=position;
    this->atributes=atributes_;
}

void player::calc_value() {
     this->value=this->Overall*this->Overall*1000;
}
std::ostream& operator<<(std::ostream& os, const player& player1){
    os<<"Nume player: "<<player1.nume_player<<", overall: "<<player1.Overall<<", pozitie: "<<player1.position<<", valoare: "<<player1.value<<"$"<<std::endl;
    return os;
}
player::~player() {
    //std::cout<<"dest player\n";
}

int player::getGoluri() const {
    return goluri;
}

void player::setGoluri(int goluri_) {
    player::goluri = goluri_;
}
