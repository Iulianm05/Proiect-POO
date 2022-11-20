#include <iostream>
#include <string>
#include <algorithm>
#include "coach.h"
#include "player.h"
#include "atribute.h"
#include "competition.h"
#include "team.h"
#include "match.h"
//void meci(team &home_team_, team &away_team_, match &meci_);
bool comparator(const team &a, const team &b) {
    return a.getPuncte()>b.getPuncte();
}
int main() {
    srand(time(NULL));
    atribute at(90,72,90,80,99);
    player p1("Lionel Messi",92, "Left Winger",36,at);
    p1.calc_value();
    competition c1("Premier League","England");
    coach antrenor1("Nicolae Dica","posesie",43);
    coach antrenor2("Jurgen Klopp","atac",55);
    coach antrenor3("Pep Guardiola","atac",55);
    team t("Liverpool",100, 32,antrenor2,0);
    team t2("Manchester City",0,30,antrenor3,0);
    team t3("Manchester United", 88,30,antrenor1,0);
    std::vector<team> echipe;
    echipe.push_back(t);
    echipe.push_back(t2);
    echipe.push_back(t3);
    c1.adauga_echipe(echipe);
    competition c2;

    coach c("Nicolae Dica","posesie",43);

    c2=c1;
    competition c3("Premier League","");
    c3.adauga_echipe();
    std::cout<<"Nume competite c2:"<<c2.getComName()<<std::endl;
    std::cout<<"==================="<<std::endl;
    std::cout<<p1.getGoluri();
    std::cout<<"==================="<<std::endl;
    p1.setGoluri(130);
    std::cout<<p1.getGoluri()<<std::endl;
    std::cout<<c1;
    std::cout<<"==================="<<std::endl;
    std::cout<<p1;
    std::cout<<"==================="<<std::endl;
    std::cout<<at;
    std::cout<<t;
    std::cout<<"==================="<<std::endl;
    std::cout<<c;
    std::cout<<"===================="<<std::endl;
    std::cout<<c3;
    int contor=0;
    std::vector <match> meciuri;
    for(size_t i=0; i<c3.getTeams().size()-1;i++)
        for(size_t j=i+1;j<c3.getTeams().size();j++){
            meciuri.push_back(match(c3.getTeams()[i],c3.getTeams()[j]));
            meci(c3.getTeams()[i],c3.getTeams()[j],meciuri[contor]);
            contor++;

        }
    for(int i=0; i<contor; i++){
        std::cout<<meciuri[i];
    }

    sort(c3.getTeams().begin(),c3.getTeams().end(),&comparator);
    std::cout<<"==============================\n";
    std::cout<<"CLASAMENT\n";
    std::cout<<"==============================\n";
    for(size_t i=0;i<c3.getTeams().size();i++){
        std::cout<<c3.getTeams()[i].getNameTeam()<<" are :"<<c3.getTeams()[i].getPuncte()<<" puncte\n";
    }

    return 0;
}
