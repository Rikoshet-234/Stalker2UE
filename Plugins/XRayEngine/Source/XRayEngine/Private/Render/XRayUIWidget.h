// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "XRayUIWidget.generated.h"

/**
 * 
 */
UCLASS()
class UXRayUIWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	

	bool Initialize() override;

protected:
	int32 NativePaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const override;
private:
	mutable uint32 LastFrame = -1;
	mutable TArray<FSlateVertex> VerticesCahce;
	mutable TArray<SlateIndex>   IndexesCahce;;
};
