unit pac2;

interface
uses
    Fsprite3;

type
    Laberinto = array[1..20] of string[28];

    tipo_laberinto = ^laberinto;

    tipo_pacman = record
                        px,py : word;
                        dx,dy : shortint;
                  end;




function no_arriba (pac : tipo_pacman; pantalla : tipo_laberinto;x,y : byte) : boolean;
function no_abajo (pac : tipo_pacman; pantalla : tipo_laberinto;x,y : byte) : boolean;
function no_derecha (pac : tipo_pacman; pantalla : tipo_laberinto;x,y : byte) : boolean;
function no_izquierda (pac : tipo_pacman; pantalla : tipo_laberinto;x,y : byte) : boolean;
function en_foco (var pac : tipo_pacman) : boolean;
function si_avanza (pac : tipo_pacman; pantalla : tipo_laberinto) : boolean;



procedure borra_punto(x,y : byte);
procedure borra_punto_GROSO(x,y : byte);
procedure posXY (pac : tipo_pacman; var x,y : byte);
procedure normal (a,b,i,d : boolean; var direccion : byte; m,p : tipo_pacman);
procedure cagado (a,b,i,d : boolean; var direccion : byte; m,p : tipo_pacman);
procedure ojitos (a,b,i,d : boolean; var direccion : byte; m,p : tipo_pacman);

implementation












function en_foco (var pac : tipo_pacman) : boolean;
var
   X,Y,x1,y1 : byte;

begin
with pac do
begin;
      if dx > 0 then
         begin;
               x := (px div 11);
               x1 := ((px + 10) div 11);
         end
            else
         begin;
               x := ((px + 10) div 11);
               x1 := (px div 11);
         end;


      if dy > 0 then
         begin;
               y := (py div 9);
               y1 := ((py + 8) div 9);
         end
            else
         begin;
               y := ((py + 8) div 9);
               y1 := (py div 9);
         end;

      if ((x = x1) and (y = y1)) then en_foco := true else en_foco := false;
end;
end;





procedure posXY (pac : tipo_pacman; var x,y : byte);
begin
with pac do
begin
      if dx > 0 then
               x := (px div 11)
            else
               x := ((px + 10) div 11);


      if dy > 0 then
               y := (py div 9)
            else
               y := ((py + 8) div 9);
end;
end;






