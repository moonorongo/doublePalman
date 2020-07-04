procedure ciclo_PACMAN (var pac : tipo_pacman);
var
   x,y : byte;
begin;
posxy (pac,x,y);
IF presionada[72] THEN
            begin;
                if no_arriba(pac,pantalla,x,y) then
                begin;
                      pac.dy := -1;
                      pac.dx := 0;
                      posicion := 0;
                end
             else
                begin;
                      if pac.dy < 0 then
                                begin;
                                      pac.dy := 0;
                                      pac.dx := 0;
                                      posicion:= 0;
                                end
                end;
            end;

IF presionada[80] THEN
            begin;
               if no_abajo(pac,pantalla,x,y) then
                  begin;
                        pac.dy := 1;
                        pac.dx := 0;
                        posicion := 4;
                  end
               else
                  begin
                        if pac.dy > 0 then
                                      begin;
                                            pac.dy := 0;
                                            pac.dx := 0;
                                            posicion := 4;
                                      end;
                  end;
            end;

IF presionada[75] THEN
            begin;
                  if no_izquierda(pac,pantalla,x,y) then
                     begin;
                           pac.dy := 0;
                           pac.dx := -1;
                           posicion := 12;
                     end
                   else
                     begin;
                           if pac.dx < 0 then
                                         begin;
                                               pac.dy := 0;
                                               pac.dx := 0;
                                               posicion := 12;
                                         end;
                     end;
            end;

IF presionada[77] THEN
            begin;
                  if no_derecha(pac,pantalla,x,y) then
                     begin;
                           pac.dy := 0;
                           pac.dx := 1;
                           posicion := 8;
                     end
                   else
                     begin;
                           if pac.dx > 0 then
                                         begin;
                                               pac.dy := 0;
                                               pac.dx := 0;
                                               posicion := 8;
                                         end;
                     end;
            end;

if presionada[2] then perdi_vida:=true;


case pantalla^[y , x] of
     'n' :  begin;
                        pantalla^[y , x] := #32;
                        borra_punto_groso(x - 1,y - 1);
                        inc (puntaje,10);
                        dec(cantidad);
                        scoreme;
                        conta_sonido := 0;
                        sonido_pastilla := true;
                        if velp > 1 then dec(velp);
            end;

     #46 :  begin;
                        pantalla^[y , x] := #32;
                        borra_punto(x - 1,y - 1);
                        inc (puntaje,10);
                        dec(cantidad);
                        scoreme;
                        conta_sonido := 0;
                        sonido_pastilla := true;
            end;

     #44 :  begin;
                        pantalla^[y , x] := #32;
                        borra_punto_GROSO (x - 1,y - 1);
                        setcol (248,0,0,63);
                        inc(puntaje,20);
                        scoreme;
                        dec(cantidad);
                        ultimo := 1;
                        conta_sonido := 0;
                        sonido_pastilla := true;

                        if st = 1 then begin
                                       velm  := guarda_velm  + 2;
                                       st := 0;
                                       posm := 66;
                                       end;

                        if st2 = 1 then begin;
                                        velm2  := guarda_velm  + 2;
                                        st2 := 0;
                                        posm2 := 66;
                                        end;

                        if st3 = 1 then begin;
                                        velm3  := guarda_velm  + 2;
                                        st3 := 0;
                                        posm3 := 66;
                                        end;

                        if st4 = 1 then begin;
                                        velm4  := guarda_velm  + 2;
                                        st4 := 0;
                                        posm4 := 66;
                                        end;

                        CONTA_MORFAR := DIFICULTAD;
                        cuanto := 1;
            end;
end;

end;















procedure ciclo_PACMAN2 (var pac : tipo_pacman);
var
   x2,y2 : byte;
begin;
posxy (pac,x2,y2);
{ S -> W }
IF presionada[17] THEN
            begin;
                if no_arriba(pac,pantalla,x2,y2) then
                begin;
                      pac.dy := -1;
                      pac.dx := 0;
                      posicion2 := 76;
                end
             else
                begin;
                      if pac.dy < 0 then
                                begin;
                                      pac.dy := 0;
                                      pac.dx := 0;
                                      posicion2:= 76;
                                end
                end;
            end;


IF presionada[31] THEN
            begin;
               if no_abajo(pac,pantalla,x2,y2) then
                  begin;
                        pac.dy := 1;
                        pac.dx := 0;
                        posicion2 := 80;
                  end
               else
                  begin
                        if pac.dy > 0 then
                                      begin;
                                            pac.dy := 0;
                                            pac.dx := 0;
                                            posicion2 := 80;
                                      end;
                  end;
            end;

{ Z -> A }
IF presionada[30] THEN
            begin;
                  if no_izquierda(pac,pantalla,x2,y2) then
                     begin;
                           pac.dy := 0;
                           pac.dx := -1;
                           posicion2 := 88;
                     end
                   else
                     begin;
                           if pac.dx < 0 then
                                         begin;
                                               pac.dy := 0;
                                               pac.dx := 0;
                                               posicion2 := 88;
                                         end;
                     end;
            end;

{ C -> D }
IF presionada[32] THEN
            begin;
                  if no_derecha(pac,pantalla,x2,y2) then
                     begin;
                           pac.dy := 0;
                           pac.dx := 1;
                           posicion2 := 84;
                     end
                   else
                     begin;
                           if pac.dx > 0 then
                                         begin;
                                               pac.dy := 0;
                                               pac.dx := 0;
                                               posicion2 := 84;
                                         end;
                     end;
            end;

if presionada[3] then perdi_vida2:=true;



