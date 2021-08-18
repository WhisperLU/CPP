// Fill out your copyright notice in the Description page of Project Settings.


#include "MyFactory.h"

UMyFactory::UMyFactory():UFactory()
{
    SupportedClass = UUserAsset::StaticClass();//������Ҫ������ʵ������
    bCreateNew = true;
    bEditAfterNew = true;
}

UObject* UMyFactory::FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn, FName CallingContext)
{

    auto MyAsset = NewObject<UUserAsset>(InParent, InClass, InName, Flags); //��ΪAsset�Ǽ̳���UObject��ģ����������õ���NewObject

    return MyAsset;
}
bool UMyFactory::ShouldShowInNewMenu() const
{
    return true;
}