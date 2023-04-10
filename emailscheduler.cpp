#include <iostream>
#include <chrono>
#include <ctime>    
#include <time.h>
#include <string.h>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

struct Message {
    string id;
    string date;
    int postBy;
    string message;
    string to;
    string from;
};

enum Status {
    UNPICKED = 1,
    PENDING = 2,
    ERROR = 3,
    SUCCESS = 4
};

struct ScheduleMsg {
    Message msg;
    Status status;
};

class ScheduleMessageRepository {
    private:
        map<string, ScheduleMsg> db;
    public:
        void addMessage(ScheduleMsg smsg)
        {
            if(db.find(smsg.msg.id) == db.end())
            {
                db[smsg.msg.id] = smsg;
                cout << "New msg is populated successfully";
            }
            else
            {
                cout << "Message already exist";
                updateMessage(smsg);
            }
        }
        void updateMessage(ScheduleMsg smsg)
        {
            if(db.find(smsg.msg.id) != db.end())
            {
                db[smsg.msg.id] = smsg;
                cout << "Message is update successfully";
            }
            else
            {
                cout << "Message doesn't exist";
            }

        }
        vector<ScheduleMsg> getAllMessages(Status status)
        {
            vector<ScheduleMsg> sm;
            for(auto msg: db)
            {
                if(msg.second.status == status)
                {
                    sm.push_back(msg.second);
                }
            }
            return sm;
        }
};
int main()
{
    return 0;
}