case pantalla^[y2,x2] of
     'n' : begin;
                        pantalla^[y2, x2] := #32;
                        borra_punto_groso(x2 - 1,y2 - 1);
                        inc (puntaje2,10);
                        dec(cantidad);
                        scoreme2;
                        conta_sonido := 0;
                        sonido_pastilla := true;
                        if velp2 > 1 then dec(velp2);
           end;

     #46 : begin;
                        pantalla^[y2 , x2] := #32;
                        borra_punto(x2 - 1,y2 - 1);
                        inc (puntaje2,10);
                        dec(cantidad);
                        scoreme2;
                        conta_sonido := 0;
                        sonido_pastilla := true;
           end;

     #44 : begin;
                        pantalla^[y2 , x2] := #32;
                        borra_punto_GROSO (x2 - 1,y2 - 1);
                        setcol (248,0,0,63);
                        inc(puntaje2,20);
                        scoreme2;
                        dec(cantidad);
                        ultimo := 2;
                        conta_sonido := 0;
                        sonido_pastilla := true;

                        if st = 1 then begin
                                       velm  := guarda_velm  + 2;
                                       st := 0;
                                       posm := 66;
                                       end;

                        if st2 = 1 then begin;
                                        velm2  := guarda_velm  + 2;
                                        st2 := 0;
                                        posm2 := 66;
                                        end;

                        if st3 = 1 then begin;
                                        velm3  := guarda_velm  + 2;
                                        st3 := 0;
                                        posm3 := 66;
                                        end;

                        if st4 = 1 then begin;
                                        velm4  := guarda_velm  + 2;
                                        st4 := 0;
                                        posm4 := 66;
                                        end;

                        CONTA_MORFAR := DIFICULTAD;
                        cuanto := 1;
           end;
end;
end;




procedure Dibuja_laberinto (p : tipo_laberinto; var cantidad : word);
var
   x,y : byte;

begin;
cantidad := 0;
onscreen[1].on:=true;
FOR X := 1 TO 28 DO
    FOR Y := 1 TO 20 DO
    BEGIN;
          CASE pantalla^[Y,X] OF
               #200 {È} : POSICION := 18;
               #201 {É} : POSICION := 20;
               #187 {»} : POSICION := 19;
               #188 {¼} : POSICION := 17;
               #205 {¹} : POSICION := 16;
               #186 {º} : POSICION := 21;
               #32  { } : POSICION := 22;
               #46  {.} : begin;
                                POSICION := 23;
                                inc(cantidad);
                          end;
               #44  {,} : begin;
                                POSICION := 24;
                                inc(cantidad);
                          end;
               #181 {µ} : posicion := 64;
               #198 {Æ} : posicion := 63;
               #202 {Ê} : posicion := 58;
               #203 {Ë} : posicion := 57;
               #204 {Ì} : posicion := 59;
               #208 {Ð} : posicion := 62;
               #210 {Ò} : posicion := 61;
               #185 {¹} : posicion := 60;
               #206 {Î} : posicion := 104;
               #61  {=} : posicion := 65;
               '<'  {<} : posicion := 106;
               '>'  {>} : posicion := 107;
               'm'  {m} : posicion := 105;

               'n'      : begin;
                          posicion := 93;
                          inc (cantidad);
                          end;

          END;
          ONSCREEN[1].X := (X * 11);
          ONSCREEN[1].Y := (Y * 9);
          ONSCREEN[1].NUM := POSICION;
          OS := 2;
          SHOW;
    END;

BACK^:=ACT;
MID^ :=BACK^;
ACT := BACK^;

{ MUESTRA LA CANTIDAD DE VIDAS EN LA PANTALLA }
onscreen[1].num := 9;
onscreen[1].y   := -1;

      onscreen[1].x := 18;
      show;

onscreen[1].num := 85;
      onscreen[1].x := 178;
      show;


BACK^:=ACT;
MID^ :=BACK^;
ACT := BACK^;

onscreen[1].on := false;
end;








procedure cargar_nivel (nivel : byte; var dificultad : word; var pantalla : tipo_laberinto; var titulo : string);

var
   archivo : file of registro;
   p       : registro;
   nx : byte;


begin;
assign (archivo,'PACMAN.LVL');
reset (archivo);

seek (archivo,nivel);
read (archivo,p);

dificultad := p.d;

pantalla^[1] := p.p[1];
pantalla^[2] := p.p[2];
pantalla^[3] := p.p[3];
pantalla^[4] := p.p[4];
pantalla^[5] := p.p[5];
pantalla^[6] := p.p[6];
pantalla^[7] := p.p[7];
pantalla^[8] := p.p[8];
pantalla^[9] := p.p[9];
pantalla^[10] := p.p[10];
pantalla^[11] := p.p[11];
pantalla^[12] := p.p[12];
pantalla^[13] := p.p[13];
pantalla^[14] := p.p[14];
pantalla^[15] := p.p[15];
pantalla^[16] := p.p[16];
pantalla^[17] := p.p[17];
pantalla^[18] := p.p[18];
pantalla^[19] := p.p[19];
pantalla^[20] := p.p[20];
velm := p.velm;
velm2 := p.velm;
velm3 := p.velm;
velm4 := p.velm;
guarda_velm := p.velm;

velp := p.velp;
velp2 := p.velp;

ret_fino_M := p.ret_fino_M;
ret_fino_p := p.ret_fino_p;

titulo := p.titulo;
close (archivo);
end;






{ Inicio de MAIN LOOP2 para juego de 2 players }

procedure main_loop2;
begin;
{ COMIENZO DEL CICLO DE MOVIMIENTO DE LOS PERSONAJES POR TODO
  EL LABERINTO }
repeat
WaitRetrace;
inc (c_principal);

{ CONTADORES VELOCIDAD DEL PACMAN 1 Y 2}
inc (conta2);
inc (conta3);

{ CONTADORES VELOCIDAD DE  LOS MONSTRUOS }
INC (CONTAM1);
INC (CONTAM2);
INC (CONTAM3);
INC (CONTAM4);

 if (c_principal mod velp = 0) then
        begin;
              if conta2 >= ret_fino_p then
                 begin
                      conta2 := 0;
                      avanzap := false
                 end
               else
                 begin;
                       avanzap := true
                 end
        end
       else
         avanzap := false;




 if (c_principal mod velp2 = 0) then
        begin;
              if conta3 >= ret_fino_p then
                 begin
                      conta3 := 0;
                      avanzap2 := false
                 end
               else
                 begin;
                       avanzap2 := true
                 end
        end
       else
         avanzap2 := false;





 if (c_principal mod velM = 0) then
        begin;
              if contaM1 >= ret_fino_M then
                 begin
                      contaM1 := 0;
                      avanzaM := false
                 end
               else
                 begin;
                       avanzaM := true
                 end
        end
       else
         avanzaM := false;


 if (c_principal mod velM2 = 0) then
        begin;
              if contaM2 >= ret_fino_M then
                 begin
                      contaM2 := 0;
                      avanzaM2 := false
                 end
               else
                 begin;
                       avanzaM2 := true
                 end
        end
       else
         avanzaM2 := false;

 if (c_principal mod velM3 = 0) then
        begin;
              if contaM3 >= ret_fino_M then
                 begin
                      contaM3 := 0;
                      avanzaM3 := false
                 end
               else
                 begin;
                       avanzaM3 := true
                 end
        end
       else
         avanzaM3 := false;


 if (c_principal mod velM4 = 0) then
        begin;
              if contaM4 >= ret_fino_M then
                 begin
                      contaM4 := 0;
                      avanzaM4 := false
                 end
               else
                 begin;
                       avanzaM4 := true
                 end
        end
       else
         avanzaM4 := false;






