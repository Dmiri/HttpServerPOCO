// Copyright 2015 cadovvl
// CommonRequestHandler.cpp 

#include "CommonRequestHandler.h"

CommonRequestHandler::CommonRequestHandler() 
{
}
Poco::Net::HTTPRequestHandler* CommonRequestHandler::createRequestHandler(
		const Poco::Net::HTTPServerRequest& request)
{
	if (request.getURI() != "/")
	{
		return new SiteHandler(request.getURI());
	}
	else//index.html
	{
		return new SiteHandler();
	}
 return nullptr;
}