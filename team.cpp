

#include "team.h"

team::team(){}
team::team(const std::string &name,  std::shared_ptr<coach> coach1_,const std::vector<player> &players_, int puncte_, int buget_transferuri_) {
    this->name_team=name;
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
    os<<"Nume echipa: "<<team1.name_team<<", numar jucatori "<<team1.players.size()<<", goluri marcate de echipa: "<<team1.nr_goluri<<", antrenor: "<<team1.coach1->get_name()<<std::endl;
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

 std::vector<player> &team::getPlayers() {
    return players;
}

const std::shared_ptr<coach> &team::getCoach1() const {
    return coach1;
}

void team::setNrGoluri(int nrGoluri) {
    nr_goluri = nrGoluri;
}

int team::getNrGoluri() const {
    return nr_goluri;
}

bool team::operator>(const team& other) {
    if(puncte>other.puncte)
        return true;
    else return false;
}

//team::team(const team &other)=default;



