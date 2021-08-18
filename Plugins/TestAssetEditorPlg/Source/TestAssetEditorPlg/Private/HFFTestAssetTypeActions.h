// Fill out your copyright notice in the Description page of Project Settings.
//������Դ�ı�����ʽ��  4.25����֮����Ҫ�Զ��������
#pragma once
#include "AssetTypeActions_Base.h"
//#include "CoreMinimal.h"

/**
 * 
 */
class HFFTestAssetTypeActions : public FAssetTypeActions_Base
{
public:

	//Asset������
	virtual FText GetName() const override;
	//Assetͼ�����ɫ
	virtual FColor GetTypeColor() const override;
	//Asset��UObject��ʲô
	virtual UClass* GetSupportedClass() const override;
	//Asset�����ķ���
	virtual uint32 GetCategories() override;

	//��AssetTypeActions��OpenAssetEditor��ָ���༭��
	//����ָ���༭��,�򿪱༭���������´����ı༭��slate
	virtual void OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<class IToolkitHost> EditWithinLevelEditor = TSharedPtr<IToolkitHost>()) override;

};
