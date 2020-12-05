#pragma once
#include "Interviewer.h"

class HiringManager {
public:
    virtual ~HiringManager() {}

    virtual Interviewer* createInterviewer() = 0;

    void removeInterviewer(Interviewer* pr){
        delete pr;
    }
};

class DeveloperManager: public HiringManager {
public:
    ~DeveloperManager() {}

    Interviewer* createInterviewer() {
        return new Developer();
    }
};

class CommunityManager: public HiringManager {
public:
    ~CommunityManager() {}

    Interviewer* createInterviewer() {
        return new CommunityExecutive();
    }
};