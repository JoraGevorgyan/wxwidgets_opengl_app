#include "GLCanvas.h"
#include <wx/glcanvas.h>
#include <wx/dcclient.h>
#include <wx/event.h>

BEGIN_EVENT_TABLE(GLCanvas, wxGLCanvas)
    EVT_PAINT(GLCanvas::OnPaint)
    EVT_LEFT_DOWN(GLCanvas::OnMouseClick)
END_EVENT_TABLE()

GLCanvas::GLCanvas(wxWindow* parent, wxPanel* sidePanel)
    : wxGLCanvas(parent, wxID_ANY, nullptr, wxDefaultPosition, wxDefaultSize, wxFULL_REPAINT_ON_RESIZE),
      m_sidePanel(sidePanel)
{
    SetBackgroundStyle(wxBG_STYLE_PAINT);
    m_glContext = new wxGLContext(this);
    InitializeOpenGL();
}

void GLCanvas::SetSidePanel(wxPanel* panel)
{
    m_sidePanel = panel;
}

void GLCanvas::InitializeOpenGL()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}
void GLCanvas::OnPaint(wxPaintEvent& event)
{
    wxPaintDC dc(this);
    SetCurrent(*m_glContext);

    glClear(GL_COLOR_BUFFER_BIT);

    RenderScene();

    SwapBuffers();
}

void GLCanvas::RenderScene()
{
    glColor3f(0.0f, 0.5f, 0.0f);
    glBegin(GL_QUADS);
        glVertex2f(-0.5f, -0.5f);
        glVertex2f(0.5f, -0.5f);
        glVertex2f(0.5f, 0.5f);
        glVertex2f(-0.5f, 0.5f);
    glEnd();
}

void GLCanvas::OnMouseClick(wxMouseEvent& event)
{
    wxSize size = GetClientSize();
    wxPoint mousePos = event.GetPosition();

    // Convert mouse position to normalized OpenGL coordinates
    float x = 2.0f * mousePos.x / size.GetWidth() - 1.0f;
    float y = 1.0f - 2.0f * mousePos.y / size.GetHeight();

    // Button bounds in OpenGL coordinates
    float left = -0.5f, right = 0.5f, top = 0.5f, bottom = -0.5f;

    if (x >= left && x <= right && y >= bottom && y <= top)
    {
        wxLogMessage("Clicked on rectangle");
    }
}