#pragma once
using namespace std;

class PC abstract {
protected:
    string box = "";
    string processor = "";
    string mainboard = "";
    string hdd = "";
    string memory = "";

public:
    virtual void SetBox() = 0;
    virtual void SetProcessor() = 0;
    virtual void SetMainBoard() = 0;
    virtual void SetHdd() = 0;
    virtual void SetMemory() = 0;
    void ShowPC() { cout << "Box: " + box + "\nProcessor: " + processor + "\nMainBoard: " + mainboard + "\nHDD: " + hdd + "\nMemory: " + memory << endl; }
};

class GamePC : public PC {
public:
    void SetBox() override { box = "Very cool box"; }
    void SetProcessor() override { processor = "Very cool processor"; }
    void SetMainBoard() override { mainboard = "Very cool mainboard"; }
    void SetHdd() override { hdd = "A lot of memory"; }
    void SetMemory() override { memory = "A lot of RAM"; }
};

class OfficePC : public PC {
public:
    void SetBox() override { box = "BlackBox"; }
    void SetProcessor() override { processor = "AMD Athlon II X4 840 (3.1 GHz)"; }
    void SetMainBoard() override { mainboard = "AMD A58 FCH (Bolton D2)"; }
    void SetHdd() override { hdd = "Seagate Desktop HDD 7200.12 500GB"; }
    void SetMemory() override { memory = "4 Gb DDR3-1600 MHz"; }
};

class HomePC : public PC {
public:
    void SetBox() override { box = "SilverBox"; }
    void SetProcessor() override { processor = "Intel Core i7-4790 (3.6 GHz)"; }
    void SetMainBoard() override { mainboard = "Intel B85"; }
    void SetHdd() override { hdd = "Western Digital Elements 1.5TB"; }
    void SetMemory() override { memory = "16 GB DDR3-1600"; }
};

class Creator abstract {
public:
    virtual PC* FactoryMethod() = 0;
};

class CreatorGamePC : public Creator {
public:
    PC* FactoryMethod() override {
        PC* pc = new GamePC();
        pc->SetBox();
        pc->SetProcessor();
        pc->SetMainBoard();
        pc->SetMemory();
        pc->SetHdd();
        return pc;
    }
};

class CreatorHomePC : public Creator {
public:
    PC* FactoryMethod() override {
        PC* pc = new HomePC();
        pc->SetBox();
        pc->SetProcessor();
        pc->SetMainBoard();
        pc->SetMemory();
        pc->SetHdd();
        return pc;
    }
};

class CreatorOfficePC : public Creator {
public:
    PC* FactoryMethod() override {
        PC* pc = new OfficePC();
        pc->SetBox();
        pc->SetProcessor();
        pc->SetMainBoard();
        pc->SetMemory();
        pc->SetHdd();
        return pc;
    }
};

void Factory(Creator** creators, int size) {
    for (int i = 0; i < size; i++) {
        PC* pc = creators[i]->FactoryMethod();
        pc->ShowPC();
    }
}