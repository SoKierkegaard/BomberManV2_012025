// Fill out your copyright notice in the Description page of Project Settings.


#include "BloqueMadera.h"

// Sets default values
ABloqueMadera::ABloqueMadera()
{
    PrimaryActorTick.bCanEverTick = true;

    // Definir un RootComponent explícito
    RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

    MallaBloqueMadera = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaBloqueMadera"));
    MallaBloqueMadera->SetupAttachment(RootComponent);

    static ConstructorHelpers::FObjectFinder<UStaticMesh> ObjetoMallaBloqueMadera(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));

    if (ObjetoMallaBloqueMadera.Succeeded())
    {
        MallaBloqueMadera->SetStaticMesh(ObjetoMallaBloqueMadera.Object);
        MallaBloqueMadera->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
    }
}


// Called when the game starts or when spawned
void ABloqueMadera::BeginPlay()
{
    Super::BeginPlay();

}

// Called every frame
void ABloqueMadera::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}