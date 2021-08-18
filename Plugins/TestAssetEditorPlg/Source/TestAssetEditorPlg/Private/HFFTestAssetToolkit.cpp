// Fill out your copyright notice in the Description page of Project Settings.


#include "HFFTestAssetToolkit.h"
#include "Widgets/Docking/SDockTab.h"
#include "Widgets/Input/SButton.h"
#include "HFFTestAsset.h"

#define LOCTEXT_NAMESPACE "HFFTest"

class UHFFTestAsset * EditAsset1;

const FName HFFTestAssetToolkit::TestTabId(TEXT("HFFTestAssetEditor_TestTab"));

FName HFFTestAssetToolkit::GetToolkitFName() const
{
	return FName("HFFTestAssetName");
}

FText HFFTestAssetToolkit::GetBaseToolkitName() const
{
	return LOCTEXT("HFFTestAssetLabel", "HFFTestAssetBase");
}

FString HFFTestAssetToolkit::GetWorldCentricTabPrefix() const
{
	return LOCTEXT("HFFTestAssetTabPrefix", "HFFTestAssetPrefix ").ToString();
}

FLinearColor HFFTestAssetToolkit::GetWorldCentricTabColorScale() const
{
	return FLinearColor(0, 0.5f, 0.6f, 0.5f);
}



TSharedRef<SDockTab> HFFTestAssetToolkit::SpawnTestTab(const FSpawnTabArgs& Args)
{

	FSlateFontInfo ButtonTextStyle = FCoreStyle::Get().GetFontStyle("EmbossedText");
	ButtonTextStyle.Size = 40.f;

	FSlateFontInfo TitleTextStyle = ButtonTextStyle;
	TitleTextStyle.Size = 60.f;

	
	return
		SNew(SDockTab)
		[
			SNew(SVerticalBox)
			+ SVerticalBox::Slot()
		    .HAlign(HAlign_Center)
		    .VAlign(VAlign_Center)
		[
			SNew(STextBlock)
			.ColorAndOpacity(FSlateColor(FLinearColor(1,0,0,1)))
			.Font(TitleTextStyle)
			.Text(FText::FromString(FString::FromInt(EditAsset1->TestData)))
		]
	//+ SVerticalBox::Slot().AutoHeight()
	        + SVerticalBox::Slot()
		    .HAlign(HAlign_Center)
		    .VAlign(VAlign_Center)
		[
			SNew(SButton)
			.Text(FText::FromString("LookWhatLook!"))
		    .HAlign(HAlign_Center)
		    .VAlign(VAlign_Center)
		    .OnClicked_Lambda([this]() {EditAsset1->TestData++; return FReply::Handled(); })
		]
		];

}

void HFFTestAssetToolkit::RegisterTabSpawners(const TSharedRef<class FTabManager>& InTabManager)
{

	FAssetEditorToolkit::RegisterTabSpawners(InTabManager);

	InTabManager->RegisterTabSpawner(TestTabId, FOnSpawnTab::CreateSP(this, &HFFTestAssetToolkit::SpawnTestTab))
		.SetDisplayName(LOCTEXT("HFFTestAssetTestTab", "HFFTestAssetTestTab"));
}

void HFFTestAssetToolkit::Initialize(const EToolkitMode::Type Mode, const TSharedPtr< class IToolkitHost >& InitToolkitHost, UHFFTestAsset* Asset)
{
	EditAsset1 = Asset;
	TSharedRef<FTabManager::FLayout> Layout = FTabManager::NewLayout("HFFTestAssetEditor_Layout")
		->AddArea
		(
			FTabManager::NewPrimaryArea()->SetOrientation(Orient_Vertical)
			->Split
			(
				FTabManager::NewSplitter()->SetOrientation(Orient_Horizontal)->SetSizeCoefficient(0.9f)
				->Split
				(
					FTabManager::NewStack()
					->SetSizeCoefficient(0.7f)
					->AddTab(TestTabId, ETabState::OpenedTab)
				)
			)
		);

	const bool bCreateDefaultStandaloneMenu = true;
	const bool bCreateDefaultToolbar = true;
	const FName AppIdentifier = TEXT("HFFTestAssetEditor");
	FAssetEditorToolkit::InitAssetEditor(Mode, InitToolkitHost, AppIdentifier, Layout, bCreateDefaultStandaloneMenu, bCreateDefaultToolbar, Asset);
}

#undef LOCTEXT_NAMESPACE


