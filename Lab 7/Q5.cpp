#include <iostream>
using namespace std;

class Media {
protected:
    string title, publicationDate, uniqueID, publisher;
public:
    Media(string t, string pD, string uID, string pub)
        : title(t), publicationDate(pD), uniqueID(uID), publisher(pub) {}
    virtual void displayInfo() = 0;
    virtual void checkOut() {
        cout << "Checking out: " << title << endl;
    }
    virtual void returnItem() {
        cout << "Returning: " << title << endl;
    }
    virtual ~Media() {}
};

class Book : public Media {
private:
    string author, ISBN;
    int numberOfPages;
public:
    Book(string t, string pD, string uID, string pub, string a, string isbn, int nP)
        : Media(t, pD, uID, pub), author(a), ISBN(isbn), numberOfPages(nP) {}
    void displayInfo() override {
        cout << "Book: " << title << " by " << author << ", ISBN: " << ISBN << ", Pages: " << numberOfPages << endl;
    }
};

class DVD : public Media {
private:
    string director;
    int duration;
    double rating;
public:
    DVD(string t, string pD, string uID, string pub, string d, int dur, double r)
        : Media(t, pD, uID, pub), director(d), duration(dur), rating(r) {}
    void displayInfo() override {
        cout << "DVD: " << title << " directed by " << director << ", Duration: " << duration << " mins, Rating: " << rating << endl;
    }
};

class CD : public Media {
private:
    string artist, genre;
    int numberOfTracks;
public:
    CD(string t, string pD, string uID, string pub, string a, int nT, string g)
        : Media(t, pD, uID, pub), artist(a), numberOfTracks(nT), genre(g) {}
    void displayInfo() override {
        cout << "CD: " << title << " by " << artist << ", Tracks: " << numberOfTracks << ", Genre: " << genre << endl;
    }
};

void searchMedia(string title) {
    cout << "Searching for media with title: " << title << endl;
}

void searchMedia(string title, string author) {
    cout << "Searching for book titled '" << title << "' by author: " << author << endl;
}

void searchMedia(int year) {
    cout << "Searching for media published in year: " << year << endl;
}

int main() {
    Book b1("C++ Primer", "2019", "B101", "Pearson", "Lippman", "978-0321714114", 970);
    DVD d1("Inception", "2010", "D202", "Warner Bros", "Christopher Nolan", 148, 8.8);
    CD c1("Thriller", "1982", "C303", "Epic", "Michael Jackson", 9, "Pop");
    
    Media* library[3] = { &b1, &d1, &c1 };
    
    for (int i = 0; i < 3; i++) {
        library[i]->displayInfo();
        library[i]->checkOut();
        library[i]->returnItem();
    }
    
    searchMedia("C++ Primer");
    searchMedia("C++ Primer", "Lippman");
    searchMedia(2010);
    
    return 0;
}
