// Fill out your copyright notice in the Description page of Project Settings.
//����������Դ
#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "HFFTestAsset.generated.h"

/**
 * 
 */
UCLASS(EditInlineNew, config = Engine)//EditInlineNew ���ʾ���Դ� ����ñ༭���� ���Դ��ڴ�������Ķ���, �����Ǵ������ʲ����á�
class TESTASSETEDITORPLG_API UHFFTestAsset : public UObject
{
	GENERATED_BODY()

public:
	UHFFTestAsset(const FObjectInitializer& ObjectInitializer);

public:
	UPROPERTY(EditAnywhere)
		int TestData;
};
