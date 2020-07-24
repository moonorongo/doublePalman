uses
    crt;

type
    registro = record
                   d : word;
                   velp : byte;
                   velm : byte;
                   p : array [1..20] of string[28];
                   ret_fino_p : byte;
                   ret_fino_m : byte;
                   titulo : string [40];
                   end;


var
   px,py   : byte;
   tecla,c : char;
   p       : registro;
   nivel   : byte;
   archivo : file of registro;


procedure fill_laberinto;
var
   x,y : byte;

begin;
for y := 1 to 20 do
    for x := 1 to 28 do
        if p.p[y,x] = #32 then p.p[y,x] := #46;

for x := 1 to 20 do
         begin;
               gotoxy (1,x);
               write (p.p[x]);
         end;
end;










procedure inicio;
begin
textmode (c80 + font8x8);
gotoxy (29,1); write ('Û');
gotoxy (29,2); write ('Û');
gotoxy (29,3); write ('Û');
gotoxy (29,4); write ('Û');
gotoxy (29,5); write ('Û');
gotoxy (29,6); write ('Û');
gotoxy (29,7); write ('Û');
gotoxy (29,8); write ('Û');
gotoxy (29,9); write ('Û');
gotoxy (29,10); write ('Û');
gotoxy (29,11); write ('Û');
gotoxy (29,12); write ('Û');
gotoxy (29,13); write ('Û');
gotoxy (29,14); write ('Û');
gotoxy (29,15); write ('Û');
gotoxy (29,16); write ('Û');
gotoxy (29,17); write ('Û');
gotoxy (29,18); write ('Û');
gotoxy (29,19); write ('Û');
gotoxy (29,20); write ('Û');
gotoxy (1,21); write ('ÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛ');

gotoxy (1,22);
writeln ('I, K, J, L : MOVIMIENTOS CURSORES');
writeln ('9 = CARGAR NIVEL       ----   ESC = SALIR Y SALVAR ');
writeln ('5 = RELLENAR LABERINTO CON PUNTITOS ');
writeln ('6 = Velocidad pacman ***** <-> = Fino Pacman ');
writeln ('7 = Vel. monsters    ***** <=> = Fino monstruos');
writeln ('8 = duracion pastilla      <`> = Titulo del nivel');

end;








procedure cargar_nivel (nivel : byte; var p : registro);
var
   archivo : file of registro;
   px : byte;

begin;
assign (archivo,'PACMAN.lvl');
reset (archivo);

seek (archivo,nivel);
read (archivo,p);
close (archivo);


for px := 1 to 20 do
         begin;
               gotoxy (1,px);
               write (p.p[px]);
         end;

gotoxy (1,28);
write ('duracion: ' );
writeln (p.d : 5);
write ('velocidad pacman: ');
writeln (p.velp : 3);
write ('velocidad monstruos: ');
writeln (p.velm : 3);
write ('NIVEL: ');
writeln (nivel : 3);
write ('Titulo: ');
writeln (p.titulo);
write ('Fino pacman: ');
writeln (p.ret_fino_p);
write ('Fino monsters: ');
writeln (p.ret_fino_m);





end;


















begin;
inicio;
p.d := 600;
p.p[1]:=  'ษอออออออออออออออออออออออออป ';
p.p[2]:=  'บ                         บ ';
p.p[3]:=  'บ                         บ ';
p.p[4]:=  'บ                         บ ';
p.p[5]:=  'บ                         บ ';
p.p[6]:=  'บ       ษอออต ฦอออป       บ ';
p.p[7]:=  'บ       บ         บ       บ ';
p.p[8]:=  'บ       ะ ษออ=ออป ะ       บ ';
p.p[9]:=  'บ         บ     บ         บ ';
p.p[10]:= 'บ       า ศอออออผ า       บ ';
p.p[11]:= 'บ       บ         บ       บ ';
p.p[12]:= 'บ       ศอออต ฦอออผ       บ ';
p.p[13]:= 'บ                         บ ';
p.p[14]:= 'บ                         บ ';
p.p[15]:= 'บ                         บ ';
p.p[16]:= 'บ                         บ ';
p.p[17]:= 'บ                         บ ';
p.p[18]:= 'บ                         บ ';
p.p[19]:= 'บ                         บ ';
p.p[20]:= 'ศอออออออออออออออออออออออออผ ';



