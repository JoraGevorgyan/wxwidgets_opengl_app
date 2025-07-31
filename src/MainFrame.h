#ifndef MAINFRAME_H
#define MAINFRAME_H

#include <wx/wx.h>
#include <wx/glcanvas.h>
#include "GLCanvas.h"
#include "panels/SidePanel.h"

class MainFrame : public wxFrame {
public:
    MainFrame(const wxString& title);

private:
    void SetupUI();
    void OnButtonClicked(wxCommandEvent& event);
    void OnClose(wxCloseEvent& event);

    GLCanvas* m_glCanvas;
    SidePanel* m_sidePanel;

    wxDECLARE_EVENT_TABLE();
};

#endif // MAINFRAME_H
