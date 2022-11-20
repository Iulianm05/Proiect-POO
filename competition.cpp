

#include "competition.h"


competition::competition() {
    //std::cout<<"constructor competitie fara param\n";
}
competition::competition(const competition &other_competition) {
    this->country=other_competition.country;
    this->com_name=other_competition.com_name;
    //this->teams=other_competition.teams;
    //std::cout<<"cc competition\n";
}
competition::competition(const std::string &com_name, const std::string &country) {
    this->com_name=com_name;
    this->country=country;
    //std::cout<<"c competitie\n";
    // }
}


void competition::adauga_echipe(std::vector<team> t) {
    for(auto t1:t){
        teams.push_back(t1);
    }
}
void competition::adauga_echipe() {
    std::ifstream fin("tastatura.txt");
    if(!fin){
        std::cout<<"Nu se poate deschide fisierul!\n";
    }

    std::string nume_echipa;
    int nr_jucatori;
    int goluri;
    std::string nume_antrenor;
    while(fin>>nume_echipa>>nr_jucatori>>goluri>>nume_antrenor){
        teams.push_back(team{nume_echipa,goluri,nr_jucatori,coach(nume_antrenor),0});
    }
}
competition &competition::operator=(const competition &other_competition) {
    this->com_name=other_competition.com_name;
    this->country=other_competition.country;
    //std::cout<<"operator = "<<com_name<<"\n";
    return *this;

}
std::ostream& operator<<(std::ostream& os, const competition& cmp){
    os<<"Numele competitiei: "<<cmp.com_name<<", tara: "<<cmp.country<<" si numarul de echipe din campionat: "<<cmp.teams.size()<<std::endl<<"Echipele:"<<std::endl;
    for(size_t i=0;i<cmp.teams.size();i++) {
        std::cout<<cmp.teams[i];
    }
    return os;
}

const std::string &competition::getComName() const {
    return com_name;
}

 std::vector<team> &competition::getTeams() {
    return teams;
}


