// Copyright 2015 cadovvl
// Handlers.h
#ifndef SERVER_HANDLERS_H_
#define SERVER_HANDLERS_H_

#include <Poco/Net/HTTPRequestHandler.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>
#include <Poco/Net/HTMLForm.h>
#include <iostream>
#include <string>
#include <memory>
#include "Config.h"


extern std::unique_ptr<Config, std::default_delete<Config>> config;

class SiteHandler : public Poco::Net::HTTPRequestHandler
{
private:
	std::string fileName = "";
public:
	SiteHandler(std::string url = "");

	virtual void handleRequest(Poco::Net::HTTPServerRequest& req,
		Poco::Net::HTTPServerResponse& res);

	bool readFile(std::string name, std::ostream* response_body);
};
 
#endif // SERVER_HANDLERS_H_ 