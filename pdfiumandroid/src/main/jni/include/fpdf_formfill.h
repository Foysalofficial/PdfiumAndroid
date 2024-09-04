// Copyright 2014 PDFium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Original code copyright 2014 Foxit Software Inc. http://www.foxitsoftware.com

#ifndef PUBLIC_FPDF_FORMFILL_H_
#define PUBLIC_FPDF_FORMFILL_H_

#include "fpdfview.h"

typedef void* FPDF_FORMHANDLE;

#ifdef PDF_ENABLE_XFA
#define DOCTYPE_PDF 0          // Normal pdf Document
#define DOCTYPE_DYNAMIC_XFA 1  // Dynamic xfa Document Type
#define DOCTYPE_STATIC_XFA 2   // Static xfa Document Type
#endif  // PDF_ENABLE_XFA

// Exported Functions
#ifdef __cplusplus
extern "C" {
#endif

typedef struct _IPDF_JsPlatform {

  int version;




  int (*app_alert)(struct _IPDF_JsPlatform* pThis,
                   FPDF_WIDESTRING Msg,
                   FPDF_WIDESTRING Title,
                   int Type,
                   int Icon);


  void (*app_beep)(struct _IPDF_JsPlatform* pThis, int nType);


  int (*app_response)(struct _IPDF_JsPlatform* pThis,
                      FPDF_WIDESTRING Question,
                      FPDF_WIDESTRING Title,
                      FPDF_WIDESTRING Default,
                      FPDF_WIDESTRING cLabel,
                      FPDF_BOOL bPassword,
                      void* response,
                      int length);


  int (*Doc_getFilePath)(struct _IPDF_JsPlatform* pThis,
                         void* filePath,
                         int length);


  void (*Doc_mail)(struct _IPDF_JsPlatform* pThis,
                   void* mailData,
                   int length,
                   FPDF_BOOL bUI,
                   FPDF_WIDESTRING To,
                   FPDF_WIDESTRING Subject,
                   FPDF_WIDESTRING CC,
                   FPDF_WIDESTRING BCC,
                   FPDF_WIDESTRING Msg);


  void (*Doc_print)(struct _IPDF_JsPlatform* pThis,
                    FPDF_BOOL bUI,
                    int nStart,
                    int nEnd,
                    FPDF_BOOL bSilent,
                    FPDF_BOOL bShrinkToFit,
                    FPDF_BOOL bPrintAsImage,
                    FPDF_BOOL bReverse,
                    FPDF_BOOL bAnnotations);


  void (*Doc_submitForm)(struct _IPDF_JsPlatform* pThis,
                         void* formData,
                         int length,
                         FPDF_WIDESTRING URL);


  void (*Doc_gotoPage)(struct _IPDF_JsPlatform* pThis, int nPageNum);

  int (*Field_browse)(struct _IPDF_JsPlatform* pThis,
                      void* filePath,
                      int length);


  void* m_pFormfillinfo;



  void* m_isolate;
  unsigned int m_v8EmbedderSlot;




} IPDF_JSPLATFORM;

// Flags for Cursor type
#define FXCT_ARROW 0
#define FXCT_NESW 1
#define FXCT_NWSE 2
#define FXCT_VBEAM 3
#define FXCT_HBEAM 4
#define FXCT_HAND 5


typedef void (*TimerCallback)(int idEvent);


typedef struct _FPDF_SYSTEMTIME {
  unsigned short wYear;
  unsigned short wMonth;
  unsigned short wDayOfWeek;
  unsigned short wDay;
  unsigned short wHour;
  unsigned short wMinute;
  unsigned short wSecond;
  unsigned short wMilliseconds;
} FPDF_SYSTEMTIME;

#ifdef PDF_ENABLE_XFA
// XFA



#define FXFA_PAGEVIEWEVENT_POSTADDED 1

#define FXFA_PAGEVIEWEVENT_POSTREMOVED 3


// menu


#define FXFA_MEMU_COPY 1
#define FXFA_MEMU_CUT 2
#define FXFA_MEMU_SELECTALL 4
#define FXFA_MEMU_UNDO 8
#define FXFA_MEMU_REDO 16
#define FXFA_MEMU_PASTE 32


// file type


#define FXFA_SAVEAS_XML 1
#define FXFA_SAVEAS_XDP 2

#endif  // PDF_ENABLE_XFA

typedef struct _FPDF_FORMFILLINFO {

  int version;



  void (*Release)(struct _FPDF_FORMFILLINFO* pThis);


  void (*FFI_Invalidate)(struct _FPDF_FORMFILLINFO* pThis,
                         FPDF_PAGE page,
                         double left,
                         double top,
                         double right,
                         double bottom);


  void (*FFI_OutputSelectedRect)(struct _FPDF_FORMFILLINFO* pThis,
                                 FPDF_PAGE page,
                                 double left,
                                 double top,
                                 double right,
                                 double bottom);


  void (*FFI_SetCursor)(struct _FPDF_FORMFILLINFO* pThis, int nCursorType);


  int (*FFI_SetTimer)(struct _FPDF_FORMFILLINFO* pThis,
                      int uElapse,
                      TimerCallback lpTimerFunc);


  void (*FFI_KillTimer)(struct _FPDF_FORMFILLINFO* pThis, int nTimerID);


  FPDF_SYSTEMTIME (*FFI_GetLocalTime)(struct _FPDF_FORMFILLINFO* pThis);


  void (*FFI_OnChange)(struct _FPDF_FORMFILLINFO* pThis);


  FPDF_PAGE   (*FFI_GetPage)(struct _FPDF_FORMFILLINFO* pThis, FPDF_DOCUMENT document, int nPageIndex);


  FPDF_PAGE   (*FFI_GetCurrentPage)(struct _FPDF_FORMFILLINFO* pThis, FPDF_DOCUMENT document);


  int (*FFI_GetRotation)(struct _FPDF_FORMFILLINFO* pThis, FPDF_PAGE page);


  void (*FFI_ExecuteNamedAction)(struct _FPDF_FORMFILLINFO* pThis,
                                 FPDF_BYTESTRING namedAction);

  void (*FFI_SetTextFieldFocus)(struct _FPDF_FORMFILLINFO* pThis,
                                FPDF_WIDESTRING value,
                                FPDF_DWORD valueLen,
                                FPDF_BOOL is_focus);


  void (*FFI_DoURIAction)(struct _FPDF_FORMFILLINFO* pThis,
                          FPDF_BYTESTRING bsURI);


  void (*FFI_DoGoToAction)(struct _FPDF_FORMFILLINFO* pThis,
                           int nPageIndex,
                           int zoomMode,
                           float* fPosArray,
                           int sizeofArray);


  IPDF_JSPLATFORM* m_pJsPlatform;

#ifdef PDF_ENABLE_XFA


  void (*FFI_DisplayCaret)(struct _FPDF_FORMFILLINFO* pThis,
                           FPDF_PAGE page,
                           FPDF_BOOL bVisible,
                           double left,
                           double top,
                           double right,
                           double bottom);


  int (*FFI_GetCurrentPageIndex)(struct _FPDF_FORMFILLINFO* pThis,
                                 FPDF_DOCUMENT document);


  void (*FFI_SetCurrentPage)(struct _FPDF_FORMFILLINFO* pThis,
                             FPDF_DOCUMENT document,
                             int iCurPage);


  void (*FFI_GotoURL)(struct _FPDF_FORMFILLINFO* pThis,
                      FPDF_DOCUMENT document,
                      FPDF_WIDESTRING wsURL);


  void (*FFI_GetPageViewRect)(struct _FPDF_FORMFILLINFO* pThis,
                              FPDF_PAGE page,
                              double* left,
                              double* top,
                              double* right,
                              double* bottom);

  FPDF_BOOL (*FFI_PopupMenu)(struct _FPDF_FORMFILLINFO* pThis, FPDF_PAGE page, FPDF_WIDGET hWidget, int menuFlag, float x, float y);


  FPDF_FILEHANDLER* (*FFI_OpenFile)(struct _FPDF_FORMFILLINFO* pThis,
                                    int fileFlag,
                                    FPDF_WIDESTRING wsURL,
                                    const char* mode);


  void (*FFI_EmailTo)(struct _FPDF_FORMFILLINFO* pThis,
                      FPDF_FILEHANDLER* fileHandler,
                      FPDF_WIDESTRING pTo,
                      FPDF_WIDESTRING pSubject,
                      FPDF_WIDESTRING pCC,
                      FPDF_WIDESTRING pBcc,
                      FPDF_WIDESTRING pMsg);


  void (*FFI_UploadTo)(struct _FPDF_FORMFILLINFO* pThis,
                       FPDF_FILEHANDLER* fileHandler,
                       int fileFlag,
                       FPDF_WIDESTRING uploadTo);


  int (*FFI_GetPlatform)(struct _FPDF_FORMFILLINFO* pThis,
                         void* platform,
                         int length);


  int (*FFI_GetLanguage)(struct _FPDF_FORMFILLINFO* pThis,
                         void* language,
                         int length);


  FPDF_LPFILEHANDLER  (*FFI_DownloadFromURL)(struct _FPDF_FORMFILLINFO* pThis, FPDF_WIDESTRING URL);

  FPDF_BOOL   (*FFI_PostRequestURL)(struct _FPDF_FORMFILLINFO* pThis, FPDF_WIDESTRING wsURL, FPDF_WIDESTRING wsData, FPDF_WIDESTRING wsContentType, FPDF_WIDESTRING wsEncode, FPDF_WIDESTRING wsHeader, FPDF_BSTR* respone);


  FPDF_BOOL   (*FFI_PutRequestURL)(struct _FPDF_FORMFILLINFO* pThis, FPDF_WIDESTRING wsURL, FPDF_WIDESTRING wsData, FPDF_WIDESTRING wsEncode);
#endif  // PDF_ENABLE_XFA

} FPDF_FORMFILLINFO;


DLLEXPORT FPDF_FORMHANDLE STDCALL
FPDFDOC_InitFormFillEnvironment(FPDF_DOCUMENT document,
                                FPDF_FORMFILLINFO* formInfo);


DLLEXPORT void STDCALL FPDFDOC_ExitFormFillEnvironment(FPDF_FORMHANDLE hHandle);


DLLEXPORT void STDCALL FORM_OnAfterLoadPage(FPDF_PAGE page,
                                            FPDF_FORMHANDLE hHandle);


DLLEXPORT void STDCALL FORM_OnBeforeClosePage(FPDF_PAGE page,
                                              FPDF_FORMHANDLE hHandle);


DLLEXPORT void STDCALL FORM_DoDocumentJSAction(FPDF_FORMHANDLE hHandle);


DLLEXPORT void STDCALL FORM_DoDocumentOpenAction(FPDF_FORMHANDLE hHandle);

// additional actions type of document.
#define FPDFDOC_AACTION_WC \
  0x10  // WC, before closing document, JavaScript action.
#define FPDFDOC_AACTION_WS \
  0x11  // WS, before saving document, JavaScript action.
#define FPDFDOC_AACTION_DS 0x12  // DS, after saving document, JavaScript
                                 // action.
#define FPDFDOC_AACTION_WP \
  0x13  // WP, before printing document, JavaScript action.
#define FPDFDOC_AACTION_DP \
  0x14  // DP, after printing document, JavaScript action.



DLLEXPORT void STDCALL FORM_DoDocumentAAction(FPDF_FORMHANDLE hHandle,
                                              int aaType);

// Additional-action types of page object
#define FPDFPAGE_AACTION_OPEN \
  0  // /O -- An action to be performed when the page is opened
#define FPDFPAGE_AACTION_CLOSE \
  1  // /C -- An action to be performed when the page is closed


DLLEXPORT void STDCALL FORM_DoPageAAction(FPDF_PAGE page,
                                          FPDF_FORMHANDLE hHandle,
                                          int aaType);


DLLEXPORT FPDF_BOOL STDCALL FORM_OnMouseMove(FPDF_FORMHANDLE hHandle,
                                             FPDF_PAGE page,
                                             int modifier,
                                             double page_x,
                                             double page_y);


DLLEXPORT FPDF_BOOL STDCALL FORM_OnLButtonDown(FPDF_FORMHANDLE hHandle,
                                               FPDF_PAGE page,
                                               int modifier,
                                               double page_x,
                                               double page_y);


DLLEXPORT FPDF_BOOL STDCALL FORM_OnLButtonUp(FPDF_FORMHANDLE hHandle,
                                             FPDF_PAGE page,
                                             int modifier,
                                             double page_x,
                                             double page_y);

#ifdef PDF_ENABLE_XFA
DLLEXPORT FPDF_BOOL STDCALL FORM_OnRButtonDown(FPDF_FORMHANDLE hHandle,
                                               FPDF_PAGE page,
                                               int modifier,
                                               double page_x,
                                               double page_y);
DLLEXPORT FPDF_BOOL STDCALL FORM_OnRButtonUp(FPDF_FORMHANDLE hHandle,
                                             FPDF_PAGE page,
                                             int modifier,
                                             double page_x,
                                             double page_y);
#endif  // PDF_ENABLE_XFA


DLLEXPORT FPDF_BOOL STDCALL FORM_OnKeyDown(FPDF_FORMHANDLE hHandle,
                                           FPDF_PAGE page,
                                           int nKeyCode,
                                           int modifier);


DLLEXPORT FPDF_BOOL STDCALL FORM_OnKeyUp(FPDF_FORMHANDLE hHandle,
                                         FPDF_PAGE page,
                                         int nKeyCode,
                                         int modifier);


DLLEXPORT FPDF_BOOL STDCALL FORM_OnChar(FPDF_FORMHANDLE hHandle,
                                        FPDF_PAGE page,
                                        int nChar,
                                        int modifier);


DLLEXPORT FPDF_BOOL STDCALL FORM_ForceToKillFocus(FPDF_FORMHANDLE hHandle);

// Field Types
#define FPDF_FORMFIELD_UNKNOWN 0      // Unknown.
#define FPDF_FORMFIELD_PUSHBUTTON 1   // push button type.
#define FPDF_FORMFIELD_CHECKBOX 2     // check box type.
#define FPDF_FORMFIELD_RADIOBUTTON 3  // radio button type.
#define FPDF_FORMFIELD_COMBOBOX 4     // combo box type.
#define FPDF_FORMFIELD_LISTBOX 5      // list box type.
#define FPDF_FORMFIELD_TEXTFIELD 6    // text field type.
#ifdef PDF_ENABLE_XFA
#define FPDF_FORMFIELD_XFA 7          // text field type.
#endif  // PDF_ENABLE_XFA


DLLEXPORT int STDCALL FPDFPage_HasFormFieldAtPoint(FPDF_FORMHANDLE hHandle,
                                                   FPDF_PAGE page,
                                                   double page_x,
                                                   double page_y);


DLLEXPORT int STDCALL FPDPage_HasFormFieldAtPoint(FPDF_FORMHANDLE hHandle,
                                                  FPDF_PAGE page,
                                                  double page_x,
                                                  double page_y);


DLLEXPORT int STDCALL FPDFPage_FormFieldZOrderAtPoint(FPDF_FORMHANDLE hHandle,
                                                      FPDF_PAGE page,
                                                      double page_x,
                                                      double page_y);


DLLEXPORT void STDCALL FPDF_SetFormFieldHighlightColor(FPDF_FORMHANDLE hHandle,
                                                       int fieldType,
                                                       unsigned long color);


DLLEXPORT void STDCALL FPDF_SetFormFieldHighlightAlpha(FPDF_FORMHANDLE hHandle,
                                                       unsigned char alpha);


DLLEXPORT void STDCALL FPDF_RemoveFormFieldHighlight(FPDF_FORMHANDLE hHandle);


DLLEXPORT void STDCALL FPDF_FFLDraw(FPDF_FORMHANDLE hHandle,
                                    FPDF_BITMAP bitmap,
                                    FPDF_PAGE page,
                                    int start_x,
                                    int start_y,
                                    int size_x,
                                    int size_y,
                                    int rotate,
                                    int flags);

#ifdef PDF_ENABLE_XFA

DLLEXPORT FPDF_BOOL STDCALL FPDF_HasXFAField(FPDF_DOCUMENT document,
                                             int* docType);


DLLEXPORT FPDF_BOOL STDCALL FPDF_LoadXFA(FPDF_DOCUMENT document);


DLLEXPORT void STDCALL FPDF_Widget_Undo(FPDF_DOCUMENT document,
                                        FPDF_WIDGET hWidget);

DLLEXPORT void STDCALL FPDF_Widget_Redo(FPDF_DOCUMENT document,
                                        FPDF_WIDGET hWidget);

DLLEXPORT void STDCALL FPDF_Widget_SelectAll(FPDF_DOCUMENT document,
                                             FPDF_WIDGET hWidget);

DLLEXPORT void STDCALL FPDF_Widget_Copy(FPDF_DOCUMENT document,
                                        FPDF_WIDGET hWidget,
                                        FPDF_WIDESTRING wsText,
                                        FPDF_DWORD* size);

DLLEXPORT void STDCALL FPDF_Widget_Cut(FPDF_DOCUMENT document,
                                       FPDF_WIDGET hWidget,
                                       FPDF_WIDESTRING wsText,
                                       FPDF_DWORD* size);

DLLEXPORT void STDCALL FPDF_Widget_Paste(FPDF_DOCUMENT document,
                                         FPDF_WIDGET hWidget,
                                         FPDF_WIDESTRING wsText,
                                         FPDF_DWORD size);

DLLEXPORT void STDCALL
FPDF_Widget_ReplaceSpellCheckWord(FPDF_DOCUMENT document,
                                  FPDF_WIDGET hWidget,
                                  float x,
                                  float y,
                                  FPDF_BYTESTRING bsText);

DLLEXPORT void STDCALL
FPDF_Widget_GetSpellCheckWords(FPDF_DOCUMENT document,
                               FPDF_WIDGET hWidget,
                               float x,
                               float y,
                               FPDF_STRINGHANDLE* stringHandle);

DLLEXPORT int STDCALL FPDF_StringHandleCounts(FPDF_STRINGHANDLE stringHandle);

DLLEXPORT FPDF_BOOL STDCALL
FPDF_StringHandleGetStringByIndex(FPDF_STRINGHANDLE stringHandle,
                                  int index,
                                  FPDF_BYTESTRING bsText,
                                  FPDF_DWORD* size);

DLLEXPORT void STDCALL FPDF_StringHandleRelease(FPDF_STRINGHANDLE stringHandle);

DLLEXPORT FPDF_BOOL STDCALL
FPDF_StringHandleAddString(FPDF_STRINGHANDLE stringHandle,
                           FPDF_BYTESTRING bsText,
                           FPDF_DWORD size);
#endif  // PDF_ENABLE_XFA

#ifdef __cplusplus
}
#endif

#endif  // PUBLIC_FPDF_FORMFILL_H_
