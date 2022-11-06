#include <iostream>
#include <string>

#include "coach.h"
#include "player.h"
#include "atribute.h"
#include "competition.h"
#include "team.h"
#include "match.h"

int main() {
    atribute at(90,72,90,80,99);
    player p1("Lionel Messi",92, "Left Winger",at );
    competition c1("Premier League","England",3);
    team t("Arsenal",100, 32);
    team t2("Manchester City",0,30);
    team t3("Manchester United", 88,30);
    std::vector<team> echipe;
    echipe.push_back(t);
    echipe.push_back(t2);
    echipe.push_back(t3);
    c1.adauga_echipe(echipe);
    competition c2;

    coach c("Nicolae Dica","posesie",43);
    c2=c1;
    std::cout<<c1;
    std::cout<<p1;
    std::cout<<at;
    std::cout<<t;
    std::cout<<c;
    match meci1(t,t2);
    meci1.meci();
    return 0;
}
