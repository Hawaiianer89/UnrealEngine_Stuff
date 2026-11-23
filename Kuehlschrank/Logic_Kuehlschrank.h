// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Logic_Kuehlschrank.generated.h"

UCLASS()
class SPIELWIESE_API ALogic_Kuehlschrank : public AActor
{
	GENERATED_BODY()

public:
	ALogic_Kuehlschrank();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	// Steuert, ob die Tür offen ist – im Blueprint lesen & schreiben
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Kuehlschrank")
	bool bIstOffen = false;

	// Aktuelle Temperatur – nur lesen im Blueprint
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Kuehlschrank")
	float AktuelleTemperatur = 4.0f;

	// Maximale Temperatur wenn Tür offen
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Kuehlschrank")
	float MaxTemperatur = 20.0f;

	// Minimale Temperatur wenn Tür geschlossen
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Kuehlschrank")
	float MinimalTemperatur = 4.0f;

	// Temperaturänderung pro Intervall (°C)
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Kuehlschrank")
	float TemperaturSchritt = 0.3f;

	// Intervall in Sekunden zwischen Temperaturänderungen
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Kuehlschrank")
	float Intervall = 3.0f;

private:
	// Interner Zähler – kein UPROPERTY nötig
	float TimerAkkumulator = 0.0f;
};
