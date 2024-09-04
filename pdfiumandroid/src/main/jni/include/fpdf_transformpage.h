// Copyright 2014 PDFium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Original code copyright 2014 Foxit Software Inc. http://www.foxitsoftware.com

#ifndef PUBLIC_FPDF_TRANSFORMPAGE_H_
#define PUBLIC_FPDF_TRANSFORMPAGE_H_

#include "fpdfview.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef void* FPDF_PAGEARCSAVER;
typedef void* FPDF_PAGEARCLOADER;


DLLEXPORT void STDCALL FPDFPage_SetMediaBox(FPDF_PAGE page,
                                            float left,
                                            float bottom,
                                            float right,
                                            float top);


DLLEXPORT void STDCALL FPDFPage_SetCropBox(FPDF_PAGE page,
                                           float left,
                                           float bottom,
                                           float right,
                                           float top);


DLLEXPORT FPDF_BOOL STDCALL FPDFPage_GetMediaBox(FPDF_PAGE page,
                                                 float* left,
                                                 float* bottom,
                                                 float* right,
                                                 float* top);


DLLEXPORT FPDF_BOOL STDCALL FPDFPage_GetCropBox(FPDF_PAGE page,
                                                float* left,
                                                float* bottom,
                                                float* right,
                                                float* top);


DLLEXPORT FPDF_BOOL STDCALL FPDFPage_TransFormWithClip(FPDF_PAGE page,
                                                       FS_MATRIX* matrix,
                                                       FS_RECTF* clipRect);


DLLEXPORT void STDCALL
FPDFPageObj_TransformClipPath(FPDF_PAGEOBJECT page_object,
                              double a,
                              double b,
                              double c,
                              double d,
                              double e,
                              double f);


DLLEXPORT FPDF_CLIPPATH STDCALL FPDF_CreateClipPath(float left,
                                                    float bottom,
                                                    float right,
                                                    float top);


DLLEXPORT void STDCALL FPDF_DestroyClipPath(FPDF_CLIPPATH clipPath);


DLLEXPORT void STDCALL FPDFPage_InsertClipPath(FPDF_PAGE page,
                                               FPDF_CLIPPATH clipPath);

#ifdef __cplusplus
}
#endif

#endif  // PUBLIC_FPDF_TRANSFORMPAGE_H_
