#include "RequestHandlerFactory.h"

RequestHandlerFactory::RequestHandlerFactory(std::shared_ptr<Config> pconfig)
{
	config = pconfig;
}

Poco::Net::HTTPRequestHandler* RequestHandlerFactory::createRequestHandler(
		const Poco::Net::HTTPServerRequest& request)
{
	// On any request other than this will return an error code 501
	if(request.getURI() == "/test" || request.getURI() == "/test/")
		return new SiteHandler(config);
	else 
		LOG(INFO) << request.getURI();
 return nullptr;
}
