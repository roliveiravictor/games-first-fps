/**********************************************************************/
/*                                                                    */
/*         Game: First FPS											  */
/*		   Author: Victor Rocha                                       */
/*																	  */
/*		   This a FPS game made to study UE4 concepts. It's			  */
/*		   the first FPS game I ever made.							  */
/*                                                                    */
/**********************************************************************/

#pragma once

#include "GameFramework/GameMode.h"
#include "MyGameMode.generated.h"


/**
 * 
 */
UCLASS()
class AMyGameMode : public AGameMode
{
	GENERATED_UCLASS_BODY()

	virtual void StartPlay() override;
};


