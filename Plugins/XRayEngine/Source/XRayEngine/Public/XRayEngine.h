// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once
#include "XRayEngine.h"
#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FXRayEngineModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};