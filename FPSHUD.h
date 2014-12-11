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

#include "GameFramework/HUD.h"
#include "FPSHUD.generated.h"

/**
 * 
 */
UCLASS()
class ALANTHORNSBOOK01_API AFPSHUD : public AHUD
{
	GENERATED_UCLASS_BODY()

private:

	/* Crosshair asset pointer */
	UTexture2D* CrosshairTex;

	/* Primary draw call for HUD */
	virtual void DrawHUD() OVERRIDE;
};