{ CONTADORES PARA DETERMINAR EN QUE CUADRO DE LA ANIMACION DEBE
  ESTAR CADA UNO DE LOS SPRITES                                 }
      inc(contador);
      if contador >= 12 then contador := 0;
      divisor := contador div 3;

      inc(contam);
      if contam >= 60 then contam := 0;
      divimons := (contam div 30);


if vidas > 0 then
    begin;
{ SI EL PACMAN SE ENCUENTRA EN UN CUADRADO ENTONCES QUE HAGA EL CICLO }
      if en_foco (p1) then ciclo_PACMAN (p1);
{ SI PUEDE AVANZAR EL PACMAN 1, QUE AVANCE }

if not(perdi_vida) then
   begin;
         if si_avanza (p1,pantalla) then
            if avanzap then
            begin;
                  p1.px := p1.px + p1.dx;
                  p1.py := p1.py + p1.dy;
            end;
   end
else
   begin;
         inc (cm1);
         case cm1 of
              20 : onscreen[0].num := 3;
              40 : onscreen[0].num := 11;
              60 : onscreen[0].num := 7;
              80 : onscreen[0].num := 13;
              100 : onscreen[0].num := 3;
              120 : onscreen[0].num := 11;
              140 : onscreen[0].num := 7;
              160 : onscreen[0].num := 13;
              180 : onscreen[0].num := 3;
              200 : onscreen[0].num := 11;
              220 : onscreen[0].num := 7;

              300 : begin;
                    onscreen[0].on := false;
                    vidas := vidas - 1;
                    muestra_vidas;
                    end;

              340 : begin;
                          x:=13;
                          y:=11;
                          p1.px := (x * 11);
                          p1.py := (y * 9);
                          p1.dx := -1;
                          p1.dy := 0;
                          posicion := 12;
                    end;
              390 : begin;
                          onscreen[0].on := true;
                          onscreen[0].num := 13;
                    end;
              430 : begin;
                    perdi_vida := false;
                    cm1 := 0;
                    conta_inmunidad_1 := 300;
                    end;
         end;
   end;


if conta_inmunidad_1 > 0 then
                         begin;
                         dec(conta_inmunidad_1);
                         onscreen[0].on := s;
                         if conta_inmunidad_1 = 0 then onscreen[0].on := true;
                         end;



{ POSICIONAMIENTO EN LA PANTALLA DEL PACMAN 1 }
      if p1.px < 12 then
               begin;
                     p1.px := 296;
                     onscreen[0].on := false;
                     show;
                     onscreen[0].on := true;
               end;

      if p1.px > 296 then
               begin;
                     p1.px := 12;
                     onscreen[0].on := false;
                     show;
                     onscreen[0].on := true;
               end;

      if not(perdi_vida) then onscreen [0].num := posicion + divisor;

      onscreen [0].x := p1.px - 2;
      onscreen [0].y := p1.py - 2;

