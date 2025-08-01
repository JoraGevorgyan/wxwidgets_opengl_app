# wxWidgets OpenGL Application

This project is a simple desktop application built using wxWidgets and OpenGL. It renders a 2D scene with interactive elements, including a clickable button, a side panel with a slider, and a checkbox, actually doing nothing special:_)

## Setup Instructions(Ubuntu)

1. **Install dependencies**:
```bash
sudo apt update && sudo apt install -y build-essential cmake libwxgtk3.2-dev libgl1-mesa-dev libglu1-mesa-dev libpng-dev
```

2. **Clone the Repository**: Clone this repository to your local machine.

3. **Build the Project**:
   - Navigate to the project directory.
   - Create a build directory: `mkdir build && cd build`
   - Run CMake: `cmake ..`
   - Compile the project: `make`

4. **Run the Application**: After building, you can run the application from the build directory.
```bash
./wxwidgets_opengl_app
```
