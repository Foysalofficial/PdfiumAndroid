// Copyright 2014 PDFium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Original code copyright 2014 Foxit Software Inc. http://www.foxitsoftware.com

#ifndef PUBLIC_FPDF_SYSFONTINFO_H_
#define PUBLIC_FPDF_SYSFONTINFO_H_

#include "fpdfview.h"


#define FXFONT_ANSI_CHARSET 0
#define FXFONT_DEFAULT_CHARSET 1
#define FXFONT_SYMBOL_CHARSET 2
#define FXFONT_SHIFTJIS_CHARSET 128
#define FXFONT_HANGEUL_CHARSET 129
#define FXFONT_GB2312_CHARSET 134
#define FXFONT_CHINESEBIG5_CHARSET 136


#define FXFONT_FF_FIXEDPITCH 1
#define FXFONT_FF_ROMAN (1 << 4)
#define FXFONT_FF_SCRIPT (4 << 4)


#define FXFONT_FW_NORMAL 400
#define FXFONT_FW_BOLD 700

// Exported Functions
#ifdef __cplusplus
extern "C" {
#endif


typedef struct _FPDF_SYSFONTINFO {

  int version;


  void (*Release)(struct _FPDF_SYSFONTINFO* pThis);


  void (*EnumFonts)(struct _FPDF_SYSFONTINFO* pThis, void* pMapper);


  void* (*MapFont)(struct _FPDF_SYSFONTINFO* pThis,
                   int weight,
                   FPDF_BOOL bItalic,
                   int charset,
                   int pitch_family,
                   const char* face,
                   FPDF_BOOL* bExact);


  void* (*GetFont)(struct _FPDF_SYSFONTINFO* pThis, const char* face);


  unsigned long (*GetFontData)(struct _FPDF_SYSFONTINFO* pThis,
                               void* hFont,
                               unsigned int table,
                               unsigned char* buffer,
                               unsigned long buf_size);


  unsigned long (*GetFaceName)(struct _FPDF_SYSFONTINFO* pThis,
                               void* hFont,
                               char* buffer,
                               unsigned long buf_size);


  int (*GetFontCharset)(struct _FPDF_SYSFONTINFO* pThis, void* hFont);


  void (*DeleteFont)(struct _FPDF_SYSFONTINFO* pThis, void* hFont);
} FPDF_SYSFONTINFO;


typedef struct FPDF_CharsetFontMap_ {
  int charset;  // Character Set Enum value, see FXFONT_*_CHARSET above.
  const char* fontname;  // Name of default font to use with that charset.
} FPDF_CharsetFontMap;


DLLEXPORT const FPDF_CharsetFontMap* STDCALL FPDF_GetDefaultTTFMap();


DLLEXPORT void STDCALL FPDF_AddInstalledFont(void* mapper,
                                             const char* face,
                                             int charset);


DLLEXPORT void STDCALL FPDF_SetSystemFontInfo(FPDF_SYSFONTINFO* pFontInfo);


DLLEXPORT FPDF_SYSFONTINFO* STDCALL FPDF_GetDefaultSystemFontInfo();

#ifdef __cplusplus
}
#endif

#endif  // PUBLIC_FPDF_SYSFONTINFO_H_
