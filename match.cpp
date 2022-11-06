//
// Created by Marin Iulian on 10/28/2022.
//

#include "match.h"

match::match()=default;

void match::set_team(const team &team_, const team &team2_) {
    team1=team_;
    team2=team2_;
}

std::string match::get_team1() {
    return this->team1.get_name();
}
std::string match::get_team2() {
    return this->team2.get_name();
}

void match::set_gol_a(int gol_a) {
    this->goluri_a=gol_a;
}
void match::set_gol_b(int gol_b) {
    this->goluri_b=gol_b;
}
//functie ce simuleaza scorul unui meci
void match::meci() {
    srand(time(NULL));
    int rand_gol1=rand()%10;
    set_gol_a(rand_gol1);
    int rand_gol2=rand()%10;
    set_gol_b(rand_gol2);
    std::cout<<"Meciul dintre "<<get_team1()<<" si "<<get_team2()<<" s-a terminat cu scorul de "<<rand_gol1<<" : "<<rand_gol2<<std::endl;

}

match::match(const team &team1, const team &team2) : team1(team1), team2(team2) {}
