#include<iostream>

using namespace std;

enum PAYMENT_METHOD{
    UPI=1,
    CARD=2,
    NETBANKING=3
} p;

enum PAYMENT_BANK {
    HDFC=1,
    SBI=2,
    PNB=3
};

enum PAYMENT_STATUS {
    INPROGRESS = 0,
    SUCCESS = 1,
    ERROR = -1
};
struct Upi
{
    PAYMENT_METHOD _type = UPI;
    string _upi;
    Upi(string upi):_upi(upi){}

};
struct Netbanking
{
    PAYMENT_METHOD _type = NETBANKING;
    string _username;
    string _password;
    Netbanking(string username, string password):_username(username), _password(password){}
};
struct Card
{
    PAYMENT_METHOD _type = CARD;
    string _card_number;
    string _cvv;
    string _card_holder_name;
    string _card_expiry_date;
    Card(string card_number,string cvv,string  card_holder_name, string card_expiry_date):_card_number(card_number), _cvv(cvv), _card_holder_name(card_holder_name), _card_expiry_date(card_expiry_date)
    {} 
};

struct transactioninfo{
    string id;
    PAYMENT_BANK paymentbank;
    PAYMENT_METHOD paymentmethod;
    string time;
    string amount;
    string client;
    PAYMENT_STATUS status;
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

class UpiService
{
    public:
        bool upiValidator(string upi)
        {
            return true;
        }
        void carryTransaction(string amount, string upiId)
        {
            try {
                if(upiValidator(upiId))
                {
                    
                }
            }
            catch(...)
            {
                cout << "hey";
            }    

        }
};
int main()
{
    PAYMENT_METHOD p = UPI;
    cout << payment_method_to_string(p);
    return 0;
}