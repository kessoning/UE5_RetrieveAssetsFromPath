// Copyright Epic Games, Inc. All Rights Reserved.

#include "RetrieveAssetsFromPathBPLibrary.h"
#include "RetrieveAssetsFromPath.h"

// Retrieves assets from a specified directory.
TArray<UObject*> URetrieveAssetsFromPathBPLibrary::RetrieveAssetsFromPath(FString Directory, UClass* Type, bool IncludeSubDirs)
{
    TArray<UObject*> Assets;
    // Convert the directory to a full path within the project's content folder.
    FString FullDirectory = FPaths::ConvertRelativePathToFull(FPaths::ProjectDir()) + "Content/" + Directory + "/";
    // Search for file paths in the specified directory.
    TArray<FString> Paths = SearchPaths(FullDirectory, IncludeSubDirs);

    // Iterate through each found file path.
    for (const FString& EachPath : Paths)
    {
        // Create the correct load path for the asset.
        FString LoadPath = CreateLoadPath(EachPath, Directory, Type, IncludeSubDirs);
        // Attempt to load the asset from the constructed path.
        UObject* Asset = StaticLoadObject(Type, NULL, *LoadPath);
        // If the asset is successfully loaded, add it to the array.
        if (Asset != nullptr)
        {
            Assets.Add(Asset);
        }
    }

    // Log the loaded assets.
    LogAssets(Assets);
    return Assets;
}

// Searches for file paths in a specified directory.
TArray<FString> URetrieveAssetsFromPathBPLibrary::SearchPaths(const FString& FullDirectory, bool IncludeSubDirs)
{
    IFileManager& FileManager = IFileManager::Get();
    TArray<FString> Paths;

    // Set the filter to search for all file types.
    FString Filter = "*.*";
    // Construct the search pattern.
    FString Pattern = FullDirectory + Filter;

    // Search for files, optionally including subdirectories.
    if (IncludeSubDirs)
    {
        FileManager.FindFilesRecursive(Paths, *FullDirectory, *Filter, true, false);
    }
    else
    {
        FileManager.FindFiles(Paths, *Pattern, true, false);
    }

    return Paths;
}

// Creates the correct load path for an asset based on its file path.
FString URetrieveAssetsFromPathBPLibrary::CreateLoadPath(const FString& Path, const FString& Directory, UClass* Type, bool IncludeSubDirs)
{
    FString LoadPath;

    // Handle load paths differently based on whether subdirectories are included.
    if (IncludeSubDirs)
    {
        // Extract the file name and directory from the path.
        int32 SlashIndex = Path.Find("/", ESearchCase::IgnoreCase, ESearchDir::FromEnd);
        FString Name = Path.RightChop(SlashIndex + 1);
        FString Dir = Path.RightChop(Path.Find(Directory, ESearchCase::CaseSensitive, ESearchDir::FromEnd) + Directory.Len());
        Dir = Dir.LeftChop(Name.Len() + 1);
        Name = Name.Left(Name.Find(".", ESearchCase::IgnoreCase, ESearchDir::FromEnd));
        // Construct the asset load path.
        LoadPath = Type->GetFName().ToString() + "'/Game/" + Directory + Dir + "/" + Name + "." + Name + "'";
    }
    else
    {
        // Construct the asset load path without considering subdirectories.
        LoadPath = Type->GetFName().ToString() + "'/Game/" + Directory + "/" + Path.LeftChop(7) + "." + Path.LeftChop(7) + "'";
    }

    return LoadPath;
}

// Logs the loaded assets, indicating if any null assets were encountered.
void URetrieveAssetsFromPathBPLibrary::LogAssets(const TArray<UObject*>& Assets)
{
    for (UObject* Asset : Assets)
    {
        if (Asset != nullptr)
        {
            UE_LOG(LogTemp, Log, TEXT("Asset Loaded: %s"), *Asset->GetFName().ToString());
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("Null asset in array"));
        }
    }
}