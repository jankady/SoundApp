
#ifndef SOUNDAPP_USER_H
#define SOUNDAPP_USER_H
#include <string>

class MainPlatform;

/**
 * Base class of the user hierarchy. Holds identity (id, username, email) and a
 * back-pointer to the owning platform so subclasses can register content.
 * Polymorphic — has a virtual destructor so MainPlatform can delete
 * Artist/Customer through a User* pointer.
 */
class User {

private:
    static int totalUsers;   // running count of live users
    static int nextUserId;   //  id generator
    int userId;
    std::string username;
    std::string email;
    MainPlatform* mainPlatform;

public:
    User(std::string username, std::string email, MainPlatform* mainPlatform);
    virtual ~User();

    static int getTotalUsers();         // count of users currently alive
    int getUserId();                    // unique per-instance id
    std::string getUsername();
    std::string getEmail();
    MainPlatform* getMainPlatform();    // platform this user belongs to

    // Non-pure virtual — base provides a default implementation that prints
    // the generic user identity. Subclasses (Artist, Customer) override this
    // to change behavior (extend the output with role-specific data).
    // Called through User* from MainPlatform::users[] to demonstrate late
    // binding (grading point 7: změna chování s pozdní vazbou).
    virtual void printInfo();
};


#endif //SOUNDAPP_USER_H
