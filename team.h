

#ifndef MAIN_CPP_TEAM_H
#define MAIN_CPP_TEAM_H
#include "coach.h"
#include <iostream>
//#include <string>

class team {

    std::string name_team;
    int nr_goluri;
    int nr_players;
    //competition campionat;
    coach coach1;
public:
    team();
    ~team();
    team(const std::string &name, int nr_goluri, int nr_players,const coach &coach1_);
    std::string get_name();
    friend std::ostream& operator<<(std::ostream& os, const team& team1);

};


#endif //MAIN_CPP_TEAM_H
