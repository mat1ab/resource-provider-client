// resource_provider_client_server.cpp
#include "resource_provider_client_server.h"
#include <iostream>

ResourceProviderClientServer::ResourceProviderClientServer()
{
}

ResourceProviderClientServer::~ResourceProviderClientServer()
{
}

void ResourceProviderClientServer::run(int port)
{
    communicationModule.startListening(port);
}

std::string ResourceProviderClientServer::getGpuModel()
{
    // Implement a method to get GPU Model
    // Placeholder for example
    return "Nvidia GeForce GTX 1080";
}
