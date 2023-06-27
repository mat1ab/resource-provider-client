#pragma once

#include "communication_module.h"
#include <string>

class ResourceProviderClientServer {
public:
    ResourceProviderClientServer();
    ~ResourceProviderClientServer();

    void run(int port);
    std::string getGpuModel();

private:
    CommunicationModule communicationModule;
};
