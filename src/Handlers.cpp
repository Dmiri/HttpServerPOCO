// Copyright 2015 cadovvl
// Handlers.cpp 
 
#include "Handlers.h"
 
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>

SiteHandler::SiteHandler(std::string url)
{
	std::cerr << "url: " << url << std::endl;
	if(url.length() > 1)
		fileName = config->defaultSiteDirectory + url;
	else
		fileName = config->defaultSiteDirectory + config->defaultController + config->defaultPage;

}

void SiteHandler::handleRequest(Poco::Net::HTTPServerRequest& req,
	Poco::Net::HTTPServerResponse& res)
{
	Poco::Net::HTMLForm form(req);
	//res.setContentType("multipart/x-mixed-replace; boundary=--MY_BOUND");
	std::ostream& reply = res.send();
	if (readFile(fileName, &reply))
		res.setStatus(Poco::Net::HTTPServerResponse::HTTP_OK);
	else res.setStatus(Poco::Net::HTTPServerResponse::HTTP_REASON_NOT_FOUND);

}

bool SiteHandler::readFile(std::string name, std::ostream* response_body)
{
	std::ifstream fread(name, std::ios::binary);
	if (fread.fail()) {
		std::cerr << "failed open file: " << name << '\n';
		return false;
	}
	std::string line = "";
	while (std::getline(fread, line)) {
		*response_body << line;
	}
	std::cerr << "read file: " << name << '\n';
	fread.close();
	return true;
}