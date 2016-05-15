//---------------------------------------------------------------------------

#ifndef UPaintH
#define UPaintH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <ToolWin.hpp>
#include <ImgList.hpp>
#include "CSPIN.h"
#include <Menus.hpp>
#include <Dialogs.hpp>
#include <ExtDlgs.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TToolBar *ToolBar1;
        TToolButton *TBLine;
        TToolButton *TBEllipse;
        TToolButton *TBRectangle;
        TToolButton *TBRoundRec;
        TImageList *ImageList1;
        TGroupBox *Linnia;
        TGroupBox *GroupBox2;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TShape *ShapeLinne;
        TShape *ShapeFill;
        TComboBox *ComboBoxLinne;
        TComboBox *ComboBoxFill;
        TCSpinEdit *CSpinEditLine;
        TMainMenu *MainMenu1;
        TMenuItem *Plik1;
        TMenuItem *Nowy1;
        TMenuItem *Ot1;
        TMenuItem *Zapisz1;
        TMenuItem *Wyjd1;
        TMenuItem *Pomoc1;
        TMenuItem *Autor1;
        TPaintBox *PB;
        TColorDialog *ColorDialog1;
        TColorDialog *ColorDialog2;
        TSavePictureDialog *SavePictureDialog1;
        TOpenPictureDialog *OpenPictureDialog1;
        TToolButton *ToolButton1;
        void __fastcall Wyjd1Click(TObject *Sender);
        void __fastcall Autor1Click(TObject *Sender);
        void __fastcall PBMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
        void __fastcall PBMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall PBMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormDestroy(TObject *Sender);
        void __fastcall PBPaint(TObject *Sender);
        void __fastcall ComboBoxLinneChange(TObject *Sender);
        void __fastcall ComboBoxFillChange(TObject *Sender);
        void __fastcall CSpinEditLineChange(TObject *Sender);
        void __fastcall ShapeLinneMouseUp(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall ShapeFillMouseUp(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall Zapisz1Click(TObject *Sender);
        void __fastcall Nowy1Click(TObject *Sender);
        void __fastcall Ot1Click(TObject *Sender);
private:
        int x,y;
        bool clicked,czysc;
        Graphics::TBitmap *obrazek;
                // User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
