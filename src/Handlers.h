#pragma once

// All STL includes in alphabetical order
#include <fstream>
#include <memory>
#include <iostream>

// All Poco includes in alphabetical order
#include <Poco/Net/HTTPRequestHandler.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>
#include <Poco/Net/HTMLForm.h>

// All Project includes in alphabetical order
#include "Config.h"
#include "WorkWithFile.h"

//extern std::unique_ptr<Config> config;

class SiteHandler : public Poco::Net::HTTPRequestHandler
{
private:
	std::string fileName = "";
	std::shared_ptr<Config> config;
public:
	SiteHandler(std::shared_ptr<Config> pconfig, std::string url = "");

	virtual void handleRequest(Poco::Net::HTTPServerRequest& req,
		Poco::Net::HTTPServerResponse& res);
};
 