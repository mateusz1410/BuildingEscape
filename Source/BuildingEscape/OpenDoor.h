// Copyright Mateusz Iwanek 2021

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "OpenDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void OpenDoor(float DeltaTime);
	void CloseDoor(float DeltaTime);
	float TotalMassOfActors() const;
	void FindAudioComponent();
	void FindPressurePlate();

	bool OpenDoorSound;
	bool CloseDoorSound;

private:
	float InitialYaw;
	float CurrentYaw;

	UPROPERTY(EditAnywhere, Category = "Door Rotation")
	float OpenAngle;

	float DoorLastOpened;

	UPROPERTY(EditAnywhere)
	float DoorCloseDalay;

	UPROPERTY(EditAnywhere)
	float DoorOpenSpeed;

	UPROPERTY(EditAnywhere)
	float DoorCloseSpeed;

	UPROPERTY(EditAnywhere)
	class ATriggerVolume* PressurePlate;

	//UPROPERTY(EditAnywhere)
	//class AActor* ActorThatOpens;

	UPROPERTY(EditAnywhere)
	float MassToOpenDoors;

	UPROPERTY()
	class UAudioComponent* AudioComponent;

};
