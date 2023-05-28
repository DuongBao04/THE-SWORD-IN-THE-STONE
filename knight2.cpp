#include "knight2.h"

//KNIGHT_ADVENTURE-------------------
KnightAdventure::KnightAdventure() {
    armyKnights = nullptr;
    events = nullptr;
}

void KnightAdventure::loadArmyKnights(const string& file) {
    armyKnights = new ArmyKnights(file);
}
void KnightAdventure::loadEvents(const string& file) {
    events = new Events(file);
}
void KnightAdventure::run() {

    bool win = 1;
    bool checkomega = 0;
    bool checkhades = 0;

    //armyKnights->printtuicuahiepsi();

    for (int i = 0; i < events->count(); i++) {
       
        //GapSuKien1toi5
        if (events->get(i) == 1){
            BaseOpponent* doithu = new Madbear(i,events->get(i));
            win = armyKnights->fight(doithu);
        }
        if (events->get(i) == 2) {
            BaseOpponent* doithu = new Bandit(i, events->get(i));
            win = armyKnights->fight(doithu);
        }
        if (events->get(i) == 3) {
            BaseOpponent* doithu = new LordLupin(i, events->get(i));
            win = armyKnights->fight(doithu);
        }
        if (events->get(i) == 4) {
            BaseOpponent* doithu = new Elf(i, events->get(i));
            win = armyKnights->fight(doithu);
        }
        if (events->get(i) == 5) {
            BaseOpponent* doithu = new Troll(i, events->get(i));
            win = armyKnights->fight(doithu);
        }
        if (events->get(i) == 6) {
            BaseOpponent* doithu = new Tornbery(i, events->get(i));
            win = armyKnights->fight(doithu);
        }
        if (events->get(i) == 7) {
            BaseOpponent* doithu = new QueenOfCards(i, events->get(i));
            win = armyKnights->fight(doithu);
        }
        if (events->get(i) == 8) {
            BaseOpponent* doithu = new NinaDeRings(i, events->get(i));
            win = armyKnights->fight(doithu);
        }
        if (events->get(i) == 9) {
            BaseOpponent* doithu = new DurianGarden(i, events->get(i));
            win = armyKnights->fight(doithu);
        }
        if (events->get(i) == 10) {
            if (checkomega == 0) {
                BaseOpponent* doithu = new OmegaWeapon(i, events->get(i));
                win = armyKnights->fight(doithu);
                if (win == 1) checkomega = 1;
                else {
                    checkomega = 0;
                    win = 1;
                }
            }
            else { win = 1; }
        }
        if (events->get(i) == 11) {
            if (checkhades == 0) {
                BaseOpponent* doithu = new Hades(i, events->get(i));
                win = armyKnights->fight(doithu);
                if (win == 1) checkhades = 1;
                else{
                    checkhades = 0;
                    win = 1;
                }
            }
            else { win = 1; }
        }
        if (events->get(i) == 95) {
            if (armyKnights->hasPaladinShield() == 0) {
                win = 1;
                armyKnights->nhan_paladin_shield();
            }
            else win = 1;
        }
        if (events->get(i) == 96) {
            if (armyKnights->hasLancelotSpear() == 0) {
                win = 1;
                armyKnights->nhan_lancelot_spear();
            }
            else win = 1;
        }
        if (events->get(i) == 97) {
            if (armyKnights->hasGuinevereHair() == 0) {
                win = 1;
                armyKnights->nhan_guinevere_hair();
            }
            else win = 1;
        }
        if (events->get(i) == 98) {
            if (armyKnights->hasGuinevereHair() == 1 &&
                armyKnights->hasLancelotSpear() == 1 &&
                armyKnights->hasPaladinShield() == 1) {
                win = 1;
                armyKnights->nhan_excalibur_sword();
            }
            else {
                win = 1;
            }
        } 
        if (events->get(i) == 112) {
            BaseItem* vatpham = new PhoenixDownII();
            armyKnights->nhan_vat_pham(vatpham);
            win = 1;
        }
        if (events->get(i) == 113) {
            BaseItem* vatpham = new PhoenixDownIII();
            armyKnights->nhan_vat_pham(vatpham);
            win = 1;
        }
        if (events->get(i) == 114) {
            BaseItem* vatpham = new PhoenixDownIV();
            armyKnights->nhan_vat_pham(vatpham);
            win = 1;
        }
        if (events->get(i) == 99) {
            if (armyKnights->hasExcaliburSword() == 1) {
                win = 1;
            }
            else if (armyKnights->hasGuinevereHair() == 1 &&
                armyKnights->hasLancelotSpear() == 1 &&
                armyKnights->hasPaladinShield() == 1) {
                BaseOpponent* doithu = new Ultimecia();
                win = armyKnights->fight(doithu);
            }
            else {
                win = 0;
            }

            if (win == 0) {
                armyKnights->thuaUlti();
            }
        }

        
        
        if (armyKnights->count() == 0) {
            win = 0;
            armyKnights->printInfo();
            break;
        }
        else if (i == events->count() - 1) {
            win = 1;
        }
        //CuoiVongLap
        armyKnights->chuyentien();
        armyKnights->printInfo();               
    }
    armyKnights->printResult(win);

}




