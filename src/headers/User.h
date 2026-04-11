//
// Created by Jan Kaduch on 11.04.2026.
//

#ifndef SOUNDAPP_USER_H
#define SOUNDAPP_USER_H
#include <string>


class User {

private:
    static int totalUsers; // Static member to keep track of total users created
    static int nextUserId; // Static member to generate unique user IDs
    int userId;
    std::string username;
    std::string email;

public:
    User(std::string username, std::string email);
    ~User();

    static int getTotalUsers();
    int getUserId();
    std::string getUsername();
    std::string getEmail();
};


#endif //SOUNDAPP_USER_H