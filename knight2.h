#ifndef __KNIGHT2_H__
#define __KNIGHT2_H__

#include "main.h"

// #define DEBUG

enum ItemType { Anti = 0, PhoenixI, PhoenixII, PhoenixIII, PhoenixIV };
enum KnightType { PALADIN = 0, LANCELOT, DRAGON, NORMAL};
enum MonsterType { MADBEAR = 0, BANDIT, LORDLUPIN, ELF, TROLL, TORNBERY, QUEENOFCARDS,NINADERINGS, DURIANGARDEN,OMEGAWEAPON,HADES,ULTIMECIA};

class BaseKnight;
class BaseItem;
class BaseOpponent;
class Events;

//BASE_BAG
class BaseBag {
protected:
    BaseKnight* knight;
    BaseItem* ptrhead;
    int hientai = 0;
    int max = 0;

public:
    virtual bool insertFirst(BaseItem* item) = 0;
    BaseItem* get(ItemType itemType);
    
    string toString ()const ;
    
    int gethientai() const{
        return hientai;
    }
    int getmax() const{
        return max;
    }
    int getnextitem(int thutu);  

    void tui_rot_do();
};

class DragonBag :public BaseBag {
public:    
    DragonBag(BaseKnight* knight, int soluong_antidote, int soluong_phoenixdownI);    
    bool insertFirst(BaseItem* item);
};
class LanceLotBag :public BaseBag {
public:   
    LanceLotBag(BaseKnight* knight, int soluong_antidote, int soluong_phoenixdownI);
    bool insertFirst(BaseItem* item);
};
class NormalBag :public BaseBag {
public:
    NormalBag(BaseKnight* knight, int soluong_antidote, int soluong_phoenixdownI);
    bool insertFirst(BaseItem* item);
};
class PaladinBag :public BaseBag {
public:  
    PaladinBag(BaseKnight* knight, int soluong_antidote, int soluong_phoenixdownI);
    bool insertFirst(BaseItem* item);
};

//CLASS BASE_OPPONENT
class BaseOpponent {
protected:
    int gil = 0;
    int basedamage = 0;
    int level0 = 0;
    MonsterType type;
public:
    BaseOpponent(){}
    BaseOpponent(int thutusukien, int masukien);
    int getlv0() {
        return level0;
    }
    int getgil() {
        return gil;
    }
    int getbasedamage() {
        return basedamage;
    }
    MonsterType gettype() {
        return type;
    }
};

class Madbear:public BaseOpponent {
public:
    Madbear(int thutusukien, int masukien):BaseOpponent(thutusukien,masukien) {
        gil = 100;
        basedamage = 10;
        type = MADBEAR;
    }
};
class Bandit :public BaseOpponent {
public:
    Bandit(int thutusukien, int masukien):BaseOpponent(thutusukien, masukien) {
        gil = 150;
        basedamage = 15;
        type = BANDIT;
    }
};
class LordLupin :public BaseOpponent {
public:
    LordLupin(int thutusukien, int masukien):BaseOpponent(thutusukien, masukien) {
        gil = 450;
        basedamage = 45;
        type = LORDLUPIN;
    }
};
class Elf :public BaseOpponent {
public:
    Elf(int thutusukien, int masukien) :BaseOpponent(thutusukien, masukien) {
        gil = 750;
        basedamage = 75;
        type = ELF;
    }
};
class Troll :public BaseOpponent {
public:
    Troll(int thutusukien, int masukien) :BaseOpponent(thutusukien, masukien){
        gil = 800;
        basedamage = 95;
        type = TROLL;
    }
};
class Tornbery :public BaseOpponent {
public:
    Tornbery(int thutusukien, int masukien) :BaseOpponent(thutusukien, masukien) {
        basedamage = 0;
        gil = 0;
        type = TORNBERY;
    }
};
class QueenOfCards :public BaseOpponent {
public:
    QueenOfCards(int thutusukien, int masukien) :BaseOpponent(thutusukien, masukien) {
        basedamage = 0;
        gil = 0;
        type = QUEENOFCARDS;
    }
};
class NinaDeRings :public BaseOpponent {
public:
    NinaDeRings(int thutusukien, int masukien) :BaseOpponent(thutusukien, masukien) {
        basedamage = 0;
        gil = 0;
        type = NINADERINGS;
    }
};
class DurianGarden :public BaseOpponent {
public:
    DurianGarden(int thutusukien, int masukien) :BaseOpponent(thutusukien, masukien) {
        basedamage = 0;
        gil = 0;
        type = DURIANGARDEN;
    }
};
class OmegaWeapon :public BaseOpponent {
public:
    OmegaWeapon(int thutusukien, int masukien) :BaseOpponent(thutusukien, masukien) {
        basedamage = 0;
        gil = 0;
        type = OMEGAWEAPON;
    }
};
class Hades :public BaseOpponent {
public:
    Hades(int thutusukien, int masukien) :BaseOpponent(thutusukien, masukien) {
        basedamage = 0;
        gil = 0;
        type = HADES;
    }
};
class Ultimecia :public BaseOpponent {
public:
    Ultimecia() {
        type = ULTIMECIA;
    }   
};

