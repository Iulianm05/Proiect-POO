

#ifndef MAIN_CPP_PLAYER_H
#define MAIN_CPP_PLAYER_H
#include "atribute.h"
#include <iostream>
#include "atribute_impl.cpp"


class player {
    std::string nume_player{};
    int Overall=0;
    int goluri=0;
    int varsta{};
    const int id{};
    static int ID_max;
    std::string position{};
    atribute<int> atributes=atribute<int>();
    int value=0;
    friend class player_builder;
public:
    player()=default;
    const std::string &getNumePlayer() const;
    bool operator > (const player &other);
    //player();
    explicit player(const std::string &nume, int ovv, const std::string &position,int varsta=0,const atribute<int> &atributes=atribute<int>());
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

class player_builder{
private:
    player p;
public:
    player_builder()=default;
    player_builder& Nume_player(const std::string &nume){
        p.nume_player=nume;
        return *this;
    }
    player_builder& Overall(int overall){
        p.Overall=overall;
        return *this;
    }
    player_builder& goluri(int goluri){
        p.goluri=goluri;
        return *this;
    }
    player_builder& varsta(int varsta){
        p.varsta=varsta;
        return *this;
    }
    player_builder& position(const std::string &position){
        p.position=position;
        return *this;
    }
    player_builder& atribute(atribute <int> &atribute){
        p.atributes=atribute;
        return *this;
    }
    player build(){
        return p;
    }

};


#endif //MAIN_CPP_PLAYER_H
