#include "graphics_Colour.h"
#include "obj_handler.h"
#include "application.h"
#include "methods.h"
#include "threads.h"
#include "exceptions.h"
#include "native.h"

///////////////////////////////////////////////////////////////////////////

static const uint16_t colour_list[] =
{
    46518, 		 // ActiveBorder
    40378, 		 // ActiveCaption
    0, 		 // ActiveCaptionText
    63455, 		 // AliceBlue
    65370, 		 // AntiqueWhite
    44373, 		 // AppWorkspace
    2047, 		 // Aqua
    32762, 		 // Aquamarine
    63487, 		 // Azure
    63419, 		 // Beige
    65336, 		 // Bisque
    0, 		 // Black
    65369, 		 // BlanchedAlmond
    31, 		 // Blue
    35164, 		 // BlueViolet
    41285, 		 // Brown
    56784, 		 // BurlyWood
    63390, 		 // ButtonFace
    65535, 		 // ButtonHighlight
    42260, 		 // ButtonShadow
    23796, 		 // CadetBlue
    32736, 		 // Chartreuse
    54083, 		 // Chocolate
    64490, 		 // Coral
    25789, 		 // CornflowerBlue
    65499, 		 // Cornsilk
    55463, 		 // Crimson
    2047, 		 // Cyan
    17, 		 // DarkBlue
    1105, 		 // DarkCyan
    48161, 		 // DarkGoldenrod
    44373, 		 // DarkGray
    800, 		 // DarkGreen
    48557, 		 // DarkKhaki
    34833, 		 // DarkMagenta
    21317, 		 // DarkOliveGreen
    64608, 		 // DarkOrange
    39321, 		 // DarkOrchid
    34816, 		 // DarkRed
    60591, 		 // DarkSalmon
    36337, 		 // DarkSeaGreen
    18929, 		 // DarkSlateBlue
    10857, 		 // DarkSlateGray
    1658, 		 // DarkTurquoise
    36890, 		 // DarkViolet
    63666, 		 // DeepPink
    1535, 		 // DeepSkyBlue
    0, 		 // Desktop
    27469, 		 // DimGray
    7327, 		 // DodgerBlue
    45316, 		 // Firebrick
    65502, 		 // FloralWhite
    9284, 		 // ForestGreen
    63519, 		 // Fuchsia
    57083, 		 // Gainsboro
    65503, 		 // GhostWhite
    65184, 		 // Gold
    56612, 		 // Goldenrod
    48797, 		 // GradientActiveCaption
    55102, 		 // GradientInactiveCaption
    33808, 		 // Gray
    27501, 		 // GrayText
    1024, 		 // Green
    45029, 		 // GreenYellow
    13535, 		 // Highlight
    65535, 		 // HighlightText
    63486, 		 // Honeydew
    64342, 		 // HotPink
    825, 		 // HotTrack
    63423, 		 // InactiveBorder
    48763, 		 // InactiveCaption
    17002, 		 // InactiveCaptionText
    51947, 		 // IndianRed
    18448, 		 // Indigo
    65532, 		 // Info
    0, 		 // InfoText
    65534, 		 // Ivory
    63281, 		 // Khaki
    59199, 		 // Lavender
    65438, 		 // LavenderBlush
    32736, 		 // LawnGreen
    65497, 		 // LemonChiffon
    44764, 		 // LightBlue
    62480, 		 // LightCoral
    59391, 		 // LightCyan
    65498, 		 // LightGoldenrodYellow
    54938, 		 // LightGray
    38770, 		 // LightGreen
    64952, 		 // LightPink
    64783, 		 // LightSalmon
    9621, 		 // LightSeaGreen
    34431, 		 // LightSkyBlue
    29779, 		 // LightSlateGray
    46651, 		 // LightSteelBlue
    65532, 		 // LightYellow
    2016, 		 // Lime
    13926, 		 // LimeGreen
    65436, 		 // Linen
    63519, 		 // Magenta
    32768, 		 // Maroon
    26229, 		 // MediumAquamarine
    25, 		 // MediumBlue
    47802, 		 // MediumOrchid
    37787, 		 // MediumPurple
    15758, 		 // MediumSeaGreen
    31581, 		 // MediumSlateBlue
    2003, 		 // MediumSpringGreen
    20121, 		 // MediumTurquoise
    49328, 		 // MediumVioletRed
    63390, 		 // Menu
    63390, 		 // MenuBar
    13535, 		 // MenuHighlight
    0, 		 // MenuText
    6350, 		 // MidnightBlue
    63487, 		 // MintCream
    65340, 		 // MistyRose
    65334, 		 // Moccasin
    65269, 		 // NavajoWhite
    16, 		 // Navy
    65468, 		 // OldLace
    33792, 		 // Olive
    27748, 		 // OliveDrab
    64800, 		 // Orange
    64032, 		 // OrangeRed
    56218, 		 // Orchid
    61269, 		 // PaleGoldenrod
    40915, 		 // PaleGreen
    44925, 		 // PaleTurquoise
    56210, 		 // PaleVioletRed
    65402, 		 // PapayaWhip
    65239, 		 // PeachPuff
    52263, 		 // Peru
    65049, 		 // Pink
    56603, 		 // Plum
    46876, 		 // PowderBlue
    32784, 		 // Purple
    63488, 		 // Red
    48241, 		 // RosyBrown
    17244, 		 // RoyalBlue
    35362, 		 // SaddleBrown
    64526, 		 // Salmon
    62764, 		 // SandyBrown
    52825, 		 // ScrollBar
    11338, 		 // SeaGreen
    65469, 		 // SeaShell
    41605, 		 // Sienna
    50712, 		 // Silver
    34429, 		 // SkyBlue
    27353, 		 // SlateBlue
    29714, 		 // SlateGray
    65503, 		 // Snow
    2031, 		 // SpringGreen
    17430, 		 // SteelBlue
    54705, 		 // Tan
    1040, 		 // Teal
    56827, 		 // Thistle
    64264, 		 // Tomato
    65535, 		 // Transparent
    18202, 		 // Turquoise
    60445, 		 // Violet
    63222, 		 // Wheat
    65535, 		 // White
    63422, 		 // WhiteSmoke
    65535, 		 // Window
    25388, 		 // WindowFrame
    0, 		 // WindowText
    65504, 		 // Yellow
    40550, 		 // YellowGreen    
};

