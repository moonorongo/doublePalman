{$M 49152,0,320000}
{$F- $a+ $b- $g+ $i- $r- $s+ $x+}

USES multitec,pac2,CRT,FSPRITE3,dos;



const
     cambia_color : boolean = true;
     frecuen_ini  : word = 1000;

type

    rec1 = record
          Nombre : string[10];
          puntaje : longint;
          end;

    hof =  array [1..5] of rec1;

    registro = record
               d : word;
               velp : byte;
               velm : byte;
               p : array [1..20] of string[28];
               ret_fino_p : byte;
               ret_fino_m : byte;
               titulo : string [40];
               end;

    reg_sound = record
                dispositivo : byte;
                mixing : word;
                sonido : boolean;
                end;

  DACType = array [0..255] of record
                                R, G, B : byte;
                              end;

var
   titulo : string;
   cm1,conta_inmunidad_1 : word;
   cm2,conta_inmunidad_2 : word;

   ano,mes,dia,diasem : word;
   borrar : text;

   nivini,
   ret_fino_p,
   ret_fino_m,
   retraso_pii : byte;

   records : hof;

   presen_col,
   pac_col,
   col1,
   col2 : dactype;


   conta_intercambio : longint;

   arc_sonido : file of reg_sound;


   rs : reg_sound;

   conta_mientras_fruta,
   conta_fruta,
   aparece_fruta : word;

   conta_morfados,
   conta2,
   conta3 : byte;

   dev,
   mix,
   stat,
   pro,
   loop,
   buc : integer;

   md : string;

   retraso,
   pausa,
   pausa2 : longint;

   c_principal,
   velm,
   velm2,
   velm3,
   velm4,
   velp,
   velp2,
   guarda_velm,
   contam1,
   contam2,
   contam3,
   contam4 : byte;

   avanzam,
   avanzam2,
   avanzam3,
   avanzam4,
   avanzap,
   avanzap2,
   fruta_on,
   competitive,
   s,
   cheat_mode : boolean;

   POSICION2,
   posicion : shortint;

   cantidad,
   contam,
   contador : word;

   divimons,
   divisor : byte;

   pantalla : tipo_laberinto;
   panta : laberinto;

   ultimo,
   VIDAS,
   vidas2,
   x,
   y,
   X2,
   Y2 : byte;

   p1 : tipo_pacman;
   P2 : TIPO_PACMAN;

   m  : tipo_pacman;
   m2 : tipo_pacman;
   m3 : tipo_pacman;
   m4 : tipo_pacman;

   posm,
   posm2,
   posm3,
   posm4,

   st,
   st2,
   st3,
   st4 : byte;

   conta_morfar : word;

   perdi_vida,W_pantalla : boolean;
   perdi_vida2 : boolean;

   contasalida : word;
   cuanto : byte;

   DIFICULTAD : WORD;
   puntaje : longint;
   puntaje2 : longint;
   aux,
   nivel : byte;

   salida : boolean;
   sonido_pastilla : boolean;
   conta_puntaje,
   conta_sonido : byte;

   retraso_fade : word;


procedure WaitRetrace;          { Wait for vertical retrace }
begin
  repeat { Nothing } until (Port[$03da] and 8) <> 0;
end;


function get_name (x,y : byte) : string;
var
   n : string;
begin;
n := '';
window(x,y,x+11,y);
clrscr;
readln (n);
if length (n) > 10 then n := copy (n,1,10);
get_name := n;
window(1,1,80,25);
end;




procedure open_records (var p : hof);
var
records : file of hof;

begin;
assign (records,'pacman.rec');
reset (records);
read(records,p);
close (records);
end;





procedure Update_records (var p : hof);
var
arch : file of hof;

begin;
{
assign (arch,'pacman.rec');
rewrite (arch);
write (arch,p);
close (arch);
}
end;




procedure Sort_records (var p : hof);
var
   x,y : byte;
   pun_aux : rec1;

begin;
for x := 5 downto 1 do
    for y := 5 downto x do
        begin
             if p[x].puntaje < p[y].puntaje then
                begin;
                      pun_aux := p[y];
                      p[y] := p[x];
                      p[x] := pun_aux;
                end;
        end;
end;





procedure sonido_fantasma;
var
   f : word;
   t : byte;

begin;
for t := 3 to 7 do
begin;
      f := t * 100;
      repeat
            inc (f,3);
            sound(f);
            delay (1);
      until f > (t + 3) * 100;
end;

nosound;
end;



procedure bip;
begin;
if sonido_pastilla then
begin;
      sound (500);
      if conta_sonido = 2 then sound(600);
      if conta_sonido = 4 then sound(700);
      if conta_sonido = 6 then sound(800);
      if conta_sonido = 8 then sound(900);
      if conta_sonido = 10 then sound(1000);
      if conta_sonido = 12 then begin;
                               nosound;
                               sonido_pastilla := false;
                          end;
      inc (conta_sonido);
