#pragma once
#include <iostream>
#include <string>


// Define the Interviewer interface
class Interviewer{
public:
    virtual ~Interviewer() {}

    virtual std::string getName() = 0;

    virtual std::string askQuestion() = 0;
};


class Developer: public Interviewer {
public:
    ~Developer() {}

    std::string getName() {
        return "Developer";
    }

    std::string askQuestion() {
        return "Ask about design patterns";
    }
};


class CommunityExecutive: public Interviewer {
public:
    ~CommunityExecutive() {}

    std::string getName() {
        return "CommunityExecutive";
    }

    std::string askQuestion() {
        return "Ask about community building";
    }
};