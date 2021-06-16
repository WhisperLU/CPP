// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Engine/Classes/Kismet/DataTableFunctionLibrary.h"
#include "MenuCharacter.generated.h"

UCLASS()
class TEST426CPP_API AMenuCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMenuCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	public:

		/**just a new world*/
		UFUNCTION(BlueprintCallable, Category = "Utilities|FlowControl", meta = (Latent, WorldContext = "WorldContextObject", LatentInfo = "LatentInfo", Duration = "0.2"))
			static void DelayAA(UObject* WorldContextObject, float Duration, struct FLatentActionInfo LatentInfo);

		/**just a bad world
		 * 
 		 * @param WorldContextObject  YOU CAN SLEEP
 		 * @param Duration      YOU CAN DRINK IT 
 		 * @param LatentInfo    YOU CAN EAT IT 
 		 */
		UFUNCTION(BlueprintCallable, Category = "Utilities|FlowControl")
			static void DelayBB(UObject* WorldContextObject, float Duration, struct FLatentActionInfo LatentInfo);

			//meta = (ExpandEnumAsExecs = "OutResult", DataTablePin = "CurveTable") 这句是把枚举变量直接解开作为输出执行引脚
		UFUNCTION(BlueprintCallable, Category = "DataTable", meta = (ExpandEnumAsExecs = "OutResult", DataTablePin = "CurveTable"))
			static void EvaluateCurveTableRow(UCurveTable* CurveTable, FName RowName, float InXY, TEnumAsByte<EEvaluateCurveTableResult::Type>& OutResult, float& OutXY);

		UFUNCTION(BlueprintCallable, Category = "DataTable")
			static void EvaluateCurveTableRowNew(UCurveTable* CurveTable, FName RowName, float InXY, TEnumAsByte<EEvaluateCurveTableResult::Type>& OutResult, float& OutXY);
};
