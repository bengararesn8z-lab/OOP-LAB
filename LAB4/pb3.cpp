#include <bits/stdc++.h>
using namespace std;
class Client {
private:
    string name;
public:
    Client(const string& name = "") : name(name) {}
    const string& getName() const { return name; }
};
class Review {
private:
    string content;
    const Client* reviewer;
public:
    Review(const string& content, const Client* reviewer)
        : content(content), reviewer(reviewer) {}
    const string& getContent() const { return content; }
    const Client* getReviewer() const { return reviewer; }
    void print() const {
        cout << "Reviewer: " << (reviewer ? reviewer->getName() : "Anonim") << "\n";
        cout << "Review: " << content << "\n";
    }
    bool matchesText(const string& text) const {
        if (!reviewer) return content.find(text) != string::npos;
        bool inReview = content.find(text) != string::npos;
        bool inName = reviewer->getName().find(text) != string::npos;
        return inReview || inName;
    }
};
class Book {
private:
    string title;
    string author;
    vector<Review> reviews;
public:
    Book(const string& title = "", const string& author = "")
        : title(title), author(author) {}
    const string& getTitle() const { return title; }
    const string& getAuthor() const { return author; }
    void addReview(const Review& r) {
        reviews.push_back(r);
    }
    void printReviews() const {
        cout << "Reviews for book: \"" << title << "\" by " << author << " ===\n";
        if (reviews.empty()) {
            cout << "Nu exista review-uri.\n";
        } else {
            for (const auto& r : reviews) {
                r.print();
            }
        }
    }
    vector<const Review*> searchReviewsByText(const string& text) const {
        vector<const Review*> result;
        for (const auto& r : reviews) {
            if (r.matchesText(text)) {
                result.push_back(&r);
            }
        }
        return result;
    }
};
class Library {
private:
    vector<Book> books;
public:
    void addBook(const Book& b) {
        books.push_back(b);
    }
    const vector<Book>& getBooks() const { return books; }
    vector<pair<const Book*, const Review*>> searchTextInReviews(const string& text) const {
        vector<pair<const Book*, const Review*>> result;
        for (const auto& book : books) {
            auto matches = book.searchReviewsByText(text);
            for (const auto& rPtr : matches) {
                result.push_back({ &book, rPtr });
            }
        }
        return result;
    }
};
int main() {
    Client c1("Andrei Popescu");
    Client c2("Maria Ionescu");
    Client c3("Ion Reviewer");
    Book b1("Clean Code", "Robert C. Martin");
    Book b2("The Pragmatic Programmer", "Andrew Hunt");
    b1.addReview(Review("Cartea este foarte utila pentru programatori.", &c1));
    b1.addReview(Review("Mi-a placut mult capitolul despre code smells.", &c2));
    b2.addReview(Review("Explica bine principiile de dezvoltare software.", &c2));
    b2.addReview(Review("Autorii au exemple practice foarte bune.", &c3));
    Library lib;
    lib.addBook(b1);
    lib.addBook(b2);
    b1.printReviews();
    string textCautat = "Andrei";
    cout << "Cautam textul: \"" << textCautat << "\" in reviews si in numele reviewer-ilor\n\n";
    auto results = lib.searchTextInReviews(textCautat);
    if (results.empty()) {
        cout << "Nu s-au gasit review-uri care contin textul cautat.\n";
    } else {
        for (const auto& pairBR : results) {
            const Book* book = pairBR.first;
            const Review* rev = pairBR.second;
            cout << "Cartea: \"" << book->getTitle()
                 << "\" de " << book->getAuthor() << "\n";
            rev->print();
        }
    }
    return 0;
}
