// Fill out your copyright notice in the Description page of Project Settings.


#include "BloqueAcero.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ABloqueAcero::ABloqueAcero()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
    MallaBloqueAcero = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaBloqueAcero"));
    MallaBloqueAcero->SetupAttachment(RootComponent);

    static ConstructorHelpers::FObjectFinder<UStaticMesh> ObjetoMallaBloqueMadera(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));

    if (ObjetoMallaBloqueMadera.Succeeded())
    {
        MallaBloqueAcero->SetStaticMesh(ObjetoMallaBloqueMadera.Object);
        MallaBloqueAcero->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
    }

    EscalaBloque = FVector(30.0f, 30.0f, 0.5f);
    MallaBloqueAcero->SetWorldScale3D(EscalaBloque);
    // Inicializamos las variables para el movimiento
    RotationSpeed = 0.0f; // No relacionado con el movimiento, pero podrías usarlo si lo deseas
    StartLocation = FVector::ZeroVector;
}

// Called when the game starts or when spawned
void ABloqueAcero::BeginPlay()
{
    Super::BeginPlay();

}

// Called every frame
void ABloqueAcero::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    FVector NuevaPosicion = GetActorLocation();

}