function no_arriba (pac : tipo_pacman; pantalla : tipo_laberinto;x,y : byte) : boolean;
begin
     if
       ((pantalla^ [y - 1, x] = #32) or
       (pantalla^ [y - 1, x] = #46)  or
       (pantalla^ [y - 1, x] = #44) or
       (pantalla^ [y - 1, x] = 'n'))
       then
           no_arriba := true else no_arriba := false;
end;





function no_abajo (pac : tipo_pacman; pantalla : tipo_laberinto;x,y : byte) : boolean;
begin
     if ((pantalla^ [y + 1, x] = #32) or
        (pantalla^ [y + 1, x] = #46) or
        (pantalla^ [y + 1, x] = #44) or
        (pantalla^ [y + 1, x] = 'n'))
        then
            no_abajo := true else no_abajo := false;
end;




function no_derecha (pac : tipo_pacman; pantalla : tipo_laberinto;x,y : byte) : boolean;
begin
     if ((pantalla^ [y , x + 1] = #32) or
         (pantalla^ [y , x + 1] = #46) or
         (pantalla^ [y , x + 1] = '*')  or
         (pantalla^ [y , x + 1] = #44) or
         (pantalla^ [y , x + 1] = 'n'))
        then
            no_derecha := true else no_derecha := false;
end;




function no_izquierda (pac : tipo_pacman; pantalla : tipo_laberinto;x,y : byte) : boolean;
begin
     if ((pantalla^ [y, x - 1] = #32) or
         (pantalla^ [y , x - 1] = #46) or
         (pantalla^ [y , x - 1] = '*')  or
         (pantalla^ [y , x - 1] = #44)  or
         (pantalla^ [y , x - 1] = 'n'))
        then
            no_izquierda := true else no_izquierda := false;
end;





function si_avanza (pac : tipo_pacman; pantalla : tipo_laberinto) : boolean;
var
   x,y : byte;
begin;
     posXY (pac,x,y);
     if
       ((no_izquierda (pac,pantalla,x,y)) and (pac.dx = -1)) or
       ((no_derecha   (pac,pantalla,x,y)) and (pac.dx = 1 )) or
       ((no_arriba    (pac,pantalla,x,y)) and (pac.dy = -1)) or
       ((no_abajo     (pac,pantalla,x,y)) and (pac.dy = 1 ))
       then
           si_avanza := true else si_avanza := false;
end;




procedure borra_punto(x,y : byte);
var
   x1,y1 : word;

begin;
x1 := ((x + 1) * 11) + 5;
y1 := ((y + 1) * 9) + 4;

back^[y1    , x1    ] := 0;
back^[y1 - 1, x1    ] := 0;
back^[y1 + 1, x1    ] := 0;
back^[y1    , x1 - 1] := 0;
back^[y1    , x1 + 1] := 0;


end;



procedure borra_punto_GROSO(x,y : byte);
var
   x1,y1 : word;

begin;
x1 := ((x + 1) * 11) + 5;
y1 := ((y + 1) * 9) + 4;

back^[y1    , x1    ] := 0;
back^[y1 - 1, x1    ] := 0;
back^[y1 + 1, x1    ] := 0;
back^[y1    , x1 - 1] := 0;
back^[y1    , x1 + 1] := 0;
back^[y1 - 1, x1 + 1] := 0;
back^[y1 + 1, x1 + 1] := 0;
back^[y1 - 1, x1 - 1] := 0;
back^[y1 + 1, x1 - 1] := 0;
back^[y1    , x1 - 2] := 0;
back^[y1    , x1 + 2] := 0;
back^[y1 + 1, x1 - 2] := 0;
back^[y1 + 1, x1 + 2] := 0;
back^[y1 - 1, x1 - 2] := 0;
back^[y1 - 1, x1 + 2] := 0;
back^[y1 - 2, x1 - 1] := 0;
back^[y1 - 2, x1    ] := 0;
back^[y1 - 2, x1 + 1] := 0;
back^[y1 + 2, x1 - 1] := 0;
back^[y1 + 2, x1    ] := 0;
back^[y1 + 2, x1 + 1] := 0;
end;

















procedure normal (a,b,i,d : boolean; var direccion : byte; m,p : tipo_pacman);
begin;
         if (not(a) and
            not(b)  and
            d       and
            not(i))          then
                                   direccion := 4;

         if (not(a) and
            not(b)  and
            not(d)  and
            i)          then
                                   direccion := 3;


         if (a and
            not(b)  and
            not(d)  and
            not(i))          then
                                   direccion := 1;

         if (not(a) and
            b       and
            not(d)  and
            not(i))          then
                                   direccion := 2;


         if (not(a) and
            b       and
            d       and
            not(i))          then
                                   if m.dx = 0 then direccion := 4
                                   else
                                       direccion := 2;

         if (not(a) and
            b       and
            not(d)  and
            i)               then
                                   if m.dx = 0 then direccion := 3
                                   else
                                       direccion := 2;


         if (a      and
            not(b)  and
            not(d)  and
            i)               then
                                   if m.dx = 0 then direccion := 3
                                   else
                                       direccion := 1;


         if (a      and
            not(b)  and
            d       and
            not(i))          then
                                   if m.dx = 0 then direccion := 4
                                   else
                                       direccion := 1;



         if (not(a) and
            b       and
            d       and
            i)               then
                                      begin;


                                        direccion := random(2) + 1;
                                        case direccion of
                                             1 : if m.px < p.px then direccion := 4
                                                    else
                                                        direccion := 3;


                                             2 : if m.py < p.py then direccion := 2
                                                    else
                                                        if m.px < p.px then direccion := 4
                                                       else
                                                         direccion := 3;
                                        end;
                                      end;



         if (a      and
            not(b)  and
            d       and
            i)               then
                                      begin;
                                        direccion := random(2) + 1;
                                        case direccion of
                                             1 : if m.px < p.px then direccion := 4
                                                    else
                                                        direccion := 3;

                                             2 : if m.py > p.py then direccion := 1
                                                    else
                                                        if m.px < p.px then direccion := 4
                                                       else
                                                         direccion := 3;

                                        end;
                                      end;


         if (a     and
            b      and
            not(d) and
            i)               then
                                      begin;
                                        direccion := random(2) + 1;
                                        case direccion of
                                             1 : if m.py < p.py then direccion := 2
                                                    else
                                                        direccion := 1;

                                             2 : if m.px > p.px then direccion := 3
                                                    else
                                                        if m.py < p.py then direccion := 2
                                                       else
                                                         direccion := 1;
                                        end;
                                      end;



         if (a      and
             b      and
             d      and
             not(i))         then
                                      begin;
                                        if ((m.px = 154) and (m.py = 171)) then direccion := 1
                                         else
                                           begin;
                                             direccion := random(2) + 1;
                                             case direccion of
                                                 1 : if m.py < p.py then direccion := 2
                                                        else
                                                            direccion := 1;

                                                 2 : if m.px < p.px then direccion := 4
                                                         else
                                                             if m.py < p.py then direccion := 2
                                                            else
                                                              direccion := 1;
                                             end;
                                           end;
                                      end;


         if (a      and
             b      and
             d      and
             i)               then
                                      begin;
                                                direccion := random(2) + 1;
                                                case direccion of
                                                    1 : if m.py < p.py then direccion := 2
                                                           else
                                                               direccion := 1;
                                                    2 : if m.px < p.px then direccion := 4
                                                           else
                                                               direccion := 3;
                                                end;
                                      end;



         if ((m.px = 154) and (m.py = 81)) then direccion := 1;

END;











procedure cagado (a,b,i,d : boolean; var direccion : byte; m,p : tipo_pacman);
begin;

         if (not(a) and
            not(b)  and
            d       and
            not(i))          then
                                   direccion := 4;

         if (not(a) and
            not(b)  and
            not(d)  and
            i)          then
                                   direccion := 3;


         if (a and
            not(b)  and
            not(d)  and
            not(i))          then
                                   direccion := 1;

         if (not(a) and
            b       and
            not(d)  and
            not(i))          then
                                   direccion := 2;





         if (not(a) and
            b       and
            d       and
            i)          then
                          begin;
                            direccion := random(2) + 1;
                            case direccion of
                                 1 : if m.px < p.px then direccion := 3
                                        else
                                            direccion := 4;
                                 2 : if m.py > p.py then direccion := 2
                                        else
                                            if m.px < p.px then direccion := 3
                                           else
                                             direccion := 4;
                            end;
                          end;



         if (a      and
            not(b)  and
            d       and
            i)          then
                          begin;
                            direccion := random(2) + 1;
                            case direccion of
                                 1 : if m.px < p.px then direccion := 3
                                        else
                                            direccion := 4;
                                 2 : if m.py < p.py then direccion := 1
                                        else
                                            if m.px < p.px then direccion := 3
                                           else
                                             direccion := 4;
                            end;
                          end;


         if (a     and
            b      and
            not(d) and
            i)               then
                                      begin;
                                        direccion := random(2) + 1;
                                        case direccion of
                                             1 : if m.py < p.py then direccion := 1
                                                    else
                                                        direccion := 2;
                                             2 : if m.px < p.px then direccion := 3
                                                    else
                                                        if m.py < p.py then direccion := 1
                                                       else
                                                         direccion := 2;
                                        end;
                                      end;



         if (a      and
             b      and
             d      and
             not(i))         then
                                      begin;
                                        direccion := random(2) + 1;
                                        case direccion of
                                            1 : if m.py < p.py then direccion := 1
                                                   else
                                                       direccion := 2;
                                            2 : if m.px > p.px then direccion := 4
                                                    else
                                                        if m.py < p.py then direccion := 1
                                                       else
                                                         direccion := 2;
                                        end;
                                      end;


         if (a      and
             b      and
             d      and
             i)               then
                                      begin;
                                        direccion := random(2) + 1;
                                        case direccion of
                                            1 : if m.py < p.py then direccion := 1
                                                   else
                                                       direccion := 2;
                                            2 : if m.px < p.px then direccion := 3
                                                   else
                                                       direccion := 4;
                                        end;
                                      end;


         if (not(a) and
            b       and
            d       and
            not(i))          then
                                   if m.dx = 0 then direccion := 4
                                   else
                                       direccion := 2;

         if (not(a) and
            b       and
            not(d)  and
            i)               then
                                   if m.dx = 0 then direccion := 3
                                   else
                                       direccion := 2;


         if (a      and
            not(b)  and
            not(d)  and
            i)               then
                                   if m.dx = 0 then direccion := 3
                                   else
                                       direccion := 1;


         if (a      and
            not(b)  and
            d       and
            not(i))          then
                                   if m.dx = 0 then direccion := 4
                                   else
                                       direccion := 1;

END;

































procedure ojitos (a,b,i,d : boolean; var direccion : byte; m,p : tipo_pacman);
begin;
         if (not(a) and
            not(b)  and
            d       and
            not(i))          then
                                   direccion := 4;

         if (not(a) and
            not(b)  and
            not(d)  and
            i)          then
                                   direccion := 3;


         if (a and
            not(b)  and
            not(d)  and
            not(i))          then
                                   direccion := 1;

         if (not(a) and
            b       and
            not(d)  and
            not(i))          then
                                   direccion := 2;



         if (not(a) and
            b       and
            d       and
            not(i))          then
                                   if m.dx = 0 then direccion := 4
                                   else
                                       direccion := 2;

         if (not(a) and
            b       and
            not(d)  and
            i)               then
                                   if m.dx = 0 then direccion := 3
                                   else
                                       direccion := 2;


         if (a      and
            not(b)  and
            not(d)  and
            i)               then
                                   if m.dx = 0 then direccion := 3
                                   else
                                       direccion := 1;


         if (a      and
            not(b)  and
            d       and
            not(i))          then
                                   if m.dx = 0 then direccion := 4
                                   else
                                       direccion := 1;



         if (not(a) and
            b       and
            d       and
            i)               then
                                      begin;
                                        if m.px = 154 then direccion := 2
                                            else
                                                 begin;
                                                       direccion := random(2) + 1;
                                                       case direccion of
                                                            1 : if m.px < 154 then direccion := 4
                                                                   else
                                                                       direccion := 3;


                                                            2 : if m.py < 81 then direccion := 2
                                                                   else
                                                                       if m.px < 154 then direccion := 4
                                                                      else
                                                                        direccion := 3;
                                                       end;
                                                 end;
                                      end;



         if (a      and
            not(b)  and
            d       and
            i)               then
                                      begin;
                                        if m.px = 154 then direccion := 1
                                            else
                                                 begin;
                                                       direccion := random(2) + 1;
                                                       case direccion of
                                                            1 : if m.px < 154 then direccion := 4
                                                                   else
                                                                       direccion := 3;

                                                            2 : if m.py > 81 then direccion := 1
                                                                   else
                                                                       if m.px < 154 then direccion := 4
                                                                      else
                                                                        direccion := 3;

                                                       end;
                                                 end;
                                      end;


         if (a     and
            b      and
            not(d) and
            i)               then
                                      begin;
                                        if m.py = 81 then direccion := 3
                                            else
                                                 begin;
                                                      direccion := random(2) + 1;
                                                      case direccion of
                                                           1 : if m.py < 81 then direccion := 2
                                                                  else
                                                                      direccion := 1;

                                                           2 : if m.px > 154 then direccion := 3
                                                                  else
                                                                      if m.py < 81 then direccion := 2
                                                                     else
                                                                       direccion := 1;
                                                      end;
                                                 end;
                                      end;



         if (a      and
             b      and
             d      and
             not(i))         then
                                      begin;
                                        if m.py = 81 then direccion := 4
                                            else
                                                 begin;
                                                       direccion := random(2) + 1;
                                                       case direccion of
                                                           1 : if m.py < 81 then direccion := 2
                                                                  else
                                                                      direccion := 1;

                                                           2 : if m.px < 154 then direccion := 4
                                                                   else
                                                                       if m.py < 81 then direccion := 2
                                                                      else
                                                                        direccion := 1;
                                                       end;
                                                 end;
                                      end;


         if (a      and
             b      and
             d      and
             i)               then
                                      begin;
                                           direccion := random(2) + 1;
                                           case direccion of
                                               1 : if m.py < 81 then direccion := 2
                                                      else
                                                          direccion := 1;
                                               2 : if m.px < 154 then direccion := 4
                                                      else
                                                          direccion := 3;
                                           end;

                                           if m.py = 79 then
                                                   if m.px < 154 then direccion := 4
                                                      else direccion := 3;

                                           if m.px = 154 then
                                                   if m.py < 81 then direccion := 2
                                                      else direccion := 1;
                                      end;


         if ((m.px = 154) and (m.py = 63)) then direccion := 2;

         if ((m.py = 99) and (m.px > 108) and (m.px < 199)) then direccion := 3;
         if ( ((m.px = 110) or (m.px = 198)) and (m.py > 62) and (m.py < 100) ) then direccion := 1;

         if ((m.py = 63) and (m.px = 110))  then direccion := 4;
         if ((m.py = 63) and (m.px = 198))  then direccion := 3;

END;











end.