//BASE_KNIGHT:-------------------
BaseKnight* BaseKnight::create(int id, int maxhp, int level, int phoenixdownI, int gil, int antidote) {
    if (maxhp > 999) maxhp = 999;
    if (phoenixdownI > 5)phoenixdownI = 5;
    if (gil > 999) gil = 999;
    if (antidote > 5) antidote = 5;

    BaseKnight* ptr;

    if (checkNguyenTo(maxhp) == 1)
    {
        ptr = new PaladinKnight();
        ptr->bag = new PaladinBag(ptr,antidote, phoenixdownI);
    }
    else if (check_pytago(maxhp) == 1) {
        ptr = new DragonKnight();
        ptr->bag = new DragonBag(ptr,antidote, phoenixdownI);
    }
    else if (maxhp == 888) {
        ptr = new LancelotKnight();
        ptr->bag = new LanceLotBag(ptr,antidote, phoenixdownI);
    }
    else {
        ptr = new NormalKnight();
        ptr->bag = new NormalBag(ptr,antidote, phoenixdownI);
    }

    ptr->id = id;
    ptr->maxhp = maxhp;
    ptr->hp = maxhp;
    ptr->level = level;
    ptr->gil = gil;

    
    return(ptr);
}
string BaseKnight::toString() const {
    string typeString[4] = { "PALADIN", "LANCELOT", "DRAGON", "NORMAL" };
    // inefficient version, students can change these code
    //      but the format output must be the same
    string s("");
    s += "[Knight:id:" + to_string(id)
        + ",hp:" + to_string(hp)
        + ",maxhp:" + to_string(maxhp)
        + ",level:" + to_string(level)
        + ",gil:" + to_string(gil)
        + "," + bag->toString()
        + ",knight_type:" + typeString[knightType]
        + "]";
    return s;
}

void BaseKnight::timphoenix(BaseKnight*knight) {
    bool sudung = 0;
    BaseItem* vatpham;
    
    for(int i = 0;i<bag->gethientai();i++){

        if (sudung == 1) {
            break;
        }
        switch (bag->getnextitem(i))
        {
        case(1):           
            vatpham = new PhoenixDownI();
            if (vatpham->canUse(knight) == true) {               
                if (bag->get(PhoenixI) != nullptr) {

                    vatpham->use(knight);
                    sudung = 1;
                    break;
                }
                else {
                    break;
                }
            }
            else {
                break;
            }
        case(2):
            vatpham = new PhoenixDownII();
            if (vatpham->canUse(knight) == true) {
                if (bag->get(PhoenixII) != nullptr) {
                    
                    vatpham->use(knight);
                    sudung = 1;
                    break;
                }
                else {
                    break;
                }
            }
            else {
                break;
            }
        case(3):
            vatpham = new PhoenixDownIII();

            if (vatpham->canUse(knight) == true) {
                if (bag->get(PhoenixIII) != nullptr) {
                    
                    vatpham->use(knight);
                    sudung = 1;
                    break;
                }
                else {
                    break;
                }
            }
            else {
                break;
            }
        case(4):
            vatpham = new PhoenixDownIV();
            if (vatpham->canUse(knight) == true) {
                if (bag->get(PhoenixIV) != nullptr) {
                    
                    vatpham->use(knight);
                    sudung = 1;
                    break;
                }
                else {
                    break;
                }
            }
            else {
                break;
            }
        default:
            break;
        }
    }
}
bool BaseKnight::timanti(BaseKnight* knight) {
    bool sudung = 0;
    BaseItem* vatpham;
    
    for (int i = 0; i < bag->gethientai(); i++) {
        if (sudung == 1) {
            break;
        }
        if (bag->getnextitem(i) == 0) {
            vatpham = new Antidote();
            if (vatpham->canUse(knight) == 1) {
                if (bag->get(Anti) != nullptr) {
                    vatpham->use(knight);
                    sudung = 1;
                    break;
                }
                else continue;
            }
            else continue;
        }
    }
    if (sudung == 0) return 0;
    else return 1;
}
bool BaseKnight::nhan_do(BaseItem*item) {
    bool a = bag->insertFirst(item);
    return a;
}

