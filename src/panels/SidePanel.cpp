#include "SidePanel.h"
#include <wx/sizer.h>
#include <wx/slider.h>
#include <wx/checkbox.h>
#include <wx/button.h>

SidePanel::SidePanel(wxWindow* parent) : wxPanel(parent) {
    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);

    wxSlider* slider = new wxSlider(this, wxID_ANY, 50, 0, 100);
    wxCheckBox* checkBox = new wxCheckBox(this, wxID_ANY, "Enable Feature");
    wxButton* button = new wxButton(this, wxID_ANY, "Click Me", wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, "button");
    wxBitmap icon("../data/cpp_icon.png", wxBITMAP_TYPE_PNG);
    wxImage img = icon.ConvertToImage();
    if (img.IsOk()) {
        img = img.Scale(24, 24, wxIMAGE_QUALITY_HIGH);
        icon = wxBitmap(img);
    }
    button->SetBitmap(icon);
    
    sizer->Add(slider, 0, wxALL | wxEXPAND, 5);
    sizer->Add(checkBox, 0, wxALL | wxEXPAND, 5);
    sizer->Add(button, 0, wxALL | wxEXPAND, 5);

    SetSizer(sizer);

    slider->Bind(wxEVT_SLIDER, &SidePanel::OnSliderChange, this);
    checkBox->Bind(wxEVT_CHECKBOX, &SidePanel::OnCheckBoxToggle, this);
    button->Bind(wxEVT_BUTTON, &SidePanel::OnButtonClick, this);
}

SidePanel::SidePanel(wxWindow* parent,
                     wxWindowID id,
                     const wxPoint& pos,
                     const wxSize& size,
                     long style,
                     const wxString& name)
    : wxPanel(parent, id, pos, size, style, name)
{
    SetBackgroundColour(*wxLIGHT_GREY);

    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);

    m_slider = new wxSlider(this, wxID_ANY, 50, 0, 100);
    m_checkBox = new wxCheckBox(this, wxID_ANY, "Enable Feature");

    sizer->Add(m_slider, 0, wxALL | wxEXPAND, 5);
    sizer->Add(m_checkBox, 0, wxALL, 5);

    SetSizer(sizer);

    m_slider->Bind(wxEVT_SLIDER, &SidePanel::OnSliderChange, this);
    m_checkBox->Bind(wxEVT_CHECKBOX, &SidePanel::OnCheckBoxToggle, this);
}

void SidePanel::OnSliderChange(wxCommandEvent& event) {
    int value = event.GetInt();
}

void SidePanel::OnCheckBoxToggle(wxCommandEvent& event) {
    wxLogMessage("Checkbox toggled: %s", event.IsChecked() ? "Checked" : "Unchecked");
}

void SidePanel::OnButtonClick(wxCommandEvent& event) {
    wxLogMessage("Button clicked in SidePanel!");
    // TODO
}