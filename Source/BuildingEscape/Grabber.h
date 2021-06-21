// Copyright Mateusz Iwanek 2021

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	float Reach;

	UPROPERTY()
	class UPhysicsHandleComponent* PhysicsHandle;

	UPROPERTY()
	class UInputComponent* InputComponent;

	void Grab();
	void Release();
	void FindPhysicsHandle();
	void SetupInputComponent();

	FHitResult GetFirstPhysicsBodyInReach() const;

	FVector GetPlayersReach()const;

	FVector GetPlayersWorldPos()const;
};
