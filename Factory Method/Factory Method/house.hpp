#pragma once

class House abstract {};

class PanelHouse : public House {
public:
	PanelHouse() { cout << "Panel house built" << endl; }
};

class WoodHouse : public House {
public:
	WoodHouse() { cout << "Wooden house built" << endl; }
};

class BrickHouse : public House {
public:
	BrickHouse() { cout << "Brick house built" << endl; }
};

class Developer abstract {
public:
	virtual House* Create() = 0;
};

class PanelDeveloper : public Developer {
public:
	House* Create() override { return new PanelHouse; }
};

class WoodDeveloper : public Developer {
public:
	House* Create() override { return new WoodHouse; }
};

class BrickDeveloper : public Developer {
public:
	House* Create() override { return new BrickHouse; }
};

House* Client(Developer* pDev) { return pDev->Create(); }