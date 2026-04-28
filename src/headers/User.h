
#ifndef SOUNDAPP_USER_H
#define SOUNDAPP_USER_H
#include <string>

class MainPlatform;

class User {

private:
    static int totalUsers; // Static member to keep track of total users created
    static int nextUserId; // Static member to generate unique user IDs
    int userId;
    std::string username;
    std::string email;
    MainPlatform* mainPlatform;

public:
    User(std::string username, std::string email, MainPlatform* mainPlatform);
    virtual ~User();

    static int getTotalUsers();
    int getUserId();
    std::string getUsername();
    std::string getEmail();
    MainPlatform* getMainPlatform();
};


#endif //SOUNDAPP_USER_H