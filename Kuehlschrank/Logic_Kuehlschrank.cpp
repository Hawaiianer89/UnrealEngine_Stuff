// Fill out your copyright notice in the Description page of Project Settings.

#include "Logic_Kuehlschrank.h"

ALogic_Kuehlschrank::ALogic_Kuehlschrank()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ALogic_Kuehlschrank::BeginPlay()
{
	Super::BeginPlay();

	// Sicherstellen, dass die Starttemperatur im erlaubten Bereich liegt
	AktuelleTemperatur = FMath::Clamp(AktuelleTemperatur, MinimalTemperatur, MaxTemperatur);
	TimerAkkumulator = 0.0f;
}

void ALogic_Kuehlschrank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	TimerAkkumulator += DeltaTime;

	// Nur alle "Intervall" Sekunden (Standard: 3s) die Temperatur anpassen
	if (TimerAkkumulator >= Intervall)
	{
		TimerAkkumulator = 0.0f;

		if (bIstOffen)
		{
			// Tür offen: Temperatur steigt bis MaxTemperatur
			AktuelleTemperatur = FMath::Min(AktuelleTemperatur + TemperaturSchritt, MaxTemperatur);
		}
		else
		{
			// Tür zu: Temperatur sinkt bis MinimalTemperatur
			AktuelleTemperatur = FMath::Max(AktuelleTemperatur - TemperaturSchritt, MinimalTemperatur);
		}

		// Float-Präzisionsfehler vermeiden: auf 1 Nachkommastelle runden
		AktuelleTemperatur = FMath::RoundToFloat(AktuelleTemperatur * 10.0f) / 10.0f;
	}
}