{ EN ESTA PARTE COMPRUEBO SI COLISIONA CON UN MONSTRUO....
  SI ESTADO = 1 ENTONCES PIERDO VIDA
  SI NO ME MORFO UN FANTASMITA }
      if ((m.px < p1.px + 7) and
          (m.px > p1.px - 7) and
          (m.py < p1.py + 6) and
          (m.py > p1.py - 6) and
          (not(perdi_vida)))
             then
                                case st of
                                     1 : if conta_inmunidad_1 = 0 then
                                                              if not(cheat_mode) then
                                                              begin;
                                                              perdi_vida := true;
                                                              me_cagastes;
                                                              end;
                                     0 : begin;
                                         st := 2;
                                         onscreen[1].num := 71 + cuanto;
                                         case cuanto of
                                              1 : puntaje := puntaje + 200;
                                              2 : puntaje := puntaje + 400;
                                              3 : puntaje := puntaje + 800;
                                              4 : begin;
                                                  puntaje := puntaje + 1600;
                                                  inc (conta_morfados);
                                                  if conta_morfados = 6 then
                                                                    begin;
                                                                          onscreen[1].num := 103;
                                                                          vidas := vidas + 1;
                                                                          conta_morfados := 0;
                                                                          muestra_vidas;
                                                                    end;
                                                  end;
                                         end;
                                         onscreen[0].on := false;
                                         show;

                                         sonido_fantasma;

                                         onscreen [1].num := 92;
                                         show;

                                         onscreen[0].on := true;
                                         inc(cuanto);
                                         posm := 68;
                                         scoreme;
                                         velm := 1;
                                end;
             end;



      if ((m2.px < p1.px + 7) and
          (m2.px > p1.px - 7) and
          (m2.py < p1.py + 6) and
          (m2.py > p1.py - 6) and
          (not(perdi_vida)))
            then
                                case st2 of
                                     1 : if conta_inmunidad_1 = 0 then
                                                              if not(cheat_mode) then
                                                              begin;
                                                              perdi_vida := true;
                                                              me_cagastes;
                                                              end;
                                     0 : begin;
                                         st2 := 2;
                                         onscreen[2].num := 71 + cuanto;
                                         case cuanto of
                                              1 : puntaje := puntaje + 200;
                                              2 : puntaje := puntaje + 400;
                                              3 : puntaje := puntaje + 800;
                                              4 : begin;
                                                  puntaje := puntaje + 1600;
                                                  inc (conta_morfados);
                                                  if conta_morfados = 6 then
                                                                    begin;
                                                                          onscreen[2].num := 103;
                                                                          vidas := vidas + 1;
                                                                          muestra_vidas;
                                                                          conta_morfados := 0;
                                                                    end;
                                                  end;
                                         end;
                                         onscreen[0].on := false;
                                         show;

                                         sonido_fantasma;
                                         onscreen [2].num := 92;
                                         show;

                                         inc(cuanto);
                                         onscreen[0].on := true;
                                         posm2 := 68;
                                         scoreme;
                                         velm2 := 1;
                                end;
             end;



      if ((m3.px < p1.px + 7) and
          (m3.px > p1.px - 7) and
          (m3.py < p1.py + 6) and
          (m3.py > p1.py - 6) and
          (not(perdi_vida)))
             then
                                case st3 of
                                     1 : if conta_inmunidad_1 = 0 then
                                                              if not(cheat_mode) then
                                                              begin;
                                                              perdi_vida := true;
                                                              me_cagastes;
                                                              end;
                                     0 : begin;
                                         st3 := 2;
                                         onscreen[3].num := 71 + cuanto;
                                         case cuanto of
                                              1 : puntaje := puntaje + 200;
                                              2 : puntaje := puntaje + 400;
                                              3 : puntaje := puntaje + 800;
                                              4 : begin;
                                                  puntaje := puntaje + 1600;
                                                  inc (conta_morfados);
                                                  if conta_morfados = 6 then
                                                                    begin;
                                                                          onscreen[3].num := 103;
                                                                          vidas := vidas + 1;
                                                                          muestra_vidas;
                                                                          conta_morfados := 0;
                                                                    end;
                                                  end;
                                         end;
                                         onscreen[0].on := false;
                                         show;

                                         sonido_fantasma;
                                         onscreen [3].num := 92;
                                         show;

                                         inc(cuanto);
                                         onscreen[0].on := true;
                                         posm3 := 68;
                                         scoreme;
                                         velm3 := 1;
                                end;
             end;


      if ((m4.px < p1.px + 7) and
          (m4.px > p1.px - 7) and
          (m4.py < p1.py + 6) and
          (m4.py > p1.py - 6) and
          (not(perdi_vida)))
             then
                                case st4 of
                                     1 : if conta_inmunidad_1 = 0 then
                                                              if not(cheat_mode) then
                                                              begin;
                                                              perdi_vida := true;
                                                              me_cagastes;
                                                              end;
                                     0 : begin;
                                         st4 := 2;
                                         onscreen[4].num := 71 + cuanto;
                                         case cuanto of
                                              1 : puntaje := puntaje + 200;
                                              2 : puntaje := puntaje + 400;
                                              3 : puntaje := puntaje + 800;
                                              4 : begin;
                                                  puntaje := puntaje + 1600;
                                                  inc (conta_morfados);
                                                  if conta_morfados = 6 then
                                                                    begin;
                                                                          onscreen[4].num := 103;
                                                                          vidas := vidas + 1;
                                                                          muestra_vidas;
                                                                          conta_morfados := 0;
                                                                    end;
                                                  end;
                                         end;
                                         onscreen[0].on := false;
                                         show;

                                         sonido_fantasma;
                                         onscreen [4].num := 92;
                                         show;
                                         inc(cuanto);
                                         onscreen[0].on := true;
                                         posm4 := 68;
                                         scoreme;
                                         velm4 := 1;
                                end;
             end;
end; {super if}




















if vidas2 > 0 then
begin;
{ SI EL PACMAN2 SE ENCUENTRA EN UN CUADRADO ENTONCES QUE HAGA EL CICLO }
      if en_foco (p2) then ciclo_PACMAN2 (p2);
{ SI PUEDE AVANZAR EL PACMAN 2, QUE AVANCE }


if not(perdi_vida2) then
   begin;
         if si_avanza (p2,pantalla) then
            if avanzap2 then
            begin;
                  p2.px := p2.px + p2.dx;
                  p2.py := p2.py + p2.dy;
            end;
   end
else
   begin;
         inc (cm2);
         case cm2 of
              20 : onscreen[5].num := 85;
              40 : onscreen[5].num := 81;
              60 : onscreen[5].num := 89;
              80 : onscreen[5].num := 77;
              100 : onscreen[5].num := 85;
              120 : onscreen[5].num := 81;
              140 : onscreen[5].num := 89;
              160 : onscreen[5].num := 77;
              180 : onscreen[5].num := 85;
              200 : onscreen[5].num := 81;
              220 : onscreen[5].num := 89;

              300 : begin;
                    onscreen[5].on := false;
                    vidas2 := vidas2 - 1;
                    muestra_vidas;
                    end;

              340 : begin;
                          x2:=15;
                          y2:=11;
                          p2.px := (x2 * 11);
                          p2.py := (y2 * 9);
                          p2.dx := 1;
                          p2.dy := 0;
                          posicion2 := 84;
                    end;

              390 : begin;
                          onscreen[5].on := true;
                          onscreen[5].num := 85;
                    end;
              430 : begin;
                    perdi_vida2 := false;
                    cm2 := 0;
                    conta_inmunidad_2 := 300;
                    end;
         end;
   end;


if conta_inmunidad_2 > 0 then
                         begin;
                         dec(conta_inmunidad_2);
                         onscreen[5].on := s;
                         if conta_inmunidad_2 = 0 then onscreen[5].on := true;
                         end;








