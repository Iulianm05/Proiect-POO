

#include "Menu.h"

template<typename T>
bool comparator( T &a, T &b) {
    return a>b;
}

Menu &Menu::get_Menu() {
    static Menu Meniu;
    return Meniu;
}

void Menu::optiuni() {
    std::cout<<"Daca doriti sa afisati informatiile echipelor din campionat tastati tasta 1.\n";
    std::cout<<"Daca doriti sa simulati meciurile din campionat apasati tasta 2.\n";
    std::cout<<"Daca doriti sa iesiti din aplicatie apasati tasta 0.\n";
}

void Menu::optiune_1() {
    std::cout<<campionat;
    abilitati_antrenori();
}

void Menu::optiune_2(){
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
    fin>>decizie;
    if(decizie==1){
        afisare_meciuri(meciuri,contor);
    }
    else
    if(decizie==2){
        afisare_clasament();
        std::cout<<"Doriti sa afisati jucatorii echipelor si golurile date de acestia in meciurile simulate? 3(Da)\n";
        std::cout<<"Doriti sa afisati topul marcatorilor ? 4(Da)\n";
        fin>>decizie;
        if(decizie==3){
            afisare_jucatori();
        }
        else
        if(decizie==4){
            afisare_total_jucatori();
        }

    }
    else std::cout<<"Tasta invalida!\n";
}

void Menu::rulare(){
    int tasta=3;
    while(tasta!=0){
        if(tasta==3)
            optiuni();
        fin>>tasta;
        try{
            if(tasta==1){
                optiune_1();
                continuare(tasta);

            }
            else
            if(tasta==2){
                optiune_2();
                continuare(tasta);
            }else{
                if(tasta==0)
                    break;
                else
                    std::cout<<"Tasta invalida \n";
            }
        }catch(eroare_competitie &err){
            std::cout<<err.what()<<std::endl;
        }
        catch(eroare_meci &err){
            std::cout<<err.what()<<std::endl;
        }
}
}

void Menu::abilitati_antrenori() {
    for(size_t i=0; i<campionat.getTeams().size(); i++) {
        auto co = std::dynamic_pointer_cast<offensive_coach>(campionat.getTeams()[i].getCoach1());
        if (co != nullptr) {
            std::cout << "Nume: " << co->get_name() << " abilitate ofensiva: " << co->getAbilitateOfensiva() << "\n";

        }
    }
}

void Menu::afisare_total_jucatori() {
    std::vector<player> jucatori;
    for(size_t i = 0; i<campionat.getTeams().size();i++){
        for(size_t j = 0; j<campionat.getTeams()[i].getPlayers().size();j++)
            jucatori.push_back(campionat.getTeams()[i].getPlayers()[j]);
        sort(jucatori.begin(),jucatori.end(), comparator<player>);
    }
    std::cout<<"In total sunt "<<player::getID_max()<<" jucatori.\n";
    for(size_t i = 0; i<jucatori.size();i++){
        std::cout<<jucatori[i].getNumePlayer()<<" are "<<jucatori[i].getGoluri()<<" goluri \n";
    }
}

void Menu::afisare_clasament() {
    sort(campionat.getTeams().begin(),campionat.getTeams().end(), &comparator<team>);
    std::cout<<"\n======Clasament======\n";
    for(size_t i=0;i<campionat.getTeams().size();i++){
        std::cout<<i+1<<"."<<campionat.getTeams()[i].getNameTeam()<<" are :"<<campionat.getTeams()[i].getPuncte()<<" puncte\n";
    }
}

void Menu::afisare_meciuri(const std::vector<match> &meciuri, int contor) {
    for(int i=0; i<contor; i++)
        std::cout<<meciuri[i];
}

void Menu::afisare_jucatori() {
    for(size_t i = 0; i<campionat.getTeams().size();i++){
        std::cout<<"\nMARCATORI "<<campionat.getTeams()[i].getNameTeam()<<": \n\n";
        for(size_t j = 0; j<campionat.getTeams()[i].getPlayers().size();j++)
            std::cout<<campionat.getTeams()[i].getPlayers()[j].getId()<<". "<<campionat.getTeams()[i].getPlayers()[j].getNumePlayer()<<" a marcat "<<campionat.getTeams()[i].getPlayers()[j].getGoluri()<<" goluri\n";
    }
}

void Menu::continuare(int &tasta) {
    std::cout<<"Pentru iesire folositi tasta 0, iar pentru a reveni la meniu apasati 3\n";
    fin>>tasta;
    if(tasta!=0 && tasta!=3){
        std::cout<<"Tasta invalida!\n";
        tasta=0;
    }
}
