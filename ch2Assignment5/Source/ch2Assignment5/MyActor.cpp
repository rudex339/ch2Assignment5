// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	start == FVector2D::ZeroVector;

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("start position %.0f, %.0f"), start.X, start.Y);
	for (int i = 0; i < 10; i++) {
		FVector2D vec(step(), step());
		start += vec;
		UE_LOG(LogTemp, Log, TEXT("current position %.0f, %.0f"), start.X, start.Y);
		float dis = vec.Size();
		UE_LOG(LogTemp, Log, TEXT("distance %.0f"), dis);
		totDist += dis;
		TriggerEventWithProbability(50);
	}
	UE_LOG(LogTemp, Log, TEXT("distance : %d, eventcount : %d"), totDist, evCnt);
	
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyActor::TriggerEventWithProbability(float Probability)
{
	int32 RandomValue = FMath::RandRange(1, 100); // 1 ~ 100의 난수 생성
	if (RandomValue <= Probability)
	{
		UE_LOG(LogTemp, Log, TEXT("Event Triggered!"));
		evCnt++;
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("Event Not Triggered"));
	}
}