{ POSICIONAMIENTO EN LA PANTALLA DEL PACMAN 2 }
      if p2.px < 12 then
         begin;
         p2.px := 296;
         onscreen[5].on := false;
         show;
         onscreen[5].on := true;
         end;


      if p2.px > 296 then
         begin;
         p2.px := 12;
         onscreen[5].on := false;
         show;
         onscreen[5].on := true;
         end;

      if not(perdi_vida2) then onscreen [5].num := posicion2 + divisor;
      onscreen [5].x := p2.px - 2;
      onscreen [5].y := p2.py - 2;
{ EN ESTA PARTE COMPRUEBO SI COLISIONA CON UN MONSTRUO.... (EL PACMAN 2)
  SI ESTADO = 1 ENTONCES PIERDO VIDA
  SI NO ME MORFO UN FANTASMITA }
      if ((m.px < p2.px + 7) and
          (m.px > p2.px - 7) and
          (m.py < p2.py + 6) and
          (m.py > p2.py - 6) and
          (not (perdi_vida2)))
             then
                                case st of
                                     1 : if conta_inmunidad_2 = 0 then
                                                              if not(cheat_mode) then
                                                              begin;
                                                              perdi_vida2 := true;
                                                              me_cagastes;
                                                              end;
                                     0 : begin;
                                         st := 2;
                                         onscreen[1].num := 71 + cuanto;
                                         case cuanto of
                                              1 : puntaje2 := puntaje2 + 200;
                                              2 : puntaje2 := puntaje2 + 400;
                                              3 : puntaje2 := puntaje2 + 800;
                                              4 : begin;
                                                  puntaje2 := puntaje2 + 1600;
                                                  inc (conta_morfados);
                                                  if conta_morfados = 6 then
                                                                    begin;
                                                                          onscreen[1].num := 103;
                                                                          vidas2 := vidas2 + 1;
                                                                          muestra_vidas;
                                                                          conta_morfados := 0;
                                                                    end;
                                                  end;
                                         end;
                                         onscreen[5].on := false;
                                         show;

                                         sonido_fantasma;
                                         onscreen [1].num := 92;
                                         show;
                                         inc(cuanto);
                                         onscreen[5].on := true;
                                         posm := 68;
                                         scoreme2;
                                         velm := 1;
                                end;
             end;



      if ((m2.px < p2.px + 7) and
          (m2.px > p2.px - 7) and
          (m2.py < p2.py + 6) and
          (m2.py > p2.py - 6) and
          (not (perdi_vida2)))
             then
                                case st2 of
                                     1 : if conta_inmunidad_2 = 0 then
                                                              if not(cheat_mode) then
                                                              begin;
                                                              perdi_vida2 := true;
                                                              me_cagastes;
                                                              end;

                                     0 : begin;
                                         st2 := 2;
                                         onscreen[2].num := 71 + cuanto;
                                         case cuanto of
                                              1 : puntaje2 := puntaje2 + 200;
                                              2 : puntaje2 := puntaje2 + 400;
                                              3 : puntaje2 := puntaje2 + 800;
                                              4 : begin;
                                                  puntaje2 := puntaje2 + 1600;
                                                  inc (conta_morfados);
                                                  if conta_morfados = 6 then
                                                                    begin;
                                                                          onscreen[2].num := 103;
                                                                          vidas2 := vidas2 + 1;
                                                                          muestra_vidas;
                                                                          conta_morfados := 0;
                                                                    end;
                                                  end;
                                         end;
                                         onscreen[5].on := false;
                                         show;

                                         sonido_fantasma;
                                         onscreen [2].num := 92;
                                         show;
                                         inc(cuanto);
                                         onscreen[5].on := true;
                                         posm2 := 68;
                                         scoreme2;
                                         velm2 := 1;
                                end;
             end;



      if ((m3.px < p2.px + 7) and
          (m3.px > p2.px - 7) and
          (m3.py < p2.py + 6) and
          (m3.py > p2.py - 6) and
          (not (perdi_vida2)))
             then
                                case st3 of
                                     1 : if conta_inmunidad_2 = 0 then
                                                              if not(cheat_mode) then
                                                              begin;
                                                              perdi_vida2 := true;
                                                              me_cagastes;
                                                              end;

                                     0 : begin;
                                         st3 := 2;
                                         onscreen[3].num := 71 + cuanto;
                                         case cuanto of
                                              1 : puntaje2 := puntaje2 + 200;
                                              2 : puntaje2 := puntaje2 + 400;
                                              3 : puntaje2 := puntaje2 + 800;
                                              4 : begin;
                                                  puntaje2 := puntaje2 + 1600;
                                                  inc (conta_morfados);
                                                  if conta_morfados = 6 then
                                                                    begin;
                                                                          onscreen[3].num := 103;
                                                                          vidas2 := vidas2 + 1;
                                                                          muestra_vidas;
                                                                          conta_morfados := 0;
                                                                    end;
                                                  end;
                                         end;
                                         onscreen[5].on := false;
                                         show;

                                         sonido_fantasma;
                                         onscreen [3].num := 92;
                                         show;
                                         inc(cuanto);
                                         onscreen[5].on := true;
                                         posm3 := 68;
                                         scoreme2;
                                         velm3 := 1;
                                end;
             end;


      if ((m4.px < p2.px + 7) and
          (m4.px > p2.px - 7) and
          (m4.py < p2.py + 6) and
          (m4.py > p2.py - 6) and
          (not (perdi_vida2)))
             then
                                case st4 of
                                     1 : if conta_inmunidad_2 = 0 then
                                                              if not(cheat_mode) then
                                                              begin;
                                                              perdi_vida2 := true;
                                                              me_cagastes;
                                                              end;

                                     0 : begin;
                                         st4 := 2;
                                         onscreen[4].num := 71 + cuanto;
                                         case cuanto of
                                              1 : puntaje2 := puntaje2 + 200;
                                              2 : puntaje2 := puntaje2 + 400;
                                              3 : puntaje2 := puntaje2 + 800;
                                              4 : begin;
                                                  puntaje2 := puntaje2 + 1600;
                                                  inc (conta_morfados);
                                                  if conta_morfados = 6 then
                                                                    begin;
                                                                          onscreen[4].num := 103;
                                                                          vidas2 := vidas2 + 1;
                                                                          muestra_vidas;
                                                                          conta_morfados := 0;
                                                                    end;
                                                  end;
                                         end;
                                         onscreen[5].on := false;
                                         show;

                                         sonido_fantasma;
                                         onscreen [4].num := 92;
                                         show;
                                         inc(cuanto);
                                         onscreen[5].on := true;
                                         posm4 := 68;
                                         scoreme2;
                                         velm4 := 1;
                                end;
             end;
end;          { if re-brutaso }


