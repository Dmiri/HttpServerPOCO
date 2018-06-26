#ifndef SERVER_LISTENER_H_
#define SERVER_LISTENER_H_
 
#include <Poco/Util/ServerApplication.h>
#include <Poco/Net/HTTPServer.h>
 
#include <vector>
#include <string>
#include <iostream>
#include <memory>
 
#include "Config.h"
#include "CommonRequestHandler.h"

#include <Poco/Net/HTTPRequestHandler.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>

class Listener : public Poco::Util::ServerApplication {
	virtual int main(const std::vector<std::string>& args) {
		extern std::unique_ptr<Config, std::default_delete<Config>> config;

		Poco::Net::HTTPServerParams* params = config->getConfig();
		Poco::Net::HTTPServer server(
			new CommonRequestHandler(),
			config->socket,
			params);

		server.start();
		waitForTerminationRequest();
		server.stop();

		return 0;
	}

};
#endif // SERVER_LISTENER_H_