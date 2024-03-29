#pragma once
#include "Core.h"
#include "Engine.h"
#include "Modules/ModuleManager.h"
#include "Async/AsyncWork.h"
#include "GameFramework/GameModeBase.h"
#include "Blueprint/UserWidget.h"
#include "Slate/SlateBrushAsset.h"
#include "SlateMaterialBrush.h"
#include "Misc/Paths.h"
THIRD_PARTY_INCLUDES_START
#include "XrAPI/xrGameManager.h"
#include "XrCore/stdafx.h"
#include "xrEngine/stdafx.h"
#include "xrEngine/Render.h"
#include "xrEngine/FMesh.h"
#include "xrEngine/bone.h"
#include "xrCDB/xrCDB.h"
#include "XrRender/Public/RenderVisual.h"
#include "XrRender/Public/KinematicsAnimated.h"
#include "XrRender/Public/Kinematics.h"
THIRD_PARTY_INCLUDES_END
FORCEINLINE uint32 GetTypeHash(shared_str Name)
{
	// This must match the GetTypeHash behavior of FString
	return FCrc::StrCrc32(Name.c_str(), Name.size());
}

DECLARE_LOG_CATEGORY_EXTERN(LogXRayEngine, Log, All);