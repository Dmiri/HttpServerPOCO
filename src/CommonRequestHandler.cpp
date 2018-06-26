// Copyright 2015 cadovvl
// CommonRequestHandler.cpp 

#include "CommonRequestHandler.h"
#include <locale>

CommonRequestHandler::CommonRequestHandler() 
{
}
Poco::Net::HTTPRequestHandler* CommonRequestHandler::createRequestHandler(
		const Poco::Net::HTTPServerRequest& request)
{
	if(request.getURI() == "/test" || request.getURI() == "/test/")
		return new SiteHandler();

	//auto controller = Controller::Undefined;
	//std::string uri = request.getURI();
	//std::string controllerName = "";
	//if (uri.length() > 1)
	//{
	//	for (size_t i = 0; i < uri.length() && uri[i] != '/' || i < 1; ++i) {
	//		controllerName += uri[i];
	//	}
	//	uri.erase(0, controllerName.length());
	//	if (controllerName != "") {
	//		if (controllerName == "/test") {
	//			//controller = Controller::Test;
	//		}
	//	}
	//}
	//else {
	//	controller = Controller::Default;
	//}

	//switch (controller)
	//{
	//case Controller::Test:
	//{
	//	if (uri.length() < 2)
	//		uri = "/index.html";
	//	return new SiteHandler(controllerName + uri);
	//}
	//case Controller::Undefined:
	//{
	//	return new SiteHandler(request.getURI());
	//}
	//default:
	//	return new SiteHandler();
	//	break;
	//}

	//if (request.getURI() != "/")
	//{
	//	return new SiteHandler(request.getURI());
	//}
	//else//index.html
	//{
	//	return new SiteHandler();
	//}
 return nullptr;
}