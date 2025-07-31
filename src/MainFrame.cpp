#include "MainFrame.h"
#include "GLCanvas.h"
#include "panels/SidePanel.h"

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
    EVT_BUTTON(wxID_ANY, MainFrame::OnButtonClicked)
    EVT_CLOSE(MainFrame::OnClose)
wxEND_EVENT_TABLE()

MainFrame::MainFrame(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(800, 600))
{
    m_glCanvas = new GLCanvas(this);

    m_sidePanel = new SidePanel(this);

    wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
    sizer->Add(m_glCanvas, 1, wxEXPAND);
    sizer->Add(m_sidePanel, 0, wxEXPAND | wxALL, 5);

    SetSizer(sizer);
    Layout();

    Bind(wxEVT_CLOSE_WINDOW, &MainFrame::OnClose, this);
}

void MainFrame::SetupUI()
{
    SetTitle("OpenGL Application");

    CreateStatusBar();
    SetStatusText("Welcome to the OpenGL App!");
}

void MainFrame::OnClose(wxCloseEvent &event)
{
    Destroy();
}

void MainFrame::OnButtonClicked(wxCommandEvent& event)
{
    wxLogMessage("Button clicked in MainFrame!");
    // TODO
}