void BaseKnight::tui_rot_do() {   
    bag->tui_rot_do();
}

//Events--------------------------
Events::Events(const string &file_events)
{
    ifstream input(file_events);
    input >> this->sosukien;

    mangsukien = new int[sosukien];

    for (int i = 0; i < this->sosukien; i++)
    {
        input >> mangsukien[i];
    }

}


//Army_Knights--------------------
ArmyKnights::ArmyKnights(const string& file_armyknights) {
    ifstream input(file_armyknights);
    int id, maxhp, level, gil, antidote, phoenixdownI;
  
    input >> so_luong_knight;
    mang_knight = new BaseKnight*[so_luong_knight];
    iniNumberKnights = so_luong_knight;

    for (int i = 0; i < so_luong_knight; i++) {
        id = 0; maxhp = 0; level = 0; gil = 0; antidote = 0; phoenixdownI = 0;
        input >> maxhp >> level >> phoenixdownI >> gil >> antidote;
        
        //the loai hiep si
        mang_knight[i] = BaseKnight::create(i + 1, maxhp, level, phoenixdownI, gil, antidote);
    }
}
ArmyKnights::~ArmyKnights() {
    for (int i = 0; i < iniNumberKnights; i++) {
        delete []mang_knight[i];
    }
    delete[]mang_knight;
}

BaseKnight** ArmyKnights::getArmy() const {
    return (mang_knight);
}
BaseKnight* ArmyKnights::lastKnight() const {
    if (so_luong_knight == 0) return nullptr;
    return (mang_knight[so_luong_knight - 1]);
}

int ArmyKnights::count() const {
    return(so_luong_knight);
}

bool ArmyKnights::hasPaladinShield() const {
    return(paladinshield);
}
bool ArmyKnights::hasLancelotSpear() const{
    return(lancelotspear);
}
bool ArmyKnights::hasGuinevereHair() const{
    return(guinerverehair);
}
bool ArmyKnights::hasExcaliburSword() const {
    return (excalibursword);
}

void ArmyKnights::nhan_paladin_shield() {
    paladinshield = 1;
}
void ArmyKnights::nhan_lancelot_spear() {
    lancelotspear = 1;
}
void ArmyKnights::nhan_guinevere_hair() {
    guinerverehair = 1;
}
void ArmyKnights::nhan_excalibur_sword() {
    excalibursword = 1;
}
void ArmyKnights::nhan_vat_pham(BaseItem* vatpham) {
    for (int i = 0; i < so_luong_knight; i++) {
        BaseKnight* lastknight = mang_knight[so_luong_knight - 1 - i];
        if (lastknight->nhan_do(vatpham) == false) {
            continue;
        }
        else break;
    }
}


