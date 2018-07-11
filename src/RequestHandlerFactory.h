#pragma once

// All Poco includes in alphabetical order
#include <Poco/Net/HTTPRequestHandlerFactory.h>
#include <locale>

// All Project includes in alphabetical order
#include "Handlers.h"
#include "easylogging++.h"

class RequestHandlerFactory : public Poco::Net::HTTPRequestHandlerFactory
{
private:
	std::shared_ptr<Config> config;
public:
	RequestHandlerFactory(std::shared_ptr<Config> pconfig);
	virtual Poco::Net::HTTPRequestHandler* createRequestHandler(
		const Poco::Net::HTTPServerRequest& request);
};
