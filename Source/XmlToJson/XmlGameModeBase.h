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

//创建固定格式的XML文件格式，再读取本地具有该格式的XML文件
	UFUNCTION(BlueprintCallable, Category = "Xml")
		void CreateXmlParser();

	UFUNCTION(BlueprintCallable, Category = "Xml")
		void ReadXmlParser(const FString& _XmlPath);

	UFUNCTION(BlueprintCallable, Category = "Xml")
		bool ReadXml(FString& IP);

//读取本地XML格式文件
	UFUNCTION(BlueprintCallable, Category = "Xml")
		bool ReadXmlNew(const FString& InXmlFilePath);

public:
	//结构体数据写入Json文件，并创建.json格式文件
	UFUNCTION(BlueprintCallable,Category = JsonData)
		void StructSaveToJson();
	//读取.json格式文件
	UFUNCTION(BlueprintCallable, Category = JsonData)
		void LoadFromJson();
private:
	FVector ParseJsonAsVector(TSharedPtr<FJsonObject>JsonValueObject, FString KeyName);
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = JsonData)
		FFruitData FruitData;

};
