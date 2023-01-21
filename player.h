

#ifndef MAIN_CPP_PLAYER_H
#define MAIN_CPP_PLAYER_H
#include "atribute.h"
#include <iostream>


class player {
    std::string nume_player{};
    int Overall=0;
    int goluri=0;
    int varsta{};
    const int id{};
    static int ID_max;
    std::string position{};
    atribute atributes=atribute();
    int value=0;
public:
    const std::string &getNumePlayer() const;
    bool operator > (const player &other);
    //player();
    explicit player(const std::string &nume, int ovv, const std::string &position,int varsta=0,const atribute &atributes=atribute());
    player (const player &other);
    player& operator=(player other);
    friend std::ostream& operator<<(std::ostream& os, const player& player1);
    int getGoluri() const;
    void setGoluri(int goluri_);
    void calc_value();

    static int getID_max();

    int getOverall() const;

    int getId() const;

    ~player();
};


#endif //MAIN_CPP_PLAYER_H
