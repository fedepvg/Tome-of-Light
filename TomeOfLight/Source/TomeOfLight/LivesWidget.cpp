// Fill out your copyright notice in the Description page of Project Settings.


#include "LivesWidget.h"
#include "Components/Image.h"

void ULivesWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	LivesArray.Add(LifeImage1);
	LivesArray.Add(LifeImage2);
	LivesArray.Add(LifeImage3);
}

void ULivesWidget::UpdateLives()
{
	for(UImage* i : LivesArray)
	{
		if(i->IsVisible())
		{
			i->SetVisibility(ESlateVisibility::Hidden);
			break;
		}
	}
}