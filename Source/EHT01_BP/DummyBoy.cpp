#include "DummyBoy.h"

#include "UObject/Object.h"

// Sets default values
ADummyBoy::ADummyBoy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	DummyMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("DummyMesh"));
	if (!ensure(DummyMesh != nullptr)) return;
	DummyMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

// Called when the game starts or when spawned
void ADummyBoy::BeginPlay()
{
	Super::BeginPlay();
	GlobalStartLocation = GetActorLocation();
	GlobalTargetLocation = GetTransform().TransformPosition(TargetLoc);

	Speed = 200;
}

// Called every frame
void ADummyBoy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector Loc = GetActorLocation();
	float LengthDistance = (GlobalTargetLocation - GlobalStartLocation).Size();
	float lengthTravelled = (Loc - GlobalStartLocation).Size();
	if (lengthTravelled >= LengthDistance)
	{
		FVector tmp = GlobalStartLocation;
		GlobalStartLocation = GlobalTargetLocation;
		GlobalTargetLocation = tmp;
	}
	FVector Direction = (GlobalTargetLocation - GlobalStartLocation).GetSafeNormal();
	Loc += Speed * DeltaTime * Direction;
	SetActorLocation(Loc);


}

// Called to bind functionality to input
void ADummyBoy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

