// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FabricaPlataformas.generated.h"

//declaración adelantada
class APlataforma;

UCLASS()
class AVENTURAUSFX022026L4_API AFabricaPlataformas : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFabricaPlataformas();
	APlataforma* CrearPlataforma(int Tipo, const FVector& Posicion, const FRotator& Rotacion);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
