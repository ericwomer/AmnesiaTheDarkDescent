
#include "LevelEditorWindowAbout.h"
#include "../../../core/include/CommunityEdition.h"
#include "LevelEditor.h"

//---------------------------------------------------------------------------------

cLevelEditorWindowAbout::cLevelEditorWindowAbout(iEditorBase* apEditor)
: iEditorWindowPopUp(apEditor, "About", true, false, true, cVector2f(400, 250))
{
}

cLevelEditorWindowAbout::~cLevelEditorWindowAbout()
{
}

//---------------------------------------------------------------------------------

void cLevelEditorWindowAbout::OnUpdate(float afTimeStep)
{

}

//---------------------------------------------------------------------------------

void cLevelEditorWindowAbout::OnInitLayout()
{
	iEditorWindowPopUp::OnInitLayout();
	mpWindow->SetText(_W("About"));

    mpLabelTitle = mpSet->CreateWidgetLabel(cVector3f(16, 30, 0), 0, _W("HPL Level Editor - Community Edition"), mpWindow);

    mpLabelVersion = mpSet->CreateWidgetLabel(cVector3f(mpWindow->GetSize().x-16, 30, 0), 0, COMMUNITY_VERSION, mpWindow);
    mpLabelVersion->SetTextAlign(eFontAlign_Right);

	mpLabelDescription = mpSet->CreateWidgetLabel(cVector3f(32, 80, 0), cVector2f(340, 200), _W("You can reach the creators of the community edition on GitHub using the button below."), mpWindow);
	// mpLabelDescription->SetMaxTextLength(50);
	mpLabelDescription->SetWordWrap(true);

    mpButtonGithub = mpSet->CreateWidgetButton(cVector3f(16, mpWindow->GetSize().y-40, 0), cVector2f(110, 24), _W("View on GitHub"), mpWindow);
	mpButtonGithub->AddCallback(eGuiMessage_ButtonPressed, this, kGuiCallback(WebsiteCallback));
}

//---------------------------------------------------------------------------------

bool cLevelEditorWindowAbout::WebsiteCallback(iWidget* apWidget, const cGuiMessageData& aData)
{
	OpenURL("https://github.com/TiManGames/AmnesiaTheDarkDescent");
	return true;
}
kGuiCallbackDeclaredFuncEnd(cLevelEditorWindowAbout, WebsiteCallback);

//---------------------------------------------------------------------------------

void cLevelEditorWindowAbout::OnSetActive(bool abX)
{
	iEditorWindowPopUp::OnSetActive(abX);

	if(abX)
		OnUpdate(0);
}

//---------------------------------------------------------------------------------

bool cLevelEditorWindowAbout::WindowSpecificInputCallback(iEditorInput* apInput)
{
	return true;
}

//---------------------------------------------------------------------------------
