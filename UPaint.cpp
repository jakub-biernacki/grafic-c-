//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UPaint.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CSPIN"
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Wyjd1Click(TObject *Sender)
{
        Application->Terminate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Autor1Click(TObject *Sender)
{
        ShowMessage("Autor: Biernacki Jakub");       
}
//---------------------------------------------------------------------------

void __fastcall TForm1::PBMouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
        if (Button!=mbRight)
        {
                x=X;
                y=Y;
                clicked=true;
                czysc=false;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::PBMouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
     if (clicked) //je�li w og�le klikni�to
        {
                PB->Repaint();

                this->PB->Canvas->Pen->Color=this->ShapeLinne->Brush->Color;
                this->PB->Color=this->ShapeFill->Brush->Color;
                if(this->ComboBoxLinne->Items->Strings[ComboBoxLinne->ItemIndex]=="Pusty")
                        PB->Canvas->Pen->Style=psClear;
                if(this->ComboBoxLinne->Items->Strings[ComboBoxLinne->ItemIndex]=="Ci�g�y")
                        PB->Canvas->Pen->Style=psSolid;
                if(this->ComboBoxLinne->Items->Strings[ComboBoxLinne->ItemIndex]=="Kreska")
                        PB->Canvas->Pen->Style=psDash;
                if(this->ComboBoxLinne->Items->Strings[ComboBoxLinne->ItemIndex]=="Kropka")
                        PB->Canvas->Pen->Style=psDot;

                obrazek->Width = PB->Width;
                obrazek->Height = PB->Height;

                if(this->ComboBoxFill->Items->Strings[ComboBoxFill->ItemIndex]=="Puste")
                        PB->Canvas->Brush->Style=bsClear;
                if(this->ComboBoxFill->Items->Strings[ComboBoxFill->ItemIndex]=="Pe�ne")
                        PB->Canvas->Brush->Style=bsSolid;
                if(this->ComboBoxFill->Items->Strings[ComboBoxFill->ItemIndex]=="Kratka")
                        PB->Canvas->Brush->Style=bsDiagCross;
                if(this->ComboBoxFill->Items->Strings[ComboBoxFill->ItemIndex]=="Paski")
                        PB->Canvas->Brush->Style=bsHorizontal;

                if(this->CSpinEditLine->Value>this->CSpinEditLine->MaxValue&&this->CSpinEditLine->Value<this->CSpinEditLine->MinValue)
                        this->CSpinEditLine->Value=1;
                this->PB->Canvas->Pen->Width=this->CSpinEditLine->Value;

                if (ToolButton1->Down) //je�li klikni�to lini�
                {
                        PB->Canvas->MoveTo(x,y);
                        PB->Canvas->LineTo(X,Y);
                        x=X;
                        y=Y;
                        TRect rect = PB->ClientRect; //tworzy prostok�t o wymiarach jak PaintBox
                        obrazek->Canvas->CopyRect(rect, PB->Canvas, rect);
                        // MoveTo wskazuje punkt pocz�tkowy linii, a LineTo ko�cowy
                }
                else if (TBLine->Down) //je�li klikni�to lini�
                {
                        PB->Canvas->MoveTo(x,y);
                        PB->Canvas->LineTo(X,Y);
                }
                else if (TBEllipse->Down) //je�li klikni�to elips�
                        PB->Canvas->Ellipse(x, y, X, Y);
                        // parametrami funkcji Ellipse s� dwa punkty wskazuj�ce lewy g�rny i prawy dolny r�g prostok�ta opisanego na tej elipsie
                else if (TBRectangle->Down) //je�li klikni�to prostok�t
                        PB->Canvas->Rectangle(x, y, X, Y);
                        // parametrami funkcji Rectangle s� dwa punkty wskazuj�ce lewy g�rny i prawy dolnyr�g prostok�ta
                else if (TBRoundRec->Down) //je�li klikni�to zaokr�glony prostok�t
                        PB->Canvas->RoundRect(x, y, X, Y, abs(X-x)/5, abs(Y-y)/5);
                        // parametrami funkcji RoundRect s� dwa punkty wskazuj�ce lewy g�rny i prawy dolnyr�g prostok�ta oraz dwie liczby okre�laj�ce stopie� zaokr�glenia rog�w
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::PBMouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
        clicked = false;
        TRect rect = PB->ClientRect; //tworzy prostok�t o wymiarach jak PaintBox
        obrazek->Canvas->CopyRect(rect, PB->Canvas, rect);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{

        PB->Color=clWhite;
        PB->Canvas->Pen->Color=clBlack;
        obrazek = new Graphics::TBitmap();
        obrazek->Width = PB->Width;
        obrazek->Height = PB->Height;
        clicked=false;
        DoubleBuffered = true;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormDestroy(TObject *Sender)
{
        delete obrazek;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::PBPaint(TObject *Sender)
{
      if (czysc)
        {
                czysc = !czysc;
                TRect rect = PB->ClientRect;
                obrazek->Canvas->CopyRect(rect, PB->Canvas, rect);
        }
        else
                PB->Canvas->Draw(0,0,obrazek);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBoxLinneChange(TObject *Sender)
{
        if(this->ComboBoxLinne->Items->Strings[ComboBoxLinne->ItemIndex]=="Pusty")
                PB->Canvas->Pen->Style=psClear;
        if(this->ComboBoxLinne->Items->Strings[ComboBoxLinne->ItemIndex]=="Ci�g�y")
                PB->Canvas->Pen->Style=psSolid;
        if(this->ComboBoxLinne->Items->Strings[ComboBoxLinne->ItemIndex]=="Kreska")
                PB->Canvas->Pen->Style=psDash;
        if(this->ComboBoxLinne->Items->Strings[ComboBoxLinne->ItemIndex]=="Kropka")
                PB->Canvas->Pen->Style=psDot;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBoxFillChange(TObject *Sender)
{
        if(this->ComboBoxFill->Items->Strings[ComboBoxFill->ItemIndex]=="Puste")
                PB->Canvas->Brush->Style=bsClear;
        if(this->ComboBoxFill->Items->Strings[ComboBoxFill->ItemIndex]=="Pe�ne")
                PB->Canvas->Brush->Style=bsSolid;
        if(this->ComboBoxFill->Items->Strings[ComboBoxFill->ItemIndex]=="Kratka")
                PB->Canvas->Brush->Style=bsDiagCross;
        if(this->ComboBoxFill->Items->Strings[ComboBoxFill->ItemIndex]=="Paski")
                PB->Canvas->Brush->Style=bsHorizontal;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::CSpinEditLineChange(TObject *Sender)
{
        if(this->CSpinEditLine->Value>this->CSpinEditLine->MaxValue&&this->CSpinEditLine->Value<this->CSpinEditLine->MinValue)
                this->CSpinEditLine->Value=1;
        this->PB->Canvas->Pen->Width=this->CSpinEditLine->Value;
}
//---------------------------------------------------------------------------




void __fastcall TForm1::ShapeLinneMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        this->ColorDialog1->Execute();
        this->ShapeLinne->Brush->Color=ColorDialog1->Color;
        this->PB->Canvas->Pen->Color=ColorDialog1->Color;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::ShapeFillMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        this->ColorDialog2->Execute();
        this->ShapeFill->Brush->Color=ColorDialog2->Color;
        PB->Color=ColorDialog2->Color;
}
//---------------------------------------------------------------------------




void __fastcall TForm1::Zapisz1Click(TObject *Sender)
{

        if (SavePictureDialog1->Execute())
               obrazek->SaveToFile(SavePictureDialog1->FileName);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Nowy1Click(TObject *Sender)
{
        czysc=true;
        this->PB->Refresh();        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Ot1Click(TObject *Sender)
{
        if (OpenPictureDialog1->Execute())
                obrazek->LoadFromFile(OpenPictureDialog1->FileName);
         PB->Repaint();

                this->PB->Canvas->Pen->Color=this->ShapeLinne->Brush->Color;
                this->PB->Color=this->ShapeFill->Brush->Color;
                if(this->ComboBoxLinne->Items->Strings[ComboBoxLinne->ItemIndex]=="Pusty")
                        PB->Canvas->Pen->Style=psClear;
                if(this->ComboBoxLinne->Items->Strings[ComboBoxLinne->ItemIndex]=="Ci�g�y")
                        PB->Canvas->Pen->Style=psSolid;
                if(this->ComboBoxLinne->Items->Strings[ComboBoxLinne->ItemIndex]=="Kreska")
                        PB->Canvas->Pen->Style=psDash;
                if(this->ComboBoxLinne->Items->Strings[ComboBoxLinne->ItemIndex]=="Kropka")
                        PB->Canvas->Pen->Style=psDot;

                if(this->ComboBoxFill->Items->Strings[ComboBoxFill->ItemIndex]=="Puste")
                        PB->Canvas->Brush->Style=bsClear;
                if(this->ComboBoxFill->Items->Strings[ComboBoxFill->ItemIndex]=="Pe�ne")
                        PB->Canvas->Brush->Style=bsSolid;
                if(this->ComboBoxFill->Items->Strings[ComboBoxFill->ItemIndex]=="Kratka")
                        PB->Canvas->Brush->Style=bsDiagCross;
                if(this->ComboBoxFill->Items->Strings[ComboBoxFill->ItemIndex]=="Paski")
                        PB->Canvas->Brush->Style=bsHorizontal;

                if(this->CSpinEditLine->Value>this->CSpinEditLine->MaxValue&&this->CSpinEditLine->Value<this->CSpinEditLine->MinValue)
                        this->CSpinEditLine->Value=1;
                this->PB->Canvas->Pen->Width=this->CSpinEditLine->Value;
}
//---------------------------------------------------------------------------