bool ArmyKnights::fight(BaseOpponent* opponent){ 

    bool win = 0;
    
    if (opponent->gettype() == MADBEAR ||
        opponent->gettype() == BANDIT || 
        opponent->gettype() == TROLL || 
        opponent->gettype() == LORDLUPIN || 
        opponent->gettype() == ELF ){ 
        int hp_bandau = 0;


         //hiep si cuoi cung danh
         BaseKnight* lastknight = ArmyKnights::lastKnight();
         hp_bandau = lastknight->gethp();

         if (lastknight->getlevel() >= opponent->getlv0() || 
             lastknight->getType() == LANCELOT ||
             lastknight->getType() == PALADIN) 
         {               
             lastknight->setGil(lastknight->getgil() + opponent->getgil());
             win = 1;
         }
         else {
             int damage = opponent->getbasedamage() * (opponent->getlv0() - lastknight->getlevel());
             lastknight->setHP(lastknight->gethp() - damage);
             win = 0;
         }

         //dung phoe
         if (lastknight->gethp() < hp_bandau) {
             
             //check xem su dung phoe chua
              lastknight->timphoenix(lastknight);
                 
              if (lastknight->gethp() <= 0) {
                  if (lastknight->getgil() >= 100) {
                      lastknight->setGil(lastknight->getgil() - 100);
                      lastknight->setHP(lastknight->getMaxHp() / 2);                           
                  }
              }

              //sau khi tim phoenix va gil ma hiep si van hp < 0
              if (lastknight->gethp() <= 0) {                   
                  hysinh();
              }
         }
    }
    else if (opponent->gettype() == TORNBERY) {

        int hp_bandau = 0;
        //check xem chet het chua
        
        //hiep si cuoi cung danh
        BaseKnight* lastknight = ArmyKnights::lastKnight();
        hp_bandau = lastknight->gethp();
        
        if (lastknight->getlevel() >= opponent->getlv0()) {            
            if (lastknight->getlevel() < 10) {
                lastknight->tang_level();
            }
            win = 1;
        }
        else {
            win = 0;
            if (lastknight->getType() == DRAGON) {
                if (lastknight->timanti(lastknight) == 0) {
                    lastknight->tui_rot_do();                   
                }
            }      
            else if (lastknight->timanti(lastknight) == 0) {
                lastknight->setHP(lastknight->gethp() - 10);
                lastknight->tui_rot_do();
            }        
            else {              
            }
        }
        
        //neu hiep si dinh doc:
        if (lastknight->gethp() < hp_bandau) {
            //check xem su dung phoe chua
            lastknight->timphoenix(lastknight);
            if (lastknight->gethp() <= 0) {
                if (lastknight->getgil() >= 100) {
                    lastknight->setGil(lastknight->getgil() - 100);
                    lastknight->setHP(lastknight->getMaxHp() / 2);                   
                }
            }
            //sau khi tim phoenix va gil ma hiep si van hp < 0
            if (lastknight->gethp() <= 0) {
                hysinh();
            }
        }
    }
    else if (opponent->gettype() == QUEENOFCARDS) {        
        BaseKnight* lastknight = lastKnight();
        if (lastknight->getlevel() >= opponent->getlv0()) {
            if (lastknight->getlevel() < 10) {
                lastknight->tang_level();
            }
            lastknight->setGil(lastknight->getgil() * 2);
            chuyentien();
        }
        else if (lastknight->getType() == PALADIN) {
        }
        else {
            lastknight->setGil(lastknight->getgil() / 2);
        }
        win = 1;
    }
    else if (opponent->gettype() == NINADERINGS) {

        BaseKnight* lastknight = lastKnight();

        if (lastknight->getType() == PALADIN) {
            if (lastknight->gethp() < int(lastknight->getMaxHp() / 3)) {
                lastknight->setHP(lastknight->gethp() + lastknight->getMaxHp() / 5);

            }
        }

        else if (lastknight->getgil() >= 50) {
            if (lastknight->gethp() < int(lastknight->getMaxHp() / 3)) {
                lastknight->setGil(lastknight->getgil() - 50);
                lastknight->setHP(lastknight->gethp() + lastknight->getMaxHp() / 5);
            }
        }
        else {}
        win = 1;
    }
    else if (opponent->gettype() == DURIANGARDEN) {
        BaseKnight* lastknight = lastKnight();
        lastknight->setHP(lastknight->getMaxHp());
        win = 1;
    }
    else if (opponent->gettype() == OMEGAWEAPON) {

        int hp_bandau = 0;

        BaseKnight* lastknight = ArmyKnights::lastKnight();
        hp_bandau = lastknight->gethp();

        if (lastknight->getlevel() == 10 && lastknight->gethp() == lastknight->getMaxHp()) {
            win = 1;
            lastknight->setGil(999);
        }
        else if (lastknight->getType() == DRAGON) {
            win = 1;
            lastknight->setGil(999);
            lastknight->setlevel(10);
        }
        else {
            lastknight->setHP(0);
            win = 0;
        }
        if (lastknight->gethp() == 0) {
            //check xem su dung phoe chua
            lastknight->timphoenix(lastknight);
            if (lastknight->gethp() <= 0) {
                if (lastknight->getgil() >= 100) {
                    lastknight->setGil(lastknight->getgil() - 100);
                    lastknight->setHP(lastknight->getMaxHp() / 2);                  
                }
                else{}
            }
            //sau khi tim phoenix va gil ma hiep si van hp < 0
            if (lastknight->gethp() <= 0) {
                hysinh();
            }
        }
    }
    else if (opponent->gettype() == HADES) {
        BaseKnight* lastknight = lastKnight();

        if (lastknight->getlevel() >= 8 && lastknight->getType() == PALADIN) {
            win = 1;
            if (paladinshield == 0) {
                nhan_paladin_shield();
            }
        }
        else if (lastknight->getlevel() == 10) {
            win = 1;
            if (paladinshield == 0) {
                nhan_paladin_shield();
            }
        }
        else {
            lastknight->setHP(0);
            win = 0;
        }

        //cuoi tran
        if (lastknight->gethp() == 0) {
            //check xem su dung phoe chua
            lastknight->timphoenix(lastknight);
            if (lastknight->gethp() <= 0) {
                if (lastknight->getgil() >= 100) {
                    lastknight->setGil(lastknight->getgil() - 100);
                    lastknight->setHP(lastknight->getMaxHp() / 2);                   
                }
            }
            //sau khi tim phoenix va gil ma hiep si van hp < 0
            if (lastknight->gethp() <= 0) {
                hysinh();
            }
        }
    }
    else if (opponent->gettype() == ULTIMECIA) {
        int hp_quai = 5000;
        int damage = 0;
        int soluonghiepsi = so_luong_knight; //so luong hiep si ban dau
        int NormalKnight = 0;
        BaseKnight* temp = nullptr;

        //mang cac normal knight      

        for (int i = 0; i < soluonghiepsi; i++) {

            damage = 0;
            BaseKnight* knight = mang_knight[soluonghiepsi - 1 - i];

            if (knight->getType() == DRAGON) {
                damage = knight->gethp() * knight->getlevel() * 0.075;
            }
            else if (knight->getType() == LANCELOT) {
                damage = knight->gethp() * knight->getlevel() * 0.05;
            }
            else if (knight->getType() == PALADIN) {
                damage = knight->gethp() * knight->getlevel() * 0.06;
            }
            else {
                if(temp == nullptr) temp = knight;
                continue;
            }
            hp_quai -= damage;
            if (hp_quai > 0)
            {
                hysinh();
            }
            else {
                if (temp != nullptr) {
                    mang_knight[so_luong_knight - 1] = temp;
                }
                win = 1;
                break;
            }
        }

        if (hp_quai > 0) {
            win = 0;
            thuaUlti();
        }
    }
    if (win == 1) return true;
    else return false;
}
bool ArmyKnights::adventure(Events* events) {
}

