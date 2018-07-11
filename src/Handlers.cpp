#include "Handlers.h"


SiteHandler::SiteHandler(std::shared_ptr<Config> pconfig, std::string url)
{
	config = pconfig;
	if(url.length() > 1)
		fileName = config->getDefaultSiteDirectory() + url;
	else
		fileName = config->getDefaultSiteDirectory() + config->getDefaultController() + config->getDefaultPage();

}


void SiteHandler::handleRequest(Poco::Net::HTTPServerRequest& req,
	Poco::Net::HTTPServerResponse& res)
{
	Poco::Net::HTMLForm form(req);
	std::ostream& reply = res.send();
	if (WorkWithFile::readFile(fileName, &reply, &std::cerr))
		res.setStatus(Poco::Net::HTTPServerResponse::HTTP_OK);
	else res.setStatus(Poco::Net::HTTPServerResponse::HTTP_REASON_NOT_FOUND);

}


