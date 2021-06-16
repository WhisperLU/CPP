// Fill out your copyright notice in the Description page of Project Settings.


#include "Creater.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GeometryCollection/GeometryCollectionSimulationCoreTypes.h"
// Sets default values
ACreater::ACreater()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    //创建组件
    RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootSceneComponent"));
    StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
    SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
    CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
    //绑定组件
    StaticMeshComp->SetupAttachment(RootComponent);
    SpringArmComp->SetupAttachment(StaticMeshComp);
    CameraComp->SetupAttachment(SpringArmComp, USpringArmComponent::SocketName);
    //设置SpringArm的变量
    SpringArmComp->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, 50.0f), FRotator(-60.0f, 0.0f, 0.0f));
    SpringArmComp->bEnableCameraLag = true;
    SpringArmComp->TargetArmLength = 400.0f;
    SpringArmComp->CameraLagSpeed = 3.0f;
	//默认控制玩家
	// AutoPossessPlayer = EAutoReceiveInput::Player0;
}

// Called when the game starts or when spawned
void ACreater::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACreater::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// void ACreater::SetupPlayerComponent(UInputComponent* InputComponent)
// {
// 	Super::SetupPlayerInputComponent(InputComponent);
// }

