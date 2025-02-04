#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <pistache/endpoint.h>
#include <pistache/router.h>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Pistache::Address addr(Pistache::Ipv4::any(), Pistache::Port(8080));
    auto opts = Pistache::Http::Endpoint::options().threads(1);
    auto server = std::make_shared<Pistache::Http::Endpoint>(addr);
    server->init(opts);

    Pistache::Rest::Router router;

    // Route for GET /
    router.get("/", [](const Pistache::Rest::Request&, Pistache::Http::ResponseWriter response) -> Pistache::Rest::Route::Result {
        response.send(Pistache::Http::Code::Ok, "Hello, Pistache!");
        return Pistache::Rest::Route::Result::Ok;
    });

    // Route for GET /api/info
    router.get("/api/info", [](const Pistache::Rest::Request&, Pistache::Http::ResponseWriter response) -> Pistache::Rest::Route::Result {
        response.send(Pistache::Http::Code::Ok, "API Information: Version 1.0");
        return Pistache::Rest::Route::Result::Ok;
    });
    //curl -X POST -d "example_data","mahmoud hany fathalla" http://localhost:8080/api/data

    // Route for POST /api/data
    // Define a route for POST requests to /api/data
    router.post("/api/data", [](const Pistache::Rest::Request& request, Pistache::Http::ResponseWriter response) -> Pistache::Rest::Route::Result {
        // Process the POST request, for example, access request body
        std::string requestBody = request.body();

        // Send a response
        response.send(Pistache::Http::Code::Ok, "Received POST request with data: " + requestBody);
        return Pistache::Rest::Route::Result::Ok;
    });


    server->setHandler(router.handler());

    std::thread serverThread([server]() {
        server->serve();
    });
    serverThread.detach();

    std::cout << "Pistache server is running on port 8080." << std::endl;
}

MainWindow::~MainWindow()
{
    delete ui;
}
