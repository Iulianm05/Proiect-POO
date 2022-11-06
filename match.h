

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
    match();
    match(const team &team1, const team &team2);
    void meci();

    void set_gol_a(int gol_a);
    void set_gol_b(int gol_b);
    std::string get_team1();
    std::string get_team2();
};


#endif //MAIN_CPP_MATCH_H
