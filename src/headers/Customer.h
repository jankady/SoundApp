//
// Created by Jan Kaduch on 21.04.2026.
//

#ifndef SOUNDAPP_CUSTOMER_H
#define SOUNDAPP_CUSTOMER_H
#include "User.h"

class User;
class Playlist;

class Customer: public User{
private:
    static int totalCustomers; // Static member to keep track of total customers created
    Playlist** playlists;

};


#endif //SOUNDAPP_CUSTOMER_H