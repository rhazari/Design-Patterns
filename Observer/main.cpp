#include "Subject.h"
#include "Observer.h"

int Observer::_count = 0;

int main() {
    Subject *subject = new Subject();

    Observer *ob1 = new Observer(*subject);
    Observer *ob2 = new Observer(*subject);
    Observer *ob3 = new Observer(*subject);

    subject->CreateMessage("This is the first message");
    ob3->RemoveFromList();

    subject->CreateMessage("This is the second message");

    Observer *ob4 = new Observer(*subject);
    subject->CreateMessage("This is the third message");

    delete subject;
    delete ob1;
    delete ob2;
    delete ob3;
    delete ob4;
}