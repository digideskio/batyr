#include "notfoundhandler.h"
#include "../response.h"
#include "../config.h"

#include <Poco/Net/HTTPResponse.h>
#include <iostream>

using namespace Batyr::HttpRequest;

void
NotFoundHandler::handleRequest(Poco::Net::HTTPServerRequest &req, Poco::Net::HTTPServerResponse &resp)
{
    resp.setStatus(Poco::Net::HTTPResponse::HTTP_NOT_FOUND);
    resp.setContentType("application/json");
    resp.setReason("Not Found");
    resp.set("Server", APP_NAME_SERVER_FULL);

    Response response;
    response.setErrorMessage("Endpoint not found");

    std::ostream & out = resp.send();
    out << response;
    out.flush();
};