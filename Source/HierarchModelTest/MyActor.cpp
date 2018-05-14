// Fill out your copyright notice in the Description page of Project Settings.

#include "MyActor.h"
#include "EngineUtils.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	TArray<UStaticMeshComponent*> mesh_components;
	this->GetComponents(mesh_components);

	
	UStaticMeshComponent *j1 = 0;
	UStaticMeshComponent *j2 = 0;

	for (int i=0; i<mesh_components.Num(); i++)
	{
		if (mesh_components[i]->GetName() == "joint1")
		{
			j1 = mesh_components[i];
		}
		else if (mesh_components[i]->GetName() == "joint2")
		{
			j2 = mesh_components[i];
		}
		UE_LOG(LogTemp, Warning, TEXT("name = %s"), *(mesh_components[i]->GetName()));
	}


	if (!j1) return;
	if (!j2) return;


	float gt = GetGameTimeSinceCreation();

	j1->SetRelativeRotation(FQuat(FRotator( sin(gt) * 80, cos(gt) * 80, 0)));
	j2->SetRelativeRotation(FQuat(FRotator(cos(2*gt) * 90, cos(2*gt)*30, 0)));

}

