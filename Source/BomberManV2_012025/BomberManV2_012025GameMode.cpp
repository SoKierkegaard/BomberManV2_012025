// Copyright Epic Games, Inc.All Rights Reserved.

#include "BomberManV2_012025GameMode.h"
#include "BomberManV2_012025Character.h"
#include "UObject/ConstructorHelpers.h"
#include "BloqueMadera.h"
#include "BloqueLadrillo.h"
#include "Kismet/KismetMathLibrary.h"

ABomberManV2_012025GameMode::ABomberManV2_012025GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void ABomberManV2_012025GameMode::BeginPlay()
{
    Super::BeginPlay();
    GetWorldTimerManager().SetTimer(BloqueTimerHandle,this,&ABomberManV2_012025GameMode::SpawnAndDestroyBlock,15.0f,true);

    for (int i = 0; i < 10; i++)
    {
        ABloqueLadrillo* bloqueladrillo01 = GetWorld()->SpawnActor<ABloqueLadrillo>(ABloqueLadrillo::StaticClass(), FVector(500.0f + i * 150, 300.0f, 100.0f), FRotator(0.0f, 0.0f, 0.0f));

    }

    GEngine->AddOnScreenDebugMessage(-1, -1, FColor::Red, TEXT("Generando Troncos"));

    FVector BasePosition(0.0f, 0.0f, 0.0f); // Posici�n base del tronco (X, Y, Z)
    float AlturaBloque = 100.0f; // Altura de cada bloque (ajusta seg�n el tama�o de tus bloques)

    int NumeroBloquesPorTronco = 5; // Cantidad de bloques en cada tronco
    int CantidadTroncos = 8; // N�mero de troncos a generar

    for (int i = 0; i < CantidadTroncos; i++)
    {
        // Calcula la posici�n base para cada tronco con algo de variaci�n en X y Y
        float OffsetX = FMath::RandRange(100.0f, 3000.0f); // Variaci�n aleatoria dentro de 3000x3000
        float OffsetY = FMath::RandRange(100.0f, 3000.0f);

        FVector PosicionTronco = BasePosition + FVector(OffsetX, OffsetY, 0.0f);

        for (int j = 0; j < NumeroBloquesPorTronco; j++)
        {
            // Calcular posici�n del bloque actual
            FVector PosicionBloque = PosicionTronco + FVector(0.0f, 0.0f, j * AlturaBloque);

            // Spawnear el bloque
            ABloqueMadera* BloqueMadera = GetWorld()->SpawnActor<ABloqueMadera>(ABloqueMadera::StaticClass(),PosicionBloque,FRotator(0.0f, 0.0f, 0.0f)
            );
        }
    }
}

void ABomberManV2_012025GameMode::SpawnAndDestroyBlock()
{
    // Generar coordenadas aleatorias para la nueva posici�n
    float LocationX = 1500.0f;
    float LocationY = 1200.0f;
    float LocationZ = 0.0f; // Mant�n la altura fija en 0
    int BloquesGenerados=16;

    for (int i = 0; i < BloquesGenerados; i++) {
        FVector InitialPosition(LocationX+i*100, LocationY, LocationZ);
        // Spawnear un bloque
        ABloqueMadera* BloqueMadera = GetWorld()->SpawnActor<ABloqueMadera>(ABloqueMadera::StaticClass(), InitialPosition, FRotator(0.0f, 0.0f, 0.0f));
        // Destruir el bloque despu�s de 10 segundoS
        if (BloqueMadera)
        {
            BloqueMadera->SetLifeSpan(10.0f); // Este m�todo destruye el bloque autom�ticamente despu�s del tiempo dado
        }
    }

}