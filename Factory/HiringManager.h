#pragma once
#include "Interviewer.h"
#include <memory>

class HiringManager {
public:
    virtual ~HiringManager() {}

    virtual std::unique_ptr<Interviewer> createInterviewer() = 0;
};

class DeveloperManager: public HiringManager {
public:
    ~DeveloperManager() {}

    std::unique_ptr<Interviewer> createInterviewer() {
        return std::make_unique<Developer>();
    }
};

class CommunityManager: public HiringManager {
public:
    ~CommunityManager() {}

    std::unique_ptr<Interviewer> createInterviewer() {
        return std::make_unique<CommunityExecutive>();
    }
};