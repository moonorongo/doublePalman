procedure ciclo_Monstruos (var m,p : tipo_pacman;pantalla : tipo_laberinto; var posm : byte; estado : byte );
var
   direccion : byte;
   a,b,d,i : boolean;
   x,y : byte;

begin;
posXY (m,x,y);
a := no_arriba (m,pantalla,x,y);
b := no_abajo (m,pantalla,x,y);
d := no_derecha (m,pantalla,x,y);
i := no_izquierda (m,pantalla,x,y);



case estado of
     1 : begin;
               normal (a,b,i,d,direccion,m,p);
               IF direccion = 1 THEN
                           begin;
                               if a then
                                  begin;
                                     m.dy := -1;
                                     m.dx := 0;
                                     posm := 25;
                                  end;
                               end;

               IF direccion = 2 THEN
                           begin;
                              if b then
                                 begin;
                                       m.dy := 1;
                                       m.dx := 0;
                                       posm := 27;
                                  end;
                           end;

               IF direccion = 3 THEN
                           begin;
                                 if i then
                                    begin;
                                          m.dy := 0;
                                          m.dx := -1;
                                          posm := 31;
                                    end;
                           end;


               IF direccion = 4 THEN
                           begin;
                                 if d then
                                    begin;
                                          m.dy := 0;
                                          m.dx := 1;
                                          posm := 29;
                                    end;
                           end ;
         end;



     0 : begin;
               cagado (a,b,i,d,direccion,m,p);
               IF direccion = 1 THEN
                           begin;
                               if a then
                                  begin;
                                     m.dy := -1;
                                     m.dx := 0;
                                     posm := 66;
                                  end;
                               end;

               IF direccion = 2 THEN
                           begin;
                              if b then
                                 begin;
                                       m.dy := 1;
                                       m.dx := 0;
                                       posm := 66;
                                  end;
                           end;

               IF direccion = 3 THEN
                           begin;
                                 if i then
                                    begin;
                                          m.dy := 0;
                                          m.dx := -1;
                                          posm := 66;
                                    end;
                           end;


               IF direccion = 4 THEN
                           begin;
                                 if d then
                                    begin;
                                          m.dy := 0;
                                          m.dx := 1;
                                          posm := 66;
                                    end;
                           end ;
          end;



     2 : begin;
               ojitos (a,b,i,d,direccion,m,p);
               IF direccion = 1 THEN
                           begin;
                               if a then
                                  begin;
                                     m.dy := -1;
                                     m.dx := 0;
                                     posm := 68;
                                  end;
                               end;

               IF direccion = 2 THEN
                           begin;
                              if b then
                                 begin;
                                       m.dy := 1;
                                       m.dx := 0;
                                       posm := 69;
                                  end;
                           end;

               IF direccion = 3 THEN
                           begin;
                                 if i then
                                    begin;
                                          m.dy := 0;
                                          m.dx := -1;
                                          posm := 71;
                                    end;
                           end;


               IF direccion = 4 THEN
                           begin;
                                 if d then
                                    begin;
                                          m.dy := 0;
                                          m.dx := 1;
                                          posm := 70;
                                    end;
                           end ;
         end;

end;










end;