void ArmyKnights::printInfo() const{
    cout << "No. knights: " << this->count() ;
    if (this->count() > 0) {
        BaseKnight* lknight = lastKnight();// last knight
        cout << ";" << lknight->toString();
    }
    cout << ";PaladinShield:" << this->hasPaladinShield()
        << ";LancelotSpear:" << this->hasLancelotSpear()
        << ";GuinevereHair:" << this->hasGuinevereHair()
        << ";ExcaliburSword:" << this->hasExcaliburSword()
        << endl
        << string(50, '-') << endl;
}
void ArmyKnights::printResult(bool win) const {
    cout << (win ? "WIN" : "LOSE") << endl;
}
void ArmyKnights::hysinh(){
    this->so_luong_knight--;
}
void ArmyKnights::chuyentien() {
    int i = 1;
    int phandu = 0;
    BaseKnight* hiepsi = mang_knight[so_luong_knight - 1];
    
    while (hiepsi->getgil() > 999) {
        phandu = (hiepsi->getgil() - 999);
        hiepsi->setGil(999);

        if (i == so_luong_knight) break;

        i++;
        hiepsi = mang_knight[so_luong_knight - i];
        hiepsi->setGil(hiepsi->getgil() + phandu);
        phandu = 0;
    }
}

void ArmyKnights::thuaUlti() {
    so_luong_knight = 0;
}


