//
// Created by Marin Iulian on 10/28/2022.
//

#ifndef MAIN_CPP_MATCH_H
#define MAIN_CPP_MATCH_H
#include "team.h"
#include <cstdlib>
#include <ctime>
#include <string>

class match {
    team team1;
    team team2;
    int goluri_a=0;
    int goluri_b=0;
public:
    void meci();
    void set_team(team team1_,team team2_);
    void set_gol_a(int gol_a);
    void set_gol_b(int gol_b);
    std::string get_team1();
    std::string get_team2();
    match(team t1, team t2);
};


#endif //MAIN_CPP_MATCH_H
