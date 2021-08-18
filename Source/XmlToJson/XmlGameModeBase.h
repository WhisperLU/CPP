// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "XmlParser.h"
#include "FastXml.h"
#include "GameFramework/GameModeBase.h"
#include "XmlGameModeBase.generated.h"

/**
 * 
 */

FString idArray[];
FString latArray[];
FString lonArray[];
FString altArray[];
struct JsonContent
{
	FString k;
	FString v;
};
struct JsonContent JsonArray[];


USTRUCT(BlueprintType)
struct FFruitDetailData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = JsonData)
		FString Name;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = JsonData)
		FVector Size;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = JsonData)
		int32 Price;
};

USTRUCT(BlueprintType)
struct FFruitData
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = JsonData)
	TArray<FFruitDetailData>Details;

};


UCLASS()
class XMLTOJSON_API AXmlGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:

//�����̶���ʽ��XML�ļ���ʽ���ٶ�ȡ���ؾ��иø�ʽ��XML�ļ�
	UFUNCTION(BlueprintCallable, Category = "Xml")
		void CreateXmlParser();

	UFUNCTION(BlueprintCallable, Category = "Xml")
		void ReadXmlParser(const FString& _XmlPath);

	UFUNCTION(BlueprintCallable, Category = "Xml")
		bool ReadXml(FString& IP);

//��ȡ����XML��ʽ�ļ�
	UFUNCTION(BlueprintCallable, Category = "Xml")
		bool ReadXmlNew(const FString& InXmlFilePath);

public:
	//�ṹ������д��Json�ļ���������.json��ʽ�ļ�
	UFUNCTION(BlueprintCallable,Category = JsonData)
		void StructSaveToJson();
	//��ȡ.json��ʽ�ļ�
	UFUNCTION(BlueprintCallable, Category = JsonData)
		void LoadFromJson();
private:
	FVector ParseJsonAsVector(TSharedPtr<FJsonObject>JsonValueObject, FString KeyName);
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = JsonData)
		FFruitData FruitData;

};