for px := 1 to 20 do
         begin;
               gotoxy (1,px);
               write (p.p[px]);
         end;



assign (archivo,'pacman.lvl');
{$I-}
reset (archivo);
if ioresult <> 0 then
                     begin;
                           rewrite (archivo);
                           for px := 0 to 100 do
                               begin;
                                     seek (archivo,px);
                                     write (archivo,p);
                               end;
                     end;
close (archivo);
{$I+}






px := 1;
py := 1;

repeat
tecla := readkey;

case tecla of
     'i' : dec(py);
     'k' : inc(py);
     'j' : dec(px);
     'l' : inc(px);


     'q' : c :=  #201;
     'z' : c :=  #200;
     'e' : c :=  #187;
     'c' : c :=  #188;

     'w' : c :=  #203;
     'x' : c :=  #202;
     'a' : c :=  #204;
     'd' : c :=  #185;

     't' : c :=  #210;
     'g' : c :=  #208;
     'f' : c :=  #198;
     'h' : c :=  #181;

     '1' : c :=  #205;
     '2' : c :=  #186;
     '3' : c :=  #206;
     ' ' : c :=  #32;
     '>' : c :=  '>';
     '<' : c :=  '<';
     '9' : begin;
           clrscr;
           write ('nivel a cargar: ');
           readln (nivel);
           inicio;
           cargar_nivel(nivel,p);
           end;

     '5' : fill_laberinto;

     '.' : c := #46;
     ',' : c := #44;
     's' : c := '*';
     'n' : c := 'n';
     'm' : c := 'm';


     '6' : begin;
           gotoxy (1,40);
           write ('Vel. Pacman:');
           write (p.velp);
           write ('--->:');
           readln (p.velp);
           end;

     '7' : begin;
           gotoxy (1,40);
           write ('Vel. Monsters:');
           write (p.velm);
           write ('--->:');
           readln (p.velm);
           end;

     '8' : begin;
           gotoxy (1,40);
           write ('Duracion:');
           write (p.d);
           write ('--->:');
           readln (p.d);
           end;


     '`' : begin;
           gotoxy (1,40);
           writeln ('Old titulo:',p.titulo);
           write ('new titulo:');
           readln (p.titulo);
           end;


     '-' : begin;
           gotoxy (1,40);
           write ('Fino pacman:');
           write (p.ret_fino_p);
           write ('--->:');
           readln (p.ret_fino_p);
           end;

     '=' : begin;
           gotoxy (1,40);
           write ('Fino monsters:');
           write (p.ret_fino_m);
           write ('--->:');
           readln (p.ret_fino_m);
           end;

     ']' : begin;
           gotoxy (1,40);
           write ('nivel:');
           write (nivel);
           write ('--->:');
           readln (nivel);
           end;





end;

if px < 1 then px := 28;
if px > 28 then px := 1;

if py < 1 then py := 20;
if py > 20 then py := 1;


if ((tecla <> 'i') and
    (tecla <> 'k') and
    (tecla <> 'j') and
    (tecla <> 'l') and
    (tecla <> #27) and
    (tecla <> '5') and
    (tecla <> '6') and
    (tecla <> '7') and
    (tecla <> '-') and
    (tecla <> '=') and
    (tecla <> '`') and
    (tecla <> '8') and
    (tecla <> '9') and
    (tecla <> ']'))   then
                      begin
                           write(c);
                           p.p[py,px] := c;
                      end;
gotoxy (px,py);

until tecla = #27;



clrscr;



assign (archivo,'pacman.lvl');
reset (archivo);
seek (archivo,nivel);
write (archivo,p);
close (archivo);



textmode (3);
end.


