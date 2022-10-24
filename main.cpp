#include <iostream>
#include "clase.h"

int main() {
    atribute at(90,72,90,80,99);
    player p1("Lionel Messi",92, "Left Winger",at );
    competition c1("Premier League","England",20);
    team t("Barcelona",100, 32);
    competition c2;
    coach c("Nicolae Dica","posesie",43);
    c2=c1;
    std::cout<<c1;
    std::cout<<p1;
    std::cout<<at;
    std::cout<<t;
    std::cout<<c;
    return 0;}
