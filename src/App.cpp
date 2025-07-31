#include "App.h"
#include "MainFrame.h"

bool App::OnInit() {
    MainFrame* frame = new MainFrame("OpenGL Application");
    return frame->Show(true);
}