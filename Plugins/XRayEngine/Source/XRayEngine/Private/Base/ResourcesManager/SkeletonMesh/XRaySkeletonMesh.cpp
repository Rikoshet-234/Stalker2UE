#include "XRaySkeletonMesh.h"
#include "Render/Resources/Visual/XRayKinematics.h"
THIRD_PARTY_INCLUDES_START
#include "../Source/XrEngine/IRenderable.h"
THIRD_PARTY_INCLUDES_END

// Sets default values
AXRaySkeletonMesh::AXRaySkeletonMesh()
{
	Kinematics = nullptr;
	PrimaryActorTick.bCanEverTick = true;
	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	SceneComponent->SetupAttachment(GetRootComponent());
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	MeshComponent->SetupAttachment(SceneComponent);
}

void AXRaySkeletonMesh::SetKinematics(XRayKinematics* InKinematics)
{
	check(InKinematics&& Kinematics == nullptr);
	Kinematics = InKinematics; 
	Fvector3 InCenter;
	InKinematics->VisData.box.getcenter(InCenter);
	Fvector3 InSize;
	InKinematics->VisData.box.getsize(InSize);
	FVector Center(( - InCenter.x * 100 ), (InCenter.z * 100 ), (InCenter.y * 100 ));
	MeshComponent->SetRelativeLocation(Center);
	FVector Size(InSize.x, InSize.z, InSize.y);
	MeshComponent->SetRelativeScale3D(Size);
}

// Called every frame
void AXRaySkeletonMesh::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (Kinematics&& Kinematics->Renderable)
	{
		Fquaternion XRayQuat;
		XRayQuat.set(Kinematics->Renderable->renderable.xform);
		FQuat Quat(XRayQuat.x, -XRayQuat.z, -XRayQuat.y, XRayQuat.w);
		Fvector InLocation = Kinematics->Renderable->renderable.xform.c;
		FVector Location(-InLocation.x * 100, InLocation.z * 100, InLocation.y * 100);
		SetActorLocationAndRotation(Location, Quat);
	}
}

void AXRaySkeletonMesh::PostInitProperties()
{
	Super::PostInitProperties();
	if (HasAnyFlags(RF_NeedLoad | RF_WasLoaded | RF_ClassDefaultObject) == false)
	{
		MeshComponent->SetStaticMesh(LoadObject<UStaticMesh>(this, TEXT("/Engine/BasicShapes/Cube.Cube")));
	
	}
}

