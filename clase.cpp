//
#include "clase.h"
#include <string>
#include <iostream>


competition::competition() {
    //std::cout<<"constructor competitie fara param\n";
}
competition::competition(const competition &other_competition) {
    this->country=other_competition.country;
    this->com_name=other_competition.com_name;
    this->nr_teams=other_competition.nr_teams;
    //this->teams=other_competition.teams;
    //std::cout<<"cc competition\n";
}
competition::competition(const std::string com_name, const std::string country, int nr_teams) {
    this->com_name=com_name;
    this->country=country;
    this->nr_teams=nr_teams;
    // teams=new std::vector<team>(nr_teams);
//    for(int i=0; i<nr_teams; i++){
//        std::string a;
//        std::cin>>a;

    //std::cout<<"c competitie\n";
    // }
}
competition &competition::operator=(const competition &other_competition) {
    this->com_name=other_competition.com_name;
    this->country=other_competition.country;
    this->nr_teams=other_competition.nr_teams;
    //std::cout<<"operator = "<<com_name<<"\n";
    return *this;

}
std::ostream& operator<<(std::ostream& os, const competition& cmp){
    os<<"Numele competitiei: "<<cmp.com_name<<", tara: "<<cmp.country<<" si numarul de echipe din campionat: "<<cmp.nr_teams<<std::endl;
    return os;
}
competition::~competition() {
    //std::cout<<"destructor competitie\n";
}



coach::coach(){}
coach::coach(const std::string coachName_, const std::string style_, int age_): coach_name{coachName_}, style{style_}, age{age_} {

}
std::ostream& operator<<(std::ostream& os, const coach& coach1){
    os<<"Numele antrenorului "<<coach1.coach_name<<", varsta :"<<coach1.age<<", stil de joc: "<<coach1.style<<std::endl;
    return os;
}



team::team(){}
team::team(const std::string name, int nr_goluri, int nr_players) {
    this->name_team=name;
    this->nr_goluri=nr_goluri;
    this->nr_players=nr_players;
}
std::string team::get_name() {return this->name_team;}

void team::set_name(const std::string &nume) {
    this->name_team=nume;
}

std::ostream& operator<<(std::ostream& os, const team& team1){
    os<<"Nume echipa: "<<team1.name_team<<", numar jucatori "<<team1.nr_players<<", goluri marcate de echipa: "<<team1.nr_goluri<<std::endl;
    return os;
}
team::~team() {
    //std::cout<<"destructor team:"<<name_team<<std::endl;
}


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









