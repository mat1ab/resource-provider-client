#pragma once

#include <string>

class CommunicationModule
{
public:
    CommunicationModule();
    ~CommunicationModule();

    void startListening(int port);
    std::string handleRequest(const std::string &request);

private:
    int serverSocket;
};
