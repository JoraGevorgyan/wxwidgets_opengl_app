#include "MainFrame.h"
#include "GLCanvas.h"
#include "panels/SidePanel.h"

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
    EVT_BUTTON(wxID_ANY, MainFrame::OnButtonClicked)
    EVT_CLOSE(MainFrame::OnClose)
wxEND_EVENT_TABLE()

MainFrame::MainFrame(const wxString& title)
    : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(800, 600))
{
    wxPanel* mainPanel = new wxPanel(this);

    wxBoxSizer* topSizer = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* contentSizer = new wxBoxSizer(wxHORIZONTAL);

    m_glCanvas = new GLCanvas(mainPanel);
    m_sidePanel = new SidePanel(mainPanel, wxID_ANY, wxDefaultPosition, wxSize(200, -1));
    m_sidePanel->SetBackgroundColour(*wxLIGHT_GREY);

    m_checkBox = new wxCheckBox(mainPanel, wxID_ANY, "Show Side Panel");
    m_checkBox->SetValue(true);
    m_checkBox->Bind(wxEVT_CHECKBOX, &MainFrame::OnTogglePanel, this);

    topSizer->Add(m_checkBox, 0, wxALL, 5);
    contentSizer->Add(m_glCanvas, 1, wxEXPAND);
    contentSizer->Add(m_sidePanel, 0, wxEXPAND);

    topSizer->Add(contentSizer, 1, wxEXPAND);
    mainPanel->SetSizer(topSizer);

    wxBoxSizer* frameSizer = new wxBoxSizer(wxVERTICAL);
    frameSizer->Add(mainPanel, 1, wxEXPAND);
    SetSizerAndFit(frameSizer);
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

void MainFrame::OnTogglePanel(wxCommandEvent& event) {
    if (m_checkBox->IsChecked()) {
        m_sidePanel->Show();
    } else {
        m_sidePanel->Hide();
    }
    Layout();
}
