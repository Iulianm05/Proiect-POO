

#ifndef MAIN_CPP_MATCH_H
#define MAIN_CPP_MATCH_H
#include "team.h"
#include "exceptions.h"
#include <cstdlib>
#include <ctime>
#include <string>
#include <ostream>

class match {


    team home_team{};
    team away_team{};
    int home_goals=0;
    int away_goals=0;
    void marcare_gol(team &home, int i);
public:
    match();
    explicit match(const team &home_team, const team &away_team);

    //void setHome_team(const team &home_team);

    //void setAway_team(const team &away_team);

    const team &getHome_team() const;

    const team &getAway_team() const;
    void set_gol_h(int gol_h);
    void set_gol_a(int gol_a);
    int getAwayGoals() const;

    int getHomeGoals() const;

    friend std::ostream &operator<<(std::ostream &os, const match &match_);

    friend void meci( team &home_team_, team &away_team_,match &meci_);

};


#endif //MAIN_CPP_MATCH_H
