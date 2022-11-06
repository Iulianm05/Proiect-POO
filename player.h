//
// Created by Marin Iulian on 10/26/2022.
//

#ifndef MAIN_CPP_PLAYER_H
#define MAIN_CPP_PLAYER_H
#include "atribute.h"
#include <iostream>


class player {
    std::string nume_player;
    int Overall;
    int goluri;
    std::string position;
    atribute atributes;
    int value=0;
public:
    player();
    player(std::string nume, int ovv, std::string position, atribute atributes);
    friend std::ostream& operator<<(std::ostream& os, const player& player1);
    int getGoluri() const;
    void setGoluri(int goluri);
    void calc_value();
    ~player();
};


#endif //MAIN_CPP_PLAYER_H
