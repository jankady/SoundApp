//
// Created by Jan Kaduch on 21.04.2026.
//

#include "Subscription.h"

#include "Date.h"

int Subscription::totalSubscriptions = 0;

Subscription::Subscription(SubscriptionType type, Date* endDate) {
    this->type = type;
    this->endDate = endDate;
    this->isActive = true; // Assuming subscription is active upon creation
    Subscription::totalSubscriptions++;
}

Subscription::Subscription(SubscriptionType type) {
    this->type = type;
    this->endDate = nullptr; // No end date for free subscription
    this->isActive = true; // Assuming subscription is active upon creation
    Subscription::totalSubscriptions++;
}

Subscription::~Subscription() {
    delete this->endDate; // Clean up the end date if it exists
    Subscription::totalSubscriptions--;
}

bool Subscription::setSubscriptionType(SubscriptionType type) {
    this->type = type;
    if (type == FREE) {
        this->endDate = nullptr; // Free subscription has no end date
        this->isActive = false;
    } else if (type == PREMIUM) {

        this->endDate = new Date(1, 1, 2027); // Placeholder date
    }
   return true;
}