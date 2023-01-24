#include <iostream>

class Laptop {
private:
    char* model;
    char* color;
    char* display;
    int year;
    double price;

public:
    Laptop() {
        model = nullptr;
        color = nullptr;
        display = nullptr;
        year = 0;
        price = 0;
    }

    Laptop(const char* mod, const char* col, const char* disp, int y, double pr) {
        model = new char[strlen(mod) + 1];
        strcpy_s(model, strlen(mod) + 1, mod);

        color = new char[strlen(col) + 1];
        strcpy_s(color, strlen(col) + 1, col);

        display = new char[strlen(disp) + 1];
        strcpy_s(display, strlen(disp) + 1, disp);

        year = y;

        price = pr;
    }

    ~Laptop() {
        delete[] model;
        delete[] color;
        delete[] display;
    }

    const char* GetModel() const { return model; }
    const char* GetColor() const { return color; }
    const char* GetDisplay() const { return display; }
    int GetYear() const { return year; }
    double GetPrice() const { return price; }

    void print() {
        printf("Model: %s\nColor: %s\nDisplay: %s\nYear: %d\nPrice: %.02f\n", model, color, display, year, price);
    }

    void init() {
        char buf1[100];
        char buf2[20];
        char buf3[20];

        std::cout << "Enter model -> ";
        std::cin.getline(buf1, 100);
        if (model != nullptr) delete[] model;
        model = new char[strlen(buf1) + 1];
        strcpy_s(model, strlen(buf1) + 1, buf1);

        std::cout << "Enter color -> ";
        std::cin.getline(buf2, 20);
        if (color != nullptr) delete[] color;
        color = new char[strlen(buf2) + 1];
        strcpy_s(color, strlen(buf2) + 1, buf2);

        std::cout << "Enter display -> ";
        std::cin.getline(buf3, 20);
        if (display != nullptr) delete[] display;
        display = new char[strlen(buf3) + 1];
        strcpy_s(display, strlen(buf3) + 1, buf3);

        std::cout << "Enter year -> ";
        std::cin >> year;

        std::cout << "Enter price -> ";
        std::cin >> price;
    }
};

std::ostream& operator << (std::ostream& o, const Laptop& l) {
    o << "Model: " << l.GetModel() << std::endl <<
        "Color: " << l.GetColor() << std::endl <<
        "Display: " << l.GetDisplay() << std::endl <<
        "Year: " << l.GetYear() << std::endl <<
        "Price: " << l.GetPrice();
    return o;
}

//"Model: %s\nColor: %s\nDisplay: %s\nYear: %d\nPrice: %.02f\n"

int main() {
    Laptop test1;
    test1.print();

    Laptop test("Dell", "Grey", "LCD", 2018, 25678.9);
    std::cout << test << std::endl;

    test.init();
    test.print();
}