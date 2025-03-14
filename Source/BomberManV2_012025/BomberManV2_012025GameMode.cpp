// Copyright Epic Games, Inc.All Rights Reserved.

#include "BomberManV2_012025GameMode.h"
#include "BomberManV2_012025Character.h"
#include "UObject/ConstructorHelpers.h"
#include "BloqueMadera.h"
#include "BloqueAcero.h"
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
    SpawnBloque();
    // Configura un timer para llamar a la función periódicamente
    GetWorldTimerManager().SetTimer(BloqueTimerHandle,this,&ABomberManV2_012025GameMode::SpawnAndDestroyBlock,15.0f,true);

    GEngine->AddOnScreenDebugMessage(-1, -1, FColor::Red, TEXT("Generando Troncos"));

    FVector BasePosition(0.0f, 0.0f, 0.0f); // Posición base del tronco (X, Y, Z)
    float AlturaBloque = 100.0f; // Altura de cada bloque (ajusta según el tamaño de tus bloques)

    int NumeroBloquesPorTronco = 5; // Cantidad de bloques en cada tronco
    int CantidadTroncos = 8; // Número de troncos a generar

    for (int i = 0; i < CantidadTroncos; i++)
    {
        // Calcula la posición base para cada tronco con algo de variación en X y Y
        float OffsetX = FMath::RandRange(100.0f, 3000.0f); // Variación aleatoria dentro de 3000x3000
        float OffsetY = FMath::RandRange(100.0f, 3000.0f);

        FVector PosicionTronco = BasePosition + FVector(OffsetX, OffsetY, 0.0f);

        for (int j = 0; j < NumeroBloquesPorTronco; j++)
        {
            // Calcular posición del bloque actual
            FVector PosicionBloque = PosicionTronco + FVector(0.0f, 0.0f, j * AlturaBloque);

            // Spawnear el bloque
            ABloqueMadera* BloqueMadera = GetWorld()->SpawnActor<ABloqueMadera>(ABloqueMadera::StaticClass(),PosicionBloque,FRotator(0.0f, 0.0f, 0.0f)
            );
        }
    }
}

void ABomberManV2_012025GameMode::SpawnAndDestroyBlock()
{
    // Generar coordenadas aleatorias para la nueva posición
    float LocationX = 1500.0f;
    float LocationY = 1200.0f;
    float LocationZ = 0.0f; // Mantén la altura fija en 0
    int BloquesGenerados=16;

    for (int i = 0; i < BloquesGenerados; i++) {
        FVector InitialPosition(LocationX+i*100, LocationY, LocationZ);
        // Spawnear un bloque
        ABloqueMadera* BloqueMadera = GetWorld()->SpawnActor<ABloqueMadera>(ABloqueMadera::StaticClass(), InitialPosition, FRotator(0.0f, 0.0f, 0.0f));
        // Destruir el bloque después de 10 segundoS
        if (BloqueMadera)
        {
            BloqueMadera->SetLifeSpan(10.0f); // Este método destruye el bloque automáticamente después del tiempo dado
        }
    }

}

void ABomberManV2_012025GameMode::SpawnBloque()
{
    if (UWorld* World = GetWorld()) {
        FVector SpawnLocation = FVector(0, 0, 0);
        FRotator SpawnRotation = FRotator::ZeroRotator;

        ABloqueAcero* NuevoBloque = World->SpawnActor<ABloqueAcero>(ABloqueAcero::StaticClass(), SpawnLocation, SpawnRotation);

    }
}
