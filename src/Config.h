#ifndef CONFIG_H_
#define CONFIG_H_
#include <string>
#include <Poco/Net/HTTPServerParams.h>
//#include <Poco/Net/HTTPServer.h>

//must be serialazed
class Config
{
public:
	bool config = true;
	std::string defaultSiteDirectory{ "site" };
	std::string defaultPage {"index.html"};
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

	Poco::Net::HTTPServerParams*  getConfig()
	{
		Poco::Net::HTTPServerParams *PocoConfig = new Poco::Net::HTTPServerParams();
		PocoConfig->setTimeout(this->timeout);
		PocoConfig->setMaxQueued(this->maxQueued);
		PocoConfig->setMaxThreads(this->maxThreads);
		PocoConfig->setKeepAliveTimeout(this->keepAliveTimeout);
		return PocoConfig;
	}
};
#endif // CONFIG_H_ 