///////////////////////////////////////////////////////////////////////////

object_t native_graphics_colour_new( void )
{
	// return( object_create( GET_CLASS_REF( NATIVE_CLASS_RUFFUS_GRAPHICS_DRAWING ), T_CLASS, NATIVE_GRAPHICS_DRAWING_TOTAL_FIELDS ) );
	return value_create_int(0);
}

void native_method_graphics_colour_init()
{
	object_t object;
	object = stack_pop();
}

void native_method_graphics_colour_from_rgb()
{
    uint8_t r_colour;
	uint8_t g_colour;
	uint8_t b_colour;
    object_t ret_object;
	
	b_colour = ( uint8_t )stack_peek_integer(0);
	g_colour = ( uint8_t )stack_peek_integer(1);
	r_colour = ( uint8_t )stack_peek_integer(2);	
	
    ret_object = value_create_int( ( int32_t )APP_RGB( r_colour, g_colour, b_colour ) );
    
    stack_remove(3);
    stack_push( ret_object );
}
			
void native_graphics_colour_get_field(uint16_t mref)
{
    object_t object;
    
    if( mref >= NATIVE_GRAPHICS_COLOUR_TOTAL_FIELDS )
    {
        exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
        return;
    }
    
    object = value_create_int( colour_list[ mref ] );
    
    stack_push( object );
}

void native_graphics_colour_invoke(uint16_t mref)
{
    switch( mref )
    {
        case NATIVE_GRAPHICS_COLOUR_INIT:
            native_method_graphics_colour_init();
            break;

        case NATIVE_GRAPHICS_COLOUR_FROM_RGB:
            native_method_graphics_colour_from_rgb();
            break;

		default:
            exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
            break;            
    }
}

