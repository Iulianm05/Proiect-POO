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


match::match(const team &home_team_, const team &away_team_) : home_team(home_team_), away_team(away_team_) {
    if(home_team.getNameTeam() == away_team.getNameTeam()){
        throw(eroare_meci{"Echipa "+home_team.getNameTeam()+" nu poate juca impotriva ei!" });
    }
}

const team &match::getHome_team() const {
    return home_team;
}

const team &match::getAway_team() const {
    return away_team;
}

//void match::setHome_team(const team &home_team_) {
//    match::home_team = home_team_;
//}

//void match::setAway_team(const team &away_team_) {
//    match::away_team = away_team_;
//}

std::ostream &operator<<(std::ostream &os, const match &match_) {
    os << "home_team: " << match_.home_team.getNameTeam() << " away_team: " << match_.away_team.getNameTeam() << " home_goals: " << match_.home_goals
       << " away_goals: " << match_.away_goals<<std::endl;
    return os;
}

void meci(team &home_team_, team &away_team_, match &meci_) {
    int goal_home_team=25; //probabilitate de a marca gol echipa in timpul unei ocazii
    int goal_away_team=25;
    int draw=50;
    int ATT=60;
    int MID=30;
    //daca diferenta de rating dintre echipe este mai mica decat 10 atunci probabilitatea de a marca a echipei cu raatingul mai mare va creste cu 2*diferenta iar restul vor scadea cu diferenta
    //altfel probabilitatea de a marca a echipei cu ratingul mai mare va creste cu 20
    //daca rating-urile sunt egale atunci prob. de a nu se marca gol la o anumita faza creste cu +4

    if(home_team_.getRating()>away_team_.getRating()){
        int diff=home_team_.getRating()-away_team_.getRating();
        goal_home_team=goal_home_team+2*diff;
        goal_away_team=goal_away_team-diff;
        draw=draw-diff;
    }else if(home_team_.getRating()<away_team_.getRating()){
        int diff=away_team_.getRating()-home_team_.getRating();
        goal_home_team=goal_home_team-diff;
        goal_away_team=goal_away_team+2*diff;
        draw=draw-diff;
    }
    else{
        draw=draw+4;
        goal_home_team=goal_home_team-2;
        goal_away_team=goal_away_team-2;
    }

    //Daca antrenorul unei echipe este unul ofensiv atunci aceasta va primi o crestere a prob de a marca cu +4, si numarul ocaziilor va creste cu +2;
    //Daca antrenorul este unul defensiv, atunci aceasta va primi o crestere a prob de a marca cu +1, a prob de draw +4 si numarul ocaziilor va scadea cu -2;
    //initial meciul va avea 10 ocazii
    int ocazii=10;
    home_team_.getCoach1()->boost_echipa(goal_home_team,draw,goal_away_team,ocazii);
    away_team_.getCoach1()->boost_echipa(goal_away_team,draw,goal_home_team,ocazii);

    for(int i=1;i<=ocazii;i++)
    {
        int rand_number=rand()%100+1;
        if(rand_number<=goal_home_team) {
            meci_.set_gol_h(meci_.getHomeGoals() + 1);
            int rand_player=rand()%100+1;
            int indice;
            if(rand_player<=ATT){
                indice=0;
                meci_.marcare_gol(home_team_,indice);
            }else if(rand_player>ATT && rand_player<=ATT+MID){
                    indice=3;
                    meci_.marcare_gol(home_team_,indice);
            }
            else {
                const int p1=25;
                const int p2=25;
                const int p3=25;
                int rp=rand()%100+1;
                if(rp<=p1)
                    home_team_.getPlayers()[6].setGoluri(home_team_.getPlayers()[6].getGoluri()+1);
                else if(rp>p1 && rp<=p1+p2){
                    home_team_.getPlayers()[7].setGoluri(home_team_.getPlayers()[7].getGoluri()+1);
                }
                else if (rp > p1 + p2 && rp <= p1 + p2 + p3) {
                    home_team_.getPlayers()[8].setGoluri(home_team_.getPlayers()[8].getGoluri() + 1);
                } else home_team_.getPlayers()[9].setGoluri(home_team_.getPlayers()[9].getGoluri() + 1);
            }

        }
        else if(rand_number>goal_home_team+draw){
            meci_.set_gol_a(meci_.getAwayGoals()+1);
            int rand_player=rand()%100+1;
            int indice;
            if(rand_player<=ATT){
                indice=0;
                meci_.marcare_gol(away_team_,indice);
            }else if(rand_player>ATT && rand_player<=ATT+MID){
                indice=3;
                meci_.marcare_gol(away_team_,indice);
            }
            else {
                const int p1=25;
                const int p2=25;
                const int p3=25;
                int rp=rand()%100+1;
                if(rp<=p1)
                    away_team_.getPlayers()[6].setGoluri(away_team_.getPlayers()[6].getGoluri()+1);
                else if(rp>p1 && rp<=p1+p2){
                    away_team_.getPlayers()[7].setGoluri(away_team_.getPlayers()[7].getGoluri()+1);
                }
                else if (rp > p1 + p2 && rp <= p1 + p2 + p3) {
                    away_team_.getPlayers()[8].setGoluri(away_team_.getPlayers()[8].getGoluri() + 1);
                } else away_team_.getPlayers()[9].setGoluri(away_team_.getPlayers()[9].getGoluri() + 1);
            }

        }

    }
    home_team_.setNrGoluri(home_team_.getNrGoluri()+meci_.getHomeGoals());
    away_team_.setNrGoluri(away_team_.getNrGoluri()+meci_.getAwayGoals());
    std::cout<<"Prob: \n"<<"1: "<<goal_home_team<<" x: "<<draw<<" 2:"<<goal_away_team<<std::endl;
    if(meci_.getHomeGoals()>meci_.getAwayGoals())
    {
        int x=home_team_.getPuncte()+3;
        home_team_.setPuncte(x);

    }

    else if(meci_.getHomeGoals()==meci_.getAwayGoals()) {
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
    //std::cout<<meci_;
}

int match::getHomeGoals() const {
    return home_goals;
}

int match::getAwayGoals() const {
    return away_goals;
}

void match::marcare_gol(team &home, int i) {
    const int p1=33;
    const int p2=33;
    int rp=rand()%99+1;
    if(rp<=p1)
        home.getPlayers()[i].setGoluri(home.getPlayers()[i].getGoluri()+1);
    else if(rp>p1 && rp<=p1+p2){
        home.getPlayers()[i+1].setGoluri(home.getPlayers()[i+1].getGoluri()+1);
    }
    else home.getPlayers()[i+2].setGoluri(home.getPlayers()[i+2].getGoluri()+1);
}


