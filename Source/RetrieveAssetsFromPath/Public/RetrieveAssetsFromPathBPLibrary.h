// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "RetrieveAssetsFromPathBPLibrary.generated.h"

/**
 * A utility class for retrieving assets from a specified directory within the project.
 */
UCLASS()
class URetrieveAssetsFromPathBPLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    // BlueprintCallable function to retrieve assets from a specified directory.
    UFUNCTION(BlueprintCallable, Category = "Utility|AssetManagement")
    static TArray<UObject*> RetrieveAssetsFromPath(FString Directory = "Assets", UClass* Type = nullptr, bool IncludeSubDirs = false);

private:
    // Helper function to search for file paths in a directory, optionally including subdirectories.
    static TArray<FString> SearchPaths(const FString& FullDirectory, bool IncludeSubDirs);

    // Helper function to create the correct load path for an asset based on its file path.
    static FString CreateLoadPath(const FString& Path, const FString& Directory, UClass* Type, bool IncludeSubDirs);

    // Helper function to log the assets that have been loaded.
    static void LogAssets(const TArray<UObject*>& Assets);
};
