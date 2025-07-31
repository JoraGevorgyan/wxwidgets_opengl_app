#ifndef SIDEPANEL_H
#define SIDEPANEL_H

#include <wx/wx.h>
#include <wx/slider.h>
#include <wx/checkbox.h>

class SidePanel : public wxPanel {
public:
    SidePanel(wxWindow* parent);

    void OnSliderChange(wxCommandEvent& event);
    void OnCheckBoxToggle(wxCommandEvent& event);
    void OnButtonClick(wxCommandEvent& event);

private:
    wxSlider* m_slider;
    wxCheckBox* m_checkBox;
};

#endif // SIDEPANEL_H
