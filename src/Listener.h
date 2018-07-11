#pragma once
 
// All STL includes in alphabetical order
#include <string>
#include <memory>

// All Poco includes in alphabetical order
#include <Poco/Util/ServerApplication.h>
 
// All Project includes in alphabetical order
#include "Config.h"
#include "RequestHandlerFactory.h"

class Listener : public Poco::Util::ServerApplication {
	virtual int main(const std::vector<std::string>& args) {
		//std::unique_ptr<Config> config(std::make_unique<Config>());
		std::shared_ptr<Config> config(std::make_shared<Config>());
		Poco::Net::HTTPServerParams* params = config->getConfig();
		Poco::Net::HTTPServer server(
			new RequestHandlerFactory(config),
			config->getSocket(),
			params);

		server.start();
		waitForTerminationRequest();
		server.stop();

		return 0;
	}

};
