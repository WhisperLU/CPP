// Fill out your copyright notice in the Description page of Project Settings.


#include "XmlGameModeBase.h"
#include "JsonObjectConverter.h"
#include "Misc/FileHelper.h"
#include"Templates/SharedPointer.h"


void  AXmlGameModeBase::CreateXmlParser()
{
    //创建的xml文件内容，需要符合xml的规则，不符合则无法写入
    const FString _XmlContent = "<DocumentElement>\n<Infor>\n< ID>01 </ID >\n<Name>AB</Name>\n<Content>BCD</Content>\n</Infor>\n</DocumentElement>";
    //以Buffer的方式创建一个XmlFile对象
    FXmlFile* _WriteXml = new FXmlFile(_XmlContent, EConstructMethod::ConstructFromBuffer);
    //创建XmlFile对象失败
    if (_WriteXml == nullptr)
    {
        GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("create xml file Error!"));
        return;
    }
    //保存xml文件到当前工程
    //GameDir() 替换成 ProjectDir(),新版本已经不用了
    _WriteXml->Save(FPaths::ProjectDir() + "write01.xml");
    GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, TEXT("create xml file Success!"));
}

void AXmlGameModeBase::ReadXmlParser(const FString& _XmlPath)
{
    //创建一个XmlFile对象
    FXmlFile* _XmlFile = new FXmlFile(_XmlPath);
    //得到_XmlFile的根节点
    FXmlNode* _RootNode = _XmlFile->GetRootNode();
    //得到根节点下的所有节点
    const TArray<FXmlNode*> _AssetNodes = _RootNode->GetChildrenNodes();
    for (FXmlNode* node : _AssetNodes)
    {
        //得到_AssetNodes下的所有子节点
        const TArray<FXmlNode*> _ChildNodes = node->GetChildrenNodes();
        FString _AssetContent = node->GetContent();
        //打印_AssetNodes内容
        GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, _AssetContent);
        for (FXmlNode* node1 : _ChildNodes)
        {
            FString _ChildContent = node1->GetContent();
            //打印_ChildNodes内容
            GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, _ChildContent);
        }
    }
}

bool AXmlGameModeBase::ReadXml(FString& IP)
{
    if (FPlatformFileManager::Get().GetPlatformFile().FileExists(*(FPaths::ProjectDir() + TEXT("XML/Setting.xml"))))
    {
        UE_LOG(LogTemp, Warning, TEXT("Find XML File!"));

        FXmlFile* file = new FXmlFile(FPaths::ProjectDir() + TEXT("write02.xml"));
        FXmlNode* RootNode = file->GetRootNode();
        FXmlNode* m_IP = RootNode->FindChildNode("IP");
        IP = *m_IP->GetContent();
        return true;
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Cannot Find XML File"));
        return false;
}
}

bool AXmlGameModeBase::ReadXmlNew(const FString& InXmlFilePath)
{
	//平台文件管理器，判断文件是否存在
	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
	if (!PlatformFile.FileExists(*InXmlFilePath))
	{
		return false;
	}
	{
		TSharedPtr<FXmlFile>XmlFile = MakeShareable(new FXmlFile(InXmlFilePath));//给共享指针赋值，私有的仍然可以运行
		if (XmlFile->IsValid())
		{
			//FXmlNode* RootNode = XmlFile->GetRootNode();
			//for (FXmlNode* ChildNode : RootNode->GetChildrenNodes())
			//{
			//	FString category = ChildNode->GetAttribute("category");
			//	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Purple, category);
			//	for (FXmlNode* SubChildNode : ChildNode->GetChildrenNodes())
			//	{
			//		FString lang = SubChildNode->GetAttribute("lang");
			//		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Purple, lang);

			//		FString Content = SubChildNode->GetContent();
			//		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Black, Content);
			//	}
			//}

            FXmlNode* RootNode = XmlFile->GetRootNode();
            for (FXmlNode* ChildNode : RootNode->GetChildrenNodes())
            {
                FString id = ChildNode->GetAttribute("id");
                GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Purple, id);
                FString lat = ChildNode->GetAttribute("lat");
                GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Purple, lat);
                FString lon = ChildNode->GetAttribute("lon");
                GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Purple, lon);
                FString alt = ChildNode->GetAttribute("alt");
                GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Purple, alt);

                for (FXmlNode* SubChildNode : ChildNode->GetChildrenNodes())
                {
                    FString k = SubChildNode->GetAttribute("k");
                    GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Black, k);
                    FString v = SubChildNode->GetAttribute("v");
                    GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Black, v);
                    //FString Content = SubChildNode->GetContent();
                    //GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Black, Content);
                }
            }
		}
		return true;
	}
	return false;
}

//结构体数据写入Json文件，并创建.json格式文件
void AXmlGameModeBase::StructSaveToJson()
{
	FFruitDetailData Apple;
	Apple.Name = TEXT("Apple");
	Apple.Size = FVector(5.0f, 5.0f, 5.0f);
	Apple.Price = 1000;
	FruitData.Details.Add(Apple);

	FFruitDetailData Banana;
	Banana.Name = TEXT("Banana");
	Banana.Size = FVector(3.0f, 5.0f, 10.0f);
	Banana.Price = 1200;
	FruitData.Details.Add(Banana);

	FString JsonString;
	FJsonObjectConverter::UStructToJsonObjectString(FruitData, JsonString);
	FFileHelper::SaveStringToFile(*JsonString, *(FPaths::ProjectContentDir() + TEXT("/Json/Test.json")));
}

//读取.json格式文件
void AXmlGameModeBase::LoadFromJson()
{
	FString JsonString;
	FFileHelper::LoadFileToString(JsonString, *(FPaths::ProjectContentDir() + TEXT("/Json/Test.json")));

	TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(JsonString);
	TSharedPtr<FJsonObject>JsonObject = MakeShareable(new FJsonObject());

	if (FJsonSerializer::Deserialize(JsonReader, JsonObject) && JsonObject.IsValid())
	{
		TArray<TSharedPtr<FJsonValue>>JsonValueArray = JsonObject->GetArrayField(TEXT("details"));
		for (int32 i = 0; i < JsonValueArray.Num(); i++)
		{
			TSharedPtr<FJsonValue>JsonValue = JsonValueArray[i];
			TSharedPtr<FJsonObject>JsonValueObject = JsonValue->AsObject();

			FFruitDetailData DetailData;
			DetailData.Name = JsonValueObject->GetStringField(TEXT("name"));
			DetailData.Size = ParseJsonAsVector(JsonValueObject, TEXT("size"));
			DetailData.Price = JsonValueObject->GetNumberField(TEXT("price"));

			FruitData.Details.Push(DetailData);
			UE_LOG(LogTemp, Warning, TEXT("Name:%s,Size:%s,Price:%d"), *DetailData.Size.ToString(), DetailData.Price);
		}
	}
    UE_LOG(LogTemp, Warning, TEXT("Can't Find Json File!"));
}

FVector AXmlGameModeBase::ParseJsonAsVector(TSharedPtr<FJsonObject> JsonValueObject, FString KeyName)
{
	TArray<FString>ArrayJson;
	JsonValueObject->TryGetStringArrayField(*KeyName, ArrayJson);

	return FVector{ FCString::Atof(*ArrayJson[0]),FCString::Atof(*ArrayJson[1]),FCString::Atof(*ArrayJson[2]) };
}
