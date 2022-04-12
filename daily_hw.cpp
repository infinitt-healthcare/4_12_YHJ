#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Calc {
public:
    virtual int calc(const int a, const int b) = 0;
    virtual float fcalc(const int a, const int b) = 0;
};
class AddCalc : public Calc {
public:
    virtual int calc(const int a, const int b) override {
        return a + b;
    }
};
class SubCalc : public Calc {
public:
    virtual int calc(const int a, const int b) override {
        return a - b;
    }
};
class MulCalc : public Calc {
public:
    virtual int calc(const int a, const int b) override {
        return a * b;
    }
};
class DivCalc : public Calc {
public:
    virtual int calc(const int a, const int b) override {
        return a / b;
    }
    virtual float fcalc(const int a, const int b) override {
        return a / float(b);
    }
};
class MyCalc {
public:
    void ShowCalc(Calc& pCalc, const int a, const int b) {
        // void CalcListAdd(const Calc* const pCalc) 안돼는 이유는?
        if (typeid(pCalc) == typeid(DivCalc)) {
            if (!CalcCheck(a, b))
                return;
            else if (a % b != 0) {
                cout << pCalc.fcalc(a, b) << endl;
                return;
            }
        }
        cout << pCalc.calc(a, b) << endl;
    }
    bool CalcCheck(const int a, const int b) {
        if (b == 0) {
            cout << "0으로 나눌 수 없습니다." << endl;
            return false;
        }
        return true;
    }
};

class IntCheck {
private:
    int tot = 0;
public:
    void showCheck() {
        if (tot != 0) {
            cout << "입력한 값이 숫자가 아닙니다." << endl;
            exit(-1);
        }
    }
    void countCheck(const string& s) {
        if (!isNumber(s))
            tot++;
    }
    bool isNumber(const string& s)
    {
        return all_of(s.begin(), s.end(), [](char c) { return isdigit(c) != 0; });
    }
};

void makeData(string &a, string &b) {
    cout << "a : ";
    cin >> a;
    cout << "b : ";
    cin >> b;

    IntCheck intCheck;

    vector<string> InputList = { a, b };
    for (auto input : InputList) {
        intCheck.countCheck(input);
    }
    intCheck.showCheck();
}


int main() {
    string a, b;
    makeData(a, b);


    MyCalc myCalc;
    DivCalc divCalc;

    myCalc.ShowCalc(divCalc, stoi(a), stoi(b));
}