if competitive then
   if ((st = 0) or
      (st2 = 0) or
      (st3 = 0) or
      (st4 = 0)) then
      begin;
            if ((vidas > 0) and (vidas2 > 0)) then
               begin;
                  if ((p1.px < p2.px + 7) and
                      (p1.px > p2.px - 7) and
                      (p1.py < p2.py + 6) and
                      (p1.py > p2.py - 6) and
                      (not (perdi_vida)) and
                      (not (perdi_vida2)))
                         then
                            begin
                                 case ultimo of
                                      1 : if conta_inmunidad_2 = 0 then begin;
                                                                        perdi_vida2 := true;
                                                                        vidas := vidas + 1;
                                                                        me_cagastes;
                                                                        end;
                                      2 : if conta_inmunidad_1 = 0 then begin;
                                                                        perdi_vida := true;
                                                                        vidas2 := vidas2 + 1;
                                                                        me_cagastes;
                                                                        end;
                                 end;
                            end;
               end;
      end;

 {COMIENZO FRUTAS}

if not(onscreen[6].on) then inc(conta_fruta);

if conta_fruta = aparece_fruta then
                                   BEGIN;
                                         onscreen[6].on := true;
                                         FRUTA_ON := TRUE;
                                   end;

if onscreen[6].on then inc(conta_mientras_fruta);

if conta_mientras_fruta >= 1200 then
                        begin;
                              onscreen[6].on := false;
                              FRUTA_ON := FALSE;
                              conta_fruta := 0;
                              aparece_fruta := random(900) + 900;
                              onscreen[6].num := random(5) + 94;
                              conta_mientras_fruta := 0;
                        end;

if ((p1.px = 154) and (p1.py = 99) and fruta_on) then
             begin;
                        conta_sonido := 0;
                        sonido_pastilla := true;
                        fruta_on := false;
                   case onscreen[6].num of
                        94 : begin;
                             puntaje := puntaje + 200;
                             onscreen[6].num := 72;
                             end;
                        95 : begin;
                             puntaje := puntaje + 500;
                             onscreen[6].num := 99;
                             end;
                        96 : begin;
                             puntaje := puntaje + 1000;
                             onscreen[6].num := 100;
                             end;
                        97 : begin;
                             puntaje := puntaje + 2000;
                             onscreen[6].num := 101;
                             end;
                        98 : begin;
                             puntaje := puntaje + 5000;
                             onscreen[6].num := 102;
                             end;
                   end;
                            conta_fruta := 0;
                            conta_mientras_fruta := 0;
                        conta_puntaje := 150;
                        scoreme;
             end;   {if}


if ((p2.px = 154) and (p2.py = 99) and fruta_on) then
             begin;
                        conta_sonido := 0;
                        sonido_pastilla := true;
                        fruta_on := false;
                   case onscreen[6].num of
                        94 : begin;
                             puntaje2 := puntaje2 + 200;
                             onscreen[6].num := 72;
                             end;
                        95 : begin;
                             puntaje2 := puntaje2 + 500;
                             onscreen[6].num := 99;
                             end;
                        96 : begin;
                             puntaje2 := puntaje2 + 1000;
                             onscreen[6].num := 100;
                             end;
                        97 : begin;
                             puntaje2 := puntaje2 + 2000;
                             onscreen[6].num := 101;
                             end;
                        98 : begin;
                             puntaje2 := puntaje2 + 5000;
                             onscreen[6].num := 102;
                             end;
                   end;
                            conta_fruta := 0;
                            conta_mientras_fruta := 0;
                        conta_puntaje := 150;
                        scoreme2;
             end;   {if}


if conta_puntaje > 10 then dec(conta_puntaje);

if conta_puntaje = 10 then
                      begin;
                            conta_puntaje := 0;
                            onscreen[6].on := false;
                            randomize;
                            aparece_fruta := random(900) + 900;
                            onscreen[6].num := random(5) + 94;
                      end;




{ AQUI COMIENZA EL CICLO DE LOS FANTASMONES. . . }
{ CONTADOR PARA QUE SALGAN LOS FANTASMAS }
      if contasalida > 0 then
                             dec(contasalida);
      if contasalida = 10 then pantalla^ [8,14] := #32;
{ CONTADOR POR EL TIEMPO QUE ME LOS PUEDO MORFAR }
      IF CONTA_MORFAR > 0 then
                              dec (conta_morfar);

      if conta_morfar = 10 then
                           begin
                                cuanto := 1;
                                ultimo := 0;
                                if st = 0 then
                                      begin;
                                            velm := guarda_velm;
                                            posm :=25;
                                            st := 1;
                                      end;

                                if st2 = 0 then
                                      begin;
                                            velm2 := guarda_velm;
                                            posm2 :=25;
                                            st2 := 1;
                                      end;

                                if st3 = 0 then
                                      begin;
                                            velm3 := guarda_velm;
                                            posm3 :=25;
                                            st3 := 1;
                                      end;

                                if st4 = 0 then
                                      begin;
                                            velm4 := guarda_velm;
                                            posm4 :=25;
                                            st4 := 1;
                                      end;
                           end;

      if (conta_morfar < 200) then
                                if (divimons = 0) then setcol (248,0,0,63)
                                  else
                                setcol (248,63,63,63);





{ CICLO DE LOS MONSTRUOS CUANDO ESTAN DENTRO DE UN CUADRADO }
if vidas > 0 then
    begin;
              if (en_foco (m) and avanzam) then ciclo_monstruos (m,p1,pantalla,posm,st);
              if (en_foco (m2) and avanzam2) then ciclo_monstruos (m2,p1,pantalla,posm2,st2);
    end
else
    begin;
              if (en_foco (m) and avanzam) then ciclo_monstruos (m,p2,pantalla,posm,st);
              if (en_foco (m2) and avanzam2) then ciclo_monstruos (m2,p2,pantalla,posm2,st2);
    end;


if vidas2 > 0 then
    begin;
              if (en_foco (m3) and avanzam3) then ciclo_monstruos (m3,p2,pantalla,posm3,st3);
              if (en_foco (m4) and avanzam4) then ciclo_monstruos (m4,p2,pantalla,posm4,st4);
    end
else
    begin;
              if (en_foco (m3) and avanzam3) then ciclo_monstruos (m3,p1,pantalla,posm3,st3);
              if (en_foco (m4) and avanzam4) then ciclo_monstruos (m4,p1,pantalla,posm4,st4);
    end;






