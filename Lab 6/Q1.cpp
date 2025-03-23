#include <iostream>
using namespace std;

class Message {
private:
    string text;

public:
    Message(string t = "") : text(t) {}
    string toString() const { return text; }
    void setText(string t) { text = t; }
};

class SMS : public Message {
private:
    string recipientContactNo;

public:
    SMS(string t, string contact) : Message(t), recipientContactNo(contact) {}
    string getRecipient() const { return recipientContactNo; }
    void setRecipient(string contact) { recipientContactNo = contact; }
    string toString() const { return recipientContactNo + " - " + Message::toString(); }
};

class Email : public Message {
private:
    string sender, receiver, subject;

public:
    Email(string t, string s, string r, string sub) : Message(t), sender(s), receiver(r), subject(sub) {}
    string getSender() const { return sender; }
    string getReceiver() const { return receiver; }
    string getSubject() const { return subject; }
    void setSender(string s) { sender = s; }
    void setReceiver(string r) { receiver = r; }
    void setSubject(string sub) { subject = sub; }
    string toString() const { return "From: " + sender + "\nTo: " + receiver + "\nSubject: " + subject + "\n" + Message::toString(); }
};

bool ContainsKeyword(const Message& messageObject, const string& keyword) {
    return messageObject.toString().find(keyword) != string::npos;
}

string encodeMessage(const string& message) {
    string encoded = message;
    for (char &c : encoded) {
        if (isalpha(c)) {
            if (c == 'Z') c = 'A';
            else if (c == 'z') c = 'a';
            else c++;
        }
    }
    return encoded;
}

int main() {
    SMS sms("Hello, how are you?", "1234567890");
    Email email("This is a test email.", "alice@example.com", "bob@example.com", "Greetings");

    cout << "SMS: " << sms.toString() << "\n";
    cout << "Email: \n" << email.toString() << "\n";

    string keyword = "test";
    cout << "Keyword \"" << keyword << "\" in email: " << (ContainsKeyword(email, keyword) ? "Yes" : "No") << "\n";

    string msg = "This is Java";
    cout << "Original: " << msg << "\nEncoded: " << encodeMessage(msg) << "\n";
    
    return 0;
}

