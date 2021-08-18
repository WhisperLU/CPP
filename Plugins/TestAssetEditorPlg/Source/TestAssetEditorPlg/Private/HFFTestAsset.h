// Fill out your copyright notice in the Description page of Project Settings.
//待创建的资源
#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "HFFTestAsset.generated.h"

/**
 * 
 */
UCLASS(EditInlineNew, config = Engine)//EditInlineNew 宏表示可以从 “虚幻编辑器” 属性窗口创建此类的对象, 而不是从现有资产引用。
class TESTASSETEDITORPLG_API UHFFTestAsset : public UObject
{
	GENERATED_BODY()

public:
	UHFFTestAsset(const FObjectInitializer& ObjectInitializer);

public:
	UPROPERTY(EditAnywhere)
		int TestData;
};