end;

end;






procedure me_cagastes;
var
   f : word;
begin;
      for f := 600  downto 300 do
      begin;
          sound (f);
          delay (1);
      end;
      for f := 100 to 300 do
      begin;
          sound (f * 3);
          delay (1);
      end;
nosound;
end;



procedure setCOL (numcol,r,g,b : byte);
begin;
port[$3c8] := numcol;
port[$3c9] := r;
port[$3c9] := g;
port[$3c9] := b;
end;


procedure LoadCOL (FileName : string; var dac : dactype);
var
  Fil : file of DACType;
  I : integer;
begin
  assign (Fil, FileName);
  reset (Fil);
  read (Fil, DAC);
  close (Fil);

end;

procedure setzeros;
var
   t : byte;
begin;
for t:= 0 to 255 do
    setcol (t,0,0,0);
end;



procedure fadein (dac : dactype);
var
   aux : dactype;
   t : byte;
   bandera : boolean;
   rr : word;

begin;
for t := 0 to 255 do
    begin;
          aux[t].r := 0;
          aux[t].g := 0;
          aux[t].b := 0;
    end;


repeat
      bandera := false;
      for t := 0 to 255 do
      begin;
          if aux[t].r < dac[t].r then
             begin;
                   inc (aux[t].r);
                   bandera := true
             end;
          if aux[t].g < dac[t].g then
             begin;
                   inc (aux[t].g);
                   bandera := true
             end;
          if aux[t].b < dac[t].b then
             begin;
                   inc (aux[t].b);
                   bandera := true
             end;
          setcol (t,aux[t].r,aux[t].g,aux[t].b);

      end;
until bandera = false;


end;  {procedure}



procedure Fade_to_black (dac : dactype);
var
   t : byte;
   bandera : boolean;
   rr : word;
   vol : byte;

begin;
vol := 255;

repeat
      bandera := false;

      for t := 0 to 255 do
      begin;
          if dac[t].r > 0 then
             begin;
                   dec (dac[t].r);
                   bandera := true
             end;
          if dac[t].g > 0 then
             begin;
                   dec (dac[t].g);
                   bandera := true
             end;
          if dac[t].b > 0 then
             begin;
                   dec (dac[t].b);
                   bandera := true
             end;
          setcol (t,dac[t].r,dac[t].g,dac[t].b);
      end;

             if vol > 10 then
                begin;
                      dec(vol,5);
                end;

until bandera = false;

end;  {procedure}




procedure Fade_to_black2 (dac : dactype);
var
   t : byte;
   bandera : boolean;
   rr : word;

begin;

repeat
      bandera := false;

      for t := 0 to 255 do
      begin;
          if dac[t].r > 0 then
             begin;
                   dec (dac[t].r);
                   bandera := true
             end;
          if dac[t].g > 0 then
             begin;
                   dec (dac[t].g);
                   bandera := true
             end;
          if dac[t].b > 0 then
             begin;
                   dec (dac[t].b);
                   bandera := true
             end;
          setcol (t,dac[t].r,dac[t].g,dac[t].b);

      end;
until bandera = false;
end;  {procedure}









function getvel : longint;
var
   contador : longint;
   hasta : byte;
begin;
getvel := 0;
end;








PROCEDURE Scoreme;
BEGIN
  TextATTr := 64 + White;
  GOTOXY(10,1);
  Write(puntaje);
END;



PROCEDURE Scoreme2;
BEGIN
  TextATTr := 64 + White;
  GOTOXY(30,1);
  Write(puntaje2);
END;



procedure muestra_vidas;
begin;
  TextATTr := 64 + White;
  gotoxy (5,1);
  Write(vidas);

  gotoxy (25,1);
  Write(vidas2);
end;





{$i monster1.inc }
{$i CICLO1.INC}


procedure load_screen (nombre : string; var inscreen : graphicscreen);
var
   ffile : file;

begin;
assign (ffile,nombre);
reset (ffile,1);
blockread (ffile,inscreen,64000);
close (ffile);
end;



procedure muestra_final;
var
   c : dactype;

begin;
      loadcol ('fin.col',c);
      load_screen ('fin.vga',act);
      fadein (c);

      repeat until keypressed;

      fade_to_black2 (c);
end;










procedure players2;

BEGIN;

salida := false;
puntaje := 0;
puntaje2 := 0;

conta_morfados := 0;


mix := rs.mixing;
dev := rs.dispositivo;


{ BORRA LA PANTALLA ACTUAL, LA DE FONDO Y LA DEL MEDIO }
fillchar (back^,64000,0);
mid^:=back^;
ACT:=BACK^;

{ CARGA LA PALETA DE COLORES DE AUTODESK ANIMATOR }
loadCOL ('PACMAN.COL',pac_col);


{ COMIENZO DEL JUEGO!!!!!!! }
repeat
port[$21]:=0;
cargar_nivel (nivel, dificultad,pantalla,titulo);


