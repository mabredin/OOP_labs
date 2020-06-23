#include <iostream>
#include <string>
using namespace std;

class hardware {
private:
    string name;
    string model;
public:
    string getName() {
        return name;
    }
    string getModel() {
        return model;
    }
    void setName(string name) {
        this->name = name;
    }
    void setModel(string model) {
        this->model = model;
    }
    void out() {
        cout << "Name: " << name << endl;
        cout << "Model: " << model << endl;
    }
    virtual void outName() = 0;
};

class motherboard {
private:
    int year;
    string socket;
public:
    int getYear() {
        return year;
    }
    string getSocket() {
        return socket;
    }
    void setYear(int year) {
        this->year = year;
    }
    void setSocket(string socket) {
        this->socket = socket;
    }
    void out4() {
        cout << "Year: " << year << endl;
        cout << "Socket: " << socket << endl;
    }
    void outName() {
        cout << "Материнская плата: " << endl;
    }
};

class proz : public hardware, public motherboard {
private:
    int core;
public:

    int getCore() {
        return core;
    }
    void setCore(int core) {
        this->core = core;
    }
    void out1() {
        cout << "Number of Cores: " << core << endl;
    }
    void outName() override {
        cout << "Процессор: " << endl;
    }
};

class memory : public hardware {
private:
    string format;
    int size, frequency;
public:
    int getSize() {
        return size;
    }
    string getFormat() {
        return format;
    }
    int getFrequency() {
        return frequency;
    }
    void setSize(int size) {
        this->size = size;
    }
    void setFormat(string format) {
        this->format = format;
    }
    void setFrequency(int frequency) {
        this->frequency = frequency;
    }
    void out2() {
        cout << "Format: " << format << endl;
        cout << "Size: " << size << " Гб" << endl;
        cout << "Frequency: " << frequency << " МГц" << endl;
    }
    void outName() override {
        cout << "Память: " << endl;
    }
};

class videocard : public hardware {
private:
    string core1;
    int minfr, maxfr;
public:
    string getCore() {
        return core1;
    }
    int getMinfr() {
        return minfr;
    }
    int getMaxfr() {
        return maxfr;
    }
    void setCore(string core) {
        this->core1 = core;
    }
    void setFr(int minfr, int maxfr) {
        this->minfr = minfr;
        this->maxfr = maxfr;
    }
    void out3() {
        cout << "Core: " << core1 << endl;
        cout << "Frequency: " << minfr << " - " << maxfr << " МГц" << endl;
    }
    void outName() override {
        cout << "Видеокарта: " << endl;
    }
};

class out
{
public:
    void outName(hardware* hardware) {
        hardware->outName();
    }
};

class nune {
private:
    int year, core, size, frequency, minfr, maxfr;
    string name, model, socket, format, core1;
public:
    nune(string name, string model, int year, string socket, int core) {
        this->name = name;
        cout << "Name: " << name << endl;
        this->model = model;
        cout << "Model: " << model << endl;
        this->year = year;
        cout << "Year: " << year << endl;
        this->socket = socket;
        cout << "Socket: " << socket << endl;
        this->core = core;
        cout << "Number of Cores: " << core << endl;
    }
    nune(string name, string model, string core1, int minfr, int maxfr) {
        this->name = name;
        cout << "Name: " << name << endl;
        this->model = model;
        cout << "Model: " << model << endl;
        this->core1 = core1;
        cout << "Core: " << core1 << endl;
        this->minfr = minfr;
        this->maxfr = maxfr;
        cout << "Frequency: " << minfr << " - " << maxfr << " МГц" << endl;
    }
    nune(string name, string model, int size, int frequency, string format) {
        this->name = name;
        cout << "Name: " << name << endl;
        this->model = model;
        cout << "Model: " << model << endl;
        this->size = size;
        cout << "Size: " << size << endl;
        this->frequency = frequency;
        cout << "Frequency: " << frequency << endl;
        this->format = format;
        cout << "Format: " << format << endl;
    }
    nune(int year, string socket) {
        this->year = year;
        cout << "Year: " << year << endl;
        this->socket = socket;
        cout << "Socket: " << socket << endl;
    }
};

class Salary {
private:
    int sal;
public:
    void SetSalary(int sal) {
        this->sal = sal;
        if (sal < 0) throw "Стоимость меньше 0!";
    }
    void out5() {
        cout << "Ваша предполагаемая стоимость аппаратного обеспечения: " << sal << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "rus");
    int count, year, core, size, frequency, minfr, maxfr;
    string name, model, socket, format, core1;
    int sal;
    cout << "Системный блок включает:" << endl << endl;
    proz proz;
    memory memory;
    videocard videocard;
    motherboard motherboard;
    out out;
    Salary salary;

    out.outName(&proz);
    proz.setName("AMD");
    proz.setModel("Ryzen 3");
    proz.out();
    proz.setYear(2020);
    proz.setSocket("AM4");
    proz.out4();
    proz.setCore(4);
    proz.out1();
    cout << endl;

    out.outName(&memory);
    memory.setName("AMD");
    memory.setModel("Radeon R5");
    memory.out();
    memory.setSize(2);
    memory.setFormat("DDR3");
    memory.setFrequency(1600);
    memory.out2();
    cout << endl;

    out.outName(&videocard);
    videocard.setName("AMD");
    videocard.setModel("Radeon RX 580");
    videocard.out();
    videocard.setCore("Polaris 20");
    videocard.setFr(1340, 1355);
    videocard.out3();
    cout << endl;

    motherboard.outName();
    motherboard.setYear(2017);
    motherboard.setSocket("LGA 775");
    motherboard.out4();
    cout << endl;


    cout << "Предполагаемая сумма аппаратного обеспечения: ";
    cin >> sal;
    cout << endl;

    try
    {
        salary.SetSalary(sal);
        salary.out5();
    }
    catch (const char *ex)
    {
        cout << "Ошибка: " << ex << endl << endl;
    }
    
    cout << "Введите какую характеристику вы хотите вывести отдельно: " << endl;
    cout << "1 - Процессор, 2 - Видеокарта, 3 - Память, 4 - Материнская плата." << endl;
    cin >> count;
    cout << endl;

    for (int i = 1; i <= count; i++) {
        if (i == count && count == 1) {
            out.outName(&proz);
            name = proz.getName();
            model = proz.getModel();
            year = proz.getYear();
            socket = proz.getSocket();
            core = proz.getCore();
            nune point(name, model, year, socket, core);
        }
        if (i == count && count == 2) {
            out.outName(&videocard);
            name = videocard.getName();
            model = videocard.getModel();
            core1 = videocard.getCore();
            minfr = videocard.getMinfr();
            maxfr = videocard.getMaxfr();
            nune point(name, model, core1, minfr, maxfr);
        }
        if (i == count && count == 3) {
            out.outName(&memory);
            name = memory.getName();
            model = memory.getModel();
            format = memory.getFormat();
            size = memory.getSize();
            frequency = memory.getFrequency();
            nune point(name, model, size, frequency, format);
        }
        if (i == count && count == 4) {
            motherboard.outName();
            year = motherboard.getYear();
            socket = motherboard.getSocket();
            nune point(year, socket);
        }
    }

    system("pause");
    return 0;
}