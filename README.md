# Qt & Pistache-Based Web Server Application

## Overview
This project is a **Qt-based GUI application** integrated with a **Pistache HTTP server**, enabling a local web server with RESTful API endpoints. The application serves HTTP requests, processes data, and provides a graphical user interface.

## Features
- **Qt GUI Integration**: A main window built using Qt for graphical interaction.
- **Pistache HTTP Server**: Lightweight RESTful API handling GET and POST requests.
- **Multithreading**: The web server runs on a separate thread to maintain GUI responsiveness.
- **CMake Build System**: Configured with CMake for easy compilation and cross-platform support.
- **Localization Support**: Translations enabled with Qt Linguist (`.ts` files).

## Prerequisites
Ensure you have the following dependencies installed:

### Required Software:
- Qt 5 or Qt 6 (with Qt Widgets module)
- Pistache (C++ HTTP framework)
- CMake (version 3.5 or higher)
- A C++17 compatible compiler (GCC, Clang, MSVC)

### Installation Instructions:
#### Install Qt
```sh
sudo apt update
sudo apt install qtbase5-dev qtchooser qt5-qmake qtbase5-dev-tools
```

#### Install Pistache
```sh
git clone https://github.com/oktal/pistache.git
cd pistache
mkdir build && cd build
cmake -G "Unix Makefiles" ..
make
sudo make install
```

## Compilation and Execution

### Build the Project
```sh
mkdir build && cd build
cmake ..
make
```

### Run the Application
```sh
./untitled
```

## Code Structure
```
├── CMakeLists.txt           # CMake build configuration
├── main.cpp                 # Application entry point
├── mainwindow.cpp           # Main window logic
├── mainwindow.h             # Main window header file
├── mainwindow.ui            # UI file for Qt Designer
├── server.h                 # Pistache server configuration
├── untitled_en_GB.ts        # Translation file for localization
```

## REST API Endpoints
The Pistache web server exposes the following RESTful endpoints:

### GET /
- **Description**: Returns a simple greeting.
- **Example Request**:
  ```sh
  curl -X GET http://localhost:8080/
  ```
- **Response**:
  ```
  Hello, Pistache!
  ```

### GET /api/info
- **Description**: Returns API version information.
- **Example Request**:
  ```sh
  curl -X GET http://localhost:8080/api/info
  ```
- **Response**:
  ```
  API Information: Version 1.0
  ```

### POST /api/data
- **Description**: Accepts and processes data.
- **Example Request**:
  ```sh
  curl -X POST -d "example_data" http://localhost:8080/api/data
  ```
- **Response**:
  ```
  Received POST request with data: example_data
  ```

## Localization Support
This project supports localization using Qt Linguist:
- **Translation Source File**: `untitled_en_GB.ts`
- **Generate `.qm` files**:
  ```sh
  lrelease untitled_en_GB.ts
  ```

## Possible Enhancements
- **Database Integration**: Store and retrieve data via a database (e.g., SQLite, PostgreSQL).
- **WebSocket Support**: Enable real-time data exchange.
- **Authentication System**: Secure API endpoints with user authentication.
- **Cross-Platform Deployment**: Package the application for Windows, Linux, and macOS.

## Author
**Mahmoud Hany** - Computer Engineering Student & AI Enthusiast

## License
This project is licensed under the MIT License.

