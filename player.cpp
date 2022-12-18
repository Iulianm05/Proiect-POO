
#include <iostream>
#include "player.h"

player::player() = default;
int player::ID_max=0;
player::player(const std::string &nume, int ovv, const std::string &position,int varsta, const atribute &atributes_){
    this->nume_player=nume;
    this->Overall=ovv;
    this->position=position;
    this->varsta=varsta;
    this->atributes=atributes_;
    id=++ID_max;
}

void player::calc_value() {
     this->value=this->Overall*this->Overall*1000;
}
std::ostream& operator<<(std::ostream& os, const player& player1){
    os<<"Nume player: "<<player1.nume_player<<", overall: "<<player1.Overall<<", pozitie: "<<player1.position<<", valoare: "<<player1.value<<"$"<<std::endl;
    os<<"Atributele jucatorului sunt: "<<std::endl<<
                                        "Atacking: "<<
                                        player1.atributes.getAttacking()<<std::endl<<
                                        "Defending:"<<
                                        player1.atributes.getDefending()<<std::endl<<
                                        "Strength: "<<
                                        player1.atributes.getStrength()<<std::endl<<
                                        "Passing: "<<
                                        player1.atributes.getPassing()<<std::endl<<
                                        "Dribling: "<<
                                        player1.atributes.getDribling()<<std::endl;
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

int player::getOverall() const {
    return Overall;
}

const std::string &player::getNumePlayer() const {
    return nume_player;
}

int player::getID_max() {
    return ID_max;
}

int player::getId() const {
    return id;
}

