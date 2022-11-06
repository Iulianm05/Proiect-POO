//
// Created by Marin Iulian on 10/26/2022.
//

#include "team.h"

team::team(){}
team::team(const std::string &name, int nr_goluri, int nr_players, const coach &coach1_) {
    this->name_team=name;
    this->nr_goluri=nr_goluri;
    this->nr_players=nr_players;
    this->coach1=coach1_;
}
std::string team::get_name() {return this->name_team;}

void team::set_name(const std::string &nume) {
    this->name_team=nume;
}

std::ostream& operator<<(std::ostream& os, const team& team1){
    os<<"Nume echipa: "<<team1.name_team<<", numar jucatori "<<team1.nr_players<<", goluri marcate de echipa: "<<team1.nr_goluri<<", antrenor: "<<team1.coach1.get_name()<<std::endl;
    return os;
}
team::~team() {}