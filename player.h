

#ifndef MAIN_CPP_PLAYER_H
#define MAIN_CPP_PLAYER_H
#include "atribute.h"
#include <iostream>


class player {
    std::string nume_player;
    int Overall=0;
    int goluri=0;
    int varsta{};
    std::string position;
    atribute atributes;
    int value=0;
public:
    player();
    player(const std::string &nume, int ovv, const std::string &position,int varsta=0,const atribute &atributes=atribute());
    friend std::ostream& operator<<(std::ostream& os, const player& player1);
    int getGoluri() const;
    void setGoluri(int goluri);
    void calc_value();

    int getOverall() const;

    ~player();
};


#endif //MAIN_CPP_PLAYER_H
