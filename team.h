

#ifndef MAIN_CPP_TEAM_H
#define MAIN_CPP_TEAM_H
#include "coach.h"
#include <iostream>
//#include <string>

class team {

    std::string name_team;
    int nr_goluri;
    int nr_players;
    int puncte{};
    coach coach1;
public:
    team();
    ~team();
    explicit team(const std::string &name, int nr_goluri, int nr_players,const coach &coach1_, int puncte=0);
    std::string get_name();
    friend std::ostream& operator<<(std::ostream& os, const team& team1);

    int getPuncte() const;

    const std::string &getNameTeam() const;

    void setPuncte(int puncte_);


};


#endif //MAIN_CPP_TEAM_H
