// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BomberManV2_012025GameMode.generated.h"

UCLASS(minimalapi)
class ABomberManV2_012025GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ABomberManV2_012025GameMode();
    virtual void BeginPlay() override;
private:
    // Timer handle para controlar el tiempo entre apariciones
    FTimerHandle BloqueTimerHandle;

    // Función para generar y destruir bloques
    void SpawnAndDestroyBlock();
};



