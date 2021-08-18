// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UserAsset.generated.h"

/**
 * 
 */
UCLASS()
class TEST426CPP_API UUserAsset : public UObject
{
	GENERATED_BODY()
public:
    UUserAsset();

    UPROPERTY(EditAnywhere, Category = Properties)
        FString Name;
};


