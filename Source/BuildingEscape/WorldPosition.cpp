// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldPosition.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UWorldPosition::UWorldPosition()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UWorldPosition::BeginPlay()
{
	Super::BeginPlay();

	FString Log = TEXT("HELLO!");
	FString* PtrLog = &Log;

	Log.Len();

	(*PtrLog).Len();
	PtrLog->Len();

	UE_LOG(LogTemp, Warning, TEXT("%s"),*Log); //* is overload convert to char 
	UE_LOG(LogTemp, Warning, TEXT("%s"), **PtrLog); // **,    *PtrLog get value from pointer, *convert to char so **PtrLog

	//UE_LOG(LogTemp, Warning, TEXT(" this is Warning"));
	//UE_LOG(LogTemp, Display, TEXT(" this is Display"))
	//UE_LOG(LogTemp, Error, TEXT("this is Error"));

	FString ObjectName = GetOwner()->GetName();
	//UE_LOG(LogTemp, Warning, TEXT("Object name is: %s"), *GetOwner()->GetName());

	FString ObjectPosition = GetOwner()->GetActorLocation().ToString(); //GetActorTransform().GetLocation()
	UE_LOG(LogTemp, Warning, TEXT("%s location is: %s"), *ObjectName, *ObjectPosition);
	
}


// Called every frame
void UWorldPosition::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

