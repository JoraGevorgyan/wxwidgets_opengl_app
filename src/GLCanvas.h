#ifndef GLCANVAS_H
#define GLCANVAS_H

#include <wx/glcanvas.h>
#include <wx/wx.h>

class GLCanvas : public wxGLCanvas {
public:
    GLCanvas(wxWindow* parent);
    void RenderScene();
    void OnPaint(wxPaintEvent& event);
    void OnMouseClick(wxMouseEvent& event);
    void InitializeOpenGL();

private:
    wxGLContext* m_context;
    wxGLContext* m_glContext;
    
    DECLARE_EVENT_TABLE()
};

#endif // GLCANVAS_H