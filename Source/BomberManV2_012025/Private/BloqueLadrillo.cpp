// Fill out your copyright notice in the Description page of Project Settings.

#include "BloqueLadrillo.h"

// Sets default values
ABloqueLadrillo::ABloqueLadrillo()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    MallaBloqueLadrillo = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaBloqueLadrillo"));
    MallaBloqueLadrillo->SetupAttachment(RootComponent);

    static ConstructorHelpers::FObjectFinder<UStaticMesh> ObjetoMallaBloqueaLadrillo(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));

    if(ObjetoMallaBloqueaLadrillo.Succeeded())
    {
        MallaBloqueLadrillo->SetStaticMesh(ObjetoMallaBloqueaLadrillo.Object);
        MallaBloqueLadrillo->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
    }

    // Inicializamos las variables para el movimiento
    RotationSpeed = 0.0f; // No relacionado con el movimiento, pero podrías usarlo si lo deseas
    StartLocation = FVector::ZeroVector;
}

// Called when the game starts or when spawned
void ABloqueLadrillo::BeginPlay()
{
    Super::BeginPlay();

    // Guardamos la ubicación inicial del actor
    StartLocation = GetActorLocation();
}

// Called every frame
void ABloqueLadrillo::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    FVector NuevaPosicion = GetActorLocation();
    if (NuevaPosicion.Z < 1000.0f) {
        // Calcula la nueva posición
        NuevaPosicion.Z += 50.0f * DeltaTime;// Velocidad de movimiento en Z
    }


    // Actualiza la ubicación del actor
    SetActorLocation(NuevaPosicion);
}
