//
// Created by Jan Kaduch on 21.04.2026.
//

#ifndef SOUNDAPP_INVOICE_H
#define SOUNDAPP_INVOICE_H
#include <string>

class Date;

/**
 * Standalone receipt-like value object: id, customer name, date and cost.
 * Holds Date by composition (class in the role of an object).
 */
class Invoice {
private:
    static int totalInvoices;      // running count of live invoices
    static int nextInvoiceId;      // monotonic id generator
    int id;
    std::string customerName;
    Date* date;                    // owned
    double cost;

public:
    Invoice(std::string customername, Date* date, double cost);
    ~Invoice();

    double getCost() const;
    Date* getDate() const;

    // Multi-line human-readable rendering of the invoice.
    std::string printInvoiceDetails();
};


#endif //SOUNDAPP_INVOICE_H
