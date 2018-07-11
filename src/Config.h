#pragma once

// All Poco includes in alphabetical order
#include <string>

// All Project includes in alphabetical order
#include <Poco/Net/HTTPServer.h>

//must be serialazed
class Config
{
private:
	bool config = false;
	std::string defaultSiteDirectory{ "../../site" };
	std::string defaultController{ "/test" };
	std::string defaultPage {"/Index.html"};
	//Poco::Timespan & ThreadIdleTime{};
	//Poco::Thread::Priority ThreadPriority{};
	//Sets the name and port (name:port) that the server uses to identify itself.
	const std::string & serverName{"localhost"};
	Poco::Net::ServerSocket socket{9999}; // argument is a port 
	int maxQueued {1000};
	int maxThreads{4};
	//Enables (keepAlive == true) or disables (keepAlive == false) persistent connections.
	bool keepAlive{false};
	//Sets the connection timeout for HTTP connections.
	const Poco::Timespan & keepAliveTimeout{1000};
	//Specifies the maximum number of requests allowed during a persistent connection. 0 means unlimited connections.
	int maxKeepAliveRequests{1000};
	//The format of the softwareVersion string should be name/version (e.g. MyHTTPServer/1.0).
	std::string softwareVersion{""};
	//Sets the connection timeout for HTTP connections.
	const Poco::Timespan & timeout{10000};
	
public:
	std::string getDefaultSiteDirectory() { return defaultSiteDirectory; };//{ "../../site" };
	std::string getDefaultController() { return defaultController; };//{ "/test" };
	std::string getDefaultPage() { return defaultPage; };// {"/Index.html"};
	const std::string & getServerName() { return serverName; };//{"localhost"};
	Poco::Net::ServerSocket getSocket() { return socket; };//{9999}; // argument is a port 
	int getMaxQueued() { return maxQueued; };// {1000};
	int getMaxThreads() { return maxThreads; };//{4};
	bool getKeepAlive() { return keepAlive; };//{false};
	const Poco::Timespan & getKeepAliveTimeout() { return keepAliveTimeout; };//{1000};
	int getMaxKeepAliveRequests() { return maxKeepAliveRequests; };//{1000};
	std::string getSoftwareVersion() { return softwareVersion; };//{""};
	const Poco::Timespan & getTimeout() { return timeout; };//{10000};


	Poco::Net::HTTPServerParams*  getConfig()
	{
		Poco::Net::HTTPServerParams* PocoConfig = new Poco::Net::HTTPServerParams();
		PocoConfig->setTimeout(this->timeout);
		PocoConfig->setMaxQueued(this->maxQueued);
		PocoConfig->setMaxThreads(this->maxThreads);
		PocoConfig->setKeepAliveTimeout(this->keepAliveTimeout);
		return PocoConfig;
	}
};
