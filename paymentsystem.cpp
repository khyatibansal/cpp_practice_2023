#include<iostream>

using namespace std;
enum PAYMENT_METHOD{
    UPI=1,
    CARD=2,
    NETBANKING=3
};

enum PAYMENT_BANK {
    HDFC=1,
    SBI=2,
    PNB=3
};

string payment_method_to_string(int choosen_payment_method)
{
    switch(choosen_payment_method)
    {
        case 1: return "upi";
        case 2: return "card";
        case 3: return "netbanking";
        default:
            return "Invalid";
    }
}
string payment_bank_to_string(int choosen_payment_bank)
{ 
    switch(choosen_payment_bank)
    {
        case 1: return "hdfc";
        case 2: return "sbi";
        case 3: return "pnb";
        default:
            return "Invalid";
    }

}

int main()
{
    PAYMENT_METHOD p = UPI;
    cout << payment_method_to_string(p);
    return 0;
}