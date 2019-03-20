#include <raylib.h>
#include <raymath.h>
#include <string.h>
#include "data.h"

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

Vector2 Screen = (Vector2) { 640, 480};
Vector2 VirtualScreen = (Vector2) { 640, 480};

void DrawQuadSprite ( Texture2D sprite , Vector2 position, float scaleX, float scaleY, Color color);
void DrawFrameBuffer(RenderTexture2D renderer);
void DrawTextImage(Texture2D texture, char * txt, float x, float y );

int main() {
	SetConfigFlags(FLAG_VSYNC_HINT);
	InitWindow( GetMonitorWidth(0),GetMonitorHeight(0),"Demo Awesome");
	SetWindowMinSize(Screen.x, Screen.y);
	
	HideCursor();

	InitAudioDevice();

	// -------------------------------------------------------------------------------------------------------------
	// Icone window
	// -------------------------------------------------------------------------------------------------------------

	Image icon = LoadImagePro( icon_data, 32, 32, UNCOMPRESSED_R8G8B8A8);
	SetWindowIcon(icon);
	UnloadImage(icon);

	// -------------------------------------------------------------------------------------------------------------
	// Copper
	// -------------------------------------------------------------------------------------------------------------

	Texture2D copper[11];

	for(int i = 0; i < 11; i++) {
		Image _copper = LoadImagePro(copper_data[i], 4, 56, UNCOMPRESSED_R8G8B8A8);
		copper[i] = LoadTextureFromImage(_copper);
		UnloadImage(_copper);
	}

	// -------------------------------------------------------------------------------------------------------------
	// Copper Bar
	// -------------------------------------------------------------------------------------------------------------

	Image cop1 = LoadImagePro(copper_bar_data, 8, 34, UNCOMPRESSED_R8G8B8A8);
	Texture2D copper_bar = LoadTextureFromImage(cop1);
	UnloadImage(cop1);

	// -------------------------------------------------------------------------------------------------------------
	// Logo
	// -------------------------------------------------------------------------------------------------------------

	Image _logo = LoadImagePro(logo_data, 636, 108, UNCOMPRESSED_R8G8B8A8);
	Texture2D logo = LoadTextureFromImage(_logo);
	UnloadImage(_logo);

	// -------------------------------------------------------------------------------------------------------------
	// Text data
	// -------------------------------------------------------------------------------------------------------------

	Image _text_data = LoadImagePro(text_data, 636, 236, UNCOMPRESSED_R8G8B8A8);
	Texture2D text_data = LoadTextureFromImage(_text_data);
	UnloadImage(_text_data);

	// -------------------------------------------------------------------------------------------------------------
	// Framebuffer
	// -------------------------------------------------------------------------------------------------------------

	RenderTexture2D frameBuffer = LoadRenderTexture( VirtualScreen.x, VirtualScreen.y );
	SetTextureFilter(frameBuffer.texture, FILTER_POINT);

	// -------------------------------------------------------------------------------------------------------------
	// Fonte
	// -------------------------------------------------------------------------------------------------------------

	Image fontData = LoadImagePro(font_data, 2048, 32, UNCOMPRESSED_R8G8B8A8 );
	Texture2D characters = LoadTextureFromImage(fontData);
	UnloadImage(fontData);

	// -------------------------------------------------------------------------------------------------------------
	// Music
	// -------------------------------------------------------------------------------------------------------------

	Music music = LoadMusicStream("NTMMEG.ogg");
	PlayMusicStream(music);
	SetMusicVolume(music, 1.0f);

	// -------------------------------------------------------------------------------------------------------------
	// Divers
	// -------------------------------------------------------------------------------------------------------------

	SetTargetFPS(60);

	char * scrollText = "WELCOME TO THIS DISK WHICH HOLDS THE TITLE OF AWESOME MENU 16!   YOUR HOST FOR THIS FULL OVERSCAN MENU IS RUTHLESS.    I WOULD LIKE TO DEDICATE THIS MUSIC TO QUEERTRO OF COCKUP ORGASM, HEY THAT'S WRONG, LET ME GET MY C.O. DICTIONARY...    AHA, SORRY IT IS ACTUALLY SUPPOSED TO READ AS...  I WOULD LIKE TO DEDICATE THIS MENU TO QUATTRO OF CLOCKWORK ORANGE BECAUSE HE KEEPS ON ASKING ME TO SEND HIM SOME LAP MUSIC - WON'T YOUR 'ULTIMATE RIPPER' HARDWARE CARTRIDGE LET YOU RIP IT WITH IT'S BUILT IN MUSIC RIPPER, WHAT'S THAT YOU DON'T KNOW HOW TO USE IT.   OH DEAR, WELL JUST TO MAKE YOU HAPPY I WILL PUT SOME LAP MUSIC FILES ON THE NEXT MENU (WITH REPLAY CODE OF COURSE, A BIT USELESS TO YOU OTHERWISE - DON'T YOU AGREE!!!).  ONLY KIDDING QUATTRO.    OR WAS I?   HO!  HO!  HO!      NOW ONTO THE MEMBERS OF AWESOME, I WOULD LIKE TO TAKE THIS OPPORTUNITY TO LET ZELDA KNOW THAT AS FROM THIS MENU HE IS NO LONGER A MEMBER OF AWESOME.  DON'T TAKE IT PERSONALLY, 3 OTHERS WILL BE KICKED OUT SOON AS WELL!    A BIG WELCOME TO OUR NEW MEMBER WHO WILL BE GOING UNDER THE NAME OF 'DOMINION'  HE IS A VERY GOOD CRACKER, CODER, FILER AND PACKER.   YOU CAN EXPECT TO SEE LOTS OF HIS WORK ON FUTURE AWESOME MENUS!!!   HE IS THE GUY WHO CODED THE POMPEY PIRATES THE FULL SCREEN INTRO ON THEIR MENU 88 AND THE CONTROLABLE SPACESHIP ON THEIR MENU 91.   TECHNO WILL BE LEAVING THE CREW OF HIS OWN ACCORD TOWARDS THE END OF THE YEAR AND HE WILL BE GREATLY MISSED!     MEMBERS OF AWESOME NOW ARE:-  RUTHLESS, FROSTY, K-KLASS, DOMINION, TECHNO, THE BALD EAGLE, JOLLY ROGER, THE EDITMAN, ONIXUS AND PHOENIX...    NOW YOUR CHANCE TO JOIN ONE OF THE WORLDS BIGGEST CREWS...  YES, HERE IS YOUR CHANCE TO JOIN AWESOME.  IF YOU CAN CRACK, FILE, CODE, OWN A MODEM OR YOU FEEL YOU DO SOMETHING ELSE WHICH WOULD BE USEFUL TO US, THEN PLEASE CONTACT US, DO NOT WRITE TO OUR P.O. BOX IN ICELAND BUT WAIT FOR THE BRITISH P.O. BOX ADDRESS COMING SOON ON A NEW AWESOME MENU!          CREDITS FOR THIS MENU GOTO... CODING BY:- ECSTASY OF THE REPLICANTS, G.F.X BY:- MAGNUM OF TWB, AND MUSIC BY:- LAP....     RIGHT DUDES, VERY QUICK 'WORD TO THE MOTHER' GREETS GOTO...   THE REST OF AWESOME, THE REPLICANTS (CAMEO, COBRA, SNAKE, ECSTASY AND ALL THE OTHERS), THE SYNDICATE - OUR PARTNERS IN CRIME (FLOSSY AND BEAST, PLEASE CALL ME FLOSSY!), THE REST OF E.S.C. (T.S.B. ESP. ZINE, I AM GLAD YOU ARE BACK!), FUZION (KELLY-X, DOCNO AND DRAGON), THE SYNIX, HAL, EGB, MAGNUM, THE POMPEY PIRATES (GENIE, YUM-YUM, PACMAN, LITTLE LULU AND MY NEW CONTACT SPARKY - NICE TALKING TO YOU DUDE!), SUPERIOR (WANDERER AND AXE), GRIFF, GINO, FACTORY (HIGHLANDER AND SPY 3), LYNX (HEADHUNTER), N.P.G. (TGA), ORION (SPIFF), UNTOUCHABLES (MATT AND TONY), QUATTRO, RIP (TITANIC TARZAN - WHAT HAS HAPPENED TO THE LETTERS?), ELECTRONIC, PROWLER, THE SOURCE (KALAMAZOO AND MUG), EVIL FORCE (JASON ELITE), THE RADICAL BANDITS (T H E  R U D E  D U D E AND HIS SUPPLIER), FUTUR MINDS (SKYLINE), THE AVENGER, BLOODANGEL, PEDRO, NOW 5 (FALCON), ANGELS OF MERCY (BUT ESPECIALLY KIM), THE FOX, TEDDY, GEORGE, NEW PIRATES, IMAGINA, EVOLOUTION (MONSTER BEETLE - HOPE YOU LIKE YOUR INTRO), THE P.H.F. CODERS FORM HULL (CODING FOR FUN), ROBERTO FROM ITALY, H.A.C. (DOCTOR BYTE), V MAX (THANX FOR GREET), JOBIL, NEXT, STUART, JOKER AND TO ALL OTHERS THAT I HAVE FORGOTTEN...   NO TIME FOR ANYMORE BULLSHIT SO UNTIL THE NEXT SAGA OF THE 'HOTEST SOFTWARE AROUND' RUTHLESS SUMMONS A WRAP.     LET'S WRAP DUDES!      .................... MADE BY ANATA WITH THE EXCELLENT RAYLIB LIBRARY ....................";
	float scrollTextX = 640;
	int textLen = strlen(scrollText);

	float rastsin=0;
	float rastoffset=0.06;
	float amp=150;

	while(!WindowShouldClose()) {
		UpdateMusicStream(music);

		// -------------------------------------------------------------------------------------------------------------
		// Scroll Text
		// -------------------------------------------------------------------------------------------------------------

		scrollTextX -= GetFrameTime() * 128;
		if(scrollTextX < -textLen*32+32 ) scrollTextX = VirtualScreen.x+32;

		rastsin += GetFrameTime()*3;

		// -------------------------------------------------------------------------------------------------------------
		// Framebuffer
		// -------------------------------------------------------------------------------------------------------------

		BeginTextureMode(frameBuffer);
		{
			ClearBackground(BLACK);

			// -------------------------------------------------------------------------------------------------------------
			// Draw copper
			// -------------------------------------------------------------------------------------------------------------
			
			for(int i = 0; i < 27; i++) {
				DrawTexturePro( copper[10], (Rectangle) { 40, 0, 4, 56 }, (Rectangle) { -4+i*24, (296/2) + sin(rastsin-rastoffset*50-(i*0.05))*amp, 24, 56 }, (Vector2) { 0.5, 0.5 }, 0, WHITE );
				DrawTexturePro( copper[9], (Rectangle) { 36, 0, 4, 56 }, (Rectangle) { -4+i*24, (296/2) + sin(rastsin-rastoffset*45-(i*0.05))*amp, 24, 56 }, (Vector2) { 0.5, 0.5 }, 0, WHITE );
				DrawTexturePro( copper[8], (Rectangle) { 32, 0, 4, 56 }, (Rectangle) { -4+i*24, (296/2) + sin(rastsin-rastoffset*40-(i*0.05))*amp, 24, 56 }, (Vector2) { 0.5, 0.5 }, 0, WHITE );
				DrawTexturePro( copper[7], (Rectangle) { 28, 0, 4, 56 }, (Rectangle) { -4+i*24, (296/2) + sin(rastsin-rastoffset*35-(i*0.05))*amp, 24, 56 }, (Vector2) { 0.5, 0.5 }, 0, WHITE );
				DrawTexturePro( copper[6], (Rectangle) { 24, 0, 4, 56 }, (Rectangle) { -4+i*24, (296/2) + sin(rastsin-rastoffset*30-(i*0.05))*amp, 24, 56 }, (Vector2) { 0.5, 0.5 }, 0, WHITE );
				DrawTexturePro( copper[5], (Rectangle) { 20, 0, 4, 56 }, (Rectangle) { -4+i*24, (296/2) + sin(rastsin-rastoffset*25-(i*0.05))*amp, 24, 56 }, (Vector2) { 0.5, 0.5 }, 0, WHITE );
				DrawTexturePro( copper[4], (Rectangle) { 16, 0, 4, 56 }, (Rectangle) { -4+i*24, (296/2) + sin(rastsin-rastoffset*20-(i*0.05))*amp, 24, 56 }, (Vector2) { 0.5, 0.5 }, 0, WHITE );
				DrawTexturePro( copper[3], (Rectangle) { 12, 0, 4, 56 }, (Rectangle) { -4+i*24, (296/2) + sin(rastsin-rastoffset*15-(i*0.05))*amp, 24, 56 }, (Vector2) { 0.5, 0.5 }, 0, WHITE );
				DrawTexturePro( copper[2], (Rectangle) { 8, 0, 4, 56 }, (Rectangle) { -4+i*24, (296/2) + sin(rastsin-rastoffset*10-(i*0.05))*amp, 24, 56 }, (Vector2) { 0.5, 0.5 }, 0, WHITE );
				DrawTexturePro( copper[1], (Rectangle) { 4, 0, 4, 56 }, (Rectangle) { -4+i*24, (296/2) + sin(rastsin-rastoffset*5-(i*0.05))*amp, 24, 56 }, (Vector2) { 0.5, 0.5 }, 0, WHITE );
				DrawTexturePro( copper[0], (Rectangle) { 0, 0, 4, 56 }, (Rectangle) { -4+i*24, (296/2) + sin(rastsin-(i*0.05))*amp, 24, 56 }, (Vector2) { 0.5, 0.5 }, 0, WHITE );
			}

			// -------------------------------------------------------------------------------------------------------------
			// Draw Logo
			// -------------------------------------------------------------------------------------------------------------

			DrawTexture(logo, 2, 6, WHITE);

			// -------------------------------------------------------------------------------------------------------------
			// Draw Text Data
			// -------------------------------------------------------------------------------------------------------------

			DrawTexture(text_data, 2, 112, WHITE);

			// -------------------------------------------------------------------------------------------------------------
			// Draw Copper Bar
			// -------------------------------------------------------------------------------------------------------------

			DrawTextureQuad(copper_bar, (Vector2){80,1}, (Vector2){0},(Rectangle){0,380,VirtualScreen.x,34},WHITE);

			// -------------------------------------------------------------------------------------------------------------
			// Draw Scroll Text
			// -------------------------------------------------------------------------------------------------------------

			for(int i=0; i < textLen; i++) {
				if (scrollTextX + ( i << 5 ) > -32 && scrollTextX + ( i << 5 ) < VirtualScreen.x + 32) {
					DrawTexturePro(
						characters,
						(Rectangle) { (scrollText[i] - 32) << 5, 0, 32, 32 },
						(Rectangle) { scrollTextX + (i << 5) , 380, 32, 32 },
						(Vector2) {0},
						0,
						WHITE
					);
				}
			}
		}
		EndTextureMode();

		BeginDrawing();
		{
			ClearBackground(BLACK);

			// -------------------------------------------------------------------------------------------------------------
			// Draw final frameBuffer
			// -------------------------------------------------------------------------------------------------------------

			DrawFrameBuffer(frameBuffer);
		}
		EndDrawing();
	}

	for(int i = 0; i < 11; i++) UnloadTexture(copper[i]);
	UnloadTexture(copper_bar);
	UnloadTexture(logo);
	UnloadTexture(text_data);
	UnloadTexture(characters);
	UnloadRenderTexture(frameBuffer);
	UnloadMusicStream(music);
	CloseWindow();
	return 0;
}

