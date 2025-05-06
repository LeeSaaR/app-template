#ifndef SENDERDATA_H
#define SENDERDATA_H

#include "commonletterdata.h"

class SenderData : public CommonLetterData
{
private:
    QString m_website;
    QString m_email;
    QString m_telephone;
    QString m_mobile;
    QString m_bank;
    QString m_bank_account;
    QString m_iban;
    QString m_bic;
    QString m_vat_number; // UstID

public:
    SenderData() : contact(new ContactData()){}
    ~SenderData(){delete contact;}
    ContactData *contact;

public:
    bool hasWebsite() const {return !m_website.isEmpty();}
    bool hasEmail() const {return !m_email.isEmpty();}
    bool hasTelephone() const {return !m_telephone.isEmpty();}
    bool hasMobile() const {return !m_mobile.isEmpty();}
    bool hasBankAccount() const {return !m_bank_account.isEmpty();}
    bool hasBank()const {return !m_bank.isEmpty();}
    bool hasIBAN() const {return !m_iban.isEmpty();}
    bool hasBIC() const {return !m_bic.isEmpty();}
    bool hasBankData() const { return hasIBAN(); }
    bool hasContact() const {return contact->hasContact();}
    bool hasVAT() const {return !m_vat_number.isEmpty();}

    QString bank() const { return m_bank; }
    QString bankAccount() const { return m_bank_account; }
    QString bic() const { return m_bic; }
    QString email() const { return m_email; }
    QString iban() const { return m_iban; }
    QString mobile() const { return m_mobile; }
    QString telephone() const { return m_telephone; }
    QString vat() const { return m_vat_number; }
    QString website() const { return m_website; }

    void website(const QString &website) { m_website = website; }
    void email(const QString &email_address) { m_email = email_address; }
    void telephone(const QString &phone_number) { m_telephone = phone_number; }
    void mobile(const QString &mobile_number) { m_mobile = mobile_number; }
    void bankAccount(const QString &bank_account_name) { m_bank_account = bank_account_name; }
    void bank(const QString &bank_name) { m_bank = bank_name; }
    void iban(const QString &iban) { m_iban = iban; }
    void bic(const QString &bic) { m_bic = bic; }
    void vat(const QString &vat_number) { m_vat_number = vat_number; }
    void setContact(
        const QString &email_address,
        const QString &phone_number,
        const QString &mobile_number)
    {
        email(email_address);
        telephone(phone_number);
        mobile(mobile_number);
    }
    void setBank(
        const QString &bank_name,
        const QString &iban_number,
        const QString &owner = "",
        const QString &bic_number = "")
    {
        bankAccount(owner);
        bank(bank_name);
        iban(iban_number);
        bic(bic_number);
    }

};

#endif // SENDERDATA_H
