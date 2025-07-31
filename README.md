# wxWidgets OpenGL Application

This project is a simple desktop application built using wxWidgets and OpenGL. It renders a 2D scene with interactive elements, including a clickable button, a side panel with a slider, and a checkbox. The application allows users to interact with the OpenGL scene through these UI components.

## Project Structure

```
wxwidgets-opengl-app
├── src
│   ├── main.cpp          # Entry point of the application
│   ├── App.h             # Header for the App class
│   ├── App.cpp           # Implementation of the App class
│   ├── MainFrame.h       # Header for the MainFrame class
│   ├── MainFrame.cpp     # Implementation of the MainFrame class
│   ├── GLCanvas.h        # Header for the GLCanvas class
│   ├── GLCanvas.cpp      # Implementation of the GLCanvas class
│   └── panels
│       ├── SidePanel.h   # Header for the SidePanel class
│       └── SidePanel.cpp # Implementation of the SidePanel class
├── CMakeLists.txt        # CMake configuration file
└── README.md             # Project documentation
```

## Setup Instructions

1. **Install wxWidgets**: Make sure you have wxWidgets installed on your system. You can download it from [wxWidgets website](https://www.wxwidgets.org/downloads/).

2. **Install OpenGL**: Ensure that you have the OpenGL libraries installed. This may vary based on your operating system.

3. **Clone the Repository**: Clone this repository to your local machine.

4. **Build the Project**:
   - Navigate to the project directory.
   - Create a build directory: `mkdir build && cd build`
   - Run CMake: `cmake ..`
   - Compile the project: `make`

5. **Run the Application**: After building, you can run the application from the build directory.

## Usage

- The main window displays a 2D scene rendered by OpenGL.
- You can interact with the scene using the clickable button.
- The side panel contains a slider to adjust properties of the scene and a checkbox to toggle certain features.

