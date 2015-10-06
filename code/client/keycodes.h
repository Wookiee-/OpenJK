/*
===========================================================================
Copyright (C) 1999 - 2005, Id Software, Inc.
Copyright (C) 2000 - 2013, Raven Software, Inc.
Copyright (C) 2001 - 2013, Activision, Inc.
Copyright (C) 2013 - 2015, OpenJK contributors

This file is part of the OpenJK source code.

OpenJK is free software; you can redistribute it and/or modify it
under the terms of the GNU General Public License version 2 as
published by the Free Software Foundation.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, see <http://www.gnu.org/licenses/>.
===========================================================================
*/

#ifndef __KEYCODES_H__
#define __KEYCODES_H__

// these are the key numbers that should be passed to KeyEvent

typedef enum
{
	A_NULL = 0,
	A_SHIFT,
	A_CTRL,
	A_ALT,
	A_CAPSLOCK,
	A_NUMLOCK,
	A_SCROLLLOCK,
	A_PAUSE,
	A_BACKSPACE,
	A_TAB,
	A_ENTER,
	A_KP_PLUS,
	A_KP_MINUS,
	A_KP_ENTER,
	A_KP_PERIOD,
	A_PRINTSCREEN,
	A_KP_0,
	A_KP_1,
	A_KP_2,
	A_KP_3,
	A_KP_4,
	A_KP_5,
	A_KP_6,
	A_KP_7,
	A_KP_8,
	A_KP_9,
	A_CONSOLE,
	A_ESCAPE,
	A_F1,
	A_F2,
	A_F3,
	A_F4,

	A_SPACE,
	A_PLING,
	A_DOUBLE_QUOTE,
	A_HASH,
	A_STRING,
	A_PERCENT,
	A_AND,
	A_SINGLE_QUOTE,
	A_OPEN_BRACKET,
	A_CLOSE_BRACKET,
	A_STAR,
	A_PLUS,
	A_COMMA,
	A_MINUS,
	A_PERIOD,
	A_FORWARD_SLASH,
	A_0,
	A_1,
	A_2,
	A_3,
	A_4,
	A_5,
	A_6,
	A_7,
	A_8,
	A_9,
	A_COLON,
	A_SEMICOLON,
	A_LESSTHAN,
	A_EQUALS,
	A_GREATERTHAN,
	A_QUESTION,

	A_AT,
	A_CAP_A,
	A_CAP_B,
	A_CAP_C,
	A_CAP_D,
	A_CAP_E,
	A_CAP_F,
	A_CAP_G,
	A_CAP_H,
	A_CAP_I,
	A_CAP_J,
	A_CAP_K,
	A_CAP_L,
	A_CAP_M,
	A_CAP_N,
	A_CAP_O,
	A_CAP_P,
	A_CAP_Q,
	A_CAP_R,
	A_CAP_S,
	A_CAP_T,
	A_CAP_U,
	A_CAP_V,
	A_CAP_W,
	A_CAP_X,
	A_CAP_Y,
	A_CAP_Z,
	A_OPEN_SQUARE,
	A_BACKSLASH,
	A_CLOSE_SQUARE,
	A_CARET,
	A_UNDERSCORE,

	A_LEFT_SINGLE_QUOTE,
	A_LOW_A,
	A_LOW_B,
	A_LOW_C,
	A_LOW_D,
	A_LOW_E,
	A_LOW_F,
	A_LOW_G,
	A_LOW_H,
	A_LOW_I,
	A_LOW_J,
	A_LOW_K,
	A_LOW_L,
	A_LOW_M,
	A_LOW_N,
	A_LOW_O,
	A_LOW_P,
	A_LOW_Q,
	A_LOW_R,
	A_LOW_S,
	A_LOW_T,
	A_LOW_U,
	A_LOW_V,
	A_LOW_W,
	A_LOW_X,
	A_LOW_Y,
	A_LOW_Z,
	A_OPEN_BRACE,
	A_BAR,
	A_CLOSE_BRACE,
	A_TILDE,
	A_DELETE,

	A_EURO,
	A_SHIFT2,
	A_CTRL2,
	A_ALT2,
	A_F5,
	A_F6,
	A_F7,
	A_F8,
	A_CIRCUMFLEX,
	A_MWHEELUP,
	A_CAP_SCARON,
	A_MWHEELDOWN,
	A_CAP_OE,
	A_MOUSE1,
	A_MOUSE2,
	A_INSERT,
	A_HOME,
	A_PAGE_UP,
	A_RIGHT_SINGLE_QUOTE,
	A_LEFT_DOUBLE_QUOTE,
	A_RIGHT_DOUBLE_QUOTE,
	A_F9,
	A_F10,
	A_F11,
	A_F12,
	A_TRADEMARK,
	A_LOW_SCARON,
	A_SHIFT_ENTER,
	A_LOW_OE,
	A_END,
	A_PAGE_DOWN,
	A_CAP_YDIERESIS,

	A_SHIFT_SPACE,
	A_EXCLAMDOWN,
	A_CENT,
	A_POUND,
	A_SHIFT_KP_ENTER,
	A_YEN,
	A_MOUSE3,
	A_MOUSE4,
	A_MOUSE5,
	A_COPYRIGHT,
	A_CURSOR_UP,
	A_CURSOR_DOWN,
	A_CURSOR_LEFT,
	A_CURSOR_RIGHT,
	A_REGISTERED,
	A_UNDEFINED_7,
	A_UNDEFINED_8,
	A_UNDEFINED_9,
	A_UNDEFINED_10,
	A_UNDEFINED_11,
	A_UNDEFINED_12,
	A_UNDEFINED_13,
	A_UNDEFINED_14,
	A_UNDEFINED_15,
	A_UNDEFINED_16,
	A_UNDEFINED_17,
	A_UNDEFINED_18,
	A_UNDEFINED_19,
	A_UNDEFINED_20,
	A_UNDEFINED_21,
	A_UNDEFINED_22,
	A_QUESTION_DOWN,

	A_CAP_AGRAVE,
	A_CAP_AACUTE,
	A_CAP_ACIRCUMFLEX,
	A_CAP_ATILDE,
	A_CAP_ADIERESIS,
	A_CAP_ARING,
	A_CAP_AE,
	A_CAP_CCEDILLA,
	A_CAP_EGRAVE,
	A_CAP_EACUTE,
	A_CAP_ECIRCUMFLEX,
	A_CAP_EDIERESIS,
	A_CAP_IGRAVE,
	A_CAP_IACUTE,
	A_CAP_ICIRCUMFLEX,
	A_CAP_IDIERESIS,
	A_CAP_ETH,
	A_CAP_NTILDE,
	A_CAP_OGRAVE,
	A_CAP_OACUTE,
	A_CAP_OCIRCUMFLEX,
	A_CAP_OTILDE,
	A_CAP_ODIERESIS,
	A_MULTIPLY,
	A_CAP_OSLASH,
	A_CAP_UGRAVE,
	A_CAP_UACUTE,
	A_CAP_UCIRCUMFLEX,
	A_CAP_UDIERESIS,
	A_CAP_YACUTE,
	A_CAP_THORN,
	A_GERMANDBLS,

	A_LOW_AGRAVE,
	A_LOW_AACUTE,
	A_LOW_ACIRCUMFLEX,
	A_LOW_ATILDE,
	A_LOW_ADIERESIS,
	A_LOW_ARING,
	A_LOW_AE,
	A_LOW_CCEDILLA,
	A_LOW_EGRAVE,
	A_LOW_EACUTE,
	A_LOW_ECIRCUMFLEX,
	A_LOW_EDIERESIS,
	A_LOW_IGRAVE,
	A_LOW_IACUTE,
	A_LOW_ICIRCUMFLEX,
	A_LOW_IDIERESIS,
	A_LOW_ETH,
	A_LOW_NTILDE,
	A_LOW_OGRAVE,
	A_LOW_OACUTE,
	A_LOW_OCIRCUMFLEX,
	A_LOW_OTILDE,
	A_LOW_ODIERESIS,
	A_DIVIDE,
	A_LOW_OSLASH,
	A_LOW_UGRAVE,
	A_LOW_UACUTE,
	A_LOW_UCIRCUMFLEX,
	A_LOW_UDIERESIS,
	A_LOW_YACUTE,
	A_LOW_THORN,
	A_LOW_YDIERESIS,

	A_JOY0,
	A_JOY1,
	A_JOY2,
	A_JOY3,
	A_JOY4,
	A_JOY5,
	A_JOY6,
	A_JOY7,
	A_JOY8,
	A_JOY9,
	A_JOY10,
	A_JOY11,
	A_JOY12,
	A_JOY13,
	A_JOY14,
	A_JOY15,
	A_JOY16,
	A_JOY17,
	A_JOY18,
	A_JOY19,
	A_JOY20,
	A_JOY21,
	A_JOY22,
	A_JOY23,
	A_JOY24,
	A_JOY25,
	A_JOY26,
	A_JOY27,
	A_JOY28,
	A_JOY29,
	A_JOY30,
	A_JOY31,

	A_AUX0,
	A_AUX1,
	A_AUX2,
	A_AUX3,
	A_AUX4,
	A_AUX5,
	A_AUX6,
	A_AUX7,
	A_AUX8,
	A_AUX9,
	A_AUX10,
	A_AUX11,
	A_AUX12,
	A_AUX13,
	A_AUX14,
	A_AUX15,
	A_AUX16,
	A_AUX17,
	A_AUX18,
	A_AUX19,
	A_AUX20,
	A_AUX21,
	A_AUX22,
	A_AUX23,
	A_AUX24,
	A_AUX25,
	A_AUX26,
	A_AUX27,
	A_AUX28,
	A_AUX29,
	A_AUX30,
	A_AUX31,

	MAX_KEYS
} fakeAscii_t;


// The menu code needs to get both key and char events, but
// to avoid duplicating the paths, the char events are just
// distinguished by or'ing in K_CHAR_FLAG (ugly)
#define	K_CHAR_FLAG		1024

#endif
