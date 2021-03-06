// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DetailCustomizationUtilities.h"
#include "IDetailCustomization.h"

class UBaseWidgetBlueprint;
class UWidgetBlueprintGeneratedClass;
class UWidget;
class IDetailLayoutBuilder;
class IPropertyHandle;

using namespace DetailCustomizationUtilities;

/**
 * Detail customization for any user widget with UWidgetComponentAsExtension component
 */
class WIDGETCOMPONENTEDITOR_API FComponentBasedWidgetDetails : public IDetailCustomization
{
#pragma region Data Members

	TArray<TWeakObjectPtr<UWidget>> ReferencableWidgets;

	TWeakObjectPtr<UWidgetBlueprintGeneratedClass> WidgetBlueprintGeneratedClass;

#pragma endregion Data Members

public:
	/** Makes a new instance of this detail layout class for a specific detail view requesting it */
	static TSharedRef<IDetailCustomization> MakeInstance();

	virtual void CustomizeDetails( IDetailLayoutBuilder& DetailBuilder ) override {}
	virtual void CustomizeDetails( const TSharedPtr<IDetailLayoutBuilder>& DetailBuilder ) override;

protected:
	virtual TSharedRef<SWidget> MakeComboButton(TSharedPtr<IPropertyHandle> PropertyHandle);

	virtual TSharedRef<SWidget> GetPopupContent(TSharedPtr<IPropertyHandle> ChildHandle,
		TSharedPtr<SComboButton> WidgetListComboButton);

	virtual void OnSelectionChanged(TWeakObjectPtr<UWidget> InItem, ESelectInfo::Type SelectionInfo,
		TSharedPtr<IPropertyHandle> ChildHandle, TSharedPtr<SComboButton> WidgetListComboButton) const;

	virtual TSharedRef<ITableRow> OnGenerateListItem(TWeakObjectPtr<UWidget> InItem,
											const TSharedRef<STableViewBase>& OwnerTable) const;

	virtual void OnFilterTextChanged(const FText& InFilterText, TSharedPtr<IPropertyHandle> ChildHandle,
		TSharedPtr<SListView<TWeakObjectPtr<UWidget>>> WidgetListView);
};