{ SI PUEDE AVANZAR EL MONSTRUO 1, QUE AVANCE }
if avanzam then
   begin;
                   m.px := m.px + m.dx;
                   m.py := m.py + m.dy;
   end;
{ SI PUEDE AVANZAR EL MONSTRUO 2, QUE AVANCE }
if avanzam2 then
   begin;
                   m2.px := m2.px + m2.dx;
                   m2.py := m2.py + m2.dy;
   end;
{ SI PUEDE AVANZAR EL MONSTRUO 3, QUE AVANCE }
if avanzam3 then
   begin;
                   m3.px := m3.px + m3.dx;
                   m3.py := m3.py + m3.dy;
   end;
{ SI PUEDE AVANZAR EL MONSTRUO 4, QUE AVANCE }
if avanzam4 then
   begin;
                   m4.px := m4.px + m4.dx;
                   m4.py := m4.py + m4.dy;
   end;


if m.px < 12 then
   begin;
   onscreen[1].on := false;
   show;
   m.px := 296;
   onscreen [1].x := m.px - 2;
   onscreen[1].on := true;
   end;

if m.px > 296 then
   begin;
   m.px := 12;
   onscreen[1].on := false;
   show;
   onscreen [1].x := m.px - 2;
   onscreen[1].on := true;
   end;



if m2.px < 12 then
   begin;
   m2.px := 296;
   onscreen[2].on := false;
   show;
   onscreen[2].on := true;
   onscreen [2].x := m2.px - 2;
   end;

if m2.px > 296 then
   begin;
   m2.px := 12;
   onscreen[2].on := false;
   show;
   onscreen[2].on := true;
   onscreen [2].x := m2.px - 2;
   end;



if m3.px < 12 then
   begin;
   m3.px := 296;
   onscreen[3].on := false;
   show;
   onscreen[3].on := true;
   onscreen [3].x := m3.px - 2;
   end;

if m3.px > 296 then
   begin;
   m3.px := 12;
   onscreen[3].on := false;
   show;
   onscreen [3].x := m3.px - 2;
   onscreen[3].on := true;
   end;


if m4.px < 12 then
   begin;
   m4.px := 296;
   onscreen[4].on := false;
   show;
   onscreen[4].on := true;
   onscreen [4].x := m4.px - 2;
   end;

if m4.px > 296 then
   begin;
   m4.px := 12;
   onscreen[4].on := false;
   show;
   onscreen[4].on := true;
   onscreen[4].x := m4.px - 2;
   end;

{ SEGUN EL ESTADO DEL MONSTRUO 1 ENTONCES QUE MUESTRE BICHO AZULADO O
  BICHO NORMAL }
if avanzam then
begin;
      case st of
           1 : begin;
                     onscreen [1].num := posm + divimons;
                     onscreen [1].x := m.px - 2;
                     onscreen [1].y := m.py - 2;
               end;
           0 : begin;
                     onscreen [1].num := posm + divimons;
                     onscreen [1].x := m.px - 2;
                     onscreen [1].y := m.py - 2;
               end;
           2 : begin;
                     onscreen [1].num := posm;
                     onscreen [1].x := m.px - 2;
                     onscreen [1].y := m.py - 2;
                     if ((m.px = 154) and (m.py = 81)) then
                     begin;
                           velm := guarda_velm;
                           st := 1;
                     end;
               end;
      end;
end;
{ SEGUN EL ESTADO DEL MONSTRUO 2 ENTONCES QUE MUESTRE BICHO AZULADO O
  BICHO NORMAL }
if avanzam2 then
begin;
      case st2 of
           1 : begin;
                    onscreen [2].num := posm2 + divimons + 8;
                    onscreen [2].x := m2.px - 2;
                    onscreen [2].y := m2.py - 2;
               end;
           0 : begin;
                    onscreen [2].num := posm2 + divimons;
                    onscreen [2].x := m2.px - 2;
                    onscreen [2].y := m2.py - 2;
               end;
           2 : begin;
                     onscreen [2].num := posm2;
                     onscreen [2].x := m2.px - 2;
                     onscreen [2].y := m2.py - 2;
                     if ((m2.px = 154) and (m2.py = 81)) then
                     begin;
                           velm2 := guarda_velm;
                           st2 := 1;
                     end;
               end;
      end;
end;
{ SEGUN EL ESTADO DEL MONSTRUO 3 ENTONCES QUE MUESTRE BICHO AZULADO O
  BICHO NORMAL }
if avanzam3 then
begin;
      case st3 of
           1 : begin;
                    onscreen [3].num := posm3 + divimons + 16;
                    onscreen [3].x := m3.px - 2;
                    onscreen [3].y := m3.py - 2;
               end;
           0 : begin;
                    onscreen [3].num := posm3 + divimons;
                    onscreen [3].x := m3.px - 2;
                    onscreen [3].y := m3.py - 2;
               end;
           2 : begin;
                     onscreen [3].num := posm3;
                     onscreen [3].x := m3.px - 2;
                     onscreen [3].y := m3.py - 2;
                     if ((m3.px = 154) and (m3.py = 81)) then
                     begin;
                           velm3 := guarda_velm;
                           st3 := 1;
                     end;
               end;
      end;
end;
{ SEGUN EL ESTADO DEL MONSTRUO 4 ENTONCES QUE MUESTRE BICHO AZULADO O
  BICHO NORMAL }
if avanzam4 then
begin;
      case st4 of
           1 : begin;
                    onscreen [4].num := posm4 + divimons + 24;
                    onscreen [4].x := m4.px - 2;
                    onscreen [4].y := m4.py - 2;
               end;
           0 : begin;
                    onscreen [4].num := posm4 + divimons;
                    onscreen [4].x := m4.px - 2;
                    onscreen [4].y := m4.py - 2;
               end;
           2 : begin;
                     onscreen [4].num := posm4;
                     onscreen [4].x := m4.px - 2;
                     onscreen [4].y := m4.py - 2;
                     if ((m4.px = 154) and (m4.py = 81)) then
                     begin;
                           velm4 := guarda_velm;
                           st4 := 1;
                     end;
               end;
      end;
