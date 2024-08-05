#pragma once

#include "CoreMinimal.h"

class Helper
{
public:
	template<typename T>
	static T* CreateSceneComponent(AActor* Owner, FName NewComponentName, USceneComponent* ParentComponent = nullptr)
	{
		T* NewComponent = Owner->CreateDefaultSubobject<T>(NewComponentName);

		if (ParentComponent)
			NewComponent->SetupAttachment(ParentComponent);
		else
			Owner->SetRootComponent(NewComponent);

		return NewComponent;
	}

	template<typename T>
	static T* CreateActorComponent(AActor* Owner, FName NewComponentName)
	{
		T* NewComponent = Owner->CreateDefaultSubobject<T>(NewComponentName);
		return NewComponent;
	}

	template<typename T>
	static TSubclassOf<T> GetClassFromConstructor(FString Path)
	{
		ConstructorHelpers::FClassFinder<T> Finder(*Path);

		if (Finder.Succeeded())
			return Finder.Class;
		return nullptr;
	}

	template<typename T>
	static TObjectPtr<T> GetAssetFromConstructor(FString Path)
	{
		ConstructorHelpers::FObjectFinder<T> Finder(*Path);

		if (Finder.Succeeded())
			return Finder.Object;
		return nullptr;
	}

	static int32 MakeDataTableFromPath(FString RootPath, FString ColumnName)
	{
		return 0;
	}
};