//BASEBAG-------------------------
BaseItem* BaseBag::get(ItemType itemType) {
    if (ptrhead->gettype() == itemType) {
        BaseItem* ketqua = ptrhead;
        ptrhead = ptrhead->next;
        hientai--;
        return (ketqua);
    }
    else if (ptrhead->next->gettype() == itemType) {
        BaseItem* ketqua = ptrhead->next;
        ptrhead->next = ptrhead->next->next;
        hientai--;
        return (ketqua);
    }
    else if (hientai > 2) {
        BaseItem* search = ptrhead;


        while (search->next->gettype() != itemType) {
            if (search->next == nullptr) {
                return nullptr;
                break;
            }
            search = search->next;
        }
        
        if (search->next->gettype() == itemType) {
            BaseItem* ketqua = search->next;
            BaseItem* temp = ptrhead;
            
            ptrhead = temp->next;
            temp->next = search->next->next;
            search->next = temp;
                                              
            hientai--;
            
            return(ketqua);
        }
    }
    else return nullptr;
    
}
string BaseBag::toString() const{
    string s = "Bag[count=";
    BaseItem* temp = ptrhead;

    s = s + to_string(hientai) + ";";
    

    for (int i = 0; i < hientai; i++) {
        switch (temp->gettype())
        {
        case(Anti):
            s = s + "Antidote";
            break;
        case(PhoenixI):
            s = s + "PhoenixI";
            break;
        case(PhoenixII):
            s = s + "PhoenixII";
            break;
        case(PhoenixIII):
            s = s + "PhoenixIII";
            break;
        case(PhoenixIV):
            s = s + "PhoenixIV";
            break;
        }
        temp = temp->next;
        if (i != hientai - 1) {
            s += ',';
        }

    }

    s = s + ']';
    return s;
}

int BaseBag::getnextitem(int thutu) {
    if (thutu == 0) return (ptrhead->gettype());
    else if (thutu > 0) {
        BaseItem* temp = ptrhead;
        for (int i = 0; i < thutu; i++) {
            temp = temp->next;
        }
        return (temp->gettype());
    }
}

void BaseBag::tui_rot_do() {
    
    if (hientai <= 3) {
        ptrhead = nullptr;
        hientai = 0;
    }
    
    else if(hientai>3) {
        hientai -= 3;
        ptrhead = ptrhead->next->next->next;
    }
}

bool DragonBag::insertFirst(BaseItem* item) {
    if (item->gettype() == Anti) {
        return false;
    }
    if (hientai == 0) {
        ptrhead = item;
        ptrhead->next = nullptr;
        hientai++;
        return true;
    }
    else if (hientai < max) {
        item->next = ptrhead;
        ptrhead = item;
        hientai++;
        return true;
    }
    else return false;
}
bool LanceLotBag::insertFirst(BaseItem* item) {
    if (hientai == 0) {
        ptrhead = item;
        ptrhead->next = nullptr;
        hientai++;
        return true;
    }
    else if (hientai < max) {
        item->next = ptrhead;
        ptrhead = item;
        hientai++;
        return true;
    }
    else return false;
}
bool NormalBag::insertFirst(BaseItem* item)  {
    if (hientai == 0) {
        ptrhead = item;
        ptrhead->next = nullptr;
        hientai++;
        return true;
    }
    else if (hientai < max) {
     
        item->next = ptrhead;
        ptrhead = item;
        hientai++;
        return true;
    }
    else return false;
}
bool PaladinBag::insertFirst(BaseItem* item) {
    if (hientai == 0) {
        ptrhead = item;
        ptrhead->next = nullptr;
        hientai++;
        return true;
    }
    else{
        
        item->next = ptrhead;
        ptrhead = item;
        hientai++;
        return true;
    }
}

