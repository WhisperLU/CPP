// Fill out your copyright notice in the Description page of Project Settings.


#include "MyFactory.h"

UMyFactory::UMyFactory():UFactory()
{
    SupportedClass = UUserAsset::StaticClass();//工厂需要创建的实例类型
    bCreateNew = true;
    bEditAfterNew = true;
}

UObject* UMyFactory::FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn, FName CallingContext)
{

    auto MyAsset = NewObject<UUserAsset>(InParent, InClass, InName, Flags); //因为Asset是继承自UObject类的，所以这里用的是NewObject

    return MyAsset;
}
bool UMyFactory::ShouldShowInNewMenu() const
{
    return true;
}