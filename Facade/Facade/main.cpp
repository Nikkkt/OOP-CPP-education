#include <iostream>
#include <string>
using namespace std;

class Washing {
public:
    void Wash() { cout << "Washing with normal water" << endl; }
    void HotWash() { cout << "washing with hot water" << endl; }
};

class Compiler
{
public:
    void Compile()
    {
        cout << "Compile application\n";
    }
};

class CLR
{
public:
    void Execute()
    {
        cout << "Execute application\n";
    }
    void Finish()
    {
        cout << "Finish application\n";
    }
};

class WashingMachine
{
    Washing washing;
    Compiler compiler;
    CLR clr;
public:
    WashingMachine(Washing te, Compiler compiler, CLR clr)
    {
        washing = te;
        compiler = compiler;
        clr = clr;
    }
    void Start()
    {
        washing.CreateCode();
        washing.Save();
        compiler.Compile();
        clr.Execute();
    }
    void Stop()
    {
        clr.Finish();
    }
};

class Programmer
{
public:
    void CreateApplication(VisualStudioFacade facade)
    {
        facade.Start();
        facade.Stop();
    }
};

int main()
{
    TextEditor textEditor;
    Compiler compiler;
    CLR clr;

    VisualStudioFacade ide(textEditor, compiler, clr);

    Programmer programmer;
    programmer.CreateApplication(ide);
}