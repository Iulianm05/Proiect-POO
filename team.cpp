

#include "team.h"

team::team(){}
team::team(const std::string &name, int nr_goluri, const coach &coach1_,std::vector<player> players_, int puncte_, int buget_transferuri_) {
    this->name_team=name;
    this->nr_goluri=nr_goluri;
    this->coach1=coach1_;
    this->players=players_;
    this->puncte=puncte_;
    this->buget_transferuri=buget_transferuri_;
    this->rating=calculeaza_rating();
}

int team::calculeaza_rating() {
    double total=0;
    for (size_t i=0; i<this->players.size();i++)
    {
        total=total+this->players[i].getOverall();

    }
    return static_cast<int>(total/this->players.size());
}
std::string team::get_name() {return this->name_team;}


std::ostream& operator<<(std::ostream& os, const team& team1){
    os<<"Nume echipa: "<<team1.name_team<<", numar jucatori "<<team1.players.size()<<", goluri marcate de echipa: "<<team1.nr_goluri<<", antrenor: "<<team1.coach1.get_name()<<std::endl;
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

int team::getRating() const {
    return rating;
}



