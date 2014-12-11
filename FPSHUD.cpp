/**********************************************************************/
/*                                                                    */
/*         Game: First FPS											  */
/*		   Author: Victor Rocha                                       */
/*																	  */
/*		   This a FPS game made to study UE4 concepts. It's			  */
/*		   the first FPS game I ever made.							  */
/*                                                                    */
/**********************************************************************/

#include "AlanThornsBook01.h"
#include "FPSHUD.h"


AFPSHUD::AFPSHUD(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	/* Set the crosshair texture */
	static ConstructorHelpers::FObjectFinder<UTexture2D> CrosshairTexObj(TEXT("Texture2D'/Game/HeroFPP/crosshair.crosshair'"));
	CrosshairTex = CrosshairTexObj.Object;
}

void AFPSHUD::DrawHUD()
{
	Super::DrawHUD();

	// Draw crosshair at canvas's center 
	const FVector2D Center(Canvas->ClipX * 0.5f, Canvas->ClipY * 0.5f);

	// Offset by hald the texture's dimension thus the center of the texture aligns with the center of the canvas
	const FVector2D CrosshairDrawPosition((Center.X - (CrosshairTex->GetSurfaceWidth() * 0.5)),
		(Center.Y - (CrosshairTex->GetSurfaceHeight() * 0.5f)));

	//Draw crosshair
	FCanvasTileItem TileItem(CrosshairDrawPosition, CrosshairTex->Resource, FLinearColor::White);
	TileItem.BlendMode = SE_BLEND_Translucent;
	Canvas->DrawItem(TileItem);
}

