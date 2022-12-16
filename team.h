

#ifndef MAIN_CPP_TEAM_H
#define MAIN_CPP_TEAM_H
#include "coach.h"
#include "player.h"
#include <iostream>
#include <vector>
#include <string>

class team {

    std::string name_team{};
    int nr_goluri{};
    std::vector<player> players;
    int puncte{};
public:
    void setNrGoluri(int nrGoluri);

private:
    int buget_transferuri{};
    int rating;
public:
    int getRating() const;

private:
    std::shared_ptr<coach> coach1;
    int calculeaza_rating();
public:
    team();
    ~team();
    explicit team(const std::string &name,const std::shared_ptr<coach> coach1_,std::vector<player> players_, int puncte=0,int buget_transferuri_=0);
    std::string get_name();
    friend std::ostream& operator<<(std::ostream& os, const team& team1);
    int getPuncte() const;
    //team(const team &other);
    const std::string &getNameTeam() const;

    std::vector<player> &getPlayers();

    const std::shared_ptr<coach> &getCoach1() const;

    void setPuncte(int puncte_);

    int getNrGoluri() const;


};


#endif //MAIN_CPP_TEAM_H
