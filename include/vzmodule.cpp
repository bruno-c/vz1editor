#include "vzmodule.h"

//(*InternalHeaders(VZModule)
#include <wx/bitmap.h>
#include <wx/font.h>
#include <wx/image.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(VZModule)
const long VZModule::ID_STATICTEXT3 = wxNewId();
const long VZModule::ID_CHKENABLE = wxNewId();
const long VZModule::ID_CHKEXTPHASE = wxNewId();
const long VZModule::ID_STATICTEXT4 = wxNewId();
const long VZModule::ID_CHOICE3 = wxNewId();
const long VZModule::ID_STATICTEXT5 = wxNewId();
const long VZModule::ID_SLIDER8 = wxNewId();
const long VZModule::ID_STATICTEXT6 = wxNewId();
const long VZModule::ID_SLIDER1 = wxNewId();
const long VZModule::ID_CHECKBOX2 = wxNewId();
const long VZModule::ID_CHECKBOX3 = wxNewId();
const long VZModule::ID_STATICTEXT8 = wxNewId();
const long VZModule::ID_STATICTEXT15 = wxNewId();
const long VZModule::ID_SLIDER11 = wxNewId();
const long VZModule::ID_CHECKBOX4 = wxNewId();
const long VZModule::ID_STATICBITMAP1 = wxNewId();
const long VZModule::ID_STATICTEXT7 = wxNewId();
const long VZModule::ID_CHOICE4 = wxNewId();
const long VZModule::ID_SLIDER9 = wxNewId();
const long VZModule::ID_SLIDER10 = wxNewId();
//*)

BEGIN_EVENT_TABLE(VZModule,wxPanel)
	//(*EventTable(VZModule)
	//*)
END_EVENT_TABLE()

