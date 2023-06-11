#include <iostream>
#include <string>
using namespace std;

class Pump {
public:
    void FillPump() { std::cout << "Fill pump" << std::endl; }
    void EmptyPump() { std::cout << "Empty pump" << std::endl; }
};

class Heater {
public:
    void HeatWater() { std::cout << "Water heating" << std::endl; }
    void CoolWater() { std::cout << "Water cooling" << std::endl; }
};

class Motor {
public:
    void StartMotor() { std::cout << "Turning motor on" << std::endl; }
    void StopMotor() { std::cout << "Turning motor off" << std::endl; }
};

class RinseAid {
public:
    void StartRinse() { std::cout << "Starting rinse" << std::endl; }
    void StopRinse() { std::cout << "Stopping rinse" << std::endl; }
};

class WashingMachine {
private:
    Pump pump;
    Heater heater;
    Motor motor;
    RinseAid rinseaid;

public:
    WashingMachine(Pump pump, Motor motor, Heater heater, RinseAid rinseaid) : pump(pump), motor(motor), heater(heater), rinseaid(rinseaid) {}
    void StartWashing() {
        pump.FillPump();
        heater.HeatWater();
        motor.StartMotor();
        rinseaid.StartRinse();
    }
    void StopWashing() {
        rinseaid.StopRinse();
        motor.StopMotor();
        heater.CoolWater();
        pump.EmptyPump();
    }
};

class User {
public:
    void Washing(WashingMachine& washingMachine) {
        std::cout << "Starting washing process" << std::endl;
        washingMachine.StartWashing();
        std::cout << std::endl;
        std::cout << "Stopping washing process" << std::endl;
        washingMachine.StopWashing();
    }
};

int main() {
    Pump pump;
    Motor motor;
    Heater heater;
    RinseAid rinser;

    WashingMachine washingMachine(pump, motor, heater, rinser);

    User user;
    user.Washing(washingMachine);
}