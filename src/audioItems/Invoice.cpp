//
// Created by Jan Kaduch on 21.04.2026.
//

#include "../headers/Invoice.h"

#include "Date.h"

int Invoice::totalInvoices = 0;
int Invoice::nextInvoiceId = 1;

Invoice::Invoice(std::string customername,  Date* date, double cost) {
    this->id = Invoice::nextInvoiceId++;
    this->customerName = customername;
    this->date = date; // Date will be set later
    this->cost = cost; // Default cost, can be updated later
    Invoice::totalInvoices++;
}

Invoice::~Invoice() {
    delete this->date; // Clean up the date object
    Invoice::totalInvoices--;
}

double Invoice::getCost() const {
    return this->cost;
}

Date* Invoice::getDate() const {
    return this->date;
}

std::string Invoice::printInvoiceDetails() {
    std::string text;
    text += "Invoice ID: " + std::to_string(this->id) + "\n";
    text += "Date: " + std::to_string(this->date->getDay())
            + "/" + std::to_string(this->date->getMonth())
            + "/" + std::to_string(this->date->getYear()) + "\n";
    text += "Customer: " + this->customerName + "\n";
    text += "Cost: $" + std::to_string(this->cost) + "\n";
    return text;
}