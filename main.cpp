#include <iostream>
#include <string>
#include <algorithm>
#include "coach.h"
#include "player.h"
#include "atribute.h"
#include "competition.h"
#include "team.h"
#include "match.h"
#include "offensive_coach.h"
#include "defensive_coach.h"



bool comparator(const team &a, const team &b) {
    return a.getPuncte()>b.getPuncte();
}
bool comparator_jucatori(const player &a, const player &b) {
    return a.getGoluri()>b.getGoluri();
}

void meniu(){
    std::cout<<"Daca doriti sa afisati informatiile echipelor din campionat tastati tasta 1.\n";
    std::cout<<"Daca doriti sa simulati meciurile din campionat apasati tasta 2.\n";
    std::cout<<"Daca doriti sa iesiti din aplicatie apasati tasta 0.\n";
}
void afisare_meciuri(const std::vector<match> &meciuri,int contor){
    for(int i=0; i<contor; i++)
        std::cout<<meciuri[i];
}
void afisare_clasament(competition &campionat){
    sort(campionat.getTeams().begin(),campionat.getTeams().end(), &comparator);
    std::cout<<"\n======Clasament======\n";
    for(size_t i=0;i<campionat.getTeams().size();i++){
        std::cout<<i+1<<"."<<campionat.getTeams()[i].getNameTeam()<<" are :"<<campionat.getTeams()[i].getPuncte()<<" puncte\n";
    }
}
void continuare(int &tasta){
    std::cout<<"Pentru iesire folositi tasta 0, iar pentru a reveni la meniu apasati 3\n";
    std::cin>>tasta;
}
void afisare_jucatori(competition &campionat){
    for(size_t i = 0; i<campionat.getTeams().size();i++){
        std::cout<<"\nMARCATORI "<<campionat.getTeams()[i].getNameTeam()<<": \n\n";
        for(size_t j = 0; j<campionat.getTeams()[i].getPlayers().size();j++)
            std::cout<<campionat.getTeams()[i].getPlayers()[j].getId()<<". "<<campionat.getTeams()[i].getPlayers()[j].getNumePlayer()<<" a marcat "<<campionat.getTeams()[i].getPlayers()[j].getGoluri()<<" goluri\n";
    }

}
void afisare_total_jucatori(competition &campionat) {
    std::vector<player> jucatori;
    for(size_t i = 0; i<campionat.getTeams().size();i++){
        for(size_t j = 0; j<campionat.getTeams()[i].getPlayers().size();j++)
            jucatori.push_back(campionat.getTeams()[i].getPlayers()[j]);
        sort(jucatori.begin(),jucatori.end(), &comparator_jucatori);
    }
    std::cout<<"In total sunt "<<player::getID_max()<<" jucatori.\n";
    for(size_t i = 0; i<jucatori.size();i++){
            std::cout<<jucatori[i].getNumePlayer()<<" are "<<jucatori[i].getGoluri()<<" goluri \n";
    }
}
void optiune_1(){
    competition campionat{"Premier League","Anglia"};
    std::cout<<campionat;
}
void optiune_2(){
    competition campionat{"Premier League","Anglia"};
    std::vector<match> meciuri;
    int contor=0;

        for (size_t i = 0; i < campionat.getTeams().size(); i++)
            for (size_t j = i + 1; j < campionat.getTeams().size(); j++) {
                meciuri.push_back(match(campionat.getTeams()[i], campionat.getTeams()[j]));
                meci(campionat.getTeams()[i], campionat.getTeams()[j], meciuri[contor++]);
            }
        for (size_t i = 0; i < campionat.getTeams().size(); i++)
            for (size_t j = i + 1; j < campionat.getTeams().size(); j++) {
                meciuri.push_back(match(campionat.getTeams()[j], campionat.getTeams()[i]));
                meci(campionat.getTeams()[j], campionat.getTeams()[i], meciuri[contor++]);
            }

    std::cout<<"Doriti sa afisati meciurile? 1(Da) \n";
    std::cout<<"Doriti sa afisati clasamentul? 2(Da)\n";
    int decizie=0;
    std::cin>>decizie;
    if(decizie==1){
        afisare_meciuri(meciuri,contor);
    }
    if(decizie==2){
        afisare_clasament(campionat);
        std::cout<<"Doriti sa afisati jucatorii echipelor si golurile date de acestia in meciurile simulate? 3(Da)\n";
        std::cout<<"Doriti sa afisati topul marcatorilor ? 4(Da)\n";
        std::cin>>decizie;
        if(decizie==3){
            afisare_jucatori(campionat);
        }
        if(decizie==4){
            afisare_total_jucatori(campionat);
        }

    }

}



int main() {
    srand(time(nullptr));
    int tasta=3;
    while(tasta!=0){
        if(tasta==3)
            meniu();
        std::cin>>tasta;
        try{
            if(tasta==1){
                optiune_1();
                continuare(tasta);

            }
            if(tasta==2){
                optiune_2();
                continuare(tasta);
            }
        }catch(eroare_competitie &err){
            std::cout<<err.what()<<std::endl;
        }
        catch(eroare_meci &err){
            std::cout<<err.what()<<std::endl;
        }

    }

    return 0;
}