VZModule::VZModule(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size) :
    m_pVoice(NULL)
{
	//(*Initialize(VZModule)
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer2;
	wxFlexGridSizer* FlexGridSizer10;
	wxFlexGridSizer* FlexGridSizer11;
	wxFlexGridSizer* FlexGridSizer4;
	wxFlexGridSizer* FlexGridSizer5;
	wxFlexGridSizer* FlexGridSizer6;
	wxFlexGridSizer* FlexGridSizer7;
	wxFlexGridSizer* FlexGridSizer8;
	wxFlexGridSizer* FlexGridSizer9;
	wxStaticBoxSizer* StaticBoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer2;
	wxStaticBoxSizer* StaticBoxSizer3;
	wxStaticBoxSizer* StaticBoxSizer4;
	wxStaticBoxSizer* StaticBoxSizer5;
	wxStaticBoxSizer* StaticBoxSizer6;

	Create(parent, id, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("id"));
	FlexGridSizer6 = new wxFlexGridSizer(1, 0, 0, 0);
	FlexGridSizer6->AddGrowableCol(2);
	FlexGridSizer6->AddGrowableCol(4);
	FlexGridSizer6->AddGrowableRow(0);
	BoxSizer2 = new wxBoxSizer(wxVERTICAL);
	m_pLblTitle = new wxStaticText(this, ID_STATICTEXT3, _("Mx"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	wxFont m_pLblTitleFont(12,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	m_pLblTitle->SetFont(m_pLblTitleFont);
	BoxSizer2->Add(m_pLblTitle, 1, wxALL, 5);
	m_pChkEnable = new wxCheckBox(this, ID_CHKENABLE, _("Enable"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHKENABLE"));
	m_pChkEnable->SetValue(true);
	m_pChkEnable->SetToolTip(_("Enable module"));
	BoxSizer2->Add(m_pChkEnable, 1, wxALL|wxEXPAND, 5);
	m_pChkExtPhase = new wxCheckBox(this, ID_CHKEXTPHASE, _("Ext Phase"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHKEXTPHASE"));
	m_pChkExtPhase->SetValue(false);
	m_pChkExtPhase->Disable();
	m_pChkExtPhase->SetToolTip(_("External phase"));
	BoxSizer2->Add(m_pChkExtPhase, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer6->Add(BoxSizer2, 1, wxALL|wxEXPAND, 5);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("DCO"));
	FlexGridSizer4 = new wxFlexGridSizer(0, 1, 0, 0);
	m_pLblWaveform = new wxStaticText(this, ID_STATICTEXT4, _("Waveform"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	FlexGridSizer4->Add(m_pLblWaveform, 1, wxALL|wxEXPAND, 5);
	m_pCmbWaveform = new wxChoice(this, ID_CHOICE3, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE3"));
	m_pCmbWaveform->SetSelection( m_pCmbWaveform->Append(_("Sine")) );
	m_pCmbWaveform->Append(_("Saw 1"));
	m_pCmbWaveform->Append(_("Saw 2"));
	m_pCmbWaveform->Append(_("Saw 3"));
	m_pCmbWaveform->Append(_("Saw 4"));
	m_pCmbWaveform->Append(_("Saw 5"));
	m_pCmbWaveform->Append(_("Noise 1"));
	m_pCmbWaveform->Append(_("Noise 2"));
	m_pCmbWaveform->SetToolTip(_("DCO Waveform"));
	FlexGridSizer4->Add(m_pCmbWaveform, 1, wxALL|wxEXPAND, 5);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT5, _("Detune Course"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	FlexGridSizer4->Add(StaticText3, 1, wxALL|wxEXPAND, 5);
	m_pSliderDetuneOctave = new wxSlider(this, ID_SLIDER8, 0, -128, 127, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_SLIDER8"));
	m_pSliderDetuneOctave->SetToolTip(_("Detune DCO in semitone steps"));
	FlexGridSizer4->Add(m_pSliderDetuneOctave, 1, wxALL|wxEXPAND, 5);
	StaticText4 = new wxStaticText(this, ID_STATICTEXT6, _("Detune Fine"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	FlexGridSizer4->Add(StaticText4, 1, wxALL|wxEXPAND, 5);
	m_pSliderDetuneFine = new wxSlider(this, ID_SLIDER1, 32, 0, 63, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_SLIDER1"));
	m_pSliderDetuneFine->SetToolTip(_("Detune DCO in 1.6 cent steps"));
	FlexGridSizer4->Add(m_pSliderDetuneFine, 1, wxALL|wxEXPAND, 5);
	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	m_pChkFixedFreq = new wxCheckBox(this, ID_CHECKBOX2, _("Fixed Freq"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX2"));
	m_pChkFixedFreq->SetValue(false);
	m_pChkFixedFreq->SetToolTip(_("DCO Fixed frequency"));
	BoxSizer1->Add(m_pChkFixedFreq, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_pChkX16 = new wxCheckBox(this, ID_CHECKBOX3, _("x16"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX3"));
	m_pChkX16->SetValue(false);
	m_pChkX16->SetToolTip(_("DCO frequency detune multiplier"));
	BoxSizer1->Add(m_pChkX16, 1, wxALL|wxEXPAND, 5);
	FlexGridSizer4->Add(BoxSizer1, 1, wxALL|wxEXPAND, 5);
	StaticBoxSizer1->Add(FlexGridSizer4, 0, wxALIGN_LEFT, 0);
	FlexGridSizer6->Add(StaticBoxSizer1, 1, wxALL|wxEXPAND, 5);
	StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("DCA"));
	FlexGridSizer5 = new wxFlexGridSizer(1, 0, 0, 0);
	FlexGridSizer5->AddGrowableCol(0);
	FlexGridSizer5->AddGrowableRow(1);
	StaticBoxSizer3 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Amplitude Envelope"));
	FlexGridSizer7 = new wxFlexGridSizer(1, 0, 0, 0);
	FlexGridSizer7->AddGrowableCol(0);
	FlexGridSizer7->AddGrowableRow(1);
	StaticText6 = new wxStaticText(this, ID_STATICTEXT8, _("ENV"), wxDefaultPosition, wxSize(122,13), wxALIGN_CENTRE, _T("ID_STATICTEXT8"));
	FlexGridSizer7->Add(StaticText6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer8 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer8->AddGrowableRow(0);
	m_pLblDepth = new wxStaticText(this, ID_STATICTEXT15, _("Env Depth"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT15"));
	FlexGridSizer8->Add(m_pLblDepth, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_pSliderEnvDepth = new wxSlider(this, ID_SLIDER11, 99, 0, 99, wxDefaultPosition, wxDefaultSize, wxSL_VERTICAL|wxSL_INVERSE, wxDefaultValidator, _T("ID_SLIDER11"));
	m_pSliderEnvDepth->SetToolTip(_("DCA Amplitued envelope depth"));
	FlexGridSizer8->Add(m_pSliderEnvDepth, 1, wxALL|wxEXPAND|wxFIXED_MINSIZE, 5);
	m_pEnvRange = new wxCheckBox(this, ID_CHECKBOX4, _("Range"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX4"));
	m_pEnvRange->SetValue(false);
	FlexGridSizer8->Add(m_pEnvRange, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer7->Add(FlexGridSizer8, 1, wxALL|wxEXPAND, 5);
	StaticBoxSizer3->Add(FlexGridSizer7, 0, wxALIGN_LEFT, 0);
	FlexGridSizer5->Add(StaticBoxSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer4 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Key Follow"));
	FlexGridSizer9 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer9->AddGrowableCol(0);
	FlexGridSizer9->AddGrowableRow(1);
	m_pBmpKeyboard = new wxStaticBitmap(this, ID_STATICBITMAP1, wxBitmap(wxImage(_T("D:\\PJ\\miditest\\images\\keyboard.png"))), wxDefaultPosition, wxDefaultSize, wxSIMPLE_BORDER, _T("ID_STATICBITMAP1"));
	FlexGridSizer9->Add(m_pBmpKeyboard, 1, wxALL|wxEXPAND, 5);
	StaticText5 = new wxStaticText(this, ID_STATICTEXT7, _("ENV"), wxDefaultPosition, wxSize(122,13), wxALIGN_CENTRE, _T("ID_STATICTEXT7"));
	FlexGridSizer9->Add(StaticText5, 1, wxALL|wxEXPAND, 5);
	StaticBoxSizer4->Add(FlexGridSizer9, 0, wxEXPAND, 0);
	FlexGridSizer5->Add(StaticBoxSizer4, 1, wxALL|wxEXPAND, 5);
	StaticBoxSizer5 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Key Velocity"));
	FlexGridSizer10 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer10->AddGrowableRow(1);
	m_pCmbCurve = new wxChoice(this, ID_CHOICE4, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE4"));
	m_pCmbCurve->SetSelection( m_pCmbCurve->Append(_("Curve 1")) );
	m_pCmbCurve->Append(_("Curve 2"));
	m_pCmbCurve->Append(_("Curve 3"));
	m_pCmbCurve->Append(_("Curve 4"));
	m_pCmbCurve->Append(_("Curve 5"));
	m_pCmbCurve->Append(_("Curve 6"));
	m_pCmbCurve->Append(_("Curve 7"));
	m_pCmbCurve->Append(_("Curve 8"));
	m_pCmbCurve->SetToolTip(_("DCA key velocity curve"));
	FlexGridSizer10->Add(m_pCmbCurve, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_pSliderVelSensitivity = new wxSlider(this, ID_SLIDER9, 0, 0, 31, wxDefaultPosition, wxDefaultSize, wxSL_VERTICAL|wxSL_INVERSE, wxDefaultValidator, _T("ID_SLIDER9"));
	m_pSliderVelSensitivity->SetToolTip(_("DCA key velocity sensitivity"));
	FlexGridSizer10->Add(m_pSliderVelSensitivity, 1, wxALL|wxEXPAND, 5);
	StaticBoxSizer5->Add(FlexGridSizer10, 0, wxEXPAND, 0);
	FlexGridSizer5->Add(StaticBoxSizer5, 1, wxALL|wxEXPAND, 5);
	StaticBoxSizer6 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Sensitivity"));
	FlexGridSizer11 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer11->AddGrowableRow(0);
	m_pSliderAmpSens = new wxSlider(this, ID_SLIDER10, 7, 0, 7, wxDefaultPosition, wxDefaultSize, wxSL_VERTICAL|wxSL_INVERSE, wxDefaultValidator, _T("ID_SLIDER10"));
	m_pSliderAmpSens->SetToolTip(_("DCA Sensititivy to external modulation"));
	FlexGridSizer11->Add(m_pSliderAmpSens, 1, wxALL|wxEXPAND|wxFIXED_MINSIZE, 5);
	StaticBoxSizer6->Add(FlexGridSizer11, 0, wxEXPAND, 0);
	FlexGridSizer5->Add(StaticBoxSizer6, 1, wxALL|wxEXPAND, 5);
	StaticBoxSizer2->Add(FlexGridSizer5, 0, wxEXPAND, 0);
	FlexGridSizer6->Add(StaticBoxSizer2, 1, wxALL|wxEXPAND, 5);
	SetSizer(FlexGridSizer6);
	FlexGridSizer6->Fit(this);
	FlexGridSizer6->SetSizeHints(this);
//*)
}

VZModule::~VZModule()
{
	//(*Destroy(VZModule)
	//*)
}

void VZModule::SetVoice(vzvoice* pVoice)
{
    m_pVoice = pVoice;
}

void VZModule::SetModule(wxByte nModule)
{
    m_nModule = nModule;
    UpdateGui();
}

void VZModule::UpdateGui()
{
    m_pLblTitle->SetLabel(wxString::Format(wxT("M%d"), m_nModule + 1));
    if(m_nModule > 2 && m_nModule %2)
        m_pChkExtPhase->Enable();
    if(!m_pVoice)
        return;
    m_pChkEnable->SetValue(m_pVoice->IsModuleEnabled(m_nModule));
    m_pChkExtPhase->SetValue(m_pVoice->IsExtPhase(m_nModule));
    m_pCmbWaveform->SetSelection(m_pVoice->GetWaveform(m_nModule));
    m_pSliderDetuneOctave->SetValue(m_pVoice->GetDetuneCourse(m_nModule));
    m_pSliderDetuneFine->SetValue(m_pVoice->GetDetuneFine(m_nModule));
    m_pChkFixedFreq->SetValue(m_pVoice->IsPitchFixRange(m_nModule));
    m_pChkX16->SetValue(m_pVoice->IsPitchFixRange(m_nModule));
}