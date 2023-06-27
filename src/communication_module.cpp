#include "communication_module.h"
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>

CommunicationModule::CommunicationModule() : serverSocket(-1)
{
}

CommunicationModule::~CommunicationModule()
{
    if (serverSocket != -1)
    {
        close(serverSocket);
    }
}

void CommunicationModule::startListening(int port)
{
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1)
    {
        std::cerr << "Failed to create socket" << std::endl;
        return;
    }

    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(port);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    if (bind(serverSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) < 0)
    {
        std::cerr << "Failed to bind socket" << std::endl;
        return;
    }

    listen(serverSocket, 10);

    std::cout << "Listening on port " << port << std::endl;

    sockaddr_in clientAddress;
    socklen_t clientAddressSize = sizeof(clientAddress);
    int clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddress, &clientAddressSize);

    char buffer[256];
    memset(buffer, 0, 256);
    read(clientSocket, buffer, 255);

    std::string request(buffer);
    std::string response = handleRequest(request);
    send(clientSocket, response.c_str(), response.size(), 0);

    close(clientSocket);
}

std::string CommunicationModule::handleRequest(const std::string &request)
{
    if (request == "get_gpu_info")
    {
        return "Nvidia GeForce GTX 1080"; // Replace this with actual GPU info retrieval
    }
    return "Unknown request";
}
