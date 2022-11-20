

#include "team.h"

team::team(){}
team::team(const std::string &name, int nr_goluri, int nr_players, const coach &coach1_, int puncte_) {
    this->name_team=name;
    this->nr_goluri=nr_goluri;
    this->nr_players=nr_players;
    this->coach1=coach1_;
    this->puncte=puncte_;
}
std::string team::get_name() {return this->name_team;}


std::ostream& operator<<(std::ostream& os, const team& team1){
    os<<"Nume echipa: "<<team1.name_team<<", numar jucatori "<<team1.nr_players<<", goluri marcate de echipa: "<<team1.nr_goluri<<", antrenor: "<<team1.coach1.get_name()<<std::endl;
    return os;
}
team::~team() {}

int team::getPuncte() const {
    return this->puncte;
}

void team::setPuncte(int puncte_)  {
    this->puncte = puncte_;
}

const std::string &team::getNameTeam() const {
    return name_team;
}



