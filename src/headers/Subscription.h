//
// Created by Jan Kaduch on 21.04.2026.
//

#ifndef SOUNDAPP_SUBSCRIPTION_H
#define SOUNDAPP_SUBSCRIPTION_H

enum SubscriptionType {
    FREE,
    PREMIUM
};

class Date;

class Subscription {
private:
    int static totalSubscriptions; // Static member to keep track of total subscriptions created
    bool isActive;
    SubscriptionType type;
    Date* endDate;

public:
    Subscription(SubscriptionType type, Date* endDate);
    Subscription(SubscriptionType type);
    ~Subscription();

    bool setSubscriptionType(SubscriptionType type);

    bool getIsActive() const;
    SubscriptionType getType() const;
    Date* getEndDate() const;


};


#endif //SOUNDAPP_SUBSCRIPTION_H