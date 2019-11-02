// Fill out your copyright notice in the Description page of Project Settings.
#include "PickupActor.h"
#include "Components\StaticMeshComponent.h"

// Sets default values
APickupActor::APickupActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create all components
	this->SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	this->RootComponent = SceneComponent;
	this->ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMesh"));
	this->ItemMesh->AttachTo(this->RootComponent);
	this->RotationRate = FRotator(0.0f, 180.0f, 0.0f);
}

// Called when the game starts or when spawned
void APickupActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APickupActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Rotate the object (local rotation)
	this->AddActorLocalRotation(this->RotationRate * DeltaTime);

}

