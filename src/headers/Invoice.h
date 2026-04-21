//
// Created by Jan Kaduch on 21.04.2026.
//

#ifndef SOUNDAPP_INVOICE_H
#define SOUNDAPP_INVOICE_H
#include <string>

class Date;

class Invoice {
private:
    static int totalInvoices; // Static member to keep track of total invoices created
    static int nextInvoiceId; // Static member to generate unique invoice IDs
    int id;
    std::string customerName; // Name of the customer associated with the invoice
    Date* date;
    double cost;

public:
    Invoice(std::string customername, Date* date, double cost);
    ~Invoice();

    double getCost() const;
    Date* getDate() const;

    std::string printInvoiceDetails();
};


#endif //SOUNDAPP_INVOICE_H