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

class ScheduleMessageService {
    ScheduleMessageRepository* scheduleMessageRepository;
    public:
    ScheduleMessageService(ScheduleMessageRepository*  scheduleMessageRepository)
    {
        
    }
    void scheduleMessage(Status status = UNPICKED)
    {
        cout << "Messaged scheduled";
        // Retrived all messages
        // Schedule the messaged based on timestamp
        // Update the msg status in the db
    }
        
};

class Scheduler {
    private:
    ScheduleMessageService* scheduleMessageService;
    public:
        Scheduler(ScheduleMessageService* scheduleMessageService)
        {

        }
        void schedule(Status status = UNPICKED)
        {
            try
            {
                cout << "Starting scheduling";
                scheduleMessageService->scheduleMessage(UNPICKED);
            }
            catch(...)
            {
                cout << "Found error";
            }
        }

};
int main()
{

    ScheduleMessageRepository* smr = new ScheduleMessageRepository();
    Message msg1,msg2;
    
    msg1.id = "3";
    msg1.date = "2023-03-06T12:00:00Z";
    msg1.postBy = 86400;
    msg1.message = "Reminder: Meeting at 2 PM today";
    msg1.to = "test@test.com";
    msg1.from = "noreply@test.com";

    msg2.id = "3";
    msg2.date = "2023-03-06T12:00:00Z";
    msg2.postBy = 86400;
    msg2.message = "Reminder: Meeting at 2 PM today";
    msg2.to = "test@test.com";
    msg2.from = "noreply@test.com";
    //messages[0].msg = msg1;
    //messages[0].status = UNPICKED; 
    ScheduleMsg messages[2] = {{msg1, UNPICKED},{msg2, UNPICKED}};
    smr->addMessage(messages[0]);
    smr->getAllMessages(UNPICKED);
    ScheduleMessageService* scheduleMessageService = new ScheduleMessageService(smr);
    Scheduler* scheduler = new Scheduler(scheduleMessageService);
    scheduler->schedule();
    /*for(int i = 0; i < messages.size(); i++)
    {
        
    } */   
    return 0;
}