// -------------------------------------------------------------------------------------------------------------
// UPDATE BUFFER , DRAW QUAD AND TEXT
// -------------------------------------------------------------------------------------------------------------

void DrawQuadSprite ( Texture2D sprite , Vector2 position, float scaleX, float scaleY, Color color) {
	Rectangle src = (Rectangle) { 0, 0, sprite.width * scaleX, sprite.height*scaleY };
	Rectangle dest = (Rectangle) { position.x, position.y, sprite.width * scaleX, sprite.height*scaleY };
	DrawTexturePro ( sprite , src , dest , (Vector2) { 0,0 } , 0 , color );
}

void DrawFrameBuffer(RenderTexture2D renderer) {
	float verticalScale = GetScreenHeight () / VirtualScreen.y;
	float horizontalScale = GetScreenWidth () / VirtualScreen.x;
	float scale = min (horizontalScale, verticalScale);

	DrawTexturePro (
		renderer.texture,
		(Rectangle) { 0.0f, 0.0f, (float)renderer.texture.width, (float)-renderer.texture.height },
		(Rectangle) { ( GetScreenWidth () - ( VirtualScreen.x*scale) ) * 0.5 , ( GetScreenHeight () - (VirtualScreen.y * scale) ) * 0.5, VirtualScreen.x * scale, VirtualScreen.y * scale },
		(Vector2) { 0, 0 },
		0.0f,
		WHITE
	);
}

void DrawTextImage(Texture2D texture, char * txt, float x, float y ) {
	DrawTexturePro(
		texture,
		(Rectangle) { (txt[0] - 32) * 24, 0, 24, 24 } ,
		(Rectangle) { x , y, 64, 64 },
		(Vector2) {0},
		0,
		WHITE
	);
}
