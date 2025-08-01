#ifndef GLCANVAS_H
#define GLCANVAS_H

#include <wx/glcanvas.h>
#include <wx/wx.h>

class GLCanvas : public wxGLCanvas {
public:
    GLCanvas(wxWindow* parent, wxPanel* sidePanel = nullptr);
    void RenderScene();
    void OnPaint(wxPaintEvent& event);
    void OnMouseClick(wxMouseEvent& event);
    void InitializeOpenGL();
    void SetSidePanel(wxPanel* panel);

private:
    wxGLContext* m_context;
    wxGLContext* m_glContext;
    wxPanel* m_sidePanel = nullptr;
    
    DECLARE_EVENT_TABLE()
};

#endif // GLCANVAS_H