dibuja_laberinto (pantalla,cantidad);
muestra_vidas;
gotoxy (2,25);
write ('Level ');
write (nivel);
{write (' - ');
write (titulo);}

    md := 'a.mod';
    pro := 0;
    loop :=4; {4 Hace que el MOD se repita constantemente}

port[$21]:=$5c;
             inicializa_variables2;
             scoreme;
             scoreme2;
             muestra_vidas;
             fadein (pac_col);


{ COMIENZO DE LAS VIDAS }
       REPEAT
             delay (700);

{ CICLO DEL JUEGO }
                        sound (100);
                        delay (3);
                        nosound;

                 main_loop2;

             nosound;

             conta_sonido := 0;
             sonido_pastilla := false;

             if presionada[1] then salida := true;

       UNTIL (salida or ((VIDAS = 0) and (vidas2 = 0)) or (cantidad = 0));

{ SI LA CANTIDAD DE PUNTOS ES 0 ENTONCES SUBE DE NIVEL }
       if cantidad = 0 then
                           begin;
                             sube_nivel2;
                             if ((nivel mod 10) = 0) then
                                begin;
                                      if vidas > 0 then inc(vidas);
                                      if vidas2 > 0 then inc (vidas2);
                                end;
                           end;

       Fade_to_black2 (pac_col);

       fillchar (back^,64000,0);
       mid^:=back^;
       ACT:=BACK^;

until (((vidas = 0) and (vidas2 = 0)) or salida or (nivel = 101));

      onscreen[0].on := false;
      onscreen[1].on := false;
      onscreen[2].on := false;
      onscreen[3].on := false;
      onscreen[4].on := false;
      onscreen[5].on := false;
      onscreen[6].on := false;
      os := 7;
      show;

      onscreen[0].x := 0;
      onscreen[1].x := 0;
      onscreen[2].x := 0;
      onscreen[3].x := 0;
      onscreen[4].x := 0;
      onscreen[5].x := 0;
      onscreen[6].x := 0;
      onscreen[0].y := 0;
      onscreen[1].y := 0;
      onscreen[2].y := 0;
      onscreen[3].y := 0;
      onscreen[4].y := 0;
      onscreen[5].y := 0;
      onscreen[6].y := 0;
      os := 7;
      show;


      fillchar (back^,64000,0);
      mid^:=back^;
      ACT:=BACK^;

      if nivel = 101 then muestra_final;

port[$21]:=0;
open_records (records);



                  if nivel <> 101 then
                              begin;
                                    loadcol ('gameo.col',col2);
                                    setzeros;
                                    load_screen ('gameo.vga',act);
                                    fadein (col2);
                                    delay (2500);
                                    fade_to_black (col2);
                              end;


                              loadcol ('dpac2.col',presen_col);
                              setzeros;
                              load_screen ('salida.vga',act);
                              {start_music;}
                              fadein (presen_col);
                              conta_intercambio := 0;
                              W_pantalla := false;


end;


















begin;
clrscr;
open_records(records);






salida := false;

getmem(Pantalla,sizeof(panta));

{ LEE LOS SPRITES DEL DISCO }

pausa2 := getvel;
retraso_fade := pausa2 * 20;
pausa := pausa2 * 1900;



cheat_mode := false;
if paramstr(1) = 'cheat' then
                              cheat_mode := true;

nivini := 1;
if paramstr(1) = 'test' then
                         begin
                              write ('Nivel inicial:');
                              readln (nivini);
                         end;

retraso_pii := 6;

ReadSprites ('PACMAN.DAT');
compile;

conta_sonido := 0;
sonido_pastilla := false;
setgraph;
DirectVideo := False;

      loadcol ('dpac2.col',presen_col);
      load_screen ('salida.vga',act);

      fadein (presen_col);

      c_principal := 0;
      conta_intercambio := 0;
      W_pantalla := false;

repeat

WaitRetrace;
inc (conta_intercambio);


for retraso := 1 to pausa do;


if presionada [59] then begin;
                              Fade_to_black (presen_col);
                              { CANTIDAD DE VIDAS }
                              vidas := 5;
                              vidas2 := 0;
                              nivel := nivini;
                              players2;
                        end;


if presionada [60] then begin;
                              Fade_to_black (presen_col);
                              { CANTIDAD DE VIDAS }
                              competitive := false;
                              vidas := 5;
                              vidas2 := 5;
                              nivel := nivini;
                              players2;
                        end;

if presionada [61] then begin;
                              Fade_to_black (presen_col);
                              { CANTIDAD DE VIDAS }
                              competitive := true;
                              vidas := 5;
                              vidas2 := 5;
                              nivel := nivini;
                              players2;
                        end;



until presionada[1];
Fade_to_black (presen_col);


{ LIBERA MEMORIA DE LA VARIABLE PANTALLA };

freemem(Pantalla,sizeof(panta));
textmode (3);
writeln ('Ahhh!!! DOS Again!...');

end.





