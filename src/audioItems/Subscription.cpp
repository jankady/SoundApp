//
// Created by Jan Kaduch on 21.04.2026.
//

#include "Subscription.h"

#include "Date.h"

int Subscription::totalSubscriptions = 0;

// Overload #1: explicit end date (typically used for PREMIUM).
Subscription::Subscription(SubscriptionType type, Date* endDate) {
    this->subscriptionName = type;
    this->endDate = endDate;
    this->isActive = true;
    Subscription::totalSubscriptions++;
}

// Overload #2: no end date — used for FREE tier.
Subscription::Subscription(SubscriptionType type) {
    this->subscriptionName = type;
    this->endDate = nullptr;
    this->isActive = true;
    Subscription::totalSubscriptions++;
}

// Owns the end Date — release it here.
Subscription::~Subscription() {
    delete this->endDate;
    Subscription::totalSubscriptions--;
}

bool Subscription::setSubscriptionType(SubscriptionType type) {
    this->subscriptionName = type;
    if (type == FREE) {
        this->endDate = nullptr;
        this->isActive = false;
    } else if (type == PREMIUM) {
        this->endDate = new Date(1, 1, 2027);
    }
    return true;
}

bool Subscription::getIsActive() const {
    return this->isActive;
}

SubscriptionType Subscription::getType() const {
    return this->subscriptionName;
}

Date* Subscription::getEndDate() const {
    return this->endDate;
}