end;
{ IMPRIMIR 8 SPRITES EN PANTALLA }
      os := 7;
      show;
      bip;
      if divimons = 1 then
      begin;
           setcol (158,52,42,0);
           if ((conta_morfados = 5) and (cuanto = 4)) then
                       setcol (248,63,0,0);
      end
   else
      begin;
           setcol (158,0,0,0);
           if ((conta_morfados = 5) and (cuanto = 4)) then
                       setcol (248,0,0,63);
      end;

      s := not(s);

      for retraso := 1 to pausa do;
      delay (retraso_pii); {MODIFICACION DEL 9-8-99 - para que ande en un PII}

until (presionada[1] or ((vidas = 0) and (vidas2 = 0)) or (cantidad = 0));
end;










procedure inicializa_variables2;
begin;

if vidas > 0 then
begin;
      cm1 := 0;
      conta_inmunidad_1 := 0;

      { POSICION DEL PACMAN  EN LA MATRIZ }
      x:=13;
      y:=11;
      { POSICION DEL PACMAN EN LA PANTALLA }
      p1.px := (x * 11);
      p1.py := (y * 9);
      { DIRECCION DEL PACMAN }
      p1.dx := -1;
      p1.dy := 0;
      posicion := 12;
      { ESTAMPAR EN LA PANTALLA EL PACMAN }
      onscreen[0].num:=posicion;
      onscreen[0].on:=true;
      onscreen[0].y:=p1.py - 2;
      onscreen[0].x:=p1.px - 2;
      { INICIALIZACION DE LA VARIABLE PERDI_VIDA, QUE INDICA SI PERDI O NO UNA
        VIDA. . .  LINDO, NO??? }
      PERDI_VIDA := FALSE;
end;


if vidas2 > 0 then
begin;
      cm2 := 0;
      conta_inmunidad_2 := 0;

      { POSICION DEL PACMAN2  EN LA MATRIZ }
      x2:=15;
      y2:=11;
      { POSICION DEL PACMAN EN LA PANTALLA }
      p2.px := (x2 * 11);
      p2.py := (y2 * 9);
      { DIRECCION DEL PACMAN 2 }
      p2.dx := 1;
      p2.dy := 0;
      posicion2 := 84;
      { ESTAMPAR EN LA PANTALLA EL PACMAN 2}
      onscreen[5].num:=posicion2;
      onscreen[5].on:=true;
      onscreen[5].y:=p2.py - 2;
      onscreen[5].x:=p2.px - 2;
      { INICIALIZACION DE LA VARIABLE PERDI_VIDA, QUE INDICA SI PERDI O NO UNA
        VIDA. . .  LINDO, NO??? }
      PERDI_VIDA2 := FALSE;
end;


{ POSICIONES DE LAS ANIMACIONES DE LOS MONSTRUOS }
posm := 29;
posm2 := 37;
posm3 := 45;
posm4 := 53;
{ POSICION EN LA PANTALLA DEL MONSTRUO 1 }
m.px := (12 * 11) ;
m.py := (9 * 9);
m.dx := 1;
m.dy := 0;
{ POSICION EN LA PANTALLA DEL MONSTRUO 2 }
m2.px := (13 * 11);
m2.py := (9 * 9);
m2.dx := 1;
m2.dy := 0;
{ POSICION EN LA PANTALLA DEL MONSTRUO 3 }
m3.px := (14 * 11);
m3.py := (9 * 9);
m3.dx := 1;
m3.dy := 0;
{ POSICION EN LA PANTALLA DEL MONSTRUO 4 }
m4.px := (15 * 11);
m4.py := (9 * 9);
m4.dx := 1;
m4.dy := 0;
{ CONTADOR DE SALIDA. QUE CUENTE HASTA 350 PARA SALIR }
contasalida := 350;
{ ESTAMPAR EN LA PANTALLA EL MONSTRUO 1 }
onscreen[1].num:=posm;
onscreen[1].on:=true;
onscreen[1].y:=m.py - 2;
onscreen[1].x:=m.px - 2;
{ ESTAMPAR EN LA PANTALLA EL MONSTRUO 2 }
onscreen[2].num:=posm2;
onscreen[2].on:=true;
onscreen[2].y:=m2.py - 2;
onscreen[2].x:=m2.px - 2;
{ ESTAMPAR EN LA PANTALLA EL MONSTRUO 3 }
onscreen[3].num:=posm3;
onscreen[3].on:=true;
onscreen[3].y:=m3.py - 2;
onscreen[3].x:=m3.px - 2;
{ ESTAMPAR EN LA PANTALLA EL MONSTRUO 4 }
onscreen[4].num:=posm4;
onscreen[4].on:=true;
onscreen[4].y:=m4.py - 2;
onscreen[4].x:=m4.px - 2;
{ INICIALIZACION DE LAS VARIABLES DE ESTADO DE LOS MONSTRUOS }
st := 1;
st2 := 1;
st3 := 1;
st4 := 1;

posm := 29;
posm2 := 29;
posm3 := 29;
posm4 := 29;
ultimo := 0;


{ inicializa variable contador frutas }
conta_fruta := 0;

{ inicializa variable cuando aparece la fruta. . .}
randomize;
aparece_fruta := random(900) + 900;

conta_mientras_fruta := 0;
conta_puntaje := 0;
fruta_on := false;

{ posiciona la fruta }
onscreen[6].on := false;
onscreen[6].x := 154;
onscreen[6].y := 99;
onscreen[6].num := random(5) + 94;


os  := 7;
show;

end;












procedure sube_nivel2;
begin;
      inc(nivel);

      onscreen[1].on := false;
      onscreen[2].on := false;
      onscreen[3].on := false;
      onscreen[4].on := false;
      onscreen[6].on := false;
      os := 7;
      show;

      onscreen[1].x := 0;
      onscreen[2].x := 0;
      onscreen[3].x := 0;
      onscreen[4].x := 0;
      onscreen[6].x := 0;
      onscreen[7].x := 0;
      onscreen[1].y := 0;
      onscreen[2].y := 0;
      onscreen[3].y := 0;
      onscreen[4].y := 0;
      onscreen[6].y := 0;
      os := 7;
      show;

      onscreen[0].on := false;
      onscreen[5].on := false;
      os := 6;
      show;

      onscreen[0].x := 0;
      onscreen[0].y := 0;
      onscreen[5].x := 0;
      onscreen[5].y := 0;
      os := 6;
      show;

      setcol (146,25,15,2);
end;