unit Multitec;

interface

Uses Dos,crt;

Var
  Presionada : Array[0..127] of Boolean;

Procedure InstalarMT;
Procedure DesinstalarMT;

Implementation

Var
  Anterior     : Procedure;
  AnteriorExit : Pointer;



{$F+}
Procedure Teclado; Interrupt;
Var
  p60 : Byte;

Begin
  p60 := Port[$60];

  if p60 > 127 then
     Presionada[p60-128]:=False
  Else Presionada[p60]:=True;
  While KeyPressed do Readkey;
  InLine($9C);
  Anterior;
end;

Procedure DesinstalarMT;
Begin
  SetIntVec($9,@Anterior);
  Release(AnteriorExit);
end;
{$F-}



Procedure InstalarMT;
Begin
  FillChar(Presionada, SizeOf(Presionada), False);
      GetIntVec($9,@Anterior);
      SetIntVec($9,@Teclado);
end;

Begin
  AnteriorExit := @ExitProc;
  ExitProc     := @DesInstalarMT;
  InstalarMT;
end.
