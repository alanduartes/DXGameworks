#include "GameFramework/Character.h"
#include "Components/StaticMeshComponent.h"

#include "DummyBoy.generated.h"

UCLASS()
class EHT01_BP_API ADummyBoy : public ACharacter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Meta = (MakeEditWidget = true))
	FVector TargetLoc;
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* DummyMesh;

	UPROPERTY(EditAnywhere)
	float Speed;

	// Sets default values for this character's properties
	ADummyBoy();


private:
	FVector GlobalTargetLocation;
	FVector GlobalStartLocation;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
