//#include <Poco/Util/ServerApplication.h>
//#include <Poco/Net/HTTPServer.h>

#include <iostream>
#include "Config.h"
#include "Listener.h"

std::unique_ptr<Config, std::default_delete<Config>> config(std::make_unique<Config>());

POCO_SERVER_MAIN(Listener)

