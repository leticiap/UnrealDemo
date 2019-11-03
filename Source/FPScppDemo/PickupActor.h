// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Components/BoxComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PickupActor.generated.h"

UCLASS()
class FPSCPPDEMO_API APickupActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickupActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void Show(bool visible);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// RotationRate
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = Pickup)
	FRotator RotationRate;

	// SceneComponent as Root
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = Pickup)
	USceneComponent* SceneComponent;

	// MeshComponent
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Pickup)
	UStaticMeshComponent* ItemMesh;

	// Speed
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = Pickup)
		float Speed;

	// Box Collider and overlap function
	UPROPERTY(EditAnyWhere)
		UBoxComponent* BoxCollider;

	UPROPERTY(EditAnyWhere)
	FString Name;

	virtual void OnInteract();

	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
