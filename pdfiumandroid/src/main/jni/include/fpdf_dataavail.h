// Copyright 2014 PDFium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Original code copyright 2014 Foxit Software Inc. http://www.foxitsoftware.com

#ifndef PUBLIC_FPDF_DATAAVAIL_H_
#define PUBLIC_FPDF_DATAAVAIL_H_

#include <stddef.h>  // For size_t.

#include "fpdfview.h"

#define PDF_LINEARIZATION_UNKNOWN -1
#define PDF_NOT_LINEARIZED 0
#define PDF_LINEARIZED 1

#define PDF_DATA_ERROR -1
#define PDF_DATA_NOTAVAIL 0
#define PDF_DATA_AVAIL 1

#define PDF_FORM_ERROR -1
#define PDF_FORM_NOTAVAIL 0
#define PDF_FORM_AVAIL 1
#define PDF_FORM_NOTEXIST 2

#ifdef __cplusplus
extern "C" {
#endif


typedef struct _FX_FILEAVAIL {

  int version;


  FPDF_BOOL (*IsDataAvail)(struct _FX_FILEAVAIL* pThis, size_t offset, size_t size);
} FX_FILEAVAIL;

typedef void* FPDF_AVAIL;


DLLEXPORT FPDF_AVAIL STDCALL FPDFAvail_Create(FX_FILEAVAIL* file_avail,
                                              FPDF_FILEACCESS* file);


DLLEXPORT void STDCALL FPDFAvail_Destroy(FPDF_AVAIL avail);


typedef struct _FX_DOWNLOADHINTS {

  int version;


  void (*AddSegment)(struct _FX_DOWNLOADHINTS* pThis,
                     size_t offset,
                     size_t size);
} FX_DOWNLOADHINTS;


DLLEXPORT int STDCALL
FPDFAvail_IsDocAvail(FPDF_AVAIL avail, FX_DOWNLOADHINTS* hints);


DLLEXPORT FPDF_DOCUMENT STDCALL FPDFAvail_GetDocument(FPDF_AVAIL avail,
                                                      FPDF_BYTESTRING password);


DLLEXPORT int STDCALL FPDFAvail_GetFirstPageNum(FPDF_DOCUMENT doc);


DLLEXPORT int STDCALL FPDFAvail_IsPageAvail(FPDF_AVAIL avail,
                                            int page_index,
                                            FX_DOWNLOADHINTS* hints);


DLLEXPORT int STDCALL FPDFAvail_IsFormAvail(FPDF_AVAIL avail,
                                            FX_DOWNLOADHINTS* hints);


DLLEXPORT int STDCALL FPDFAvail_IsLinearized(FPDF_AVAIL avail);

#ifdef __cplusplus
}
#endif

#endif  // PUBLIC_FPDF_DATAAVAIL_H_
