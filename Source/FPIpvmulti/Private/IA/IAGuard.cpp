// Fill out your copyright notice in the Description page of Project Settings.


#include "FPIpvmulti/Public/IA/IAGuard.h"

#include "Perception/PawnSensingComponent.h"


// Sets default values
AIAGuard::AIAGuard()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PawnSensingComp = CreateDefaultSubobject<UPawnSensingComponent>("PawnSensingComp");
	PawnSensingComp->OnSeePawn.AddDynamic(this, &ThisClass::OnPawnSeen);
}

// Called when the game starts or when spawned
void AIAGuard::BeginPlay()
{
	Super::BeginPlay();
	
}

void AIAGuard::OnPawnSeen(APawn* SeenPawn)
{
	if (SeenPawn == nullptr) return;
	DrawDebugSphere(GetWorld(), SeenPawn->GetActorLocation(), 35.0f,
		12.0f, FColor::Blue, false, 6.0f);
	
}

// Called every frame
void AIAGuard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AIAGuard::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