//CLASS BASE_KNIGHT:

class BaseKnight     {
protected:
    int id = 0;
    int hp = 0;
    int maxhp = 0;
    int level = 0;
    int gil = 0;
    BaseBag * bag;
    KnightType knightType;
public:
    static BaseKnight* create(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI);
    string toString() const;

    int gethp() const {
        return hp;
    }
    int getlevel() const {
        return level;
    }    
    int getMaxHp() const {
        return maxhp;
    }   
    int getgil() const {
        return gil;
    }
    int getId() const {
        return id;
    }

    void timphoenix(BaseKnight* knight);
    bool timanti(BaseKnight* knight);

    bool nhan_do(BaseItem* item); 

    void setGil(int gil) {
        this->gil = gil;
    }
    void setHP(int hp) {
        this->hp = hp;
    }
    void setlevel(int level) {
        this->level = level;
    }
    void tang_level() {
        this->level++;
    }
    void tui_rot_do();

    KnightType getType() {
        return knightType;
    }
    ~BaseKnight() {
        delete bag;
    }
};

class PaladinKnight : public BaseKnight {
public:
    PaladinKnight() {       
        knightType = PALADIN;
    }
};
class LancelotKnight :public BaseKnight {
public:
    LancelotKnight() {
        
        knightType = LANCELOT;
    }
    
};
class DragonKnight :public BaseKnight {
public:
    DragonKnight() {
        knightType = DRAGON;
    }
};
class NormalKnight :public BaseKnight {
public:
    NormalKnight() {
        knightType = NORMAL;
        
    }
};


//ARMYKNIGHT-----------------------
class ArmyKnights {
private:
    BaseKnight** mang_knight;
    int so_luong_knight;
    int iniNumberKnights;
    bool paladinshield = 0;
    bool lancelotspear = 0;
    bool guinerverehair = 0;
    bool excalibursword = 0;
public:
    ArmyKnights(const string& file_armyknights);
    bool fight(BaseOpponent * opponent);
    bool adventure(Events* events);
    int count() const;

    BaseKnight * lastKnight() const;

    bool hasPaladinShield() const;
    bool hasLancelotSpear() const;
    bool hasGuinevereHair() const;
    bool hasExcaliburSword() const;

    void printInfo() const;
    void printResult(bool win) const;
    void hysinh();
    void chuyentien();

    void nhan_paladin_shield();
    void nhan_lancelot_spear();
    void nhan_guinevere_hair();
    void nhan_excalibur_sword();
    void nhan_vat_pham(BaseItem* vatpham);

    void thuaUlti();
   
    BaseKnight** getArmy() const;

    ~ArmyKnights();
};

//CLASS BASE_ITEM
class BaseItem {
protected:   
public:
    ItemType loai_vat_pham;
    BaseItem* next;
    
    virtual bool canUse ( BaseKnight * knight ) = 0;
    virtual void use(BaseKnight* knight) = 0;
    ItemType gettype() const{
        return loai_vat_pham;
    }
    
    
};

class Antidote :public BaseItem {
public:
    Antidote(){
        loai_vat_pham = Anti;
    }
    bool canUse(BaseKnight* knight);
    void use(BaseKnight* knight);
};
class PhoenixDownI :public BaseItem {
public:
    PhoenixDownI() {
        loai_vat_pham = PhoenixI;
    }
    bool canUse(BaseKnight* knight);
    void use(BaseKnight* knight);
};
class PhoenixDownII :public BaseItem {
public:
    PhoenixDownII() {
        loai_vat_pham = PhoenixII;
    }
    bool canUse(BaseKnight* knight);
    void use(BaseKnight* knight);
};
class PhoenixDownIII :public BaseItem {
public:
    PhoenixDownIII() {
        loai_vat_pham = PhoenixIII;
    }
    bool canUse(BaseKnight* knight);
    void use(BaseKnight* knight);
};
class PhoenixDownIV :public BaseItem {
public:
    PhoenixDownIV() {
        loai_vat_pham = PhoenixIV;
    }
    bool canUse(BaseKnight* knight);
    void use(BaseKnight* knight);
};



//CLASS EVENTS:
class Events {
private:
    int sosukien = 0;
    int* mangsukien;
public:
    Events(const string& file_events);
    int count() const {
        return sosukien;
    }
    int get(int i) const {
        return mangsukien[i];
    }    
    void printmang();
    ~Events(){
        delete[]mangsukien;
    }
};

//CLASS KNIGHT_ADVENTURE:
class KnightAdventure {
private:
    ArmyKnights * armyKnights;
    Events * events;

public:
    KnightAdventure();
    //~KnightAdventure(); // TODO:

    void loadArmyKnights(const string& file);
    void loadEvents(const string & file);
    void run();
};

bool checkNguyenTo(int n);
bool check_pytago(int n);

#endif // __KNIGHT2__



