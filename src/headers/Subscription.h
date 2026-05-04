//
// Created by Jan Kaduch on 21.04.2026.
//

#ifndef SOUNDAPP_SUBSCRIPTION_H
#define SOUNDAPP_SUBSCRIPTION_H

// Subscription tiers. PREMIUM has an end date, FREE does not.
enum SubscriptionType {
    FREE,
    PREMIUM
};

class Date;

/**
 * Held by composition inside Customer. Represents the customer's current
 * subscription tier and (for PREMIUM) when it expires. Demonstrates "class in
 * the role of an object" — Date is held as a member.
 */
class Subscription {
private:
    int static totalSubscriptions; // running count of live subscriptions
    bool isActive;
    SubscriptionType subscriptionName;
    Date* endDate;                 // owned: nullptr for FREE

public:
    // Overloaded constructors: with or without an explicit end date.
    Subscription(SubscriptionType type, Date* endDate);
    Subscription(SubscriptionType type);
    ~Subscription();

    // Switch tier. Sets endDate accordingly (clears for FREE).
    bool setSubscriptionType(SubscriptionType type);

    bool getIsActive() const;
    SubscriptionType getType() const;
    Date* getEndDate() const;


};


#endif //SOUNDAPP_SUBSCRIPTION_H
