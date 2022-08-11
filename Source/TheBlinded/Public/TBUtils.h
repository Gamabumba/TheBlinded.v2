#pragma once


class TBUtils
{
public:
	template<typename T> 
	static T* GetTBPlayerComponent(APawn *PlayerPawn)
    {
        if (!PlayerPawn) return nullptr;

        const auto Component = PlayerPawn->GetComponentByClass(T::StaticClass());

        return Cast<T>(Component);
        

          }
};