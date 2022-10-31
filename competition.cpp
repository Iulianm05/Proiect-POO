
#include "competition.h"


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

team *competition::get_teams() {
    return this->teams;
}

void competition::adauga_echipe() {
    std::cout<<"Cate echipe doriti :"<<std::endl;
    int numar_echipe;
    std::cin>>numar_echipe;
    std::string nume;
    for(int i=0; i<numar_echipe;i++){

        std::cin>>nume;
        team t(nume,0,0);
        teams[i]=t;
    }
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


