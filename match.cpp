//
// Created by Marin Iulian on 10/28/2022.
//

#include "match.h"

match::match()=default;


std::string match::get_home_team_name() {
    return this->home_team.get_name();
}
std::string match::get_away_team_name() {
    return this->away_team.get_name();
}

void match::set_gol_h(int gol_h) {
    this->home_goals=gol_h;
}
void match::set_gol_a(int gol_a) {
    this->away_goals=gol_a;
}
//functie ce simuleaza scorul unui meci


match::match(const team &home_team, const team &away_team) : home_team(home_team), away_team(away_team) {}

const team &match::getHome_team() const {
    return home_team;
}

const team &match::getAway_team() const {
    return away_team;
}

void match::setHome_team(const team &home_team_) {
    match::home_team = home_team_;
}

void match::setAway_team(const team &away_team_) {
    match::away_team = away_team_;
}

std::ostream &operator<<(std::ostream &os, const match &match_) {
    os << "home_team: " << match_.home_team.getNameTeam() << " away_team: " << match_.away_team.getNameTeam() << " home_goals: " << match_.home_goals
       << " away_goals: " << match_.away_goals<<std::endl;
    return os;
}

void meci(team &home_team_, team &away_team_, match &meci_) {
    int rand_gol1=rand()%10;
    int rand_gol2=rand()%10;
    meci_.set_gol_a(rand_gol2);
    meci_.set_gol_h(rand_gol1);
    //std::cout<<"Meciul dintre "<<meci_.get_home_team_name()<<" si "<<meci_.get_away_team_name()<<" s-a terminat cu scorul de "<<rand_gol1<<" : "<<rand_gol2<<std::endl;
    if(rand_gol1>rand_gol2)
    {
        int x=home_team_.getPuncte()+3;
        home_team_.setPuncte(x);

    }

    else if(rand_gol1==rand_gol2) {
        int x=home_team_.getPuncte()+1;
        int y=away_team_.getPuncte() + 1;
        home_team_.setPuncte(x);
        away_team_.setPuncte(y);

    }
    else
    {
        int x=away_team_.getPuncte()+3;
        away_team_.setPuncte(x);
    }
}