PaladinBag::PaladinBag(BaseKnight* knight, int soluong_antidote, int soluong_phoenixdownI){
    hientai = 0;
    while (soluong_phoenixdownI > 0) {
        BaseItem* vatpham = new PhoenixDownI();
        if (insertFirst(vatpham) == 1) {
            soluong_phoenixdownI--;            
        }
    }
    while (soluong_antidote > 0)
    {
        BaseItem* vatpham = new Antidote();
        if (insertFirst(vatpham) == 1) {
            soluong_antidote--;
        }
    }
}
DragonBag::DragonBag(BaseKnight* knight, int soluong_antidote, int soluong_phoenixdownI)
{
    hientai = 0;
    max = 14;
    soluong_antidote = 0;
    while (soluong_phoenixdownI > 0) {
        BaseItem* vatpham = new PhoenixDownI();
        if (insertFirst(vatpham) == 1) {
            soluong_phoenixdownI--;
        }
    }
    while (soluong_antidote > 0)
    {
        BaseItem* vatpham = new Antidote();
        if (insertFirst(vatpham) == 1) {
            soluong_antidote--;
        }
    }
}
NormalBag::NormalBag(BaseKnight * knight, int soluong_antidote, int soluong_phoenixdownI)    
{   
    hientai = 0;
    max = 19;
    while (soluong_phoenixdownI > 0) {
        BaseItem* vatpham = new PhoenixDownI();
        if (insertFirst(vatpham) == 1) {
            soluong_phoenixdownI--;
        }
    }
    while (soluong_antidote > 0)
    {
        BaseItem* vatpham = new Antidote();
        if (insertFirst(vatpham) == 1) {
            soluong_antidote--;
        }
    }
}
LanceLotBag::LanceLotBag(BaseKnight* knight,int soluong_antidote, int soluong_phoenixdownI)  
{
    hientai = 0;
    max = 16;
    while (soluong_phoenixdownI > 0) {
        BaseItem* vatpham = new PhoenixDownI();
        if (insertFirst(vatpham) == 1) {
            soluong_phoenixdownI--;
        }
    }
    while (soluong_antidote > 0)
    {
        BaseItem* vatpham = new Antidote();
        if (insertFirst(vatpham) == 1) {
            soluong_antidote--;
        }
    }
}


//BASEITEM------------------------------
bool Antidote::canUse(BaseKnight* knight) {
    return 1;
}
bool PhoenixDownI::canUse(BaseKnight* knight) {
    if (knight->gethp() <= 0 ){
        return true;
    }
    else return false;
}
bool PhoenixDownII::canUse(BaseKnight* knight) {
    if (knight->gethp() < (knight->getMaxHp() / 4)) {
        return true;
    }
    else return false;
}
bool PhoenixDownIII::canUse(BaseKnight* knight) {
    if (knight->gethp() < (knight->getMaxHp() / 3)) {
        return true;
    }
    else return false;
}
bool PhoenixDownIV::canUse(BaseKnight* knight) {
    int hp = knight->gethp();
    int maxhp = knight->getMaxHp();
    if (hp<maxhp/2) {
        return true;
    }
    else return false;
}

void Antidote::use(BaseKnight* knight) {

}
void PhoenixDownI::use(BaseKnight* knight) {
    knight->setHP(knight->getMaxHp());
}
void PhoenixDownII::use(BaseKnight* knight) {
    knight->setHP(knight->getMaxHp());
}
void PhoenixDownIII::use(BaseKnight* knight) {
    if (knight->gethp() <= 0) {
        knight->setHP(knight->getMaxHp() / 3);
    }
    else(knight->setHP(knight->gethp() + knight->getMaxHp() / 4));
}
void PhoenixDownIV::use(BaseKnight* knight) {
    if (knight->gethp() <= 0) {
        knight->setHP(knight->getMaxHp() / 2);
    }
    else {
        knight->setHP(knight->gethp()+knight->getMaxHp() / 5);
    }
}


//BASEOPPONENT-----------------------------
BaseOpponent::BaseOpponent(int thutusukien, int masukien) {
    level0 = (thutusukien + masukien) % 10 + 1;
}

//check Nguyen To
bool checkNguyenTo(int n) {
    if (n <= 1) return false;
    else if (n == 2) return true;
    else {
        for (int i = 2; i < n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }
}

//check PY_Tha_Go----------------
bool check_pytago(int n) {
    if (n == 345 || n == 354 || n == 435 || n == 453 || n == 534 || n == 543) return true;
    else return false;
    return true;
}