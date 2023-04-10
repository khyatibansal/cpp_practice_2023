#include<iostream>
#include<vector>

using namespace std;
struct User {
    string username;
    string email_id;
};

enum Status {
    SCHEDULED = 1,
    CANCELLED = 2,
    UNKNOWN = 3
};
struct Meeting {
    string title;
    string date;
    string start_time;
    string duration;
    Status status = UNKNOWN;
    User* user;
};

struct MeetingEntity {
    string meeting_id;
    string room_id;
};

class MeetingLog {
    MeetingEntity meetingentity;
    Meeting meeting;
};

class MeetingRepository {
    private:
        vector<MeetingLog> db;
    public:
        void getMeetingRoom(string start_time, string duration){
            cout << "Find room 5";
        }
        void createMeeting(Meeting* meeting){
            getMeetingRoom(meeting->start_time, meeting->duration);
            populateDB(meeting);
        }
        void populateDB(Meeting* meeting){
            cout << "Created Meeting successfully";
        }
        void getMeeting(){}     
};
class NotificationService {
    public:
        void notify(Meeting* meeting)
        {
            /*for(auto i = meeting->user->email_id(); i!= meeting->user.end() ;i++)
            {
                cout << "Notifying this user";
            }*/
            cout << "Notified all the users";
        }
};
class MeetingService{
    private:
        NotificationService* notificationService;
        MeetingRepository* meetingRepository;
    public:
        MeetingService(NotificationService* notificationService, MeetingRepository* meetingRepository)
        {
            notificationService = notificationService;
            meetingRepository = meetingRepository;
        }
        void scheduleMeeting(Meeting* meeting){

            // take all the meeting details
            // Check if room is available
            // if not then return error otherwise
            //return booking details
            meetingRepository->createMeeting(meeting);
            notificationService->notify(meeting);
        }
        void cancelMeeting(Meeting* meeting){
            // take the meeting details 
            // freed the room

        }
        void updateMeeting(Meeting* meeting){

        }
};


int main()
{
    User user[2] = {{"khyatib", "gmail.com"}, {"shivani3","gmail.com"}};
    Meeting m[2];
    m[0].title = "A";
    m[0].date = "2023-04-10";
    m[0].start_time = "03:03";
    m[0].duration = 30;
    m[0].user = user;
    MeetingRepository* meetingRepository = new MeetingRepository();
    NotificationService* notificationService = new NotificationService();
    MeetingService* meetingservice = new MeetingService(notificationService, meetingRepository);
    meetingservice->scheduleMeeting(&m[0]);
    meetingservice->cancelMeeting(&m[0]);
    meetingservice->updateMeeting(&m[0]);
    return 0;
}
