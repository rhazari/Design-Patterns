#pragma once

#include "IObserver.h"
#include "Subject.h"


class Observer: public IObserver{
    int _id;
    static int _count;
    std::string _message;
    Subject& _subject;

public:
    Observer(Subject& subject): _subject(subject){
        ++Observer::_count;
        this->_id = Observer::_count;
        this->_subject.AttachObserver(this);
    }

    virtual ~Observer() {
        std::cout<<"Destroying the Observer\n";
    }

    int getId() const {
        return _id;
    }

    void Update(const std::string& message){
        _message = message;
        std::cout<<"Message for Observer: "<<_id<<"\n";
    }

    void RemoveFromList(){
        _subject.DetachObserver(this);
        std::cout<<"Observer: "<<_id<<" remove from the Observer list\n";
    }
};